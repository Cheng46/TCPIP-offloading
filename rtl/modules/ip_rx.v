`include "defines.v"

/******************************************************************************************************************************************************************
$Description :  Exchanges deliberately keep packet sizes smaller than the IP packet size limit, with a maximum of around 1200 bytes. 
                IP fragmentation only occurs in cases of network equipment anomalies or broadcast traffic, but most major exchanges use UDP unicast.
                Maintaining a fragmentation reassembly state machine consumes FPGA logic and storage resources, so we discard all fragmented packets directly.

******************************************************************************************************************************************************************/

module ip_rx #(
    parameter FPGA_IP    = 32'hC0A80106
)(
    input wire                       i_sys_clk,
    input wire                       i_rstn,

    input wire                       i_new_frame,
    input wire[`MII_DATA_WIDTH-1:0]  i_ip_data,

    input wire                       i_bad_frame_en,
    input wire                       i_bad_frame,

    output wire                      o_drop_frame,
    output reg                       o_ip_rx_busy,

    output reg                       o_new_frame,
    output reg[                7:0]  o_frame_type,                          // protocol_type_latch, 8'h01 => icmp, 8'h06 => tcp, 8'h11 => udp
    output reg[`MII_DATA_WIDTH-1:0]  o_frame_data
    
);

  // ==============================================================================
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

    reg       new_frame_en_latch;
    reg[3:0]  ip_ver_latch;           // ip version latch
    reg[3:0]  ihl_latch;              // internet header latch, we pretent there's no option + pending for exchanges frame. 
                                      // We will drop frame if ihl_latch is not 4'b1110, which means 0x14 (20) bytes
    //reg[15:0] total_len;            // total length for whole ip frame, only needed when we need to recieve tcp frame
    reg[2:0]  flag_latch;             // flag latch, it can only be 3'b010, which means no fragmentation
    reg[12:0] frag_offset_latch;      // fragment offset
    reg[7:0]  protocol_latch;
    reg[15:0] checksum_latch;
    reg[31:0] src_ip_latch;           // source ip address
    reg[31:0] dst_ip_latch;           // destination ip address
    reg[13:0] rx_cnt;
    reg[15:0] checksum_temp;
    reg[15:0] checksum_sum;
    reg[1:0] checksum_cnt;
    reg[16:0] checksum_extend;


    assign o_drop_frame = new_frame_en_latch && ((ip_ver_latch != 4'b0100) || (ihl_latch != 4'b1110) || (flag_latch != 3'b010) || (protocol_latch == 8'h01) ||
                      (frag_offset_latch != 13'b0) || (src_ip_latch != FPGA_IP) || check_failed);     // drop the frame if: 
                                                                                                      // - not IPC4 frame / 
                                                                                                      // - fragment frame / 
                                                                                                      // - ICMP frame / 
                                                                                                      // - IP is not FPGA address / 
                                                                                                      // - Checksum failed / 
    wire header_done = (rx_cnt == 14'd39) && (~check_failed); 


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
    
    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            NXT_STAGE <= IDLE_STAGE;
        end 
        else begin 
            case (CUR_STAGE) 
                IDLE_STAGE: begin 
                    if (i_new_frame) begin 
                        NXT_STAGE <= HEADER_STAGE;
                    end 
                end 
                HEADER_STAGE: begin 
                    if ((i_bad_frame_en && i_bad_frame) || o_drop_frame) begin 
                        NXT_STAGE <= IDLE_STAGE;
                    end 
                    else if (header_done) begin 
                        NXT_STAGE <= TRANS_STAGE;
                    end 
                end 
                TRANS_STAGE: begin 
                    NXT_STAGE <= IDLE_STAGE;
                end 
                default: begin 
                    NXT_STAGE <= IDLE_STAGE;
                end 
            endcase
        end 
    end 

    // ==============================================================================
    // Parse frame and send it to next layer 

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (!i_rstn || (CUR_STAGE == IDLE_STAGE)) begin 
            new_frame_en_latch  <= 1'b0;
            ip_ver_latch        <= 4'b0;
            ihl_latch           <= 4'b0;
            flag_latch          <= 3'b0;
            frag_offset_latch   <= 13'b0;
            protocol_latch      <= 8'b0;
            checksum_latch      <= 16'b0;
            src_ip_latch        <= 32'b0;
            dst_ip_latch        <= 32'b0;
            rx_cnt              <= 14'b0;
            o_new_frame         <= 1'b0;
            o_frame_type        <= 8'b0;
            o_frame_data        <= 4'b0;
        end 
        else if (i_new_frame) begin 
            rx_cnt <= rx_cnt + 14'b1;
            case (rx_cnt)
                14'd0: begin 
                    ip_ver_latch <= i_ip_data;
                end 
                14'd1: begin 
                    ihl_latch    <= i_ip_data;
                end
                14'd12: begin 
                    flag_latch             <= i_ip_data[3:1];
                    frag_offset_latch[12]  <= i_ip_data[0];
                end 
                14'd13, 14'd14, 14'd15: begin 
                    frag_offset_latch      <= (frag_offset_latch << 4) | {9'b0, i_ip_data};
                end 
                14'd18, 14'd19: begin 
                    protocol_latch <= (protocol_latch << 4) | {4'b0, i_ip_data};
                end 
                14'd20, 14'd21, 14'd22, 14'd23: begin 
                    checksum_latch <= (checksum_latch << 4) | {12'b0, i_ip_data};
                end 
                14'd24, 14'd25, 14'd26, 14'd27, 14'd28, 14'd29, 14'd30, 14'd31: begin 
                    src_ip_latch   <=  (src_ip_latch << 4) | {28'b0, i_ip_data};
                end
                14'd32, 14'd33, 14'd34, 14'd35, 14'd36, 14'd37, 14'd38, 14'd39: begin 
                    dst_ip_latch   <=  (dst_ip_latch << 4) | {28'b0, i_ip_data};
                end
                default: begin 
                    if ((rx_cnt > 14'd39) && (!check_failed)) begin                    
                        o_new_frame  <= 1'b1;
                        o_frame_type <= protocol_latch;
                        o_frame_data <= i_ip_data;
                    end 
                end 
            endcase
        end 
    end 


    // ==============================================================================
    // Checksum 

    wire check_failed = (rx_cnt > 14'd39) && ((checksum_extend[15:0] + checksum_latch) != 16'hFFFF);

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || (CUR_STAGE == IDLE_STAGE)) begin 
            checksum_extend <= 17'b0;
            checksum_temp   <= 16'b0;
            checksum_sum    <= 16'b0;
            checksum_cnt    <= 2'b0;
        end 
        else if (i_new_frame && ((rx_cnt < 14'd20) || (rx_cnt > 14'd23)) && (rx_cnt <= 14'd39)) begin 
            checksum_cnt <= checksum_cnt + 2'b1;
            if (checksum_cnt == 2'b11) begin 
                checksum_extend <= {1'b0, checksum_sum} + {1'b0, checksum_temp[11:0], i_ip_data};
            end 
            else if (checksum_cnt == 2'b00) begin 
                checksum_temp   <= 16'b0 | {12'b0, i_ip_data};
                checksum_extend <= 17'b0;
                if (checksum_extend[16]) begin 
                    checksum_sum <= 16'b1;
                end 
                else begin 
                    checksum_sum <= checksum_extend[15:0];
                end
            end 
            else begin 
                checksum_temp <= (checksum_temp << 4) | {12'b0, i_ip_data};
            end 
        end
    end 
endmodule