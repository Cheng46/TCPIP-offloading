`define IP                  16'h0800
`define ARP                 16'h0806

`define IPV4                4'b0100
`define IPV6                4'b0110



`define ROUTER_MAC          48'h107C4FA2A003     // 亂設的
<<<<<<< HEAD
`define ROUTER_IP           32'hC0A80100         // 亂設的 192.168.1.0
`define FPGA_MAC            48'00183E043329     // 亂設的
`define FPGA_IP             32'hC0A80106         // 亂設的 192.168.1.6
=======
`define ROUTER_IP           32'hC0A80106         // 亂設的 192.168.1.6
`define FPGA_MAC            48'00183E043329     // 亂設的
`define FPGA_IP             32'hC0A80100         // 亂設的 192.168.1.0
>>>>>>> 51757a0 (WIP: save changes before rebase)
`define BROADCAST           48'hFFFFFFFFFFFF


`define MII_DATA_WIDTH      4
`define ETH_FRAME_WIdTH     14      // log 12144

`define DATA_FIFO_DEPTH     12144     
`define LEN_FIFO_DEPTH      24

