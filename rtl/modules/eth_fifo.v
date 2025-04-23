`include "defines.v"

/******************************************************************************************************************************************************************
$Description :  This fifo queue is design for storing both ethernet frame and the size of each ethernet frame.

                In MII interface, we will receive 4bit data in a single clock, and an ethernet frame can up to 1518 bytes,
                which is 12144 bits, we cache 2 transmission for one line, so we need 1518 lines for storing a ethernet frame.

                In this design, we will use FIFO_DEPTH = 12144 lines (data fifo queue), which means we can store at least 8 ethernet frames. 
                Also, we will use FIFO_DEPTH = 190 lines (len fifo queue), which means we can store 190 ethernet framess length. 
                (Because ethernet could be 64 bytes, 12144/64 = 189.75 => we need 190 lines)
******************************************************************************************************************************************************************/

module eth_fifo (
    input wire                                 i_rx_clk,
    input wire                                 i_sys_clk,          //for read data from the queue

    input wire                                 i_rstn,

    // data queue fifo input
    input wire                                 i_data_fifo_w_en,
    input wire[        `FPGA_DATA_WIDTH-1:0]   i_data_fifo_data,

    input wire                                 i_data_fifo_r_en,
    input wire                                 i_data_fifo_r_stop,
    input wire[$clog2(`DATA_FIFO_DEPTH)-1:0]   i_data_fifo_r_line,           // i_data_fifo_r_end_line

    // len queue fifo input
    input wire                                 i_len_fifo_w_en,
    input wire[        `ETH_FRAME_WIdTH-1:0]   i_len_fifo_data,
    
    input wire                                 i_len_fifo_r_en,
    input wire[ $clog2(`LEN_FIFO_DEPTH)-1:0]   i_len_fifo_r_line,

    // data queue fifo output
    output reg                                 o_data_fifo_r_done,
    output wire                                o_data_fifo_empty,     
    output wire                                o_data_fifo_full,    
    output reg[        `FPGA_DATA_WIDTH-1:0]   o_data_fifo_data,      
    
    // len queue fifo output
    output reg                                 o_len_fifo_r_done,
    output wire                                o_len_fifo_empty,     
    output wire                                o_len_fifo_full,    
    output reg[        `ETH_FRAME_WIdTH-1:0]   o_len_fifo_data      
);

    fifo_queue#(
        .DATA_WIDTH              (  `FPGA_DATA_WIDTH),
        .FIFO_DEPTH              (  `DATA_FIFO_DEPTH)
    )eth_data_fifo0 (
        .i_sys_clk               (         i_sys_clk),         
        .i_rx_clk                (          i_rx_clk),
        .i_rstn                  (            i_rstn),
        .i_fifo_w_en             (  i_data_fifo_w_en),
        .i_data                  (  i_data_fifo_data),
        .i_fifo_r_en             (  i_data_fifo_r_en),
        .i_fifo_r_stop           (i_data_fifo_r_stop),
        .i_fifo_r_len            (i_data_fifo_r_line),
        .o_fifo_r_done           (o_data_fifo_r_done),
        .o_fifo_empty            ( o_data_fifo_empty),     
        .o_fifo_full             (  o_data_fifo_full),    
        .o_data                  (  o_data_fifo_data)
    );


    fifo_queue#(
        .DATA_WIDTH              (    `ETH_FRAME_WIdTH),
        .FIFO_DEPTH              (     `LEN_FIFO_DEPTH)
    )eth_len_fifo1 (
        .i_sys_clk               (        i_sys_clk),         
        .i_rx_clk                (         i_rx_clk),
        .i_rstn                  (           i_rstn),
        .i_fifo_w_en             (  i_len_fifo_w_en),
        .i_data                  (  i_len_fifo_data),
        .i_fifo_r_en             (  i_len_fifo_r_en),
        .i_fifo_r_stop           (             1'b0),
        .i_fifo_r_len            (i_len_fifo_r_line),
        .o_fifo_r_done           (o_len_fifo_r_done),
        .o_fifo_empty            ( o_len_fifo_empty),     
        .o_fifo_full             (  o_len_fifo_full),    
        .o_data                  (  o_len_fifo_data)
    );


endmodule