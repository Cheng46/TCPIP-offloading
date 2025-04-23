`include "defines.v"

/******************************************************************************************************************************************************************
$Description :  Exchanges deliberately keep packet sizes smaller than the IP packet size limit, with a maximum of around 1200 bytes. 
                IP fragmentation only occurs in cases of network equipment anomalies or broadcast traffic, but most major exchanges use UDP unicast.
                Maintaining a fragmentation reassembly state machine consumes FPGA logic and storage resources, so we discard all fragmented packets directly.

******************************************************************************************************************************************************************/

module ip_rx (
    input wire                        i_sys_clk,
    input wire                        i_rstn,

    input wire                        i_new_packet,
    input wire[ `FPGA_DATA_WIDTH-1:0] i_ip_data,

    input wire                        i_bad_packet_en,
    input wire                        i_bad_packet,

    input wire                        i_tcp_drop,
    input wire                        i_udp_drop,

    output wire                       o_drop_packet,
    output wire                       o_ip_rx_busy,

    output reg                        o_new_segment,
    output wire                       o_drop_segment,
    output reg[                31:0]  o_src_ip,
    output reg[                15:0]  o_segment_len_b,
    output reg[                 7:0]  o_segment_type,                          // protocol_type_latch, 8'h01 => icmp, 8'h06 => tcp, 8'h11 => udp
    output reg[`FPGA_DATA_WIDTH-1:0]  o_segment_data
    
);

  // ================================================================================================
  // IP datagram header format
  //
  //	0          4          8                      16      19             24                    31
  //	--------------------------------------------------------------------------------------------
  //	| Version  | *Header  |    Service Type      |        Total Length including header        |
  //	|   (4)    |  Length  |     (ignored)        |                 (in bytes)                  |
  //	--------------------------------------------------------------------------------------------
  //	|           Identification                   | Flags |       Fragment Offset               |
  //	|                                            |       |      (in 32 bit words)              |
  //	--------------------------------------------------------------------------------------------
  //	|    Time To Live     |       Protocol       |             Header Checksum                 |
  //	|     (ignored)       |                      |                                             |
  //	--------------------------------------------------------------------------------------------
  //	|                                   Source IP Address                                      |
  //	|                                                                                          |
  //	--------------------------------------------------------------------------------------------
  //	|                                 Destination IP Address                                   |
  //	|                                                                                          |
  //	--------------------------------------------------------------------------------------------
  //	|                          Options (if any - ignored)               |       Padding        |
  //	|                                                                   |      (if needed)     |
  //	--------------------------------------------------------------------------------------------
  //	|                                          Data                                            |
  //	|                                                                                          |
  //	--------------------------------------------------------------------------------------------
  //	|                                          ....                                            |
  //	|                                                                                          |
  //	--------------------------------------------------------------------------------------------

    localparam TYPE_TCP  = 8'h06;                
    localparam TYPE_UDP  = 8'h11;
    localparam TYPE_ICMP = 8'h01;

    localparam IDLE_STAGE   = 2'b00; 
    localparam HEADER_STAGE = 2'b01;
    localparam TRANS_STAGE  = 2'b10;

    reg[1:0]  CUR_STAGE;
    reg[1:0]  NXT_STAGE;

    reg[3:0]  ip_ver_latch;           // ip version latch
    reg[3:0]  ihl_latch;              // internet header latch, we pretent there's no option + pending for exchanges packet. 
                                      // We will drop packet if ihl_latch is not 4'b0101, which means 0x5 (20) bytes
    //reg[15:0] total_len;            // total length for whole ip packet, only needed when we need to recieve tcp packet
    reg[2:0]  flag_latch;             // flag latch, it can only be 3'b010, which means no fragmentation
    reg[12:0] frag_offset_latch;      // fragment offset
    reg[7:0]  protocol_latch;
    reg[31:0] src_ip_latch;           // source ip address
    reg[31:0] dst_ip_latch;           // destination ip address
    reg[15:0] tt_len_latch;
    reg[13:0] rx_cnt;
    reg[ 7:0] checksum_temp;
    reg[15:0] checksum_sum;
    reg       checksum_cnt;
    reg[16:0] checksum_extend;
    reg       packet_en_prev;

    assign o_ip_rx_busy = CUR_STAGE != IDLE_STAGE;

    assign o_drop_packet = (rx_cnt > 14'd19) && ((ip_ver_latch != 4'b0100) || (ihl_latch != 4'b0101) || (flag_latch != 3'b010) || (protocol_latch == TYPE_ICMP) ||
                           (frag_offset_latch != 13'b0) || (dst_ip_latch != `FPGA_IP) || check_failed);     // drop the packet if: 
                                                                                                            // - not IPV4 packet / 
                                                                                                            // - have options or padding
                                                                                                            // - fragment packet / 
                                                                                                            // - ICMP packet / 
                                                                                                            // - IP is not FPGA address / 
                                                                                                            // - Checksum failed / 
    assign o_drop_segment = i_bad_packet_en && i_bad_packet && (CUR_STAGE == TRANS_STAGE);

    wire header_done = (rx_cnt == 14'd19) && (~check_failed); 
    wire trans_drop  = i_udp_drop || i_tcp_drop;

    // ==============================================================================
    // IP RX FSM
    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            CUR_STAGE <= IDLE_STAGE;
        end 
        else begin 
            CUR_STAGE <= NXT_STAGE;
        end 
    end 
    
    always @(*) begin 
        if (~i_rstn) begin 
            NXT_STAGE = IDLE_STAGE;
        end 
        case (CUR_STAGE) 
            IDLE_STAGE: begin 
                if (i_new_packet) begin 
                    NXT_STAGE = HEADER_STAGE;
                end 
            end 
            HEADER_STAGE: begin 
                if (o_drop_packet) begin 
                    NXT_STAGE = IDLE_STAGE;
                end 
                else if (header_done) begin 
                    NXT_STAGE = TRANS_STAGE;
                end 
            end 
            TRANS_STAGE: begin 
                if (i_bad_packet_en && i_bad_packet || (packet_en_prev && ~i_new_packet) || trans_drop) begin 
                    NXT_STAGE = IDLE_STAGE;
                end
                else begin 
                    NXT_STAGE = CUR_STAGE;
                end  
            end 
            default: begin 
                NXT_STAGE = IDLE_STAGE;
            end 
        endcase
    end 
    always @(posedge i_sys_clk or negedge i_rstn) begin
        if (~i_rstn) begin
            packet_en_prev      <= 1'b0;
        end 
        else begin 
            packet_en_prev      <= i_new_packet;
        end
    end

    // ==============================================================================
    // Parse packet and send it to next layer 

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || ~i_new_packet || trans_drop) begin 
            ip_ver_latch        <= 4'b0;
            ihl_latch           <= 4'b0;
            flag_latch          <= 3'b0;
            frag_offset_latch   <= 13'b0;
            protocol_latch      <= 8'b0;
            src_ip_latch        <= 32'b0;
            dst_ip_latch        <= 32'b0;
            rx_cnt              <= 14'b0;
            o_new_segment       <= 1'b0;
            o_src_ip            <= 32'b0;
            o_segment_len_b     <= 16'b0;
            o_segment_type      <= 8'b0;
            o_segment_data      <= 8'b0;
        end 
        else begin 
            rx_cnt <= rx_cnt + 14'b1;
            if ((rx_cnt > 14'd19) && ~check_failed) begin                    
                o_new_segment    <= 1'b1;
                o_src_ip         <= src_ip_latch;
                o_segment_len_b  <= tt_len_latch - ({12'b0, ihl_latch} << 2);
                o_segment_type   <= protocol_latch;
                o_segment_data   <= i_ip_data;
            end 
            case (rx_cnt)
                14'd0: begin 
                    ip_ver_latch <= i_ip_data[7:4];
                    ihl_latch    <= i_ip_data[3:0];
                end 
                14'd2, 14'd3: begin 
                    tt_len_latch <= (tt_len_latch << 8) | {8'b0, i_ip_data};
                end 
                14'd6: begin 
                    flag_latch          <= i_ip_data[7:5];
                    frag_offset_latch   <= {i_ip_data[4:0], 8'b0};
                end 
                14'd7: begin 
                    frag_offset_latch   <= frag_offset_latch | {5'b0, i_ip_data};
                end 
                14'd9: begin 
                    protocol_latch      <= i_ip_data;
                end 
                14'd12, 14'd13, 14'd14, 14'd15: begin 
                    src_ip_latch        <=  (src_ip_latch << 8) | {24'b0, i_ip_data};
                end
                14'd16, 14'd17, 14'd18, 14'd19: begin 
                    dst_ip_latch        <=  (dst_ip_latch << 8) | {24'b0, i_ip_data};
                end
                default: begin 
                end 
            endcase
        end 
    end 


    // ==============================================================================
    // Checksum 

    wire check_failed = (rx_cnt > 14'd19) && (checksum_extend[15:0]!= 16'hFFFF);

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || ~i_new_packet) begin 
            checksum_extend <= 17'b0;
            checksum_temp   <= 8'b0;
            checksum_sum    <= 16'b0;
            checksum_cnt    <= 1'b0;
        end 
        else if (rx_cnt <= 14'd19) begin 
            checksum_cnt <= checksum_cnt + 1'b1;
            if (checksum_cnt == 1'b1) begin 
                checksum_extend <= {1'b0, checksum_sum} + {1'b0, checksum_temp, i_ip_data};
            end 
            else if (checksum_cnt == 1'b0) begin 
                checksum_temp   <= i_ip_data;
                checksum_extend <= 17'b0;
                if (checksum_extend[16]) begin 
                    checksum_sum <= checksum_extend[15:0] + 16'b1;
                end 
                else begin                                              
                    checksum_sum <= checksum_extend[15:0];
                end
            end 
        end
    end 
endmodule

