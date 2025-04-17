`include "defines.v"

module arp_rx #(
    parameter FPGA_IP    = 32'hC0A80106,
    parameter FPGA_MAC   = 48'h00183E043329
)(
    input wire                          i_sys_clk,
    input wire                          i_rstn,

<<<<<<< HEAD
    input wire                          i_new_frame,
    input wire[`MII_DATA_WIDTH-1:0]     i_frame_data,

    input wire                          i_bad_frame_en,
    input wire                          i_bad_frame,

    input wire                          i_arp_tx_busy,

    output reg                          o_new_frame,
=======
    input wire                          i_new_packet,
    input wire[`MII_DATA_WIDTH-1:0]     i_packet_data,

    input wire                          i_bad_packet_en,
    input wire                          i_bad_packet,

    input wire                          i_arp_tx_busy,

    output reg                          o_new_packet,
>>>>>>> 51757a0 (WIP: save changes before rebase)
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
<<<<<<< HEAD
    reg        new_frame_latch;
=======
    reg        new_packet_latch;
>>>>>>> 51757a0 (WIP: save changes before rebase)

    reg[ 1:0]  CUR_STAGE;
    reg[ 1:0]  NXT_STAGE;

<<<<<<< HEAD
    wire correct_frame = i_bad_frame_en && (~i_bad_frame);
    wire gather_done   = new_frame_latch && correct_frame;
=======
    wire correct_packet = i_bad_packet_en && (~i_bad_packet);
    wire gather_done   = new_packet_latch && correct_packet;
>>>>>>> 51757a0 (WIP: save changes before rebase)

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
    
    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
<<<<<<< HEAD
            o_new_frame          <= 1'b1;
=======
            o_new_packet         <= 1'b1;
>>>>>>> 51757a0 (WIP: save changes before rebase)
            o_arp_receive_ip     <= 32'b0;
            o_arp_receive_mac    <= 48'b0;
            o_arp_need_reply     <= 1'b0;
            o_arp_rx_busy        <= 1'b0;
            NXT_STAGE            <= IDLE_STAGE;  
        end 
        else begin 
            case (CUR_STAGE)
                IDLE_STAGE: begin 
<<<<<<< HEAD
                    o_new_frame          <= 1'b1;
=======
                    o_new_packet         <= 1'b1;
>>>>>>> 51757a0 (WIP: save changes before rebase)
                    o_arp_receive_ip     <= 32'b0;
                    o_arp_receive_mac    <= 48'b0;
                    o_arp_need_reply     <= 1'b0;
                    o_arp_rx_busy        <= 1'b0;
<<<<<<< HEAD
                    if (i_new_frame) begin 
=======
                    if (i_new_packet) begin 
>>>>>>> 51757a0 (WIP: save changes before rebase)
                        NXT_STAGE   <= GATHER_STAGE;
                    end
                    else begin 
                        NXT_STAGE <= IDLE_STAGE;
                    end  
                end 
                GATHER_STAGE: begin 
                    o_arp_rx_busy <= 1'b1;
<<<<<<< HEAD
                    if (i_bad_frame_en && i_bad_frame) begin 
                        NXT_STAGE <= IDLE_STAGE;
                    end 
                    else if (arp_request || arp_reply) begin 
                        NXT_STAGE <= TRANS_STAGE;
                    end
=======
                    o_arp_rx_busy <= 1'b1;
                    if (arp_request || arp_reply && (i_bad_packet_en && ~i_bad_packet)) begin 
                        NXT_STAGE <= TRANS_STAGE;
                    end
                    else if (i_bad_packet_en && i_bad_packet) begin 
                        NXT_STAGE <= IDLE_STAGE;
                    end 
>>>>>>> 51757a0 (WIP: save changes before rebase)
                    else begin 
                        NXT_STAGE <= GATHER_STAGE;
                    end  
                end 
                TRANS_STAGE: begin 
                    if (i_arp_tx_busy) begin 
                        o_arp_rx_busy <= 1'b1;
                        NXT_STAGE     <= TRANS_STAGE;
                    end 
                    else begin 
<<<<<<< HEAD
                        o_new_frame          <= 1'b1;
=======
                        o_new_packet         <= 1'b1;
>>>>>>> 51757a0 (WIP: save changes before rebase)
                        o_arp_receive_ip     <= src_ip_latch;
                        o_arp_receive_mac    <= src_mac_latch;
                        NXT_STAGE            <= IDLE_STAGE;  
                        if (arp_request) begin 
                            o_arp_need_reply <= 1'b1;
                        end
                        else begin 
                            o_arp_need_reply <= 1'b0;
                        end
                    end
                end 
                default: begin 
<<<<<<< HEAD
                        o_new_frame          <= 1'b0;
=======
                        o_new_packet         <= 1'b0;
>>>>>>> 51757a0 (WIP: save changes before rebase)
                        o_arp_receive_ip     <= 32'b0;
                        o_arp_receive_mac    <= 48'b0;
                        o_arp_need_reply     <= 1'b0;
                        o_arp_rx_busy        <= 1'b0;
                        NXT_STAGE            <= IDLE_STAGE;  
                end 
            endcase
        end 
    end 


    // ==============================================================================
<<<<<<< HEAD
    // Receive ARP frame
    wire arp_done;
    wire my_arp_frame = (hardware_type_latch == 16'd1) && (protocol_type_latch == 16'h0800) && (dest_ip_latch == FPGA_IP);
    wire arp_request  = gather_done && my_arp_frame && (opcode_latch == 16'd1) && (~arp_done);
    wire arp_reply    = gather_done && my_arp_frame && (opcode_latch == 16'd2) && (~arp_done);
=======
    // Receive ARP packet
    wire arp_done;
    wire my_arp_packet= (hardware_type_latch == 16'd1) && (protocol_type_latch == 16'h0800) && (dest_ip_latch == FPGA_IP);
    wire arp_request  = gather_done && my_arp_packet && (opcode_latch == 16'd1) && (~arp_done);
    wire arp_reply    = gather_done && my_arp_packet && (opcode_latch == 16'd2) && (~arp_done);
>>>>>>> 51757a0 (WIP: save changes before rebase)

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || arp_done) begin 
            hardware_type_latch     <= 16'b0; 
            protocol_type_latch     <= 16'b0;
            opcode_latch            <= 16'b0;
            src_mac_latch           <= 48'b0;
            src_ip_latch            <= 32'b0;
            dest_ip_latch           <= 32'b0;
            arp_recieve_cnt         <= 6'b0;
<<<<<<< HEAD
            new_frame_latch         <= 1'b0;
        end 
        else if (i_new_frame) begin 
            arp_recieve_cnt <= arp_recieve_cnt + 6'b1;
            new_frame_latch <= 1;
            case (arp_recieve_cnt) 
                6'd0, 6'd1, 6'd2, 6'd3: begin 
                    hardware_type_latch <= (hardware_type_latch << 4) | {12'b0, i_frame_data};
                end 
                6'd4, 6'd5, 6'd6, 6'd7: begin 
                    protocol_type_latch <= (protocol_type_latch << 4) | {12'b0, i_frame_data};
                end 
                6'd12, 6'd13, 6'd14, 6'd15: begin 
                    opcode_latch        <= (opcode_latch << 4) | {12'b0, i_frame_data};
                end 
                6'd16, 6'd17, 6'd18, 6'd19, 6'd20, 6'd21, 
                6'd22, 6'd23, 6'd24, 6'd25, 6'd26, 6'd27: begin 
                    src_mac_latch       <= (src_mac_latch << 4) | {44'b0, i_frame_data};
                end 
                6'd28, 6'd29, 6'd30, 6'd31, 6'd32, 6'd33, 6'd34, 6'd35: begin 
                    src_ip_latch        <= (src_ip_latch << 4) | {28'b0, i_frame_data};
                end 
                6'd48, 6'd49, 6'd50, 6'd51, 6'd52, 6'd53, 6'd54, 6'd55: begin 
                    dest_ip_latch       <= (dest_ip_latch << 4) | {28'b0, i_frame_data};
=======
            new_packet_latch         <= 1'b0;
        end 
        else if (i_new_packet) begin 
            arp_recieve_cnt <= arp_recieve_cnt + 6'b1;
            new_packet_latch <= 1;
            case (arp_recieve_cnt) 
                6'd0, 6'd1, 6'd2, 6'd3: begin 
                    hardware_type_latch <= (hardware_type_latch << 4) | {12'b0, i_packet_data};
                end 
                6'd4, 6'd5, 6'd6, 6'd7: begin 
                    protocol_type_latch <= (protocol_type_latch << 4) | {12'b0, i_packet_data};
                end 
                6'd12, 6'd13, 6'd14, 6'd15: begin 
                    opcode_latch        <= (opcode_latch << 4) | {12'b0, i_packet_data};
                end 
                6'd16, 6'd17, 6'd18, 6'd19, 6'd20, 6'd21, 
                6'd22, 6'd23, 6'd24, 6'd25, 6'd26, 6'd27: begin 
                    src_mac_latch       <= (src_mac_latch << 4) | {44'b0, i_packet_data};
                end 
                6'd28, 6'd29, 6'd30, 6'd31, 6'd32, 6'd33, 6'd34, 6'd35: begin 
                    src_ip_latch        <= (src_ip_latch << 4) | {28'b0, i_packet_data};
                end 
                6'd48, 6'd49, 6'd50, 6'd51, 6'd52, 6'd53, 6'd54, 6'd55: begin 
                    dest_ip_latch       <= (dest_ip_latch << 4) | {28'b0, i_packet_data};
>>>>>>> 51757a0 (WIP: save changes before rebase)
                end 
                default: begin 
                end
            endcase
        end
    end 

endmodule