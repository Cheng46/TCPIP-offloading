`include "defines.v"

module ip_tx #(
    parameter FPGA_IP   =  32'hC0A80106
)(
    input wire  i_sys_clk,
    input wire  i_rstn,

    input wire                          i_datagram_valid,
    input wire[`MII_DATA_WIDTH-1:0]     i_datagram,
    input wire[               31:0]     i_dst_ip,

    output reg                          o_lookup_valid,
    output reg[               31:0]     o_lookup_ip,

    output reg                          o_packet_en,
    output reg[`MII_DATA_WIDTH-1:0]     o_packet
);

endmodule