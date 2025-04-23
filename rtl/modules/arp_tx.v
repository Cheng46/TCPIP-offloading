`include "defines.v"

module arp_tx #(
    parameter FPGA_IP    = 32'hC0A80106,
    parameter FPGA_MAC   = 48'h00183E043329
)(
    input wire                          i_sys_clk,
    input wire                          i_rstn,

    input wire                          i_lookup_en,
    input wire[               31:0]     i_lookup_ip,

    input wire                          i_rx_new_packet,
    input wire                          i_need_reply,
    input wire[               31:0]     i_receive_ip,
    input wire[               47:0]     i_receive_mac,

    output reg                          o_lookup_done,
    output reg                          o_lookup_result,         // success = 1, failed = 0
    output reg[               47:0]     o_lookup_mac,

    output reg                          o_arp_packet_en,
    output reg[`MII_DATA_WIDTH-1:0]     o_arp_packet_data,
    output wire                         o_arp_tx_busy
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
    localparam LOOKUP_STAGE  = 2'b01;
    localparam SEND_STAGE    = 2'b10;


    reg[ 1:0]  CUR_STAGE;
    reg[ 1:0]  NXT_STAGE;

    assign o_arp_tx_busy = CUR_STAGE != IDLE_STAGE;
    
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
            NXT_STAGE = IDLE_STAGE;
        end 
        else begin 
            case (CUR_STAGE)
                IDLE_STAGE: begin 
                    if (i_lookup_en) begin 
                        NXT_STAGE <= LOOKUP_STAGE;
                    end
                    else if (i_rx_new_packet && i_need_reply) begin 
                        NXT_STAGE = SEND_STAGE;
                    end 
                    else begin 
                        NXT_STAGE = IDLE_STAGE;
                    end  
                end 
                LOOKUP_STAGE: begin 
                    if (mac_unkwown) begin 
                        NXT_STAGE = SEND_STAGE;
                    end 
                    else begin 
                        NXT_STAGE = IDLE_STAGE;
                    end
                end 
                SEND_STAGE: begin 
                    if (arp_send_done) begin 
                        NXT_STAGE = IDLE_STAGE;
                    end 
                    else begin 
                        NXT_STAGE = SEND_STAGE;
                    end 
                end 
                default: begin 
                end 
            endcase
        end 
    end 

    // ==============================================================================
    // ARP Reply latch
    reg[47:0]  src_mac_latch;
    reg[31:0]  src_ip_latch;

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || (CUR_STAGE == IDLE_STAGE)) begin 
            src_mac_latch <= 48'b0;
            src_ip_latch  <= 32'b0;
        end 
        else if (i_need_reply) begin 
            src_mac_latch <= i_receive_mac;
            src_ip_latch  <= i_receive_ip;
        end 
    end 

    // ==============================================================================
    // ARP Cache
    reg         mac_unkwown;
    reg[31:0]   lookup_ip_latch;


    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || (CUR_STAGE == IDLE_STAGE)) begin 
            mac_unkwown          <= 1'b0;
            lookup_ip_latch      <= 32'b0;
        end
        else if (CUR_STAGE == LOOKUP_STAGE) begin 
            if (i_lookup_en) begin 
                lookup_ip_latch <= i_lookup_ip;
            end 
            if (o_lookup_done && (~o_lookup_result)) begin 
                mac_unkwown      <=  1'b1;
            end
        end
    end 


    arp_cache  #(
        .ENTRY_DEPTH        (              5)
    )arp_cache0(
        .i_sys_clk          (      i_sys_clk),
        .i_rstn             (         i_rstn),
        .i_lookup_en        (    i_lookup_en),
        .i_lookup_ip        (    i_lookup_ip),
        .i_cache_w_en       (i_rx_new_packet),
        .i_cache_w_ip       (   i_receive_ip),
        .i_cache_w_mac      (  i_receive_mac),
        .o_lookup_done      (  o_lookup_done),
        .o_lookup_result    (o_lookup_result),            
        .o_lookup_mac       (   o_lookup_mac)
    );

    // ==============================================================================
    // Send ARP packet
    // We will send an ARP request

    reg[ 5:0]  arp_send_cnt;
    reg        arp_send_done;

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            arp_send_cnt        <= 6'b0;
            o_arp_packet_en      <= 1'b1;
            o_arp_packet_data    <= 4'b0;
            arp_send_done       <= 1'b0;
        end 
        else if (arp_send_done) begin 
            arp_send_cnt        <= 6'b0;
            o_arp_packet_en      <= 1'b1;
            o_arp_packet_data    <= 4'b0;
            arp_send_done       <= 1'b0;
        end 
        else if (mac_unkwown) begin                            // Send ARP Request packet
            arp_send_cnt   <= arp_send_cnt + 6'b1;
            o_arp_packet_en <= 1'b1;
            case (arp_send_cnt)
                6'd0, 6'd1, 6'd2: begin        	               // Hardware type -- ETH (0x01)
                    o_arp_packet_data <= 4'b0;
                end 
                6'd3: begin                                    // Hardware type -- ETH (0x01)
                    o_arp_packet_data <= 4'b1; 
                end  
                6'd4, 6'd6, 6'd7: begin                        // Protocol type -- IPV4 (0x0800)
                    o_arp_packet_data <= 4'b0;
                end 
                6'd5: begin                                    // Protocol type -- IPV4 (0x0800)
                    o_arp_packet_data <= 4'b1000; 
                end     
                6'd8: begin                                    // Hardware Address length in bytes -- 6
                    o_arp_packet_data <= 4'b0;
                end 
                6'd9: begin                                    // Hardware Address length in bytes -- 6
                    o_arp_packet_data <= 4'b0110;
                end           
                6'd10: begin                                   // IP Address length in bytes -- 4
                    o_arp_packet_data <= 4'b0;
                end 
                6'd11: begin                                   // IP Address length in bytes -- 64
                    o_arp_packet_data <= 4'b0100;
                end           
                6'd12, 6'd13, 6'd14: begin                     // Operation Code -- Request (1)
                    o_arp_packet_data <= 4'b0;
                end 
                6'd15: begin                                   // Operation Code -- Request (1)
                    o_arp_packet_data <= 4'b0001; 
                end     
                6'd16: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[47:44];
                end 
                6'd17: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[43:40];
                end 
                6'd18: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[39:36];
                end 
                6'd19: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[35:32];
                end 
                6'd20: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[31:28];
                end 
                6'd21: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[27:24];
                end 
                6'd22: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[23:20];
                end 
                6'd23: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[19:16];
                end 
                6'd24: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[15:12];
                end 
                6'd25: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[11:8];
                end 
                6'd26: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[7:4];
                end 
                6'd27: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[3:0];
                end 
                6'd28: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[31:28];
                end 
                6'd29: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[27:24];
                end 
                6'd30: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[23:20];
                end 
                6'd31: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[19:16];
                end 
                6'd32: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[15:12];
                end 
                6'd33: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[11:8];
                end 
                6'd34: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[7:4];
                end 
                6'd35: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[3:0];
                end 
                6'd36: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd37: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd38: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd39: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd40: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd41: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd42: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd43: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd44: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd45: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd46: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd47: begin                                   // Dst MAC -- need to be 48'b0
                    o_arp_packet_data <= 4'b0;
                end 
                6'd48: begin                                   // Dst IP Address byte -- from IP
                    o_arp_packet_data <= lookup_ip_latch[31:28];
                end 
                6'd49: begin                                   // Dst IP Address byte -- from IP
                    o_arp_packet_data <= lookup_ip_latch[27:24];
                end 
                6'd50: begin                                   // Dst IP Address byte -- from IP
                    o_arp_packet_data <= lookup_ip_latch[23:20];
                end 
                6'd51: begin                                   // Dst IP Address byte -- from IP
                    o_arp_packet_data <= lookup_ip_latch[19:16];
                end 
                6'd52: begin                                   // Dst IP Address byte -- from IP
                    o_arp_packet_data <= lookup_ip_latch[15:12];
                end 
                6'd53: begin                                   // Dst IP Address byte -- from IP
                    o_arp_packet_data <= lookup_ip_latch[11:8];
                end 
                6'd54: begin                                   // Dst IP Address byte -- from IP
                    o_arp_packet_data <= lookup_ip_latch[7:4];
                end 
                6'd55: begin                                   // Dst IP Address byte -- from IP
                    o_arp_packet_data <= lookup_ip_latch[3:0];
                    arp_send_done     <= 1'b1;
                end 
                default: begin
                end
            endcase
        end 
        else if (i_need_reply) begin                           // Send ARP Reply packet
            arp_send_cnt   <= arp_send_cnt + 6'b1;
            o_arp_packet_en <= 1'b1;
            case (arp_send_cnt)
                6'd0, 6'd1, 6'd2: begin        	               // Hardware type -- ETH (0x01)
                    o_arp_packet_data <= 4'b0;
                end 
                6'd3: begin                                    // Hardware type -- ETH (0x01)
                    o_arp_packet_data <= 4'b1; 
                end  
                6'd4, 6'd6, 6'd7: begin                        // Protocol type -- IPV4 (0x0800)
                    o_arp_packet_data <= 4'b0;
                end 
                6'd5: begin                                    // Protocol type -- IPV4 (0x0800)
                    o_arp_packet_data <= 4'b1000; 
                end     
                6'd8: begin                                    // Hardware Address length in bytes -- 6
                    o_arp_packet_data <= 4'b0;
                end 
                6'd9: begin                                    // Hardware Address length in bytes -- 6
                    o_arp_packet_data <= 4'b0110;
                end           
                6'd10: begin                                   // IP Address length in bytes -- 4
                    o_arp_packet_data <= 4'b0;
                end 
                6'd11: begin                                   // IP Address length in bytes -- 64
                    o_arp_packet_data <= 4'b0100;
                end           
                6'd12, 6'd13, 6'd14: begin                     // Operation Code -- Reply (2)
                    o_arp_packet_data <= 4'b0;
                end 
                6'd15: begin                                   // Operation Code -- Reply (2)
                    o_arp_packet_data <= 4'b0010; 
                end     
                6'd16: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[47:44];
                end 
                6'd17: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[43:40];
                end 
                6'd18: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[39:36];
                end 
                6'd19: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[35:32];
                end 
                6'd20: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[31:28];
                end 
                6'd21: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[27:24];
                end 
                6'd22: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[23:20];
                end 
                6'd23: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[19:16];
                end 
                6'd24: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[15:12];
                end 
                6'd25: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[11:8];
                end 
                6'd26: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[7:4];
                end 
                6'd27: begin                                   // Src MAC -- FPGA MAC
                    o_arp_packet_data <= FPGA_MAC[3:0];
                end 
                6'd28: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[31:28];
                end 
                6'd29: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[27:24];
                end 
                6'd30: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[23:20];
                end 
                6'd31: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[19:16];
                end 
                6'd32: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[15:12];
                end 
                6'd33: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[11:8];
                end 
                6'd34: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[7:4];
                end 
                6'd35: begin                                   // Sender IP Address byte -- FPGA IP
                    o_arp_packet_data <= FPGA_IP[3:0];
                end 
                6'd36: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[47:44];
                end 
                6'd37: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[43:40];
                end 
                6'd38: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[39:36];
                end 
                6'd39: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[35:32];
                end 
                6'd40: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[31:28];
                end 
                6'd41: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[27:24];
                end 
                6'd42: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[23:20];
                end 
                6'd43: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[19:16];
                end 
                6'd44: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[15:12];
                end 
                6'd45: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[11:8];
                end 
                6'd46: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[7:4];
                end 
                6'd47: begin                                   // Dst MAC -- source MAC of last ARP packet
                    o_arp_packet_data <= src_mac_latch[3:0];
                end 
                6'd48: begin                                   // Dst IP Address byte -- source IP of last ARP packet
                    o_arp_packet_data <= src_ip_latch[31:28];
                end 
                6'd49: begin                                   // Dst IP Address byte -- source IP of last ARP packet
                    o_arp_packet_data <= src_ip_latch[27:24];
                end 
                6'd50: begin                                   // Dst IP Address byte -- source IP of last ARP packet
                    o_arp_packet_data <= src_ip_latch[23:20];
                end 
                6'd51: begin                                   // Dst IP Address byte -- source IP of last ARP packet
                    o_arp_packet_data <= src_ip_latch[19:16];
                end 
                6'd52: begin                                   // Dst IP Address byte -- source IP of last ARP packet
                    o_arp_packet_data <= src_ip_latch[15:12];
                end 
                6'd53: begin                                   // Dst IP Address byte -- source IP of last ARP packet
                    o_arp_packet_data <= src_ip_latch[11:8];
                end 
                6'd54: begin                                   // Dst IP Address byte -- source IP of last ARP packet
                    o_arp_packet_data <= src_ip_latch[7:4];
                end 
                6'd55: begin                                   // Dst IP Address byte -- source IP of last ARP packet
                    o_arp_packet_data <= src_ip_latch[3:0];
                    arp_send_done     <= 1'b1;
                end 
                default: begin
                end
            endcase
        end 
    end
endmodule