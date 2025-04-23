`include "defines.v"

/******************************************************************************************************************************************************************
$Description :  This module is responsible for communication with physical layer.

                -------------                        -------------
                |           | <------ TX_CLK ------- |           |
                |           | ------- TX_ER -------> |           |
                |           | ------- TX_EN -------> |           |
                |           | ----- TXD[3:0] ------> |           |
                |           | <------ RX_CLK ------- |           |
                |           | <------ RX_ER -------- |           |
                |  MAC Side | <------ RX_DV -------- |  PHY Side |
                |           | <----- RXD[3:0] ------ |           |
                |           | <------ CRS ---------- |           |
                |           | <------ COL ---------- |           |
                |           | ------- MDC ---------> |           |
                |           | <------- MDIO -------> |           |
                -------------                        -------------
******************************************************************************************************************************************************************/

module tcpip_top (
    input wire                               i_sys_clk,
    input wire                               i_mii_tx_clk,
    input wire                               i_mii_rx_clk,
    input wire                               i_rstn

    // input wire                               i_mii_rx_er,      // abnormal receive signal from phy
    // input wire                               i_mii_rx_dv,
    // input wire[`MII_DATA_WIDTH-1:0]          i_mii_rx_data,
    // input wire                               i_mii_rx_crs,     // CRS
    // input wire                               i_mii_rx_col,     // COL, for collision test
    // input wire                               i_mii_mdio,       // MDIO

    // output reg                               o_mii_tx_er,
    // output reg                               o_mii_tx_en,
    // output reg[`MII_DATA_WIDTH-1:0]          o_mii_tx_data,
    // output reg                               o_mdc,
    // output reg                               o_mdio      
);

    wire                      test_phy_mii_rx_er;                                    // abnormal receive signal from phy
    wire                      test_phy_mii_rx_dv;
    wire[`MII_DATA_WIDTH-1:0] test_phy_mii_rx_data;
    wire                      test_phy_mii_rx_crs;                                   // CRS
    wire                      test_phy_mii_rx_col;                                   // COL, for collision test
    wire                      test_phy_mii_mdio;                                     // MDIO

    test_phy test_phy0(
    .i_rx_clk               (        i_mii_rx_clk),
    .i_tx_clk               (        i_mii_tx_clk),  
    .i_rstn                 (              i_rstn),
    .i_mii_tx_er            (                1'b0),
    .i_mii_tx_en            (                1'b0),
    .i_mii_tx_data          (                4'b0),
    .i_mdc                  (                1'b0),
    .i_mdio                 (                1'b0),      
    .o_mii_rx_er            (  test_phy_mii_rx_er),             // abnormal receive signal from phy
    .o_mii_rx_dv            (  test_phy_mii_rx_dv),
    .o_mii_rx_data          (test_phy_mii_rx_data),
    .o_mii_rx_crs           ( test_phy_mii_rx_crs),             // CRS
    .o_mii_rx_col           ( test_phy_mii_rx_col),             // COL, for collision test
    .o_mii_mdio             (   test_phy_mii_mdio)              // MDIO
    );


    wire                        eth_ctrl_len_fifo_w_en;
    wire[`ETH_FRAME_WIdTH-1:0]  eth_ctrl_frame_len;
    wire                        eth_ctrl_data_fifo_w_en;
    wire[`FPGA_DATA_WIDTH-1:0]  eth_ctrl_frame_data;
    wire                        eth_ctrl_mdio;

    eth_rx_ctrl eth_rx_ctrl0(
        .i_sys_clk                  (              i_sys_clk),          // system clock
        .i_rx_clk                   (           i_mii_rx_clk),          // RXCLK
        .i_rstn                     (                 i_rstn),
        .i_fifo_full                ( eth_fifo_len_fifo_full),
        .i_rx_dv                    (     test_phy_mii_rx_dv),          //(            i_mii_rx_dv),          // RX_DV, which is valid signal for recieving data from physical layer 
        .i_rx_data                  (   test_phy_mii_rx_data),          //(          i_mii_rx_data),          // RXD
        .i_rx_er                    (     test_phy_mii_rx_er),          //(            i_mii_rx_er),          // abnormal receive signal from phy
        .i_rx_col                   (    test_phy_mii_rx_col),          //(           i_mii_rx_col),          // COL, for collision test
        .i_rx_crs                   (    test_phy_mii_rx_crs),          //(           i_mii_rx_crs),          // CRS
        .i_mdio                     (      test_phy_mii_mdio),          //(             i_mii_mdio),
        .o_len_fifo_w_en            ( eth_ctrl_len_fifo_w_en),
        .o_frame_len                (     eth_ctrl_frame_len),
        .o_data_fifo_w_en           (eth_ctrl_data_fifo_w_en),
        .o_frame_data               (    eth_ctrl_frame_data),
        .o_mdio                     (          eth_ctrl_mdio)
    );


wire                          eth_fifo_data_fifo_r_done;
wire                          eth_fifo_data_fifo_empty;     
wire                          eth_fifo_data_fifo_full;    
wire[ `FPGA_DATA_WIDTH-1:0]   eth_fifo_data_fifo_data;      
wire                          eth_fifo_len_fifo_r_done;
wire                          eth_fifo_len_fifo_empty;     
wire                          eth_fifo_len_fifo_full;    
wire[`ETH_FRAME_WIdTH-1:0]    eth_fifo_len_fifo_data;      

    eth_fifo eth_fifo0(
            .i_rx_clk               (             i_mii_rx_clk),
            .i_sys_clk              (                i_sys_clk),          //for read data from the queue
            .i_rstn                 (                   i_rstn),
            .i_data_fifo_w_en       (  eth_ctrl_data_fifo_w_en),
            .i_data_fifo_data       (      eth_ctrl_frame_data),
            .i_data_fifo_r_en       (    mac_rx_data_fifo_r_en),
            .i_data_fifo_r_stop     (  mac_rx_data_fifo_r_stop),
            .i_data_fifo_r_line     (  mac_rx_data_fifo_r_line),
            .i_len_fifo_w_en        (   eth_ctrl_len_fifo_w_en),
            .i_len_fifo_data        (       eth_ctrl_frame_len),           
            .i_len_fifo_r_en        (     mac_rx_len_fifo_r_en),
            .i_len_fifo_r_line      (   mac_rx_len_fifo_r_line),
            .o_data_fifo_r_done     (eth_fifo_data_fifo_r_done),
            .o_data_fifo_empty      ( eth_fifo_data_fifo_empty),     
            .o_data_fifo_full       (  eth_fifo_data_fifo_full),    
            .o_data_fifo_data       (  eth_fifo_data_fifo_data),      
            .o_len_fifo_r_done      ( eth_fifo_len_fifo_r_done),
            .o_len_fifo_empty       (  eth_fifo_len_fifo_empty),     
            .o_len_fifo_full        (   eth_fifo_len_fifo_full),    
            .o_len_fifo_data        (   eth_fifo_len_fifo_data)      
    );

    wire                                 mac_rx_len_fifo_r_en;
    wire[$clog2(`LEN_FIFO_DEPTH)-1:0]    mac_rx_len_fifo_r_line;

    wire                                 mac_rx_data_fifo_r_en;
    wire[$clog2(`DATA_FIFO_DEPTH)-1:0]   mac_rx_data_fifo_r_line;

    wire[                        15:0]   mac_rx_eth_type;  
    wire                                 mac_rx_bad_frame_en;
    wire                                 mac_rx_bad_frame;
    wire                                 mac_rx_new_frame_en;
    wire[       `FPGA_DATA_WIDTH-1:0]    mac_rx_frame_data;
    wire                                 mac_rx_data_fifo_r_stop;

    wire                                 arp_frame  = (mac_rx_eth_type == 16'h0806);
    wire                                 ip_frame   = (mac_rx_eth_type == 16'h0800);

    wire                                 mac_rx_to_arp_rx_bad_frame_en  = arp_frame? mac_rx_bad_frame_en : 1'b0;
    wire                                 mac_rx_to_arp_rx_bad_frame     = arp_frame? mac_rx_bad_frame : 1'b0;
    wire                                 mac_rx_to_arp_rx_new_frame_en  = arp_frame? mac_rx_new_frame_en : 1'b0;
    wire[       `FPGA_DATA_WIDTH-1:0]    mac_rx_to_arp_rx_frame_data    = arp_frame? mac_rx_frame_data : 8'b0;

    wire                                 mac_rx_to_ip_rx_bad_frame_en   = ip_frame? mac_rx_bad_frame_en : 1'b0;
    wire                                 mac_rx_to_ip_rx_bad_frame      = ip_frame? mac_rx_bad_frame : 1'b0;
    wire                                 mac_rx_to_ip_rx_new_frame_en   = ip_frame? mac_rx_new_frame_en : 1'b0;
    wire[       `FPGA_DATA_WIDTH-1:0]    mac_rx_to_ip_rx_frame_data     = ip_frame? mac_rx_frame_data : 8'b0;

    mac_rx mac_rx0 (
        .i_sys_clk                  (                i_sys_clk),
        .i_rstn                     (                   i_rstn),
        .i_len_fifo_empty           (  eth_fifo_len_fifo_empty),
        .i_len_r_done               ( eth_fifo_len_fifo_r_done),
        .i_data_r_done              (eth_fifo_data_fifo_r_done),
        .i_frame_len                (   eth_fifo_len_fifo_data),
        .i_frame_data               (  eth_fifo_data_fifo_data), 
        .i_arp_rx_busy              (       arp_rx_arp_rx_busy),
        .i_ip_rx_busy               (         ip_rx_ip_rx_busy),
        .i_ip_rx_drop               (         ip_rx_drop_frame),
        //.i_payload_len            (),    // from ip parser
        .o_len_fifo_r_en            (     mac_rx_len_fifo_r_en),
        .o_len_fifo_r_line          (   mac_rx_len_fifo_r_line),

        .o_data_fifo_r_en           (    mac_rx_data_fifo_r_en),
        .o_data_fifo_r_line         (  mac_rx_data_fifo_r_line),
        .o_data_fifo_r_stop         (  mac_rx_data_fifo_r_stop),
        .o_eth_type                 (          mac_rx_eth_type),   // 0 -> ip / 1-> arp 
        .o_bad_packet_en            (      mac_rx_bad_frame_en),
        .o_bad_packet               (         mac_rx_bad_frame),
        .o_new_packet_en            (      mac_rx_new_frame_en),
        .o_packet_data              (        mac_rx_frame_data)
    );


    // mac_tx  eth_mac_tx0(

    // );


    wire        arp_rx_new_frame;    
    wire        arp_rx_need_reply;
    wire[31:0]  arp_rx_receive_ip;
    wire[47:0]  arp_rx_receive_mac;
    wire        arp_rx_arp_rx_busy;

    arp_rx  arp_rx0(
        .i_sys_clk                  (                    i_sys_clk),
        .i_rstn                     (                       i_rstn),
        .i_new_packet               (mac_rx_to_arp_rx_new_frame_en),
        .i_packet_data              (  mac_rx_to_arp_rx_frame_data),
        .i_bad_packet_en            (mac_rx_to_arp_rx_bad_frame_en),
        .i_bad_packet               (   mac_rx_to_arp_rx_bad_frame),
        .i_arp_tx_busy              (           arp_tx_arp_tx_busy),
        .o_new_packet               (             arp_rx_new_frame),
        .o_arp_need_reply           (            arp_rx_need_reply),
        .o_arp_receive_ip           (            arp_rx_receive_ip),
        .o_arp_receive_mac          (           arp_rx_receive_mac),
        .o_arp_rx_busy              (           arp_rx_arp_rx_busy)
    );

    wire                        arp_tx_lookup_done;
    wire                        arp_tx_lookup_result;
    wire[               47:0]   arp_tx_lookup_mac;
    wire                        arp_tx_arp_frame_en;
    wire[`MII_DATA_WIDTH-1:0]   arp_tx_arp_frame_data;
    wire                        arp_tx_arp_tx_busy;

    arp_tx #(
        .FPGA_IP                    (             `FPGA_IP),
        .FPGA_MAC                   (            `FPGA_MAC)
    )arp_tx0 (
        .i_sys_clk                  (            i_sys_clk),
        .i_rstn                     (               i_rstn),
        .i_lookup_en                (1'b0),
        .i_lookup_ip                (32'h0),
        .i_rx_new_packet            (     arp_rx_new_frame),
        .i_need_reply               (    arp_rx_need_reply),
        .i_receive_ip               (    arp_rx_receive_ip),      
        .i_receive_mac              (   arp_rx_receive_mac),
        .o_lookup_done              (   arp_tx_lookup_done),
        .o_lookup_result            ( arp_tx_lookup_result),            // success = 1, failed = 0
        .o_lookup_mac               (    arp_tx_lookup_mac),
        .o_arp_packet_en            (  arp_tx_arp_frame_en),
        .o_arp_packet_data          (arp_tx_arp_frame_data),
        .o_arp_tx_busy              (   arp_tx_arp_tx_busy) 

    );


    wire                      ip_rx_drop_frame;
    wire                      ip_rx_ip_rx_busy;
    wire                      ip_rx_new_frame;
    wire[                7:0] ip_rx_frame_type;                                                  // protocol_type_latch, 8'h01 => icmp, 8'h06 => tcp, 8'h11 => udp
    wire[`FPGA_DATA_WIDTH-1:0]ip_rx_frame_data;   
    wire[               31:0] ip_rx_tcp_rx_src_ip;
    wire[               15:0] ip_rx_tcp_rx_segment_len_b;
    wire                      ip_rx_drop_segment;

    wire                      is_udp_datagram           = ip_rx_frame_type == 8'h11;
    wire                      ip_rx_udp_rx_datagram_vld = is_udp_datagram? ip_rx_new_frame  : 1'b0;
    wire[`FPGA_DATA_WIDTH-1:0]ip_rx_udp_rx_datagram     = is_udp_datagram? ip_rx_frame_data : 8'b0;
    wire[               31:0] ip_rx_udp_rx_src_ip       = is_udp_datagram? ip_rx_tcp_rx_src_ip : 32'b0;
    wire                      ip_rx_udp_rx_drop_datagram= is_udp_datagram? ip_rx_drop_segment : 1'b0;

    ip_rx  ip_rx0(
        .i_sys_clk                  (                   i_sys_clk),
        .i_rstn                     (                      i_rstn),
        .i_new_packet               (mac_rx_to_ip_rx_new_frame_en),
        .i_ip_data                  (  mac_rx_to_ip_rx_frame_data), 
        .i_bad_packet_en            (mac_rx_to_ip_rx_bad_frame_en),
        .i_bad_packet               (   mac_rx_to_ip_rx_bad_frame),
        .i_tcp_drop                 (1'b0),
        .i_udp_drop                 (  udp_rx_ip_rx_drop_datagram),
        .o_drop_packet              (            ip_rx_drop_frame),
        .o_drop_segment             (          ip_rx_drop_segment),
        .o_ip_rx_busy               (            ip_rx_ip_rx_busy),          
        .o_new_segment              (             ip_rx_new_frame),
        .o_segment_type             (            ip_rx_frame_type),         // protocol_type_latch, 8'h01 => icmp, 8'h06 => tcp, 8'h11 => udp
        .o_segment_data             (            ip_rx_frame_data),
        .o_src_ip                   (         ip_rx_tcp_rx_src_ip),
        .o_segment_len_b            (  ip_rx_tcp_rx_segment_len_b)
    );

    // ip_tx   ip_tx0(

    // );

    wire                       udp_rx_fix_data_vld;
    wire                       udp_rx_ip_rx_drop_datagram;
    wire[`FPGA_DATA_WIDTH-1:0] udp_rx_fix_data;

    udp_rx  udp_rx0(
        .i_sys_clk                  (                 i_sys_clk),
        .i_rstn                     (                   i_rstn),
        .i_datagram_vld             ( ip_rx_udp_rx_datagram_vld),
        .i_datagram                 (     ip_rx_udp_rx_datagram),
        .i_drop_datagram            (ip_rx_udp_rx_drop_datagram),
        .i_src_ip                   (       ip_rx_udp_rx_src_ip),
        .o_data_vld                 (       udp_rx_fix_data_vld),
        .o_drop_datagram            (udp_rx_ip_rx_drop_datagram),
        .o_data                     (           udp_rx_fix_data)
    );


endmodule
