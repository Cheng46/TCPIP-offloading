`include "defines.v"

/******************************************************************************************************************************************************************
$Description : This module is responsible for receiving ethernet frame and store data and it's length 
               into fifo queue and generate responding signals. 

               The reason why we need this module is that there could be difference between system clock speed
               and ethernet clock speed, we need to store it into fifo queue, we cache data until it reach 8bit.
******************************************************************************************************************************************************************/

module eth_rx_ctrl(
    input wire                               i_sys_clk,  // system clock
    input wire                               i_rx_clk,   // RXCLK
    input wire                               i_rstn,

    input wire                               i_fifo_full,
    input wire                               i_rx_dv,    // RX_DV, which is valid signal for recieving data from physical layer 
    input wire[  `MII_DATA_WIDTH-1:0]        i_rx_data,  // RXD
    input wire                               i_rx_er,    // abnormal receive signal from phy
    input wire                               i_rx_col,   // COL, for collision test
    input wire                               i_rx_crs,   // CRS
    input wire                               i_mdio,
    output wire                              o_len_fifo_w_en,
    output wire[`ETH_FRAME_WIdTH-1:0]        o_frame_len,
    output reg                               o_data_fifo_w_en,
    output reg[ `FPGA_DATA_WIDTH-1:0]        o_frame_data,
    output reg                               o_mdio
);

    reg                          prev_rx_dv;
    reg[                 3:0]    frame_data;
    reg[`ETH_FRAME_WIdTH-1:0]    frame_length;
    reg                          rx_toggle;
    reg                          drop_frame;

    wire   rx_trans_start = ~prev_rx_dv && i_rx_dv;
    wire   rx_trans_done  = prev_rx_dv && ~i_rx_dv;

    assign o_len_fifo_w_en = rx_trans_done && (frame_length != 0);
    assign o_frame_len     = (o_len_fifo_w_en)? frame_length : 0;
    
    always @(posedge i_rx_clk or negedge i_rstn) begin
        if (~i_rstn) begin 
            rx_toggle         <= 1'b0;
            prev_rx_dv        <= 1'b0;
            drop_frame        <= 1'b0;
            o_data_fifo_w_en  <= 1'b0;
            o_frame_data      <= {`FPGA_DATA_WIDTH{1'b0}};
            frame_length      <= {`ETH_FRAME_WIdTH{1'b0}};
            frame_data        <= 4'b0;
        end 
        else if (i_fifo_full) begin 
            prev_rx_dv        <= i_rx_dv;
            drop_frame        <= 1'b1;
            o_data_fifo_w_en  <= 1'b0;
            o_frame_data      <= {`FPGA_DATA_WIDTH{1'b0}};
            frame_length      <= {`ETH_FRAME_WIdTH{1'b0}};
        end 
        else if ((~i_fifo_full && drop_frame && ~i_rx_dv) || (~i_fifo_full && drop_frame && rx_trans_done)) begin   // drop frame and not in tranmssion stage || drop_frame and transmmision done
            prev_rx_dv        <= i_rx_dv;
            drop_frame        <= 1'b0;
            o_data_fifo_w_en  <= 1'b0;
            o_frame_data      <= {`FPGA_DATA_WIDTH{1'b0}};
            frame_length      <= {`ETH_FRAME_WIdTH{1'b0}};
        end 
        else if (i_rx_dv && ~drop_frame) begin
            prev_rx_dv        <= i_rx_dv;
            rx_toggle         <= rx_toggle + 1'b1;
            if (rx_toggle == 1'b1) begin 
                o_data_fifo_w_en  <= 1'b1;
                o_frame_data      <= {frame_data, i_rx_data};
                frame_length      <= frame_length + 1;
                frame_data        <= 4'b0;
            end 
            else begin                                  // rx_toggle == 1'b0
                o_data_fifo_w_en  <= 1'b0;
                o_frame_data      <= {`FPGA_DATA_WIDTH{1'b0}};
                frame_data        <= i_rx_data;
            end 
        end
        else begin 
            rx_toggle         <= 1'b0;
            prev_rx_dv        <= i_rx_dv;
            o_data_fifo_w_en  <= 1'b0;
            o_frame_data      <= {`FPGA_DATA_WIDTH{1'b0}};
            frame_length      <= {`ETH_FRAME_WIdTH{1'b0}};
            frame_data        <= 4'b0;
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