// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTCPIP_TOP_H_
#define _VTCPIP_TOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtcpip_top__Syms;
class Vtcpip_top_VerilatedVcd;


//----------

VL_MODULE(Vtcpip_top) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_sys_clk,0,0);
    VL_IN8(i_mii_tx_clk,0,0);
    VL_IN8(i_mii_rx_clk,0,0);
    VL_IN8(i_rstn,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tcpip_top__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__i_mii_tx_clk;
        CData/*0:0*/ tcpip_top__DOT__i_mii_rx_clk;
        CData/*0:0*/ tcpip_top__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__test_phy_mii_rx_er;
        CData/*0:0*/ tcpip_top__DOT__test_phy_mii_rx_dv;
        CData/*3:0*/ tcpip_top__DOT__test_phy_mii_rx_data;
        CData/*0:0*/ tcpip_top__DOT__test_phy_mii_rx_crs;
        CData/*0:0*/ tcpip_top__DOT__test_phy_mii_rx_col;
        CData/*0:0*/ tcpip_top__DOT__test_phy_mii_mdio;
        CData/*0:0*/ tcpip_top__DOT__eth_ctrl_len_fifo_w_en;
        CData/*0:0*/ tcpip_top__DOT__eth_ctrl_data_fifo_w_en;
        CData/*3:0*/ tcpip_top__DOT__eth_ctrl_frame_data;
        CData/*0:0*/ tcpip_top__DOT__eth_ctrl_mdio;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo_data_fifo_r_done;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo_data_fifo_empty;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo_data_fifo_full;
        CData/*3:0*/ tcpip_top__DOT__eth_fifo_data_fifo_data;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo_len_fifo_r_done;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo_len_fifo_empty;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo_len_fifo_full;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_len_fifo_r_en;
        CData/*4:0*/ tcpip_top__DOT__mac_rx_len_fifo_r_line;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_data_fifo_r_en;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_data_fifo_r_stop;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_bad_packet_en;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_bad_packet;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_new_packet_en;
        CData/*3:0*/ tcpip_top__DOT__mac_rx_packet_data;
        CData/*0:0*/ tcpip_top__DOT__arp_packet;
        CData/*0:0*/ tcpip_top__DOT__ip_packet;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet_en;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_to_arp_rx_new_packet_en;
        CData/*3:0*/ tcpip_top__DOT__mac_rx_to_arp_rx_packet_data;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet_en;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet;
        CData/*0:0*/ tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en;
        CData/*3:0*/ tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
        CData/*0:0*/ tcpip_top__DOT__arp_rx_new_packet;
        CData/*0:0*/ tcpip_top__DOT__arp_rx_need_reply;
        CData/*0:0*/ tcpip_top__DOT__arp_rx_arp_rx_busy;
        CData/*0:0*/ tcpip_top__DOT__arp_tx_lookup_done;
        CData/*0:0*/ tcpip_top__DOT__arp_tx_lookup_result;
        CData/*0:0*/ tcpip_top__DOT__arp_tx_arp_packet_en;
        CData/*3:0*/ tcpip_top__DOT__arp_tx_arp_packet_data;
        CData/*0:0*/ tcpip_top__DOT__arp_tx_arp_tx_busy;
        CData/*0:0*/ tcpip_top__DOT__ip_rx_drop_packet;
        CData/*0:0*/ tcpip_top__DOT__ip_rx_ip_rx_busy;
        CData/*0:0*/ tcpip_top__DOT__ip_rx_new_segment;
        CData/*7:0*/ tcpip_top__DOT__ip_rx_segment_type;
        CData/*3:0*/ tcpip_top__DOT__ip_rx_segment_data;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__i_rx_clk;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__i_tx_clk;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__i_mii_tx_er;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__i_mii_tx_en;
        CData/*3:0*/ tcpip_top__DOT__test_phy0__DOT__i_mii_tx_data;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__i_mdc;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__i_mdio;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__o_mii_rx_er;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__o_mii_rx_dv;
        CData/*3:0*/ tcpip_top__DOT__test_phy0__DOT__o_mii_rx_data;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__o_mii_rx_crs;
    };
    struct {
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__o_mii_rx_col;
        CData/*0:0*/ tcpip_top__DOT__test_phy0__DOT__o_mii_mdio;
        CData/*2:0*/ tcpip_top__DOT__test_phy0__DOT__frame_done;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_clk;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_dv;
        CData/*3:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_data;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_er;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_col;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_crs;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__i_mdio;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__o_len_fifo_w_en;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__o_data_fifo_w_en;
        CData/*3:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__o_frame_data;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__o_mdio;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__prev_rx_dv;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_start;
        CData/*0:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_done;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_rx_clk;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_w_en;
        CData/*3:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_data;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_en;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_stop;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_w_en;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_r_en;
        CData/*4:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_r_line;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_r_done;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_empty;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_full;
        CData/*3:0*/ tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_data;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_r_done;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_empty;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_full;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_rx_clk;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_w_en;
        CData/*3:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_data;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_en;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_stop;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_r_done;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_empty;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_full;
        CData/*3:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_data;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__last_read;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_rx_clk;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_w_en;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_en;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_stop;
        CData/*4:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_len;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_r_done;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_empty;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_full;
        CData/*4:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr;
        CData/*4:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr;
        CData/*4:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_start_ptr;
        CData/*0:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__last_read;
        CData/*4:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__end_line;
        CData/*4:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_r_end_line;
    };
    struct {
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__i_len_fifo_empty;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__i_len_r_done;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__i_data_r_done;
        CData/*3:0*/ tcpip_top__DOT__mac_rx0__DOT__i_frame_data;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__i_arp_rx_busy;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__i_ip_rx_busy;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__i_ip_rx_drop;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__o_len_fifo_r_en;
        CData/*4:0*/ tcpip_top__DOT__mac_rx0__DOT__o_len_fifo_r_line;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_en;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_stop;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__o_bad_packet_en;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__o_bad_packet;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__o_new_packet_en;
        CData/*3:0*/ tcpip_top__DOT__mac_rx0__DOT__o_packet_data;
        CData/*1:0*/ tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE;
        CData/*1:0*/ tcpip_top__DOT__mac_rx0__DOT__NXT_STAGE;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__eth_parse_done;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__ip_rx_clear;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__my_frame;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__fcs_data_start;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__fcs_check;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__fcs_en;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__fcs_comp_done;
        CData/*3:0*/ tcpip_top__DOT__mac_rx0__DOT__frame_prev_latch;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt;
        CData/*7:0*/ tcpip_top__DOT__mac_rx0__DOT__fcs_data;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_rstn;
        CData/*7:0*/ tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_data;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_crc_en;
        CData/*0:0*/ tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_crc_done;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__i_new_packet;
        CData/*3:0*/ tcpip_top__DOT__arp_rx0__DOT__i_packet_data;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__i_bad_packet_en;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__i_bad_packet;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__i_arp_tx_busy;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__o_new_packet;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__o_arp_need_reply;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__o_arp_rx_busy;
        CData/*5:0*/ tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__new_packet_latch;
        CData/*1:0*/ tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE;
        CData/*1:0*/ tcpip_top__DOT__arp_rx0__DOT__NXT_STAGE;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__correct_packet;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__gather_done;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__arp_done;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__my_arp_packet;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__arp_request;
        CData/*0:0*/ tcpip_top__DOT__arp_rx0__DOT__arp_reply;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__i_lookup_en;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__i_rx_new_packet;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__i_need_reply;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__o_lookup_done;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__o_lookup_result;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__o_arp_packet_en;
        CData/*3:0*/ tcpip_top__DOT__arp_tx0__DOT__o_arp_packet_data;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__o_arp_tx_busy;
    };
    struct {
        CData/*1:0*/ tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE;
        CData/*1:0*/ tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__mac_unkwown;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache_w_en;
        CData/*5:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_send_done;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_lookup_en;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_en;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_done;
        CData/*0:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_result;
        CData/*2:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr;
        CData/*2:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__a;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__i_sys_clk;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__i_rstn;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__i_new_packet;
        CData/*3:0*/ tcpip_top__DOT__ip_rx0__DOT__i_ip_data;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__i_bad_packet_en;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__i_bad_packet;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__o_drop_packet;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__o_ip_rx_busy;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__o_new_segment;
        CData/*7:0*/ tcpip_top__DOT__ip_rx0__DOT__o_segment_type;
        CData/*3:0*/ tcpip_top__DOT__ip_rx0__DOT__o_segment_data;
        CData/*1:0*/ tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE;
        CData/*1:0*/ tcpip_top__DOT__ip_rx0__DOT__NXT_STAGE;
        CData/*3:0*/ tcpip_top__DOT__ip_rx0__DOT__ip_ver_latch;
        CData/*3:0*/ tcpip_top__DOT__ip_rx0__DOT__ihl_latch;
        CData/*2:0*/ tcpip_top__DOT__ip_rx0__DOT__flag_latch;
        CData/*7:0*/ tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
        CData/*1:0*/ tcpip_top__DOT__ip_rx0__DOT__checksum_cnt;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__packet_en_prev;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__header_done;
        CData/*0:0*/ tcpip_top__DOT__ip_rx0__DOT__check_failed;
        SData/*13:0*/ tcpip_top__DOT__eth_ctrl_frame_len;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo_len_fifo_data;
        SData/*13:0*/ tcpip_top__DOT__mac_rx_data_fifo_r_line;
        SData/*15:0*/ tcpip_top__DOT__mac_rx_eth_type;
        SData/*13:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__o_frame_len;
        SData/*13:0*/ tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_line;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_data;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_data;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_len;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_start_ptr;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__end_line;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_r_end_line;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_data;
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_data;
        SData/*13:0*/ tcpip_top__DOT__mac_rx0__DOT__i_frame_len;
        SData/*13:0*/ tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_line;
        SData/*15:0*/ tcpip_top__DOT__mac_rx0__DOT__o_eth_type;
        SData/*13:0*/ tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt;
        SData/*15:0*/ tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
        SData/*13:0*/ tcpip_top__DOT__mac_rx0__DOT__frame_len_latch;
        SData/*15:0*/ tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch;
        SData/*15:0*/ tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch;
        SData/*15:0*/ tcpip_top__DOT__arp_rx0__DOT__opcode_latch;
        SData/*12:0*/ tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch;
        SData/*15:0*/ tcpip_top__DOT__ip_rx0__DOT__checksum_latch;
        SData/*13:0*/ tcpip_top__DOT__ip_rx0__DOT__rx_cnt;
    };
    struct {
        SData/*15:0*/ tcpip_top__DOT__ip_rx0__DOT__checksum_temp;
        SData/*15:0*/ tcpip_top__DOT__ip_rx0__DOT__checksum_sum;
        IData/*31:0*/ tcpip_top__DOT__arp_rx_receive_ip;
        IData/*31:0*/ tcpip_top__DOT__test_phy0__DOT__tx_index;
        IData/*31:0*/ tcpip_top__DOT__test_phy0__DOT__rx_index;
        IData/*31:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i;
        IData/*31:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i;
        IData/*31:0*/ tcpip_top__DOT__mac_rx0__DOT__fcs_comp;
        IData/*31:0*/ tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__o_fcs;
        IData/*31:0*/ tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q;
        IData/*31:0*/ tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c;
        IData/*31:0*/ tcpip_top__DOT__arp_rx0__DOT__o_arp_receive_ip;
        IData/*31:0*/ tcpip_top__DOT__arp_rx0__DOT__src_ip_latch;
        IData/*31:0*/ tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch;
        IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__i_lookup_ip;
        IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__i_receive_ip;
        IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__src_ip_latch;
        IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch;
        IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_lookup_ip;
        IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_ip;
        IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__b;
        IData/*31:0*/ tcpip_top__DOT__ip_rx0__DOT__src_ip_latch;
        IData/*31:0*/ tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch;
        IData/*16:0*/ tcpip_top__DOT__ip_rx0__DOT__checksum_extend;
        QData/*47:0*/ tcpip_top__DOT__arp_rx_receive_mac;
        QData/*47:0*/ tcpip_top__DOT__arp_tx_lookup_mac;
        QData/*47:0*/ tcpip_top__DOT__mac_rx0__DOT__src_mac_latch;
        QData/*47:0*/ tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch;
        QData/*47:0*/ tcpip_top__DOT__arp_rx0__DOT__o_arp_receive_mac;
        QData/*47:0*/ tcpip_top__DOT__arp_rx0__DOT__src_mac_latch;
        QData/*47:0*/ tcpip_top__DOT__arp_tx0__DOT__i_receive_mac;
        QData/*47:0*/ tcpip_top__DOT__arp_tx0__DOT__o_lookup_mac;
        QData/*47:0*/ tcpip_top__DOT__arp_tx0__DOT__src_mac_latch;
        QData/*47:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_mac;
        QData/*47:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_mac;
        CData/*3:0*/ tcpip_top__DOT__test_phy0__DOT__frame0[1024];
        CData/*3:0*/ tcpip_top__DOT__test_phy0__DOT__frame1[1024];
        CData/*3:0*/ tcpip_top__DOT__test_phy0__DOT__frame2[1024];
        CData/*3:0*/ tcpip_top__DOT__test_phy0__DOT__frame3[1024];
        CData/*3:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q[12144];
        SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q[24];
        QData/*47:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue[5];
        IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue[5];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*3:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT____Vlvbound1;
    CData/*3:0*/ __Vdlyvval__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0;
    CData/*0:0*/ __Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0;
    CData/*4:0*/ __Vdlyvdim0__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0;
    CData/*0:0*/ __Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0;
    CData/*0:0*/ __Vclklast__TOP__i_mii_rx_clk;
    CData/*0:0*/ __Vclklast__TOP__i_rstn;
    CData/*0:0*/ __Vclklast__TOP__i_mii_tx_clk;
    CData/*0:0*/ __Vclklast__TOP__i_sys_clk;
    SData/*13:0*/ tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT____Vlvbound1;
    SData/*13:0*/ __Vdlyvdim0__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0;
    SData/*13:0*/ __Vdlyvval__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0;
    IData/*31:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT____Vlvbound2;
    QData/*47:0*/ tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT____Vlvbound1;
    CData/*0:0*/ __Vtablechg1[128];
    CData/*0:0*/ __Vm_traceActivity[1];
    static CData/*1:0*/ __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[128];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtcpip_top__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    enum _QDatatcpip_top__DOT__ROUTER_MAC { tcpip_top__DOT__ROUTER_MAC = 0x107c4fa2a003ULL};
    const QData var_tcpip_top__DOT__ROUTER_MAC;
    enum _IDatatcpip_top__DOT__ROUTER_IP { tcpip_top__DOT__ROUTER_IP = 0xc0a80100U};
    const IData var_tcpip_top__DOT__ROUTER_IP;
    enum _QDatatcpip_top__DOT__FPGA_MAC { tcpip_top__DOT__FPGA_MAC = 0x183e043329ULL};
    const QData var_tcpip_top__DOT__FPGA_MAC;
    enum _IDatatcpip_top__DOT__FPGA_IP { tcpip_top__DOT__FPGA_IP = 0xc0a80106U};
    const IData var_tcpip_top__DOT__FPGA_IP;
    enum _IDatatcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__DATA_WIDTH { tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__DATA_WIDTH = 4U};
    const IData var_tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__DATA_WIDTH;
    enum _IDatatcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__FIFO_DEPTH { tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__FIFO_DEPTH = 0x2f70U};
    const IData var_tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__FIFO_DEPTH;
    enum _IDatatcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__DATA_WIDTH { tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__DATA_WIDTH = 0xeU};
    const IData var_tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__DATA_WIDTH;
    enum _IDatatcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__FIFO_DEPTH { tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__FIFO_DEPTH = 0x18U};
    const IData var_tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__FIFO_DEPTH;
    enum _QDatatcpip_top__DOT__mac_rx0__DOT__ROUTER_MAC { tcpip_top__DOT__mac_rx0__DOT__ROUTER_MAC = 0x107c4fa2a003ULL};
    const QData var_tcpip_top__DOT__mac_rx0__DOT__ROUTER_MAC;
    enum _QDatatcpip_top__DOT__mac_rx0__DOT__FPGA_MAC { tcpip_top__DOT__mac_rx0__DOT__FPGA_MAC = 0x183e043329ULL};
    const QData var_tcpip_top__DOT__mac_rx0__DOT__FPGA_MAC;
    enum _IDatatcpip_top__DOT__mac_rx0__DOT__IDLE_STAGE { tcpip_top__DOT__mac_rx0__DOT__IDLE_STAGE = 0U};
    const IData var_tcpip_top__DOT__mac_rx0__DOT__IDLE_STAGE;
    enum _IDatatcpip_top__DOT__mac_rx0__DOT__LEN_STAGE { tcpip_top__DOT__mac_rx0__DOT__LEN_STAGE = 1U};
    const IData var_tcpip_top__DOT__mac_rx0__DOT__LEN_STAGE;
    enum _IDatatcpip_top__DOT__mac_rx0__DOT__PARSE_STAGE { tcpip_top__DOT__mac_rx0__DOT__PARSE_STAGE = 2U};
    const IData var_tcpip_top__DOT__mac_rx0__DOT__PARSE_STAGE;
    enum _IDatatcpip_top__DOT__mac_rx0__DOT__CHECK_STAGE { tcpip_top__DOT__mac_rx0__DOT__CHECK_STAGE = 3U};
    const IData var_tcpip_top__DOT__mac_rx0__DOT__CHECK_STAGE;
    enum _IDatatcpip_top__DOT__arp_rx0__DOT__FPGA_IP { tcpip_top__DOT__arp_rx0__DOT__FPGA_IP = 0xc0a80106U};
    const IData var_tcpip_top__DOT__arp_rx0__DOT__FPGA_IP;
    enum _QDatatcpip_top__DOT__arp_rx0__DOT__FPGA_MAC { tcpip_top__DOT__arp_rx0__DOT__FPGA_MAC = 0x183e043329ULL};
    const QData var_tcpip_top__DOT__arp_rx0__DOT__FPGA_MAC;
    enum _IDatatcpip_top__DOT__arp_rx0__DOT__IDLE_STAGE { tcpip_top__DOT__arp_rx0__DOT__IDLE_STAGE = 0U};
    const IData var_tcpip_top__DOT__arp_rx0__DOT__IDLE_STAGE;
    enum _IDatatcpip_top__DOT__arp_rx0__DOT__GATHER_STAGE { tcpip_top__DOT__arp_rx0__DOT__GATHER_STAGE = 1U};
    const IData var_tcpip_top__DOT__arp_rx0__DOT__GATHER_STAGE;
    enum _IDatatcpip_top__DOT__arp_rx0__DOT__TRANS_STAGE { tcpip_top__DOT__arp_rx0__DOT__TRANS_STAGE = 2U};
    const IData var_tcpip_top__DOT__arp_rx0__DOT__TRANS_STAGE;
    enum _IDatatcpip_top__DOT__arp_tx0__DOT__FPGA_IP { tcpip_top__DOT__arp_tx0__DOT__FPGA_IP = 0xc0a80100U};
    const IData var_tcpip_top__DOT__arp_tx0__DOT__FPGA_IP;
    enum _QDatatcpip_top__DOT__arp_tx0__DOT__FPGA_MAC { tcpip_top__DOT__arp_tx0__DOT__FPGA_MAC = 0x183e043329ULL};
    const QData var_tcpip_top__DOT__arp_tx0__DOT__FPGA_MAC;
    enum _IDatatcpip_top__DOT__arp_tx0__DOT__ROUTER_IP { tcpip_top__DOT__arp_tx0__DOT__ROUTER_IP = 0xc0a80106U};
    const IData var_tcpip_top__DOT__arp_tx0__DOT__ROUTER_IP;
    enum _QDatatcpip_top__DOT__arp_tx0__DOT__ROUTER_MAC { tcpip_top__DOT__arp_tx0__DOT__ROUTER_MAC = 0x107c4fa2a003ULL};
    const QData var_tcpip_top__DOT__arp_tx0__DOT__ROUTER_MAC;
    enum _IDatatcpip_top__DOT__arp_tx0__DOT__IDLE_STAGE { tcpip_top__DOT__arp_tx0__DOT__IDLE_STAGE = 0U};
    const IData var_tcpip_top__DOT__arp_tx0__DOT__IDLE_STAGE;
    enum _IDatatcpip_top__DOT__arp_tx0__DOT__LOOKUP_STAGE { tcpip_top__DOT__arp_tx0__DOT__LOOKUP_STAGE = 1U};
    const IData var_tcpip_top__DOT__arp_tx0__DOT__LOOKUP_STAGE;
    enum _IDatatcpip_top__DOT__arp_tx0__DOT__SEND_STAGE { tcpip_top__DOT__arp_tx0__DOT__SEND_STAGE = 2U};
    const IData var_tcpip_top__DOT__arp_tx0__DOT__SEND_STAGE;
    enum _IDatatcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ENTRY_DEPTH { tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ENTRY_DEPTH = 5U};
    const IData var_tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ENTRY_DEPTH;
    enum _IDatatcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ROUTER_IP { tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ROUTER_IP = 0xc0a80106U};
    const IData var_tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ROUTER_IP;
    enum _QDatatcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ROUTER_MAC { tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ROUTER_MAC = 0x107c4fa2a003ULL};
    const QData var_tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ROUTER_MAC;
    enum _IDatatcpip_top__DOT__ip_rx0__DOT__FPGA_IP { tcpip_top__DOT__ip_rx0__DOT__FPGA_IP = 0xc0a80100U};
    const IData var_tcpip_top__DOT__ip_rx0__DOT__FPGA_IP;
    enum _IDatatcpip_top__DOT__ip_rx0__DOT__TYPE_TCP { tcpip_top__DOT__ip_rx0__DOT__TYPE_TCP = 6U};
    const IData var_tcpip_top__DOT__ip_rx0__DOT__TYPE_TCP;
    enum _IDatatcpip_top__DOT__ip_rx0__DOT__TYPE_UDP { tcpip_top__DOT__ip_rx0__DOT__TYPE_UDP = 0x11U};
    const IData var_tcpip_top__DOT__ip_rx0__DOT__TYPE_UDP;
    enum _IDatatcpip_top__DOT__ip_rx0__DOT__TYPE_ICMP { tcpip_top__DOT__ip_rx0__DOT__TYPE_ICMP = 1U};
    const IData var_tcpip_top__DOT__ip_rx0__DOT__TYPE_ICMP;
    enum _IDatatcpip_top__DOT__ip_rx0__DOT__IDLE_STAGE { tcpip_top__DOT__ip_rx0__DOT__IDLE_STAGE = 0U};
    const IData var_tcpip_top__DOT__ip_rx0__DOT__IDLE_STAGE;
    enum _IDatatcpip_top__DOT__ip_rx0__DOT__HEADER_STAGE { tcpip_top__DOT__ip_rx0__DOT__HEADER_STAGE = 1U};
    const IData var_tcpip_top__DOT__ip_rx0__DOT__HEADER_STAGE;
    enum _IDatatcpip_top__DOT__ip_rx0__DOT__TRANS_STAGE { tcpip_top__DOT__ip_rx0__DOT__TRANS_STAGE = 2U};
    const IData var_tcpip_top__DOT__ip_rx0__DOT__TRANS_STAGE;
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtcpip_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtcpip_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtcpip_top();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtcpip_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtcpip_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtcpip_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtcpip_top__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vtcpip_top__Syms* __restrict vlSymsp);
    static void _combo__TOP__9(Vtcpip_top__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtcpip_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtcpip_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtcpip_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtcpip_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__8(Vtcpip_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtcpip_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtcpip_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtcpip_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtcpip_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtcpip_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
