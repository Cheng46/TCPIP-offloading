`include "defines.v"

/******************************************************************************************************************************************************************
$Description : This module is responsible for receiving ethernet frame and store data and it's length 
               into fifo queue and generate responding signals. 

               The reason why we need this module is that there could be difference between system clock speed
               and ethernet clock speed, we need to store it into fifo queue.
******************************************************************************************************************************************************************/

module eth_rx_ctrl(
    input wire                               i_sys_clk,  // system clock
    input wire                               i_rx_clk,   // RXCLK
    input wire                               i_rstn,

    input wire                               i_rx_dv,    // RX_DV, which is valid signal for recieving data from physical layer 
    input wire[ `MII_DATA_WIDTH-1:0]         i_rx_data,  // RXD
    input wire                               i_rx_er,    // abnormal receive signal from phy
    input wire                               i_rx_col,   // COL, for collision test
    input wire                               i_rx_crs,   // CRS
    input wire                               i_mdio,
    output wire                              o_len_fifo_w_en,
    output wire[`ETH_FRAME_WIdTH-1:0]        o_frame_len,
    output reg                               o_data_fifo_w_en,
    output reg[ `MII_DATA_WIDTH-1:0]         o_frame_data,
    output reg                               o_mdio
);

    reg                          prev_rx_dv;
    reg[`ETH_FRAME_WIdTH-1:0]    frame_lenth;

    wire   rx_trans_start = ~prev_rx_dv && i_rx_dv;
    wire   rx_trans_done  = prev_rx_dv && ~i_rx_dv;

    assign o_len_fifo_w_en = rx_trans_done && (frame_lenth != 0);
    assign o_frame_len     = (o_len_fifo_w_en)? frame_lenth : 0;
    
    always @(posedge i_rx_clk or negedge i_rstn) begin
        if (~i_rstn) begin 
            prev_rx_dv        <= 0;
            o_data_fifo_w_en  <= 0;
            o_frame_data      <= 0;
            frame_lenth       <= 0;
        end 
        else if (i_rx_dv) begin
            prev_rx_dv        <= i_rx_dv;
            o_data_fifo_w_en  <= 1;
            o_frame_data      <= i_rx_data;
            frame_lenth       <= frame_lenth + 1;
        end
        else begin 
            prev_rx_dv        <= i_rx_dv;
            o_data_fifo_w_en  <= 0;
            o_frame_data      <= 0;
            frame_lenth       <= 0;
        end 
    end

    always @(posedge i_rx_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            o_mdio <= 1'b0;
        end 
        else begin 
            o_mdio <= 1'b0;
        end 
    end 


endmodule