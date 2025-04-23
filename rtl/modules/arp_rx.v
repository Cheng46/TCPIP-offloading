`include "defines.v"

module arp_rx (
    input wire                          i_sys_clk,
    input wire                          i_rstn,

    input wire                          i_new_packet,
    input wire[`FPGA_DATA_WIDTH-1:0]    i_packet_data,

    input wire                          i_bad_packet_en,
    input wire                          i_bad_packet,

    input wire                          i_arp_tx_busy,

    output reg                          o_new_packet,
    output reg                          o_arp_need_reply,
    output reg[               31:0]     o_arp_receive_ip,
    output reg[               47:0]     o_arp_receive_mac,
    output reg                          o_arp_rx_busy
);

  // ======================================================================================================================
  //    ARP header format
  //
  //	0                      8                      16                                          31               47
  //	------------------------------------------------------------------------------------------------------------
  //	|                 Hardware Type              |                Protocol Type                |
  //	|                                            |                                             |
  //	--------------------------------------------------------------------------------------------
  //	|     Hard. Addr.      |       Prot. Addr.   |                Operation Code               |
  //	|       Length         |         Type        |                                             |
  //	------------------------------------------------------------------------------------------------------------
  //	|                                       Source Mac                                                         |
  //	------------------------------------------------------------------------------------------------------------
  //	|                                  Source Protocol Address                                 |
  //	------------------------------------------------------------------------------------------------------------
  //	|                                       Target Mac                                                         |
  //	------------------------------------------------------------------------------------------------------------
  //	|                                  Target Protocol Address                                 |
  //	--------------------------------------------------------------------------------------------
  //
  // ======================================================================================================================


    localparam IDLE_STAGE    = 2'b00;
    localparam GATHER_STAGE  = 2'b01;
    localparam TRANS_STAGE   = 2'b10;

    reg[15:0]  hardware_type_latch;
    reg[15:0]  protocol_type_latch;
    reg[15:0]  opcode_latch;
    reg[47:0]  src_mac_latch;
    reg[31:0]  src_ip_latch;
    reg[31:0]  dest_ip_latch;
    reg[ 5:0]  arp_recieve_cnt;
    reg        new_packet_latch;

    reg[ 1:0]  CUR_STAGE;
    reg[ 1:0]  NXT_STAGE;

    wire correct_packet = i_bad_packet_en && (~i_bad_packet);
    wire gather_done   = new_packet_latch && correct_packet;

    // ==============================================================================
    // ARP Ctrl FSM
    
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
            o_new_packet         = 1'b1;
            o_arp_receive_ip     = 32'b0;
            o_arp_receive_mac    = 48'b0;
            o_arp_need_reply     = 1'b0;
            o_arp_rx_busy        = 1'b0;
            NXT_STAGE            = IDLE_STAGE;  
        end 
        else begin 
            case (CUR_STAGE)
                IDLE_STAGE: begin 
                    o_new_packet         = 1'b1;
                    o_arp_receive_ip     = 32'b0;
                    o_arp_receive_mac    = 48'b0;
                    o_arp_need_reply     = 1'b0;
                    o_arp_rx_busy        = 1'b0;
                    if (i_new_packet) begin 
                        NXT_STAGE   = GATHER_STAGE;
                    end
                    else begin 
                        NXT_STAGE = IDLE_STAGE;
                    end  
                end 
                GATHER_STAGE: begin 
                    o_arp_rx_busy = 1'b1;
                    if ((arp_request || arp_reply) && (i_bad_packet_en && ~i_bad_packet)) begin 
                        NXT_STAGE = TRANS_STAGE;
                    end
                    else if (i_bad_packet_en && i_bad_packet) begin 
                        NXT_STAGE = IDLE_STAGE;
                    end 
                    else begin 
                        NXT_STAGE = GATHER_STAGE;
                    end  
                end 
                TRANS_STAGE: begin 
                    if (i_arp_tx_busy) begin 
                        o_arp_rx_busy = 1'b1;
                        NXT_STAGE     = TRANS_STAGE;
                    end 
                    else begin 
                        o_arp_rx_busy        = 1'b1;
                        o_new_packet         = 1'b1;
                        o_arp_receive_ip     = src_ip_latch;
                        o_arp_receive_mac    = src_mac_latch;
                        NXT_STAGE            = IDLE_STAGE;  
                        if (arp_request) begin 
                            o_arp_need_reply = 1'b1;
                        end
                        else begin 
                            o_arp_need_reply = 1'b0;
                        end
                    end
                end 
                default: begin 
                end 
            endcase
        end 
    end 


    // ==============================================================================
    // Receive ARP packet
    wire arp_done;
    wire my_arp_packet= (hardware_type_latch == 16'd1) && (protocol_type_latch == 16'h0800) && (dest_ip_latch == `FPGA_IP);
    wire arp_request  = gather_done && my_arp_packet && (opcode_latch == 16'd1) && (~arp_done);
    wire arp_reply    = gather_done && my_arp_packet && (opcode_latch == 16'd2) && (~arp_done);

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || arp_done) begin 
            hardware_type_latch     <= 16'b0; 
            protocol_type_latch     <= 16'b0;
            opcode_latch            <= 16'b0;
            src_mac_latch           <= 48'b0;
            src_ip_latch            <= 32'b0;
            dest_ip_latch           <= 32'b0;
            arp_recieve_cnt         <= 6'b0;
            new_packet_latch        <= 1'b0;
        end 
        else if (i_new_packet) begin 
            arp_recieve_cnt <= arp_recieve_cnt + 6'b1;
            new_packet_latch <= 1;
            case (arp_recieve_cnt) 
                6'd0, 6'd1: begin 
                    hardware_type_latch <= (hardware_type_latch << 8) | {8'b0, i_packet_data};
                end 
                6'd2, 6'd3: begin 
                    protocol_type_latch <= (protocol_type_latch << 8) | {8'b0, i_packet_data};
                end 
                6'd6, 6'd7: begin 
                    opcode_latch        <= (opcode_latch << 8) | {8'b0, i_packet_data};
                end 
                6'd8, 6'd9, 6'd10, 6'd11, 6'd12, 6'd13: begin 
                    src_mac_latch       <= (src_mac_latch << 8) | {40'b0, i_packet_data};
                end 
                6'd14, 6'd15, 6'd16, 6'd17: begin 
                    src_ip_latch        <= (src_ip_latch << 8) | {24'b0, i_packet_data};
                end 
                6'd18, 6'd19, 6'd20, 6'd21: begin 
                    dest_ip_latch       <= (dest_ip_latch << 8) | {24'b0, i_packet_data};
                end 
                default: begin 
                end
            endcase
        end
    end 

endmodule