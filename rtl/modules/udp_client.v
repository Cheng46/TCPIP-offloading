`include "defines.v"
/******************************************************************************************************************************************************************
$Description :  In the udp_client module, we receive datagrams from the IP layer and check whether they originate from a registered stock exchange IP and port.
                If the datagram matches, its payload is forwarded to the application layer.
                To save time and resources, we do not check the checksum in this module.
******************************************************************************************************************************************************************/

module udp_client #(
    parameter TWSE_IP     = 32'hEA006464,
    parameter TWSE_PORT   = 16'h2710,         // udp port 10000
    parameter FPGA_IP     = 32'hC0A80100,
    parameter FPGA_PORT   = 16'h5487
)(  
    input wire                          i_sys_clk,
    input wire                          i_rstn,
    input wire                          i_datagram_vld,
    input wire[`MII_DATA_WIDTH-1:0]     i_datagram,
    input wire[               31:0]     i_src_ip,
    
    output reg[                3:0]     o_app_type,
    output reg                          o_data_vld,
    output reg                          o_drop_datagram,
    output reg[`MII_DATA_WIDTH-1:0]     o_data
);
    localparam IDLE_STAGE   = 2'b00;
    localparam HEADER_STAGE = 2'b01;
    localparam TRANS_STAGE  = 2'b10;

    reg[1:0] CUR_STAGE;
    reg[1:0] NXT_STAGE;

    reg[15:0] src_port_latch;
    reg[15:0] dst_port_latch;
    reg[11:0] rx_cnt;

    wire header_check_done = ((i_src_ip == TWSE_IP) && (src_port_latch == TWSE_PORT)) || 
                             ((i_src_ip == NASDAQ_IP) && (src_port_latch == NASDAQ_PORT));

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            CUR_STAGE <= IDLE_STAGE;
        end
        else begin 
            CUR_STAGE <=  NXT_STAGE;
        end 
    end 

    always @(*) begin 
        if (~i_rstn) begin 
            NXT_STAGE = IDLE_STAGE;
        end 
        else begin 
            case (CUR_STAGE)
                IDLE_STAGE: begin 
                    if (i_datagram_vld) begin 
                        NXT_STAGE = HEADER_STAGE;
                    end
                    else begin 
                        NXT_STAGE = IDLE_STAGE; 
                    end
                end 
                HEADER_STAGE: begin
                    if (rx_cnt == 12'h00E) begin 
                        if (header_check_done) begin 
                            NXT_STAGE = TRANS_STAGE;
                        end 
                        else begin 
                            NXT_STAGE = IDLE_STAGE;     // Discard UDP datagram
                        end 
                    end
                    else begin 
                        NXT_STAGE = CUR_STAGE;
                    end 
                end
                TRANS_STAGE: begin 
                    if (~i_datagram_vld) begin 
                        NXT_STAGE = IDLE_STAGE;
                    end 
                    else begin 
                        NXT_STAGE = CUR_STAGE;
                    end
                end
                default: begin 
                    NXT_STAGE = IDLE_STAGE;
                end 
            endcase
        end 
    end 


    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || ~i_datagram_vld) begin 
            src_port_latch <= 16'b0;
            dst_port_latch <= 16'b0;
            rx_cnt         <= 12'b0;
            o_data_vld     <= 1'b0;
            o_data         <= 4'b0;
            o_drop_datagram<= 1'b0;
        end 
        else begin 
            rx_cnt <= rx_cnt + 12'b1;
            case (rx_cnt)
                12'h0, 12'h1, 12'h2, 12'h3: begin 
                    src_port_latch <= (src_port_latch << 4) | {12'b0, i_datagram};
                end 
                12'h4, 12'h5, 12'h6, 12'h7: begin 
                    dst_port_latch <= (dst_port_latch << 4) | {12'b0, i_datagram};
                end 
                default: begin 
                    if ((rx_cnt == 12'hE) && ~header_check_done) begin 
                        o_drop_datagram <= 1'b1;
                    end 
                    if ((rx_cnt > 12'hE) && header_check_done) begin 
                        o_data_vld    <= 1'b1;
                        o_data        <= i_datagram;
                    end 
                end
            endcase 
        end 
    end 

endmodule