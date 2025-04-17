// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtcpip_top.h for the primary calling header

#include "Vtcpip_top.h"
#include "Vtcpip_top__Syms.h"

//==========
CData/*1:0*/ Vtcpip_top::__Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[128];

VL_CTOR_IMP(Vtcpip_top), var_tcpip_top__DOT__ROUTER_MAC (0x107c4fa2a003ULL), 
  var_tcpip_top__DOT__ROUTER_IP (0xc0a80100U), var_tcpip_top__DOT__FPGA_MAC (0x183e043329ULL), 
  var_tcpip_top__DOT__FPGA_IP (0xc0a80106U), var_tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__DATA_WIDTH (4U), 
  var_tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__FIFO_DEPTH (0x2f70U), 
  var_tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__DATA_WIDTH (0xeU), 
  var_tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__FIFO_DEPTH (0x18U), 
  var_tcpip_top__DOT__mac_rx0__DOT__ROUTER_MAC (0x107c4fa2a003ULL), 
  var_tcpip_top__DOT__mac_rx0__DOT__FPGA_MAC (0x183e043329ULL), 
  var_tcpip_top__DOT__mac_rx0__DOT__IDLE_STAGE (0U), 
  var_tcpip_top__DOT__mac_rx0__DOT__LEN_STAGE (1U), 
  var_tcpip_top__DOT__mac_rx0__DOT__PARSE_STAGE (2U), 
  var_tcpip_top__DOT__mac_rx0__DOT__CHECK_STAGE (3U), 
  var_tcpip_top__DOT__arp_rx0__DOT__FPGA_IP (0xc0a80106U), 
  var_tcpip_top__DOT__arp_rx0__DOT__FPGA_MAC (0x183e043329ULL), 
  var_tcpip_top__DOT__arp_rx0__DOT__IDLE_STAGE (0U), 
  var_tcpip_top__DOT__arp_rx0__DOT__GATHER_STAGE (1U), 
  var_tcpip_top__DOT__arp_rx0__DOT__TRANS_STAGE (2U), 
  var_tcpip_top__DOT__arp_tx0__DOT__FPGA_IP (0xc0a80100U), 
  var_tcpip_top__DOT__arp_tx0__DOT__FPGA_MAC (0x183e043329ULL), 
  var_tcpip_top__DOT__arp_tx0__DOT__ROUTER_IP (0xc0a80106U), 
  var_tcpip_top__DOT__arp_tx0__DOT__ROUTER_MAC (0x107c4fa2a003ULL), 
  var_tcpip_top__DOT__arp_tx0__DOT__IDLE_STAGE (0U), 
  var_tcpip_top__DOT__arp_tx0__DOT__LOOKUP_STAGE (1U), 
  var_tcpip_top__DOT__arp_tx0__DOT__SEND_STAGE (2U), 
  var_tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ENTRY_DEPTH (5U), 
  var_tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ROUTER_IP (0xc0a80106U), 
  var_tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__ROUTER_MAC (0x107c4fa2a003ULL), 
  var_tcpip_top__DOT__ip_rx0__DOT__FPGA_IP (0xc0a80100U), 
  var_tcpip_top__DOT__ip_rx0__DOT__TYPE_TCP (6U), var_tcpip_top__DOT__ip_rx0__DOT__TYPE_UDP (0x11U), 
  var_tcpip_top__DOT__ip_rx0__DOT__TYPE_ICMP (1U), 
  var_tcpip_top__DOT__ip_rx0__DOT__IDLE_STAGE (0U), 
  var_tcpip_top__DOT__ip_rx0__DOT__HEADER_STAGE (1U), 
  var_tcpip_top__DOT__ip_rx0__DOT__TRANS_STAGE (2U) {
    Vtcpip_top__Syms* __restrict vlSymsp = __VlSymsp = new Vtcpip_top__Syms(this, name());
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtcpip_top::__Vconfigure(Vtcpip_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtcpip_top::~Vtcpip_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtcpip_top::_initial__TOP__1(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_initial__TOP__1\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp1[4];
    WData/*127:0*/ __Vtemp2[4];
    WData/*127:0*/ __Vtemp3[4];
    WData/*127:0*/ __Vtemp4[4];
    // Body
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__tx_index = 0U;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__i_mii_tx_er = 0U;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__i_mii_tx_en = 0U;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__i_mii_tx_data = 0U;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__i_mdc = 0U;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__i_mdio = 0U;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_stop = 0U;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_lookup_en = 0U;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_lookup_ip = 0U;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index = 0U;
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x61746130U;
    __Vtemp1[2U] = 0x6d655f64U;
    __Vtemp1[3U] = 0x667261U;
    VL_READMEM_N(true, 4, 1024, 0, VL_CVT_PACK_STR_NW(4, __Vtemp1)
                 , vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame0
                 , 0, ~0ULL);
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x61746131U;
    __Vtemp2[2U] = 0x6d655f64U;
    __Vtemp2[3U] = 0x667261U;
    VL_READMEM_N(true, 4, 1024, 0, VL_CVT_PACK_STR_NW(4, __Vtemp2)
                 , vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame1
                 , 0, ~0ULL);
    __Vtemp3[0U] = 0x2e686578U;
    __Vtemp3[1U] = 0x61746132U;
    __Vtemp3[2U] = 0x6d655f64U;
    __Vtemp3[3U] = 0x667261U;
    VL_READMEM_N(true, 4, 1024, 0, VL_CVT_PACK_STR_NW(4, __Vtemp3)
                 , vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame2
                 , 0, ~0ULL);
    __Vtemp4[0U] = 0x2e686578U;
    __Vtemp4[1U] = 0x61746133U;
    __Vtemp4[2U] = 0x6d655f64U;
    __Vtemp4[3U] = 0x667261U;
    VL_READMEM_N(true, 4, 1024, 0, VL_CVT_PACK_STR_NW(4, __Vtemp4)
                 , vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame3
                 , 0, ~0ULL);
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_lookup_en 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_lookup_en;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_lookup_ip 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_lookup_ip;
}

void Vtcpip_top::_settle__TOP__2(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_settle__TOP__2\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_mdio 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_mdio;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_mdio 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_mdio;
    vlTOPp->tcpip_top__DOT__arp_tx_lookup_mac = 0ULL;
    vlTOPp->tcpip_top__DOT__i_mii_tx_clk = vlTOPp->i_mii_tx_clk;
    vlTOPp->tcpip_top__DOT__i_mii_rx_clk = vlTOPp->i_mii_rx_clk;
    vlTOPp->tcpip_top__DOT__i_sys_clk = vlTOPp->i_sys_clk;
    vlTOPp->tcpip_top__DOT__i_rstn = vlTOPp->i_rstn;
    vlTOPp->tcpip_top__DOT__arp_tx_lookup_done = 0U;
    vlTOPp->tcpip_top__DOT__arp_tx_lookup_result = 0U;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_er 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_er;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_crs 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_crs;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_col 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_col;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_er 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_er;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_col 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_col;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_crs 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_crs;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_mdio 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_mdio;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_len_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_r_done;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_arp_rx_busy 
        = vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_eth_type 
        = vlTOPp->tcpip_top__DOT__mac_rx_eth_type;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_bad_packet_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_bad_packet_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_bad_packet 
        = vlTOPp->tcpip_top__DOT__mac_rx_bad_packet;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_new_packet_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_packet_data 
        = vlTOPp->tcpip_top__DOT__mac_rx_packet_data;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_arp_rx_busy 
        = vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_arp_packet_en 
        = vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_en;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_arp_packet_data 
        = vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_new_segment 
        = vlTOPp->tcpip_top__DOT__ip_rx_new_segment;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_segment_type 
        = vlTOPp->tcpip_top__DOT__ip_rx_segment_type;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_segment_data 
        = vlTOPp->tcpip_top__DOT__ip_rx_segment_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_r_done;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__my_arp_packet 
        = (((1U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch)) 
            & (0x800U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch))) 
           & (0xc0a80106U == vlTOPp->tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch));
    vlTOPp->tcpip_top__DOT__ip_packet = (0x800U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx_eth_type));
    vlTOPp->tcpip_top__DOT__arp_packet = (0x806U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx_eth_type));
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed 
        = ((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
           & (0xffffU != (0xffffU & (vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_extend 
                                     + (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_latch)))));
    vlTOPp->tcpip_top__DOT__ip_rx_ip_rx_busy = (0U 
                                                != (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE));
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_data_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_data_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_frame_data 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_data;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_data_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_frame_len 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_frame_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_new_packet 
        = vlTOPp->tcpip_top__DOT__arp_rx_new_packet;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_rx_new_packet 
        = vlTOPp->tcpip_top__DOT__arp_rx_new_packet;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame 
        = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
           & ((0x183e043329ULL == vlTOPp->tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch) 
              | (0xffffffffffffULL == vlTOPp->tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch)));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_data_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_data 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_empty 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr));
    vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_full 
        = (VL_MODDIV_III(32, ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr)), (IData)(0x2f70U)) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr));
    vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_full 
        = (VL_MODDIV_III(32, ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr)), (IData)(0x18U)) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr));
    vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr));
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_dv 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_data 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_dv 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_data 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_arp_need_reply 
        = vlTOPp->tcpip_top__DOT__arp_rx_need_reply;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_arp_receive_ip 
        = vlTOPp->tcpip_top__DOT__arp_rx_receive_ip;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_arp_receive_mac 
        = vlTOPp->tcpip_top__DOT__arp_rx_receive_mac;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_need_reply 
        = vlTOPp->tcpip_top__DOT__arp_rx_need_reply;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_start 
        = ((~ (IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__prev_rx_dv)) 
           & (IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv));
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_receive_ip 
        = vlTOPp->tcpip_top__DOT__arp_rx_receive_ip;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_receive_mac 
        = vlTOPp->tcpip_top__DOT__arp_rx_receive_mac;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache_w_en 
        = ((IData)(vlTOPp->tcpip_top__DOT__arp_rx_new_packet) 
           & ((0xc0a80106U != vlTOPp->tcpip_top__DOT__arp_rx_receive_ip) 
              | (0x107c4fa2a003ULL != vlTOPp->tcpip_top__DOT__arp_rx_receive_mac)));
    vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy = (0U 
                                                  != (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE));
    vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_en = 
        ((IData)(vlTOPp->i_rstn) & ((2U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))
                                     ? ((~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)) 
                                        & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done)))
                                     : (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_check 
        = (3U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE));
    if (vlTOPp->i_rstn) {
        if ((2U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((1U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
                vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line = 0U;
            } else {
                if (vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done) {
                    vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line = 0U;
                }
            }
        } else {
            vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line 
                = ((1U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))
                    ? (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data)
                    : 0U);
        }
    } else {
        vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line = 0U;
    }
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_start 
        = ((2U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)) 
           & (0xfU < (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt)));
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_done 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__prev_rx_dv) 
           & (~ (IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv)));
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_lookup_en 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_lookup_en;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_lookup_ip 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_lookup_ip;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_mac 
        = vlTOPp->tcpip_top__DOT__arp_tx_lookup_mac;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_mac 
        = vlTOPp->tcpip_top__DOT__arp_tx_lookup_mac;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__i_tx_clk 
        = vlTOPp->tcpip_top__DOT__i_mii_tx_clk;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__i_rx_clk 
        = vlTOPp->tcpip_top__DOT__i_mii_rx_clk;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_clk 
        = vlTOPp->tcpip_top__DOT__i_mii_rx_clk;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_rx_clk 
        = vlTOPp->tcpip_top__DOT__i_mii_rx_clk;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__i_rstn 
        = vlTOPp->tcpip_top__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rstn 
        = vlTOPp->tcpip_top__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__i_rstn = vlTOPp->tcpip_top__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__i_rstn = vlTOPp->tcpip_top__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_rstn = vlTOPp->tcpip_top__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_rstn = vlTOPp->tcpip_top__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_rstn 
        = vlTOPp->tcpip_top__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_done 
        = vlTOPp->tcpip_top__DOT__arp_tx_lookup_done;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_done 
        = vlTOPp->tcpip_top__DOT__arp_tx_lookup_done;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_result 
        = vlTOPp->tcpip_top__DOT__arp_tx_lookup_result;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_result 
        = vlTOPp->tcpip_top__DOT__arp_tx_lookup_result;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_r_done;
    if (vlTOPp->tcpip_top__DOT__ip_packet) {
        vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data 
            = vlTOPp->tcpip_top__DOT__mac_rx_packet_data;
        vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet_en 
            = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_bad_packet_en) 
               & 1U);
        vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet 
            = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_bad_packet) 
               & 1U);
        vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en 
            = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en) 
               & 1U);
    } else {
        vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data = 0U;
        vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet_en = 0U;
        vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet = 0U;
        vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en = 0U;
    }
    vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_new_packet_en 
        = ((IData)(vlTOPp->tcpip_top__DOT__arp_packet) 
           & (IData)(vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en));
    if (vlTOPp->tcpip_top__DOT__arp_packet) {
        vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data 
            = vlTOPp->tcpip_top__DOT__mac_rx_packet_data;
        vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet_en 
            = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_bad_packet_en) 
               & 1U);
        vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet 
            = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_bad_packet) 
               & 1U);
    } else {
        vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data = 0U;
        vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet_en = 0U;
        vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet = 0U;
    }
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__header_done 
        = ((0x27U == (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
           & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)));
    vlTOPp->tcpip_top__DOT__ip_rx_drop_packet = ((0x27U 
                                                  < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                                 & (((((((4U 
                                                          != (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__ip_ver_latch)) 
                                                         | (5U 
                                                            != (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__ihl_latch))) 
                                                        | (2U 
                                                           != (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__flag_latch))) 
                                                       | (1U 
                                                          == (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch))) 
                                                      | (0U 
                                                         != (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch))) 
                                                     | (0xc0a80100U 
                                                        != vlTOPp->tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch)) 
                                                    | (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_ip_rx_busy 
        = vlTOPp->tcpip_top__DOT__ip_rx_ip_rx_busy;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_ip_rx_busy 
        = vlTOPp->tcpip_top__DOT__ip_rx_ip_rx_busy;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__ip_rx_clear 
        = (1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy) 
                    | (IData)(vlTOPp->tcpip_top__DOT__ip_rx_ip_rx_busy))));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_r_done;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_full 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_full;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_full 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_full;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_len_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_ip 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_receive_ip;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_mac 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_receive_mac;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_en 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache_w_en;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__i_arp_tx_busy 
        = vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_arp_tx_busy 
        = vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_crc_done 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_check;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_comp 
        = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_check)
            ? vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q
            : 0U);
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_line 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_line 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__end_line 
        = (0x3fffU & (((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_start_ptr) 
                       + (IData)(vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line)) 
                      - (IData)(1U)));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_en = 
        ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt) 
         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_start));
    vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_done) 
           & (0U != (IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth)));
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_mac 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_mac;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_mac 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_mac;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_rx_clk 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_rx_clk;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_rx_clk 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_rx_clk;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_sys_clk 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_sys_clk;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_rstn 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_rstn 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_rstn 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_rstn 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_rstn;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_done 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_done;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_done 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_done;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_result 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_result;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_result 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_lookup_result;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__i_ip_data 
        = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__i_bad_packet_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet_en;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__i_bad_packet 
        = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__i_new_packet 
        = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__i_new_packet 
        = vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_new_packet_en;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__i_packet_data 
        = vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__i_bad_packet_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet_en;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__i_bad_packet 
        = vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__correct_packet 
        = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet_en) 
           & (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet)));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_ip_rx_drop 
        = vlTOPp->tcpip_top__DOT__ip_rx_drop_packet;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_drop_packet 
        = vlTOPp->tcpip_top__DOT__ip_rx_drop_packet;
    if ((1U & (~ (IData)(vlTOPp->i_rstn)))) {
        vlTOPp->tcpip_top__DOT__ip_rx0__DOT__NXT_STAGE = 0U;
    }
    if ((0U == (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE))) {
        if (vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en) {
            vlTOPp->tcpip_top__DOT__ip_rx0__DOT__NXT_STAGE = 1U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE))) {
            if (vlTOPp->tcpip_top__DOT__ip_rx_drop_packet) {
                vlTOPp->tcpip_top__DOT__ip_rx0__DOT__NXT_STAGE = 0U;
            } else {
                if (vlTOPp->tcpip_top__DOT__ip_rx0__DOT__header_done) {
                    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__NXT_STAGE = 2U;
                }
            }
        } else {
            vlTOPp->tcpip_top__DOT__ip_rx0__DOT__NXT_STAGE 
                = ((2U == (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE))
                    ? ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet_en) 
                         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet)) 
                        | ((IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__packet_en_prev) 
                           & (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en))))
                        ? 0U : (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE))
                    : 0U);
        }
    }
    if (vlTOPp->i_rstn) {
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__NXT_STAGE 
            = ((2U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))
                ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))
                    ? 0U : ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done)
                             ? 3U : ((IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)
                                      ? 0U : (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))))
                : ((1U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))
                    ? 2U : (((~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty)) 
                             & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__ip_rx_clear))
                             ? 1U : (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))));
    }
    vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_en = 
        ((IData)(vlTOPp->i_rstn) & ((~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE) 
                                        >> 1U)) & (
                                                   (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)) 
                                                   & ((~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty)) 
                                                      & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__ip_rx_clear)))));
    if (vlTOPp->i_rstn) {
        if ((2U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)))) {
                if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done)))) {
                    if (vlTOPp->tcpip_top__DOT__ip_rx_drop_packet) {
                        vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_stop = 1U;
                    }
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)))) {
                if (((~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty)) 
                     & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__ip_rx_clear))) {
                    vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_stop = 0U;
                }
            }
        }
    } else {
        vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_stop = 0U;
    }
    if (vlTOPp->i_rstn) {
        if ((2U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((1U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
                vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line = 0U;
            } else {
                if (vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done) {
                    vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line = 0U;
                } else {
                    if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                        vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line = 0U;
                    }
                }
            }
        } else {
            vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line 
                = ((1U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))
                    ? 0U : (((~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty)) 
                             & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__ip_rx_clear))
                             ? 1U : 0U));
        }
    } else {
        vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line = 0U;
    }
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_full 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_full;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_full 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_full;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__o_fcs 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_comp;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_len 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_line;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_r_end_line 
        = (0x3fffU & ((((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__end_line) 
                        >= (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_start_ptr)) 
                       & (0x2f70U > (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__end_line)))
                       ? (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__end_line)
                       : (((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_start_ptr) 
                           - (IData)(1U)) - ((IData)(0x2f70U) 
                                             - (IData)(vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line)))));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_crc_en 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data 
        = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_en)
            ? ((0x80U & ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data) 
                         << 7U)) | ((0x40U & ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data) 
                                              << 5U)) 
                                    | ((0x20U & ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data) 
                                                 << 3U)) 
                                       | ((0x10U & 
                                           ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data) 
                                            << 1U)) 
                                          | ((8U & 
                                              ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_prev_latch) 
                                               << 3U)) 
                                             | ((4U 
                                                 & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_prev_latch) 
                                                    << 1U)) 
                                                | ((2U 
                                                    & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_prev_latch) 
                                                       >> 1U)) 
                                                   | (1U 
                                                      & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_prev_latch) 
                                                         >> 3U)))))))))
            : 0U);
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_len_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_ctrl_frame_len = ((IData)(vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en)
                                                   ? 
                                                  (0x3fffU 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth))
                                                   : 0U);
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__gather_done 
        = ((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__new_packet_latch) 
           & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__correct_packet));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_len_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_stop 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_stop;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_stop 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_stop;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_len_fifo_r_line 
        = vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_r_line 
        = vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__end_line 
        = (0x1fU & (((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_start_ptr) 
                     + (IData)(vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line)) 
                    - (IData)(1U)));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__last_read 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_r_end_line));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_data 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data;
    if (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_en) {
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffffffeU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (1U & ((((vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                           >> 0x18U) ^ (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                        >> 0x1eU)) 
                         ^ (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data)) 
                        ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                           >> 6U))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffffffdU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (2U & ((((((((0x1feU & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                         >> 0x17U)) 
                              ^ (0xfeU & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          >> 0x18U))) 
                             ^ (6U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                      >> 0x1dU))) ^ 
                            (2U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                   >> 0x1eU))) ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 1U)) 
                          ^ (0xfffffffeU & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data))) 
                         ^ (0x7fffffeU & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                          >> 5U))) 
                        ^ (0x3fffffeU & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                         >> 6U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffffffbU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (4U & ((((((((((0x3fcU & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           >> 0x16U)) 
                                ^ (0x1fcU & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             >> 0x17U))) 
                               ^ (0xfcU & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           >> 0x18U))) 
                              ^ (0xcU & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                         >> 0x1cU))) 
                             ^ (4U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                      >> 0x1dU))) ^ 
                            ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                             << 2U)) ^ (0xfffffffcU 
                                        & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                           << 1U))) 
                          ^ (0xfffffffcU & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data))) 
                         ^ (0xffffffcU & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                          >> 4U))) 
                        ^ (0x7fffffcU & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                         >> 5U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffffff7U & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (8U & ((((((((0x3f8U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                         >> 0x16U)) 
                              ^ (0x1f8U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           >> 0x17U))) 
                             ^ (0xf8U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                         >> 0x18U))) 
                            ^ (8U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                     >> 0x1cU))) ^ 
                           (0xfffffff8U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                           << 2U))) 
                          ^ (0xfffffff8U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                            << 1U))) 
                         ^ (0xfffffff8U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data))) 
                        ^ (0xffffff8U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                         >> 4U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffffffefU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x10U & ((((((((((0xff0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                              >> 0x14U)) 
                                   ^ (0x3f0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0x16U))) 
                                  ^ (0x1f0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x17U))) 
                                 ^ (0xf0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             >> 0x18U))) 
                                ^ (0x30U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                            >> 0x1aU))) 
                               ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                  << 4U)) ^ (0xfffffff0U 
                                             & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 2U))) 
                             ^ (0xfffffff0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 1U))) 
                            ^ (0xfffffff0U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data))) 
                           ^ (0x3ffffff0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                             >> 2U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffffffdfU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x20U & ((((((((((((((0x1fe0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 0x13U)) 
                                       ^ (0xfe0U & 
                                          (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           >> 0x14U))) 
                                      ^ (0x3e0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 0x16U))) 
                                     ^ (0x1e0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  >> 0x17U))) 
                                    ^ (0xe0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0x18U))) 
                                   ^ (0x60U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x19U))) 
                                  ^ (0x20U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                              >> 0x1aU))) 
                                 ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                    << 5U)) ^ (0xffffffe0U 
                                               & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 4U))) 
                               ^ (0xffffffe0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 2U))) 
                              ^ (0xffffffe0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 1U))) 
                             ^ (0xffffffe0U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data))) 
                            ^ (0x7fffffe0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                              >> 1U))) 
                           ^ (0x3fffffe0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                             >> 2U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffffffbfU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x40U & ((((((((((((0x1fc0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0x13U)) 
                                     ^ (0xfc0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  >> 0x14U))) 
                                    ^ (0x3c0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0x16U))) 
                                   ^ (0x1c0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0x17U))) 
                                  ^ (0xc0U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                              >> 0x18U))) 
                                 ^ (0x40U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             >> 0x19U))) 
                                ^ (0xffffffc0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 5U))) 
                               ^ (0xffffffc0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 4U))) 
                              ^ (0xffffffc0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 2U))) 
                             ^ (0xffffffc0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 1U))) 
                            ^ (0xffffffc0U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data))) 
                           ^ (0x7fffffc0U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                             >> 1U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffffff7fU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x80U & ((((((((((0x7f80U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x11U)) 
                                   ^ (0x1f80U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0x13U))) 
                                  ^ (0xf80U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x14U))) 
                                 ^ (0x380U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                              >> 0x16U))) 
                                ^ (0x80U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                            >> 0x18U))) 
                               ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                  << 7U)) ^ (0xffffff80U 
                                             & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 5U))) 
                             ^ (0xffffff80U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 4U))) 
                            ^ (0xffffff80U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                              << 2U))) 
                           ^ (0xffffff80U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffffeffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x100U & (((((((((vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                    << 8U) ^ (0xff00U 
                                              & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0x10U))) 
                                  ^ (0x7f00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0x11U))) 
                                 ^ (0x1f00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x13U))) 
                                ^ (0xf00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             >> 0x14U))) 
                               ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                  << 8U)) ^ (0xffffff00U 
                                             & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 7U))) 
                             ^ (0xffffff00U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 5U))) 
                            ^ (0xffffff00U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                              << 4U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffffdffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x200U & (((((((((0xfffffe00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   << 8U)) 
                                   ^ (0xfe00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0x10U))) 
                                  ^ (0x7e00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0x11U))) 
                                 ^ (0x1e00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x13U))) 
                                ^ (0xe00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             >> 0x14U))) 
                               ^ (0xfffffe00U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 8U))) 
                              ^ (0xfffffe00U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 7U))) 
                             ^ (0xfffffe00U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 5U))) 
                            ^ (0xfffffe00U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                              << 4U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffffbffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x400U & (((((((((0xfffffc00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   << 8U)) 
                                   ^ (0x3fc00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  >> 0xeU))) 
                                  ^ (0xfc00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0x10U))) 
                                 ^ (0x7c00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x11U))) 
                                ^ (0x1c00U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                              >> 0x13U))) 
                               ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                  << 0xaU)) ^ (0xfffffc00U 
                                               & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 8U))) 
                             ^ (0xfffffc00U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 7U))) 
                            ^ (0xfffffc00U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                              << 5U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffff7ffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x800U & (((((((((0xfffff800U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   << 8U)) 
                                   ^ (0x7f800U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  >> 0xdU))) 
                                  ^ (0x3f800U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0xeU))) 
                                 ^ (0xf800U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x10U))) 
                                ^ (0x7800U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                              >> 0x11U))) 
                               ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                  << 0xbU)) ^ (0xfffff800U 
                                               & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0xaU))) 
                             ^ (0xfffff800U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 8U))) 
                            ^ (0xfffff800U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                              << 7U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffffefffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x1000U & (((((((((((((0xfffff000U 
                                         & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                            << 8U)) 
                                        ^ (0xff000U 
                                           & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                              >> 0xcU))) 
                                       ^ (0x7f000U 
                                          & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             >> 0xdU))) 
                                      ^ (0x3f000U & 
                                         (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          >> 0xeU))) 
                                     ^ (0xf000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 0x10U))) 
                                    ^ (0x7000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  >> 0x11U))) 
                                   ^ (0x3000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0x12U))) 
                                  ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                     << 0xcU)) ^ (0xfffff000U 
                                                  & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                     << 0xbU))) 
                                ^ (0xfffff000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0xaU))) 
                               ^ (0xfffff000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 8U))) 
                              ^ (0xfffff000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 7U))) 
                             ^ (0xfffff000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 6U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffffdfffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x2000U & (((((((((((((0xffffe000U 
                                         & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                            << 8U)) 
                                        ^ (0xfe000U 
                                           & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                              >> 0xcU))) 
                                       ^ (0x7e000U 
                                          & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             >> 0xdU))) 
                                      ^ (0x3e000U & 
                                         (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          >> 0xeU))) 
                                     ^ (0xe000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 0x10U))) 
                                    ^ (0x6000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  >> 0x11U))) 
                                   ^ (0x2000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0x12U))) 
                                  ^ (0xffffe000U & 
                                     ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                      << 0xcU))) ^ 
                                 (0xffffe000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0xbU))) 
                                ^ (0xffffe000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0xaU))) 
                               ^ (0xffffe000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 8U))) 
                              ^ (0xffffe000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 7U))) 
                             ^ (0xffffe000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 6U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffffbfffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x4000U & (((((((((((0xffffc000U 
                                       & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          << 8U)) ^ 
                                      (0xfc000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 0xcU))) 
                                     ^ (0x7c000U & 
                                        (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                         >> 0xdU))) 
                                    ^ (0x3c000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 0xeU))) 
                                   ^ (0xc000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0x10U))) 
                                  ^ (0x4000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0x11U))) 
                                 ^ (0xffffc000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                   << 0xcU))) 
                                ^ (0xffffc000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0xbU))) 
                               ^ (0xffffc000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0xaU))) 
                              ^ (0xffffc000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 8U))) 
                             ^ (0xffffc000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 7U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffff7fffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x8000U & (((((((((0xffff8000U & 
                                     (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                      << 8U)) ^ (0xf8000U 
                                                 & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                    >> 0xcU))) 
                                   ^ (0x78000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  >> 0xdU))) 
                                  ^ (0x38000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0xeU))) 
                                 ^ (0x8000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0x10U))) 
                                ^ (0xffff8000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0xcU))) 
                               ^ (0xffff8000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0xbU))) 
                              ^ (0xffff8000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 0xaU))) 
                             ^ (0xffff8000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                               << 8U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffeffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x10000U & (((((((0xffff0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   << 8U)) 
                                   ^ (0xff0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 8U))) 
                                  ^ (0xf0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0xcU))) 
                                 ^ (0x70000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0xdU))) 
                                ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                   << 0x10U)) ^ (0xffff0000U 
                                                 & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                    << 0xcU))) 
                              ^ (0xffff0000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 0xbU)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffdffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x20000U & (((((((0xfffe0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   << 8U)) 
                                   ^ (0xfe0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 8U))) 
                                  ^ (0xe0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0xcU))) 
                                 ^ (0x60000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0xdU))) 
                                ^ (0xfffe0000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0x10U))) 
                               ^ (0xfffe0000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0xcU))) 
                              ^ (0xfffe0000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 0xbU)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfffbffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x40000U & (((((((0xfffc0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   << 8U)) 
                                   ^ (0xfc0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   >> 8U))) 
                                  ^ (0xc0000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 0xcU))) 
                                 ^ (0x40000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 0xdU))) 
                                ^ (0xfffc0000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0x10U))) 
                               ^ (0xfffc0000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0xcU))) 
                              ^ (0xfffc0000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 0xbU)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfff7ffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x80000U & (((((0xfff80000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 << 8U)) 
                                 ^ (0xf80000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                 >> 8U))) 
                                ^ (0x80000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                               >> 0xcU))) 
                               ^ (0xfff80000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0x10U))) 
                              ^ (0xfff80000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                << 0xcU)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffefffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x100000U & (((0xfff00000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                << 8U)) 
                                ^ (0xf00000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 8U))) 
                               ^ (0xfff00000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0x10U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffdfffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x200000U & (((0xffe00000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                << 8U)) 
                                ^ (0xe00000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                >> 8U))) 
                               ^ (0xffe00000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0x10U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xffbfffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x400000U & (((0xffc00000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                << 8U)) 
                                ^ (0x3fc00000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  >> 2U))) 
                               ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                  << 0x16U))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xff7fffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x800000U & (((((((0xff800000U & 
                                     (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                      << 8U)) ^ (0x7f800000U 
                                                 & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                    >> 1U))) 
                                   ^ (0x3f800000U & 
                                      (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                       >> 2U))) ^ (0x1800000U 
                                                   & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                      >> 7U))) 
                                 ^ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                    << 0x17U)) ^ (0xff800000U 
                                                  & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                     << 0x16U))) 
                               ^ (0xff800000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0x11U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfeffffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x1000000U & (((((((0xff000000U & 
                                      (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                       << 8U)) ^ (0x7f000000U 
                                                  & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                     >> 1U))) 
                                    ^ (0x3f000000U 
                                       & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          >> 2U))) 
                                   ^ (0x1000000U & 
                                      (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                       >> 7U))) ^ (0xff000000U 
                                                   & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                      << 0x17U))) 
                                 ^ (0xff000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                   << 0x16U))) 
                                ^ (0xff000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0x11U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfdffffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x2000000U & (((((0xfe000000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                   << 8U)) 
                                   ^ (0x7e000000U & 
                                      (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                       >> 1U))) ^ (0x3e000000U 
                                                   & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                      >> 2U))) 
                                 ^ (0xfe000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                   << 0x17U))) 
                                ^ (0xfe000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0x16U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xfbffffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x4000000U & (((((((((0xfc000000U 
                                        & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           << 8U)) 
                                       ^ (0xfc000000U 
                                          & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             << 2U))) 
                                      ^ (0x7c000000U 
                                         & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                            >> 1U))) 
                                     ^ (0x3c000000U 
                                        & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           >> 2U))) 
                                    ^ (0xc000000U & 
                                       (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                        >> 4U))) ^ 
                                   ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                    << 0x1aU)) ^ (0xfc000000U 
                                                  & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                     << 0x17U))) 
                                 ^ (0xfc000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                   << 0x16U))) 
                                ^ (0xfc000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0x14U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xf7ffffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x8000000U & (((((((((0xf8000000U 
                                        & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           << 8U)) 
                                       ^ (0xf8000000U 
                                          & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                             << 2U))) 
                                      ^ (0x78000000U 
                                         & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                            >> 1U))) 
                                     ^ (0x38000000U 
                                        & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           >> 2U))) 
                                    ^ (0x8000000U & 
                                       (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                        >> 4U))) ^ 
                                   (0xf8000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                   << 0x1aU))) 
                                  ^ (0xf8000000U & 
                                     ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                      << 0x17U))) ^ 
                                 (0xf8000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0x16U))) 
                                ^ (0xf8000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                  << 0x14U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xefffffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x10000000U & (((((((0xf0000000U 
                                       & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          << 8U)) ^ 
                                      (0xf0000000U 
                                       & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          << 2U))) 
                                     ^ (0x70000000U 
                                        & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           >> 1U))) 
                                    ^ (0x30000000U 
                                       & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          >> 2U))) 
                                   ^ (0xf0000000U & 
                                      ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                       << 0x1aU))) 
                                  ^ (0xf0000000U & 
                                     ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                      << 0x17U))) ^ 
                                 (0xf0000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0x16U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xdfffffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x20000000U & (((((((0xe0000000U 
                                       & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          << 8U)) ^ 
                                      (0xe0000000U 
                                       & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          << 2U))) 
                                     ^ (0x60000000U 
                                        & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                           >> 1U))) 
                                    ^ (0x20000000U 
                                       & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                          >> 2U))) 
                                   ^ (0xe0000000U & 
                                      ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                       << 0x1aU))) 
                                  ^ (0xe0000000U & 
                                     ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                      << 0x17U))) ^ 
                                 (0xe0000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                 << 0x16U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0xbfffffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x40000000U & (((((0xc0000000U & 
                                     (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                      << 8U)) ^ (0xc0000000U 
                                                 & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                    << 2U))) 
                                   ^ (0x40000000U & 
                                      (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                       >> 1U))) ^ (0xc0000000U 
                                                   & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                      << 0x1aU))) 
                                 ^ (0xc0000000U & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                   << 0x17U)))));
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c 
            = ((0x7fffffffU & vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c) 
               | (0x80000000U & (((0x80000000U & (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                                  << 8U)) 
                                  ^ (0x80000000U & 
                                     (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
                                      << 2U))) ^ (0x80000000U 
                                                  & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data) 
                                                     << 0x1aU)))));
    }
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_frame_len 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_len;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_data 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_len;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_request 
        = ((((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__gather_done) 
             & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__my_arp_packet)) 
            & (1U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__opcode_latch))) 
           & (~ (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_done)));
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_reply 
        = ((((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__gather_done) 
             & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__my_arp_packet)) 
            & (2U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__opcode_latch))) 
           & (~ (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_done)));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_r_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_stop 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_stop;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_len 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_r_line;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_r_end_line 
        = (0x1fU & ((((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__end_line) 
                      >= (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_start_ptr)) 
                     & (0x18U > (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__end_line)))
                     ? (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__end_line)
                     : (((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_start_ptr) 
                         - (IData)(1U)) - ((IData)(0x18U) 
                                           - (IData)(vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_line)))));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__last_read 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_r_end_line));
}

void Vtcpip_top::_eval_initial(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_eval_initial\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__i_mii_rx_clk = vlTOPp->i_mii_rx_clk;
    vlTOPp->__Vclklast__TOP__i_rstn = vlTOPp->i_rstn;
    vlTOPp->__Vclklast__TOP__i_mii_tx_clk = vlTOPp->i_mii_tx_clk;
    vlTOPp->__Vclklast__TOP__i_sys_clk = vlTOPp->i_sys_clk;
}

void Vtcpip_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::final\n"); );
    // Variables
    Vtcpip_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtcpip_top::_eval_settle(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_eval_settle\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtcpip_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_ctor_var_reset\n"); );
    // Body
    i_sys_clk = VL_RAND_RESET_I(1);
    i_mii_tx_clk = VL_RAND_RESET_I(1);
    i_mii_rx_clk = VL_RAND_RESET_I(1);
    i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__i_mii_tx_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__i_mii_rx_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy_mii_rx_er = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy_mii_rx_dv = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy_mii_rx_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__test_phy_mii_rx_crs = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy_mii_rx_col = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy_mii_mdio = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_ctrl_len_fifo_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_ctrl_frame_len = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_ctrl_data_fifo_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_ctrl_frame_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__eth_ctrl_mdio = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo_data_fifo_r_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo_data_fifo_empty = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo_data_fifo_full = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo_data_fifo_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__eth_fifo_len_fifo_r_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo_len_fifo_empty = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo_len_fifo_full = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo_len_fifo_data = VL_RAND_RESET_I(14);
    tcpip_top__DOT__mac_rx_len_fifo_r_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_len_fifo_r_line = VL_RAND_RESET_I(5);
    tcpip_top__DOT__mac_rx_data_fifo_r_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_data_fifo_r_stop = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_data_fifo_r_line = VL_RAND_RESET_I(14);
    tcpip_top__DOT__mac_rx_eth_type = VL_RAND_RESET_I(16);
    tcpip_top__DOT__mac_rx_bad_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_bad_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_new_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_packet_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__arp_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_to_arp_rx_new_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_to_arp_rx_packet_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_to_ip_rx_bad_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx_to_ip_rx_packet_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__arp_rx_new_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx_need_reply = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx_receive_ip = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_rx_receive_mac = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_rx_arp_rx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx_lookup_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx_lookup_result = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx_lookup_mac = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_tx_arp_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx_arp_packet_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__arp_tx_arp_tx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx_drop_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx_ip_rx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx_new_segment = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx_segment_type = VL_RAND_RESET_I(8);
    tcpip_top__DOT__ip_rx_segment_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__test_phy0__DOT__i_rx_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__i_tx_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__i_mii_tx_er = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__i_mii_tx_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__i_mii_tx_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__test_phy0__DOT__i_mdc = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__i_mdio = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__o_mii_rx_er = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__o_mii_rx_dv = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__o_mii_rx_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__test_phy0__DOT__o_mii_rx_crs = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__o_mii_rx_col = VL_RAND_RESET_I(1);
    tcpip_top__DOT__test_phy0__DOT__o_mii_mdio = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            tcpip_top__DOT__test_phy0__DOT__frame0[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            tcpip_top__DOT__test_phy0__DOT__frame1[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            tcpip_top__DOT__test_phy0__DOT__frame2[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            tcpip_top__DOT__test_phy0__DOT__frame3[__Vi0] = VL_RAND_RESET_I(4);
    }}
    tcpip_top__DOT__test_phy0__DOT__tx_index = VL_RAND_RESET_I(32);
    tcpip_top__DOT__test_phy0__DOT__rx_index = VL_RAND_RESET_I(32);
    tcpip_top__DOT__test_phy0__DOT__frame_done = VL_RAND_RESET_I(3);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_dv = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_er = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_col = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_crs = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__i_mdio = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__o_len_fifo_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__o_frame_len = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__o_data_fifo_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__o_frame_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__o_mdio = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__prev_rx_dv = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_start = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_rx_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_stop = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_line = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_data = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_r_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_r_line = VL_RAND_RESET_I(5);
    tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_r_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_empty = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_full = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_r_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_empty = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_full = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_data = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_rx_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_stop = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_len = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_r_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_empty = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_full = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_data = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<12144; ++__Vi0) {
            tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q[__Vi0] = VL_RAND_RESET_I(4);
    }}
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_start_ptr = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__last_read = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i = VL_RAND_RESET_I(32);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__end_line = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_r_end_line = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT____Vlvbound1 = VL_RAND_RESET_I(4);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_rx_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_data = VL_RAND_RESET_I(14);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_stop = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_r_len = VL_RAND_RESET_I(5);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_r_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_empty = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_full = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_data = VL_RAND_RESET_I(14);
    { int __Vi0=0; for (; __Vi0<24; ++__Vi0) {
            tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q[__Vi0] = VL_RAND_RESET_I(14);
    }}
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr = VL_RAND_RESET_I(5);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr = VL_RAND_RESET_I(5);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_start_ptr = VL_RAND_RESET_I(5);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__last_read = VL_RAND_RESET_I(1);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i = VL_RAND_RESET_I(32);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__end_line = VL_RAND_RESET_I(5);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_r_end_line = VL_RAND_RESET_I(5);
    tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT____Vlvbound1 = VL_RAND_RESET_I(14);
    tcpip_top__DOT__mac_rx0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__i_len_fifo_empty = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__i_len_r_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__i_data_r_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__i_frame_len = VL_RAND_RESET_I(14);
    tcpip_top__DOT__mac_rx0__DOT__i_frame_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__mac_rx0__DOT__i_arp_rx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__i_ip_rx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__i_ip_rx_drop = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__o_len_fifo_r_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__o_len_fifo_r_line = VL_RAND_RESET_I(5);
    tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_line = VL_RAND_RESET_I(14);
    tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_stop = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__o_eth_type = VL_RAND_RESET_I(16);
    tcpip_top__DOT__mac_rx0__DOT__o_bad_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__o_bad_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__o_new_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__o_packet_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE = VL_RAND_RESET_I(2);
    tcpip_top__DOT__mac_rx0__DOT__NXT_STAGE = VL_RAND_RESET_I(2);
    tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt = VL_RAND_RESET_I(14);
    tcpip_top__DOT__mac_rx0__DOT__src_mac_latch = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__mac_rx0__DOT__eth_type_latch = VL_RAND_RESET_I(16);
    tcpip_top__DOT__mac_rx0__DOT__eth_parse_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__frame_len_latch = VL_RAND_RESET_I(14);
    tcpip_top__DOT__mac_rx0__DOT__ip_rx_clear = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__my_frame = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__fcs_data_start = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__fcs_check = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__fcs_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__fcs_comp_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__fcs_comp = VL_RAND_RESET_I(32);
    tcpip_top__DOT__mac_rx0__DOT__frame_prev_latch = VL_RAND_RESET_I(4);
    tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__fcs_data = VL_RAND_RESET_I(8);
    tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_data = VL_RAND_RESET_I(8);
    tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_crc_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_crc_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__o_fcs = VL_RAND_RESET_I(32);
    tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q = VL_RAND_RESET_I(32);
    tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_rx0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__i_new_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__i_packet_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__arp_rx0__DOT__i_bad_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__i_bad_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__i_arp_tx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__o_new_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__o_arp_need_reply = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__o_arp_receive_ip = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_rx0__DOT__o_arp_receive_mac = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_rx0__DOT__o_arp_rx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch = VL_RAND_RESET_I(16);
    tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch = VL_RAND_RESET_I(16);
    tcpip_top__DOT__arp_rx0__DOT__opcode_latch = VL_RAND_RESET_I(16);
    tcpip_top__DOT__arp_rx0__DOT__src_mac_latch = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_rx0__DOT__src_ip_latch = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt = VL_RAND_RESET_I(6);
    tcpip_top__DOT__arp_rx0__DOT__new_packet_latch = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE = VL_RAND_RESET_I(2);
    tcpip_top__DOT__arp_rx0__DOT__NXT_STAGE = VL_RAND_RESET_I(2);
    tcpip_top__DOT__arp_rx0__DOT__correct_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__gather_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__arp_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__my_arp_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__arp_request = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_rx0__DOT__arp_reply = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__i_lookup_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__i_lookup_ip = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_tx0__DOT__i_rx_new_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__i_need_reply = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__i_receive_ip = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_tx0__DOT__i_receive_mac = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_tx0__DOT__o_lookup_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__o_lookup_result = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__o_lookup_mac = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_tx0__DOT__o_arp_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__o_arp_packet_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__arp_tx0__DOT__o_arp_tx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE = VL_RAND_RESET_I(2);
    tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE = VL_RAND_RESET_I(2);
    tcpip_top__DOT__arp_tx0__DOT__src_mac_latch = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_tx0__DOT__src_ip_latch = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_tx0__DOT__mac_unkwown = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt = VL_RAND_RESET_I(6);
    tcpip_top__DOT__arp_tx0__DOT__arp_send_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_lookup_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_lookup_ip = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_ip = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_mac = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_result = VL_RAND_RESET_I(1);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__o_lookup_mac = VL_RAND_RESET_Q(48);
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue[__Vi0] = VL_RAND_RESET_Q(48);
    }}
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue[__Vi0] = VL_RAND_RESET_I(32);
    }}
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr = VL_RAND_RESET_I(3);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__a = VL_RAND_RESET_I(3);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__b = VL_RAND_RESET_I(32);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT____Vlvbound1 = VL_RAND_RESET_Q(48);
    tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT____Vlvbound2 = VL_RAND_RESET_I(32);
    tcpip_top__DOT__ip_rx0__DOT__i_sys_clk = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__i_rstn = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__i_new_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__i_ip_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__ip_rx0__DOT__i_bad_packet_en = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__i_bad_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__o_drop_packet = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__o_ip_rx_busy = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__o_new_segment = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__o_segment_type = VL_RAND_RESET_I(8);
    tcpip_top__DOT__ip_rx0__DOT__o_segment_data = VL_RAND_RESET_I(4);
    tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE = VL_RAND_RESET_I(2);
    tcpip_top__DOT__ip_rx0__DOT__NXT_STAGE = VL_RAND_RESET_I(2);
    tcpip_top__DOT__ip_rx0__DOT__ip_ver_latch = VL_RAND_RESET_I(4);
    tcpip_top__DOT__ip_rx0__DOT__ihl_latch = VL_RAND_RESET_I(4);
    tcpip_top__DOT__ip_rx0__DOT__flag_latch = VL_RAND_RESET_I(3);
    tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch = VL_RAND_RESET_I(13);
    tcpip_top__DOT__ip_rx0__DOT__protocol_latch = VL_RAND_RESET_I(8);
    tcpip_top__DOT__ip_rx0__DOT__checksum_latch = VL_RAND_RESET_I(16);
    tcpip_top__DOT__ip_rx0__DOT__src_ip_latch = VL_RAND_RESET_I(32);
    tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch = VL_RAND_RESET_I(32);
    tcpip_top__DOT__ip_rx0__DOT__rx_cnt = VL_RAND_RESET_I(14);
    tcpip_top__DOT__ip_rx0__DOT__checksum_temp = VL_RAND_RESET_I(16);
    tcpip_top__DOT__ip_rx0__DOT__checksum_sum = VL_RAND_RESET_I(16);
    tcpip_top__DOT__ip_rx0__DOT__checksum_cnt = VL_RAND_RESET_I(2);
    tcpip_top__DOT__ip_rx0__DOT__checksum_extend = VL_RAND_RESET_I(17);
    tcpip_top__DOT__ip_rx0__DOT__packet_en_prev = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__header_done = VL_RAND_RESET_I(1);
    tcpip_top__DOT__ip_rx0__DOT__check_failed = VL_RAND_RESET_I(1);
    __Vtablechg1[0] = 0U;
    __Vtablechg1[1] = 1U;
    __Vtablechg1[2] = 0U;
    __Vtablechg1[3] = 1U;
    __Vtablechg1[4] = 0U;
    __Vtablechg1[5] = 1U;
    __Vtablechg1[6] = 0U;
    __Vtablechg1[7] = 1U;
    __Vtablechg1[8] = 0U;
    __Vtablechg1[9] = 1U;
    __Vtablechg1[10] = 0U;
    __Vtablechg1[11] = 1U;
    __Vtablechg1[12] = 0U;
    __Vtablechg1[13] = 1U;
    __Vtablechg1[14] = 0U;
    __Vtablechg1[15] = 1U;
    __Vtablechg1[16] = 0U;
    __Vtablechg1[17] = 1U;
    __Vtablechg1[18] = 0U;
    __Vtablechg1[19] = 1U;
    __Vtablechg1[20] = 0U;
    __Vtablechg1[21] = 1U;
    __Vtablechg1[22] = 0U;
    __Vtablechg1[23] = 1U;
    __Vtablechg1[24] = 0U;
    __Vtablechg1[25] = 1U;
    __Vtablechg1[26] = 0U;
    __Vtablechg1[27] = 1U;
    __Vtablechg1[28] = 0U;
    __Vtablechg1[29] = 1U;
    __Vtablechg1[30] = 0U;
    __Vtablechg1[31] = 1U;
    __Vtablechg1[32] = 0U;
    __Vtablechg1[33] = 1U;
    __Vtablechg1[34] = 0U;
    __Vtablechg1[35] = 1U;
    __Vtablechg1[36] = 0U;
    __Vtablechg1[37] = 1U;
    __Vtablechg1[38] = 0U;
    __Vtablechg1[39] = 1U;
    __Vtablechg1[40] = 0U;
    __Vtablechg1[41] = 1U;
    __Vtablechg1[42] = 0U;
    __Vtablechg1[43] = 1U;
    __Vtablechg1[44] = 0U;
    __Vtablechg1[45] = 1U;
    __Vtablechg1[46] = 0U;
    __Vtablechg1[47] = 1U;
    __Vtablechg1[48] = 0U;
    __Vtablechg1[49] = 1U;
    __Vtablechg1[50] = 0U;
    __Vtablechg1[51] = 1U;
    __Vtablechg1[52] = 0U;
    __Vtablechg1[53] = 1U;
    __Vtablechg1[54] = 0U;
    __Vtablechg1[55] = 1U;
    __Vtablechg1[56] = 0U;
    __Vtablechg1[57] = 1U;
    __Vtablechg1[58] = 0U;
    __Vtablechg1[59] = 1U;
    __Vtablechg1[60] = 0U;
    __Vtablechg1[61] = 1U;
    __Vtablechg1[62] = 0U;
    __Vtablechg1[63] = 1U;
    __Vtablechg1[64] = 0U;
    __Vtablechg1[65] = 1U;
    __Vtablechg1[66] = 0U;
    __Vtablechg1[67] = 1U;
    __Vtablechg1[68] = 0U;
    __Vtablechg1[69] = 1U;
    __Vtablechg1[70] = 0U;
    __Vtablechg1[71] = 1U;
    __Vtablechg1[72] = 0U;
    __Vtablechg1[73] = 1U;
    __Vtablechg1[74] = 0U;
    __Vtablechg1[75] = 1U;
    __Vtablechg1[76] = 0U;
    __Vtablechg1[77] = 1U;
    __Vtablechg1[78] = 0U;
    __Vtablechg1[79] = 1U;
    __Vtablechg1[80] = 0U;
    __Vtablechg1[81] = 1U;
    __Vtablechg1[82] = 0U;
    __Vtablechg1[83] = 1U;
    __Vtablechg1[84] = 0U;
    __Vtablechg1[85] = 1U;
    __Vtablechg1[86] = 0U;
    __Vtablechg1[87] = 1U;
    __Vtablechg1[88] = 0U;
    __Vtablechg1[89] = 1U;
    __Vtablechg1[90] = 0U;
    __Vtablechg1[91] = 1U;
    __Vtablechg1[92] = 0U;
    __Vtablechg1[93] = 1U;
    __Vtablechg1[94] = 0U;
    __Vtablechg1[95] = 1U;
    __Vtablechg1[96] = 0U;
    __Vtablechg1[97] = 1U;
    __Vtablechg1[98] = 0U;
    __Vtablechg1[99] = 1U;
    __Vtablechg1[100] = 0U;
    __Vtablechg1[101] = 1U;
    __Vtablechg1[102] = 0U;
    __Vtablechg1[103] = 1U;
    __Vtablechg1[104] = 0U;
    __Vtablechg1[105] = 1U;
    __Vtablechg1[106] = 0U;
    __Vtablechg1[107] = 1U;
    __Vtablechg1[108] = 0U;
    __Vtablechg1[109] = 1U;
    __Vtablechg1[110] = 0U;
    __Vtablechg1[111] = 1U;
    __Vtablechg1[112] = 0U;
    __Vtablechg1[113] = 1U;
    __Vtablechg1[114] = 0U;
    __Vtablechg1[115] = 1U;
    __Vtablechg1[116] = 0U;
    __Vtablechg1[117] = 1U;
    __Vtablechg1[118] = 0U;
    __Vtablechg1[119] = 1U;
    __Vtablechg1[120] = 0U;
    __Vtablechg1[121] = 1U;
    __Vtablechg1[122] = 0U;
    __Vtablechg1[123] = 1U;
    __Vtablechg1[124] = 0U;
    __Vtablechg1[125] = 1U;
    __Vtablechg1[126] = 0U;
    __Vtablechg1[127] = 1U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[0] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[1] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[2] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[3] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[4] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[5] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[6] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[7] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[8] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[9] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[10] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[11] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[12] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[13] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[14] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[15] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[16] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[17] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[18] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[19] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[20] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[21] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[22] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[23] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[24] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[25] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[26] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[27] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[28] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[29] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[30] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[31] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[32] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[33] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[34] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[35] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[36] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[37] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[38] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[39] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[40] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[41] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[42] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[43] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[44] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[45] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[46] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[47] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[48] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[49] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[50] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[51] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[52] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[53] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[54] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[55] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[56] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[57] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[58] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[59] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[60] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[61] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[62] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[63] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[64] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[65] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[66] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[67] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[68] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[69] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[70] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[71] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[72] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[73] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[74] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[75] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[76] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[77] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[78] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[79] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[80] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[81] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[82] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[83] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[84] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[85] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[86] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[87] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[88] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[89] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[90] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[91] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[92] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[93] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[94] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[95] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[96] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[97] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[98] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[99] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[100] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[101] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[102] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[103] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[104] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[105] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[106] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[107] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[108] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[109] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[110] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[111] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[112] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[113] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[114] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[115] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[116] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[117] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[118] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[119] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[120] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[121] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[122] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[123] = 2U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[124] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[125] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[126] = 0U;
    __Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE[127] = 0U;
    __Vdlyvdim0__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0 = 0;
    __Vdlyvval__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0 = VL_RAND_RESET_I(4);
    __Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0 = 0;
    __Vdlyvdim0__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0 = 0;
    __Vdlyvval__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0 = VL_RAND_RESET_I(14);
    __Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0 = 0;
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
