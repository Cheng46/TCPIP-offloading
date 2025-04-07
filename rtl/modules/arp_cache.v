`include "defines.v"


/*  In this ARP Cache module, we use a FIFO queue, which has 5 entry, but w_ptr only count from 0~3, because entry number 5 store router's IP and MAC. The reason why we don't use a timer to downcount entry and delete it when it's timeout is that, 
    router don't often change it's MAC address.
*/
module arp_cache #(
    parameter ENTRY_DEPTH     = 5,
    parameter ROUTER_IP       = 32'hC0A80106,
    parameter ROUTER_MAC      = 48'h107C4FA2A003
)(
    input wire          i_sys_clk,
    input wire          i_rstn,
    input wire          i_lookup_en,
    input wire[31:0]    i_lookup_ip,
    input wire          i_cache_w_en,
    input wire[31:0]    i_cache_w_ip,
    input wire[47:0]    i_cache_w_mac,

    output reg          o_lookup_done,
    output reg          o_lookup_result,            // success = 1, failed = 0
    output reg[47:0]    o_lookup_mac
);

    reg[47:0]   arp_mac_queue          [ENTRY_DEPTH-1:0];
    reg[31:0]   arp_ip_queue           [ENTRY_DEPTH-1:0];
    //reg         arp_data_valid         [ENTRY_DEPTH-1:0];
    //reg         arp_queue_timer_fresh  [ENTRY_DEPTH-1:0];
    reg[ 2:0]   queue_w_ptr;

    reg[$clog2(ENTRY_DEPTH-1):0] a;
    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            queue_w_ptr                   <= 3'b0;
            arp_mac_queue[ENTRY_DEPTH-1]  <= ROUTER_MAC;
            arp_ip_queue [ENTRY_DEPTH-1]  <= ROUTER_IP;
            for (a = 0; a < ENTRY_DEPTH-1; a = a + 1) begin 
                arp_mac_queue[a]          <= 48'b0;
                arp_ip_queue [a]          <= 32'b0;
                //arp_data_valid[a]         <= 1'b0;
                //arp_queue_timer_fresh[a]  <= 1'b0;
            end 
        end 
        else if (i_cache_w_en) begin 
            arp_mac_queue[queue_w_ptr] <= i_cache_w_mac;
            arp_ip_queue [queue_w_ptr] <= i_cache_w_ip;
            queue_w_ptr                <= queue_w_ptr;
        end 
    end 


    integer b;
    always @(*) begin 
        o_lookup_done   = 1'b0;
        o_lookup_result = 1'b0;
        o_lookup_mac    = 48'b0;
        if (i_lookup_en) begin 
            for (b = 0; b < ENTRY_DEPTH; b = b + 1) begin
                if (i_lookup_ip == arp_ip_queue[b]) begin
                    o_lookup_done   = 1'b1;
                    o_lookup_result = 1'b1;
                    o_lookup_mac    = arp_mac_queue[b];
                end
            end
            if (o_lookup_done == 1'b0) begin
                o_lookup_done   = 1'b1;
                o_lookup_result = 1'b0;
                o_lookup_mac    = 48'b0;
            end
        end    
    end    
endmodule