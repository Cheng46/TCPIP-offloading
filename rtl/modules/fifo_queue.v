`include "defines.v"

module fifo_queue #(
    parameter DATA_WIDTH = 4,
    parameter FIFO_DEPTH = 12144                            
)(
    input wire                          i_rx_clk,
    input wire                          i_sys_clk,          //for read data
    input wire                          i_rstn,

    input wire                          i_fifo_w_en,
    input wire[       DATA_WIDTH-1:0]   i_data,
    
    input wire                          i_fifo_r_en,
    input wire                          i_fifo_r_stop,
    //input wire[$clog2(FIFO_DEPTH)-1:0]   i_fifo_r_start_line,
    input wire[$clog2(FIFO_DEPTH)-1:0]  i_fifo_r_len,
    output reg                          o_fifo_r_done,
    output wire                         o_fifo_empty,     
    output wire                         o_fifo_full,    
    output reg[       DATA_WIDTH-1:0]   o_data      
);

    reg[        DATA_WIDTH-1:0] fifo_q  [FIFO_DEPTH-1:0];
    reg[$clog2(FIFO_DEPTH)-1:0] w_ptr;
    reg[$clog2(FIFO_DEPTH)-1:0] r_ptr;
    reg[$clog2(FIFO_DEPTH)-1:0] r_start_ptr;

    wire last_read;

    assign o_fifo_empty = w_ptr == r_ptr;
    assign o_fifo_full  = ((w_ptr + 1) % FIFO_DEPTH) == r_ptr;

    // write to fifo
    integer i;
    always @(posedge i_rx_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            w_ptr <= 0;
        end 
        else if (i_fifo_w_en && ~o_fifo_full) begin 
            fifo_q [w_ptr] <= i_data;
            w_ptr          <= (w_ptr + 1) % FIFO_DEPTH;
        end
    end 

    wire[$clog2(FIFO_DEPTH)-1:0] end_line = r_start_ptr + i_fifo_r_len - 1;
    wire[$clog2(FIFO_DEPTH)-1:0] fifo_r_end_line = ((end_line >= r_start_ptr) && ~(end_line >= FIFO_DEPTH))? end_line : (r_start_ptr - 1 - (FIFO_DEPTH - i_fifo_r_len));
    assign                       last_read = r_ptr == fifo_r_end_line;

    // read from fifo
    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            r_start_ptr   <= 0;
            o_data        <= 0;
            o_fifo_r_done <= 0;
            r_ptr         <= 0;
        end 
        else if (i_fifo_r_en && ~o_fifo_empty) begin 
            if (i_fifo_r_stop) begin 
                o_data        <= {DATA_WIDTH{1'b0}};
                o_fifo_r_done <= 1'b1;
                r_ptr         <= (fifo_r_end_line + 1) % FIFO_DEPTH;
            end 
            else if (last_read) begin 
                o_data        <= fifo_q[r_ptr];
                o_fifo_r_done <= 1;
                r_ptr         <= (r_ptr + 1) % FIFO_DEPTH;
            end 
            else begin
                o_data        <= fifo_q[r_ptr];
                o_fifo_r_done <= 0;
                r_ptr         <= (r_ptr + 1) % FIFO_DEPTH;
            end 
        end
        else begin 
            r_start_ptr   <= r_ptr;
            o_data        <= 0;
            o_fifo_r_done <= 0;
        end 
    end   


endmodule