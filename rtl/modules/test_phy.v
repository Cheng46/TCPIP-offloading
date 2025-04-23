`include "defines.v"

module test_phy(
    input wire                               i_rx_clk,
    input wire                               i_tx_clk,
    input wire                               i_rstn,

    // MII TX (MAC → PHY)
    input wire                               i_mii_tx_er,
    input wire                               i_mii_tx_en,
    input wire [`MII_DATA_WIDTH-1:0]         i_mii_tx_data,

    // MII MDIO
    input wire                               i_mdc,
    input wire                               i_mdio,      

    // MII RX (PHY → MAC)
    output reg                               o_mii_rx_er,
    output reg                               o_mii_rx_dv,
    output reg [`MII_DATA_WIDTH-1:0]         o_mii_rx_data,
    output reg                               o_mii_rx_crs,
    output reg                               o_mii_rx_col,
    output reg                               o_mii_mdio
);

    (* verilator public_flat_rw *) reg[3:0]    frame0  [1023:0];
    (* verilator public_flat_rw *) reg[3:0]    frame1  [1023:0];


    initial begin
        $readmemh("frame_data0.hex", frame0);
        $readmemh("frame_data1.hex", frame1);
    end

    integer tx_index = 0;
    integer rx_index = 0;

    reg[2:0] frame_done;


    // RX: PHY → MAC, 從 frame0 發送資料
    always @(posedge i_rx_clk or negedge i_rstn) begin
        if (~i_rstn) begin
            o_mii_rx_er   <= 1'b0;
            o_mii_rx_dv   <= 1'b0;
            o_mii_rx_data <= 4'b0;
            rx_index      <= 0;
            frame_done    <= 0;
        end 
        else if (frame_done < 3'b010) begin
            if (frame_done == 3'b000) begin
                if(rx_index == 32'h00000084) begin 
                    o_mii_rx_dv   <= 1'b0;
                    o_mii_rx_data <= frame0[rx_index];
                    rx_index      <= 0;
                    frame_done    <= frame_done + 1;
                end
                else begin 
                    o_mii_rx_dv   <= 1'b1;
                    o_mii_rx_data <= frame0[rx_index];
                    rx_index      <= rx_index + 1;
                end 
            end 
            else if (frame_done == 3'b001) begin
                if (rx_index == 32'h0000006C) begin 
                    o_mii_rx_dv   <= 1'b0;
                    o_mii_rx_data <= 0;
                    rx_index      <= 0;
                    frame_done    <= frame_done + 1;
                end 
                else begin 
                    o_mii_rx_dv   <= 1'b1;
                    o_mii_rx_data <= frame1[rx_index];
                    rx_index      <= rx_index + 1;
                end
            end 
        end
        else begin
            o_mii_rx_dv   <= 1'b0;
        end
    end

    // 模擬 CRS / COL
    always @(posedge i_tx_clk) begin
        o_mii_rx_crs <= i_mii_tx_en;  // TX 活動時產生 CRS
        if (i_mii_tx_en && o_mii_rx_dv) begin
            o_mii_rx_col <= 1'b1;  // TX 和 RX 同時進行 → 碰撞
        end else begin
            o_mii_rx_col <= 1'b0;
        end
    end

endmodule