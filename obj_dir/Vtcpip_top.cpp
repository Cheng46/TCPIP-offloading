// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtcpip_top.h for the primary calling header

#include "Vtcpip_top.h"
#include "Vtcpip_top__Syms.h"

//==========

void Vtcpip_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtcpip_top::eval\n"); );
    Vtcpip_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("rtl/tcpip_top.v", 22, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtcpip_top::_eval_initial_loop(Vtcpip_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("rtl/tcpip_top.v", 22, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtcpip_top::_combo__TOP__3(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_combo__TOP__3\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->tcpip_top__DOT__i_mii_tx_clk = vlTOPp->i_mii_tx_clk;
    vlTOPp->tcpip_top__DOT__i_mii_rx_clk = vlTOPp->i_mii_rx_clk;
    vlTOPp->tcpip_top__DOT__i_sys_clk = vlTOPp->i_sys_clk;
    vlTOPp->tcpip_top__DOT__i_rstn = vlTOPp->i_rstn;
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
}

VL_INLINE_OPT void Vtcpip_top::_sequent__TOP__4(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_sequent__TOP__4\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__tcpip_top__DOT__test_phy0__DOT__frame_done;
    IData/*31:0*/ __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index;
    // Body
    __Vdly__tcpip_top__DOT__test_phy0__DOT__frame_done 
        = vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done;
    __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index 
        = vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index;
    vlTOPp->__Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0 = 0U;
    vlTOPp->__Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0 = 0U;
    vlTOPp->tcpip_top__DOT__eth_ctrl_mdio = 0U;
    if ((1U & (~ (IData)(vlTOPp->i_rstn)))) {
        vlTOPp->tcpip_top__DOT__test_phy_mii_rx_er = 0U;
    }
    if (vlTOPp->i_rstn) {
        vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth 
            = ((IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv)
                ? (0x3fffU & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth)))
                : 0U);
        vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__prev_rx_dv 
            = ((IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv) 
               & 1U);
    } else {
        vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth = 0U;
        vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__prev_rx_dv = 0U;
    }
    if (vlTOPp->i_rstn) {
        if (((IData)(vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en) 
             & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_full)))) {
            vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT____Vlvbound1 
                = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_len;
            if ((0x17U >= (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr))) {
                vlTOPp->__Vdlyvval__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0 
                    = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT____Vlvbound1;
                vlTOPp->__Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0 = 1U;
                vlTOPp->__Vdlyvdim0__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0 
                    = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr;
            }
            vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr 
                = (0x1fU & VL_MODDIV_III(32, ((IData)(1U) 
                                              + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr)), (IData)(0x18U)));
        }
    } else {
        vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr = 0U;
    }
    if (vlTOPp->i_rstn) {
        if (((IData)(vlTOPp->tcpip_top__DOT__eth_ctrl_data_fifo_w_en) 
             & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_full)))) {
            vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT____Vlvbound1 
                = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_data;
            if ((0x2f6fU >= (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr))) {
                vlTOPp->__Vdlyvval__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0 
                    = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT____Vlvbound1;
                vlTOPp->__Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0 = 1U;
                vlTOPp->__Vdlyvdim0__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0 
                    = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr;
            }
            vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr 
                = (0x3fffU & VL_MODDIV_III(32, ((IData)(1U) 
                                                + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr)), (IData)(0x2f70U)));
        }
    } else {
        vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr = 0U;
    }
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_mdio 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_mdio;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_er 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_er;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_er 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_er;
    vlTOPp->tcpip_top__DOT__eth_ctrl_data_fifo_w_en 
        = ((IData)(vlTOPp->i_rstn) & (IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv));
    vlTOPp->tcpip_top__DOT__eth_ctrl_frame_data = ((IData)(vlTOPp->i_rstn)
                                                    ? 
                                                   ((IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv)
                                                     ? (IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data)
                                                     : 0U)
                                                    : 0U);
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_data_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_data_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_data_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_frame_data 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_data 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_data;
    if (vlTOPp->i_rstn) {
        if ((4U > (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done))) {
            if ((0U == (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done))) {
                if ((0xb2U == vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)) {
                    __Vdly__tcpip_top__DOT__test_phy0__DOT__frame_done 
                        = (7U & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done)));
                    vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 0U;
                    vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data 
                        = vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame0
                        [(0x3ffU & vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)];
                    __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index = 0U;
                } else {
                    vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 1U;
                    vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data 
                        = vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame0
                        [(0x3ffU & vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)];
                    __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index 
                        = ((IData)(1U) + vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index);
                }
            } else {
                if ((1U == (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done))) {
                    if ((0xb0U == vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)) {
                        __Vdly__tcpip_top__DOT__test_phy0__DOT__frame_done 
                            = (7U & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done)));
                        vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 0U;
                        vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data = 0U;
                        __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index = 0U;
                    } else {
                        vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 1U;
                        vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data 
                            = vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame1
                            [(0x3ffU & vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)];
                        __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index 
                            = ((IData)(1U) + vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index);
                    }
                } else {
                    if ((2U == (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done))) {
                        if ((0xb0U == vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)) {
                            __Vdly__tcpip_top__DOT__test_phy0__DOT__frame_done 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done)));
                            vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 0U;
                            vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data = 0U;
                            __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index = 0U;
                        } else {
                            vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 1U;
                            vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data 
                                = vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame2
                                [(0x3ffU & vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)];
                            __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index 
                                = ((IData)(1U) + vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index);
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done))) {
                            if ((0xaeU == vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)) {
                                __Vdly__tcpip_top__DOT__test_phy0__DOT__frame_done 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done)));
                                vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 0U;
                                vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data = 0U;
                                __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index = 0U;
                            } else {
                                vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 1U;
                                vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data 
                                    = vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame3
                                    [(0x3ffU & vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index)];
                                __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index 
                                    = ((IData)(1U) 
                                       + vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index);
                            }
                        }
                    }
                }
            }
        } else {
            vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 0U;
        }
    } else {
        __Vdly__tcpip_top__DOT__test_phy0__DOT__frame_done = 0U;
        vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv = 0U;
        vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data = 0U;
        __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index = 0U;
    }
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_data;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__frame_done 
        = __Vdly__tcpip_top__DOT__test_phy0__DOT__frame_done;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__rx_index 
        = __Vdly__tcpip_top__DOT__test_phy0__DOT__rx_index;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_data 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_data 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_data;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_dv 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_dv 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_start 
        = ((~ (IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__prev_rx_dv)) 
           & (IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv));
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_done 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__prev_rx_dv) 
           & (~ (IData)(vlTOPp->tcpip_top__DOT__test_phy_mii_rx_dv)));
    vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__rx_trans_done) 
           & (0U != (IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth)));
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_len_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_ctrl_frame_len = ((IData)(vlTOPp->tcpip_top__DOT__eth_ctrl_len_fifo_w_en)
                                                   ? 
                                                  (0x3fffU 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__frame_lenth))
                                                   : 0U);
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_fifo_w_en 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_w_en;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__o_frame_len 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_len;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_data 
        = vlTOPp->tcpip_top__DOT__eth_ctrl_frame_len;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__i_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_len_fifo_data;
}

VL_INLINE_OPT void Vtcpip_top::_sequent__TOP__5(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_sequent__TOP__5\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->tcpip_top__DOT__test_phy_mii_rx_col = 0U;
    vlTOPp->tcpip_top__DOT__test_phy_mii_rx_crs = 0U;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_col 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_col;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_col 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_col;
    vlTOPp->tcpip_top__DOT__test_phy0__DOT__o_mii_rx_crs 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_crs;
    vlTOPp->tcpip_top__DOT__eth_rx_ctrl0__DOT__i_rx_crs 
        = vlTOPp->tcpip_top__DOT__test_phy_mii_rx_crs;
}

VL_INLINE_OPT void Vtcpip_top::_sequent__TOP__6(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_sequent__TOP__6\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*6:0*/ __Vtableidx1;
    CData/*4:0*/ __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr;
    CData/*0:0*/ __Vdly__tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt;
    CData/*1:0*/ __Vdly__tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE;
    CData/*5:0*/ __Vdly__tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt;
    CData/*1:0*/ __Vdly__tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE;
    CData/*0:0*/ __Vdly__tcpip_top__DOT__arp_tx0__DOT__mac_unkwown;
    CData/*5:0*/ __Vdly__tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt;
    CData/*2:0*/ __Vdlyvdim0__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0;
    CData/*0:0*/ __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0;
    CData/*2:0*/ __Vdlyvdim0__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0;
    CData/*0:0*/ __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0;
    CData/*0:0*/ __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v1;
    CData/*7:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
    CData/*1:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_cnt;
    SData/*13:0*/ __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr;
    SData/*13:0*/ __Vdly__tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt;
    SData/*15:0*/ __Vdly__tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
    SData/*15:0*/ __Vdly__tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch;
    SData/*15:0*/ __Vdly__tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch;
    SData/*15:0*/ __Vdly__tcpip_top__DOT__arp_rx0__DOT__opcode_latch;
    SData/*12:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch;
    SData/*15:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_latch;
    SData/*13:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__rx_cnt;
    SData/*15:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_temp;
    SData/*15:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_sum;
    IData/*31:0*/ __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_ip_latch;
    IData/*31:0*/ __Vdly__tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch;
    IData/*31:0*/ __Vdlyvval__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0;
    IData/*31:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__src_ip_latch;
    IData/*31:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch;
    IData/*16:0*/ __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_extend;
    QData/*47:0*/ __Vdly__tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch;
    QData/*47:0*/ __Vdly__tcpip_top__DOT__mac_rx0__DOT__src_mac_latch;
    QData/*47:0*/ __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_mac_latch;
    QData/*47:0*/ __Vdlyvval__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0;
    // Body
    __Vdly__tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt 
        = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt;
    __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_ip_latch 
        = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_ip_latch;
    __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_mac_latch 
        = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_mac_latch;
    __Vdly__tcpip_top__DOT__arp_rx0__DOT__opcode_latch 
        = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__opcode_latch;
    __Vdly__tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch 
        = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch;
    __Vdly__tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch 
        = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch;
    __Vdly__tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch 
        = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch;
    __Vdly__tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE;
    __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0 = 0U;
    __Vdly__tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE 
        = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE;
    __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr;
    __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0 = 0U;
    __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v1 = 0U;
    __Vdly__tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt;
    __Vdly__tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt;
    __Vdly__tcpip_top__DOT__arp_tx0__DOT__mac_unkwown 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__mac_unkwown;
    __Vdly__tcpip_top__DOT__mac_rx0__DOT__src_mac_latch 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__src_mac_latch;
    __Vdly__tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch;
    __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_cnt 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_cnt;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_sum 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_sum;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_temp 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_temp;
    __Vdly__tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_extend 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_extend;
    __Vdly__tcpip_top__DOT__mac_rx0__DOT__eth_type_latch 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__src_ip_latch 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__src_ip_latch;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__protocol_latch 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_latch 
        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_latch;
    __Vdly__tcpip_top__DOT__ip_rx0__DOT__rx_cnt = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt;
    if ((1U & (~ (IData)(vlTOPp->i_rstn)))) {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__a = 1U;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__a = 2U;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__a = 3U;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__a = 4U;
    }
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__packet_en_prev 
        = ((IData)(vlTOPp->i_rstn) & (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en));
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_done)))) {
        vlTOPp->tcpip_top__DOT__arp_rx0__DOT__new_packet_latch = 0U;
    } else {
        if (vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_new_packet_en) {
            vlTOPp->tcpip_top__DOT__arp_rx0__DOT__new_packet_latch = 1U;
        }
    }
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q 
        = ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_check)))
            ? 0xffffffffU : ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_en)
                              ? vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_c
                              : vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q));
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_done)))) {
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch = 0U;
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch = 0U;
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__opcode_latch = 0U;
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_mac_latch = 0ULL;
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_ip_latch = 0U;
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch = 0U;
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt = 0U;
    } else {
        if (vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_new_packet_en) {
            __Vdly__tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt 
                = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt)));
            if ((0x20U & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt))) {
                if ((0x10U & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt))) {
                    if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt) 
                                  >> 3U)))) {
                        __Vdly__tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch 
                            = ((vlTOPp->tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch 
                                << 4U) | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt) 
                                      >> 2U)))) {
                            __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_ip_latch 
                                = ((vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_ip_latch 
                                    << 4U) | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data));
                        }
                    }
                }
            } else {
                if ((0x10U & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt))) {
                    if ((8U & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt))) {
                        if ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt))) {
                            __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_ip_latch 
                                = ((vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_ip_latch 
                                    << 4U) | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data));
                        } else {
                            __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_mac_latch 
                                = (0xffffffffffffULL 
                                   & ((vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_mac_latch 
                                       << 4U) | (QData)((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data))));
                        }
                    } else {
                        __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_mac_latch 
                            = (0xffffffffffffULL & 
                               ((vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_mac_latch 
                                 << 4U) | (QData)((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data))));
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt))) {
                        if ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt))) {
                            __Vdly__tcpip_top__DOT__arp_rx0__DOT__opcode_latch 
                                = (0xffffU & (((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__opcode_latch) 
                                               << 4U) 
                                              | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data)));
                        }
                    } else {
                        if ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt))) {
                            __Vdly__tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch 
                                = (0xffffU & (((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch) 
                                               << 4U) 
                                              | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data)));
                        } else {
                            __Vdly__tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch 
                                = (0xffffU & (((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch) 
                                               << 4U) 
                                              | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_packet_data)));
                        }
                    }
                }
            }
        }
    }
    __Vtableidx1 = (((IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_done) 
                     << 6U) | (((IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__mac_unkwown) 
                                << 5U) | (((IData)(vlTOPp->tcpip_top__DOT__arp_rx_need_reply) 
                                           << 4U) | 
                                          (((IData)(vlTOPp->tcpip_top__DOT__arp_rx_new_packet) 
                                            << 3U) 
                                           | (((IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE) 
                                               << 1U) 
                                              | (IData)(vlTOPp->i_rstn))))));
    if (vlTOPp->__Vtablechg1[__Vtableidx1]) {
        __Vdly__tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE 
            = vlTOPp->__Vtable1_tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE
            [__Vtableidx1];
    }
    if (vlTOPp->i_rstn) {
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE 
            = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__NXT_STAGE;
        vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_r_done 
            = ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_en) 
                 & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty))) 
                & (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__last_read)) 
               & 1U);
    } else {
        __Vdly__tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE = 0U;
        vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_r_done = 0U;
    }
    if (vlTOPp->i_rstn) {
        if (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache_w_en) {
            vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT____Vlvbound1 
                = vlTOPp->tcpip_top__DOT__arp_rx_receive_mac;
            if ((4U >= (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr))) {
                __Vdlyvval__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0 
                    = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT____Vlvbound1;
                __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0 = 1U;
                __Vdlyvdim0__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0 
                    = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr;
            }
            vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT____Vlvbound2 
                = vlTOPp->tcpip_top__DOT__arp_rx_receive_ip;
            if ((4U >= (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr))) {
                __Vdlyvval__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0 
                    = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT____Vlvbound2;
                __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0 = 1U;
                __Vdlyvdim0__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0 
                    = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr;
            }
            vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr 
                = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr;
        }
    } else {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__queue_w_ptr = 0U;
        __Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v1 = 1U;
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_start))))) {
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_prev_latch = 0U;
        __Vdly__tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt = 0U;
    } else {
        if (vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_start) {
            __Vdly__tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt 
                = (1U & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt)));
            if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt)))) {
                vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_prev_latch 
                    = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
            }
        }
    }
    if (vlTOPp->i_rstn) {
        if ((0U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
            vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy = 0U;
        } else {
            if ((1U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy = 1U;
                vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy = 1U;
            } else {
                if ((2U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                    if (vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy) {
                        vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy = 1U;
                    }
                } else {
                    vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy = 0U;
                }
            }
        }
    } else {
        vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy = 0U;
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE))))) {
        __Vdly__tcpip_top__DOT__arp_tx0__DOT__mac_unkwown = 0U;
    } else {
        if ((1U == (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE))) {
            if (((IData)(vlTOPp->tcpip_top__DOT__arp_tx_lookup_done) 
                 & (~ (IData)(vlTOPp->tcpip_top__DOT__arp_tx_lookup_result)))) {
                __Vdly__tcpip_top__DOT__arp_tx0__DOT__mac_unkwown = 1U;
            }
        }
    }
    if (vlTOPp->i_rstn) {
        if (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_done) {
            __Vdly__tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt = 0U;
            vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_en = 1U;
            vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data = 0U;
            vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_done = 0U;
            __Vdly__tcpip_top__DOT__arp_tx0__DOT__mac_unkwown = 0U;
        } else {
            if (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__mac_unkwown) {
                __Vdly__tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt 
                    = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt)));
                vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_en = 1U;
                if ((0x20U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                    if ((0x10U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                        if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt) 
                                      >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                                if ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                                    if ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                                        vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                            = (0xfU 
                                               & vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch);
                                        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_done = 1U;
                                    } else {
                                        vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                            = (0xfU 
                                               & (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch 
                                                  >> 4U));
                                    }
                                } else {
                                    vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                        = (0xfU & (
                                                   (1U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch 
                                                    >> 8U)
                                                    : 
                                                   (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch 
                                                    >> 0xcU)));
                                }
                            } else {
                                vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                    = (0xfU & ((2U 
                                                & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch 
                                                    >> 0x10U)
                                                    : 
                                                   (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch 
                                                    >> 0x14U))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch 
                                                    >> 0x18U)
                                                    : 
                                                   (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch 
                                                    >> 0x1cU))));
                            }
                        }
                    } else {
                        vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                            = ((8U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                ? 0U : ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                         ? 0U : ((2U 
                                                  & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                   ? 1U
                                                   : 0U))));
                    }
                } else {
                    vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                        = ((0x10U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                            ? ((8U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                ? ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                    ? ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                        ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                            ? 8U : 0xaU)
                                        : ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                            ? 0U : 0xcU))
                                    : ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                        ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                            ? 9U : 2U)
                                        : 3U)) : ((4U 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? 4U
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? 0xeU
                                                     : 3U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? 8U
                                                     : 1U)
                                                    : 0U)))
                            : ((8U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                ? ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                    ? ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                        ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                            ? 1U : 0U)
                                        : 0U) : ((2U 
                                                  & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                   ? 4U
                                                   : 0U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                   ? 6U
                                                   : 0U)))
                                : ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                    ? ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                        ? 0U : ((1U 
                                                 & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                 ? 8U
                                                 : 0U))
                                    : ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                        ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                            ? 1U : 0U)
                                        : 0U))));
                }
            } else {
                if (vlTOPp->tcpip_top__DOT__arp_rx_need_reply) {
                    __Vdly__tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt 
                        = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt)));
                    vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_en = 1U;
                    if ((0x20U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                        if ((0x10U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                            if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt) 
                                          >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                                    if ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                                        if ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))) {
                                            vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                                = (0xfU 
                                                   & vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch);
                                            vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_done = 1U;
                                        } else {
                                            vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                                = (0xfU 
                                                   & (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch 
                                                      >> 4U));
                                        }
                                    } else {
                                        vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                            = (0xfU 
                                               & ((1U 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                   ? 
                                                  (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch 
                                                   >> 8U)
                                                   : 
                                                  (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch 
                                                   >> 0xcU)));
                                    }
                                } else {
                                    vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                        = (0xfU & (
                                                   (2U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? 
                                                    (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch 
                                                     >> 0x10U)
                                                     : 
                                                    (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch 
                                                     >> 0x14U))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? 
                                                    (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch 
                                                     >> 0x18U)
                                                     : 
                                                    (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch 
                                                     >> 0x1cU))));
                                }
                            }
                        } else {
                            vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                                = (0xfU & ((8U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                            ? ((4U 
                                                & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch)
                                                     : (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 4U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 8U))
                                                     : (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0xcU))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0x10U))
                                                     : (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0x14U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0x18U))
                                                     : (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0x1cU)))))
                                            : ((4U 
                                                & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0x20U))
                                                     : (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0x24U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0x28U))
                                                     : (IData)(
                                                               (vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                                                                >> 0x2cU))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                     ? 1U
                                                     : 0U)))));
                        }
                    } else {
                        vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data 
                            = ((0x10U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                ? ((8U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                    ? ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                        ? ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                            ? ((1U 
                                                & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                ? 8U
                                                : 0xaU)
                                            : ((1U 
                                                & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                ? 0U
                                                : 0xcU))
                                        : ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                            ? ((1U 
                                                & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                ? 9U
                                                : 2U)
                                            : 3U)) : 
                                   ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                     ? ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                         ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                             ? 4U : 0U)
                                         : ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                             ? 0xeU
                                             : 3U))
                                     : ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                         ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                             ? 8U : 1U)
                                         : 0U))) : 
                               ((8U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                 ? ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                     ? ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                         ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                             ? 2U : 0U)
                                         : 0U) : ((2U 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 4U
                                                    : 0U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                    ? 6U
                                                    : 0U)))
                                 : ((4U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                     ? ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                         ? 0U : ((1U 
                                                  & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                                  ? 8U
                                                  : 0U))
                                     : ((2U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                         ? ((1U & (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt))
                                             ? 1U : 0U)
                                         : 0U))));
                    }
                }
            }
        }
    } else {
        __Vdly__tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt = 0U;
        vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_en = 1U;
        vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data = 0U;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_done = 0U;
        __Vdly__tcpip_top__DOT__arp_tx0__DOT__mac_unkwown = 1U;
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))))) {
        vlTOPp->tcpip_top__DOT__mac_rx_bad_packet_en = 0U;
    } else {
        if ((2U != (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((3U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
                vlTOPp->tcpip_top__DOT__mac_rx_bad_packet_en = 1U;
            }
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))))) {
        vlTOPp->tcpip_top__DOT__mac_rx_bad_packet = 0U;
    } else {
        if ((2U != (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((3U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
                vlTOPp->tcpip_top__DOT__mac_rx_bad_packet 
                    = (0U != vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_comp);
            }
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))))) {
        __Vdly__tcpip_top__DOT__mac_rx0__DOT__src_mac_latch = 0ULL;
    } else {
        if ((2U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                          >> 0xdU)))) {
                if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                              >> 0xcU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                  >> 0xbU)))) {
                        if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                      >> 0xaU)))) {
                            if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                          >> 9U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                              >> 8U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                  >> 7U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                    >> 6U)))) {
                                            if ((0x20U 
                                                 & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                         >> 4U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                             >> 3U)))) {
                                                        __Vdly__tcpip_top__DOT__mac_rx0__DOT__src_mac_latch 
                                                            = 
                                                            (0xffffffffffffULL 
                                                             & ((vlTOPp->tcpip_top__DOT__mac_rx0__DOT__src_mac_latch 
                                                                 << 4U) 
                                                                | (QData)((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data))));
                                                    }
                                                }
                                            } else {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                            __Vdly__tcpip_top__DOT__mac_rx0__DOT__src_mac_latch 
                                                                = 
                                                                (0xffffffffffffULL 
                                                                 & ((vlTOPp->tcpip_top__DOT__mac_rx0__DOT__src_mac_latch 
                                                                     << 4U) 
                                                                    | (QData)((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data))));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))))) {
        __Vdly__tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch = 0ULL;
    } else {
        if ((2U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                          >> 0xdU)))) {
                if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                              >> 0xcU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                  >> 0xbU)))) {
                        if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                      >> 0xaU)))) {
                            if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                          >> 9U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                              >> 8U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                  >> 7U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                    >> 6U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                     >> 5U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                                 >> 2U)))) {
                                                            __Vdly__tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch 
                                                                = 
                                                                (0xffffffffffffULL 
                                                                 & ((vlTOPp->tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch 
                                                                     << 4U) 
                                                                    | (QData)((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data))));
                                                        }
                                                    } else {
                                                        __Vdly__tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch 
                                                            = 
                                                            (0xffffffffffffULL 
                                                             & ((vlTOPp->tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch 
                                                                 << 4U) 
                                                                | (QData)((IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data))));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE 
        = ((IData)(vlTOPp->i_rstn) ? (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__NXT_STAGE)
            : 0U);
    if ((1U & (((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done)) 
               | (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
        __Vdly__tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt = 0U;
    } else {
        if ((1U != (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((2U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
                __Vdly__tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt 
                    = (0x3fffU & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt)));
            }
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en))))) {
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_extend = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_temp = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_sum = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_cnt = 0U;
    } else {
        if (((0x14U > (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
             | ((0x17U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                & (0x27U >= (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))))) {
            __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_cnt 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_cnt)));
            if ((3U == (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_cnt))) {
                __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_extend 
                    = (0x1ffffU & ((IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_sum) 
                                   + ((0xfff0U & ((IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_temp) 
                                                  << 4U)) 
                                      | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data))));
            } else {
                if ((0U == (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_cnt))) {
                    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_temp 
                        = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_sum 
                        = (0xffffU & ((0x10000U & vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_extend)
                                       ? ((IData)(1U) 
                                          + vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_extend)
                                       : vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_extend));
                    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_extend = 0U;
                } else {
                    __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_temp 
                        = (0xffffU & (((IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_temp) 
                                       << 4U) | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data)));
                }
            }
        }
    }
    if ((1U & (((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done)) 
               | (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_len_latch = 0U;
    } else {
        if ((1U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_len_latch 
                = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))))) {
        __Vdly__tcpip_top__DOT__mac_rx0__DOT__eth_type_latch = 0U;
        vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
        vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
        vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
    } else {
        if ((2U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((0x2000U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                     & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                    if ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                          & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                         & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                        vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                        vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                            = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                        vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                            = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                    } else {
                        vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                        vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                        vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                    }
                }
            } else {
                if ((0x1000U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                    if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                        if ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                              & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                             & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                            vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                            vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                            vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                        } else {
                            vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                            vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                            vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                        }
                    }
                } else {
                    if ((0x800U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                        if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                             & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                            if ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                  & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                                 & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                                vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                                vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                    = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                                vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                    = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                            } else {
                                vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                                vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                                vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                            }
                        }
                    } else {
                        if ((0x400U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                            if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                 & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                                if ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                      & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                                     & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                                    vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                                    vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                                    vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                                } else {
                                    vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                                    vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                                    vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                                }
                            }
                        } else {
                            if ((0x200U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                     & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                                    if ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                          & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                                         & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                                        vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                                        vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                            = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                                        vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                            = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                                    } else {
                                        vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                                        vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                                        vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                                    }
                                }
                            } else {
                                if ((0x100U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                    if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                                        if ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                              & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                                             & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                                            vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                                            vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                                = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                                            vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                                = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                                        } else {
                                            vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                                            vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                                            vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                                        }
                                    }
                                } else {
                                    if ((0x80U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                        if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                             & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                                            if ((((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                                  & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                                                 & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                                                vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                                                vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                                    = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                                                vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                                    = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                                            } else {
                                                vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                                                vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                                                vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                                            }
                                        }
                                    } else {
                                        if ((0x40U 
                                             & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                            if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                                 & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                                                if (
                                                    (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                                      & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                                                     & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                                                    vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                                                    vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                                        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                                                    vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                                        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                                                } else {
                                                    vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                                                    vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                                                    vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                                                }
                                            }
                                        } else {
                                            if ((0x20U 
                                                 & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                    if (
                                                        ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                                         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                                                        if (
                                                            (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                                              & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                                                             & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                                                            vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                                                            vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                                                = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                                                            vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                                                = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                                                        } else {
                                                            vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                                                            vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                                                            vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                                                        }
                                                    }
                                                } else {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                            if (
                                                                ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                                                 & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame))) {
                                                                if (
                                                                    (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
                                                                      & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame)) 
                                                                     & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx_drop_packet)))) {
                                                                    vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 1U;
                                                                    vlTOPp->tcpip_top__DOT__mac_rx_packet_data 
                                                                        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
                                                                    vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                                                                        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
                                                                } else {
                                                                    vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en = 0U;
                                                                    vlTOPp->tcpip_top__DOT__mac_rx_packet_data = 0U;
                                                                    vlTOPp->tcpip_top__DOT__mac_rx_eth_type = 0U;
                                                                }
                                                            }
                                                        } else {
                                                            __Vdly__tcpip_top__DOT__mac_rx0__DOT__eth_type_latch 
                                                                = 
                                                                (0xffffU 
                                                                 & ((2U 
                                                                     & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))
                                                                     ? 
                                                                    ((1U 
                                                                      & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))
                                                                      ? 
                                                                     (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch) 
                                                                       << 4U) 
                                                                      | (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data))
                                                                      : 
                                                                     (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch) 
                                                                       << 4U) 
                                                                      | (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data)))
                                                                     : 
                                                                    (((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch) 
                                                                      << 4U) 
                                                                     | (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data))));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((3U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
                vlTOPp->tcpip_top__DOT__mac_rx_eth_type 
                    = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
            }
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_new_packet_en))))) {
        vlTOPp->tcpip_top__DOT__ip_rx0__DOT__ip_ver_latch = 0U;
        vlTOPp->tcpip_top__DOT__ip_rx0__DOT__ihl_latch = 0U;
        vlTOPp->tcpip_top__DOT__ip_rx0__DOT__flag_latch = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__protocol_latch = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_latch = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__src_ip_latch = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch = 0U;
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__rx_cnt = 0U;
        vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 0U;
        vlTOPp->tcpip_top__DOT__ip_rx_segment_type = 0U;
        vlTOPp->tcpip_top__DOT__ip_rx_segment_data = 0U;
    } else {
        __Vdly__tcpip_top__DOT__ip_rx0__DOT__rx_cnt 
            = (0x3fffU & ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)));
        if ((0x2000U & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
            if (((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                 & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                    = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                    = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
            }
        } else {
            if ((0x1000U & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                if (((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                     & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                    vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                    vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                    vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                        = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                }
            } else {
                if ((0x800U & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                    if (((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                         & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                        vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                        vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                            = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                        vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                            = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                    }
                } else {
                    if ((0x400U & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                        if (((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                             & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                            vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                            vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                            vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                        }
                    } else {
                        if ((0x200U & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                            if (((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                 & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                    = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                    = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                            }
                        } else {
                            if ((0x100U & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                if (((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                     & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                    vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                    vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                    vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                        = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                }
                            } else {
                                if ((0x80U & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                    if (((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                         & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                        vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                        vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                            = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                        vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                            = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                    }
                                } else {
                                    if ((0x40U & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                        if (((0x27U 
                                              < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                             & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                            vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                            vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                                = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                            vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                                = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                        }
                                    } else {
                                        if ((0x20U 
                                             & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                            if ((0x10U 
                                                 & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                if (
                                                    ((0x27U 
                                                      < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                                     & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                                    vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                                    vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                                        = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                                    vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                                        = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                                }
                                            } else {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                    if (
                                                        ((0x27U 
                                                          < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                                         & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                                        vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                                        vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                                            = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                                        vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                                            = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                                    }
                                                } else {
                                                    __Vdly__tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch 
                                                        = 
                                                        ((vlTOPp->tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch 
                                                          << 4U) 
                                                         | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data));
                                                }
                                            }
                                        } else {
                                            if ((0x10U 
                                                 & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                    __Vdly__tcpip_top__DOT__ip_rx0__DOT__src_ip_latch 
                                                        = 
                                                        ((vlTOPp->tcpip_top__DOT__ip_rx0__DOT__src_ip_latch 
                                                          << 4U) 
                                                         | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data));
                                                } else {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                        __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_latch 
                                                            = 
                                                            (0xffffU 
                                                             & (((IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_latch) 
                                                                 << 4U) 
                                                                | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data)));
                                                    } else {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                            __Vdly__tcpip_top__DOT__ip_rx0__DOT__protocol_latch 
                                                                = 
                                                                (0xffU 
                                                                 & (((IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch) 
                                                                     << 4U) 
                                                                    | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data)));
                                                        } else {
                                                            if (
                                                                ((0x27U 
                                                                  < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                                                 & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                                                vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                                                vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                                                    = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                                                vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                                                    = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                            __Vdly__tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch 
                                                                = 
                                                                (0x1fffU 
                                                                 & (((IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch) 
                                                                     << 4U) 
                                                                    | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data)));
                                                        } else {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                                __Vdly__tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch 
                                                                    = 
                                                                    (0x1fffU 
                                                                     & (((IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch) 
                                                                         << 4U) 
                                                                        | (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data)));
                                                            } else {
                                                                vlTOPp->tcpip_top__DOT__ip_rx0__DOT__flag_latch 
                                                                    = 
                                                                    (7U 
                                                                     & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data) 
                                                                        >> 1U));
                                                                __Vdly__tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch 
                                                                    = 
                                                                    ((0xfffU 
                                                                      & (IData)(__Vdly__tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch)) 
                                                                     | (0x1000U 
                                                                        & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data) 
                                                                           << 0xcU)));
                                                            }
                                                        }
                                                    } else {
                                                        if (
                                                            ((0x27U 
                                                              < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                                             & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                                            vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                                            vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                                                = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                                            vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                                                = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                                        }
                                                    }
                                                } else {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                        if (
                                                            ((0x27U 
                                                              < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                                             & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                                            vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                                            vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                                                = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                                            vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                                                = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                                        }
                                                    } else {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                            if (
                                                                ((0x27U 
                                                                  < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
                                                                 & (~ (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed)))) {
                                                                vlTOPp->tcpip_top__DOT__ip_rx_new_segment = 1U;
                                                                vlTOPp->tcpip_top__DOT__ip_rx_segment_type 
                                                                    = vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
                                                                vlTOPp->tcpip_top__DOT__ip_rx_segment_data 
                                                                    = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                                            }
                                                        } else {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt))) {
                                                                vlTOPp->tcpip_top__DOT__ip_rx0__DOT__ihl_latch 
                                                                    = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                                            } else {
                                                                vlTOPp->tcpip_top__DOT__ip_rx0__DOT__ip_ver_latch 
                                                                    = vlTOPp->tcpip_top__DOT__mac_rx_to_ip_rx_packet_data;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt 
        = __Vdly__tcpip_top__DOT__arp_rx0__DOT__arp_recieve_cnt;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__opcode_latch 
        = __Vdly__tcpip_top__DOT__arp_rx0__DOT__opcode_latch;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch 
        = __Vdly__tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch 
        = __Vdly__tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch 
        = __Vdly__tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch;
    if (__Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0) {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue[__Vdlyvdim0__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0] 
            = __Vdlyvval__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue__v0;
    }
    if (__Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v1) {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue[4U] = 0xc0a80106U;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue[0U] = 0U;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue[1U] = 0U;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue[2U] = 0U;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_ip_queue[3U] = 0U;
    }
    if (__Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0) {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue[__Vdlyvdim0__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0] 
            = __Vdlyvval__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v0;
    }
    if (__Vdlyvset__tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue__v1) {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue[4U] = 0x107c4fa2a003ULL;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue[0U] = 0ULL;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue[1U] = 0ULL;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue[2U] = 0ULL;
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__arp_mac_queue[3U] = 0ULL;
    }
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt 
        = __Vdly__tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt 
        = __Vdly__tcpip_top__DOT__arp_tx0__DOT__arp_send_cnt;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__mac_unkwown 
        = __Vdly__tcpip_top__DOT__arp_tx0__DOT__mac_unkwown;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__src_mac_latch 
        = __Vdly__tcpip_top__DOT__mac_rx0__DOT__src_mac_latch;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch 
        = __Vdly__tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_temp 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_temp;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_sum 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_sum;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_cnt 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_cnt;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_extend 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_extend;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_type_latch 
        = __Vdly__tcpip_top__DOT__mac_rx0__DOT__eth_type_latch;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__src_ip_latch 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__src_ip_latch;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__frag_offset_latch;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__protocol_latch 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__protocol_latch;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__dst_ip_latch;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_latch 
        = __Vdly__tcpip_top__DOT__ip_rx0__DOT__checksum_latch;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt = __Vdly__tcpip_top__DOT__ip_rx0__DOT__rx_cnt;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__my_arp_packet 
        = (((1U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__hardware_type_latch)) 
            & (0x800U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__protocol_type_latch))) 
           & (0xc0a80106U == vlTOPp->tcpip_top__DOT__arp_rx0__DOT__dest_ip_latch));
    if (vlTOPp->i_rstn) {
        if ((0U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
            vlTOPp->tcpip_top__DOT__arp_rx_new_packet = 1U;
        } else {
            if ((1U != (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                if ((2U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                    if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy)))) {
                        vlTOPp->tcpip_top__DOT__arp_rx_new_packet = 1U;
                    }
                } else {
                    vlTOPp->tcpip_top__DOT__arp_rx_new_packet = 0U;
                }
            }
        }
    } else {
        vlTOPp->tcpip_top__DOT__arp_rx_new_packet = 1U;
    }
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__NXT_STAGE 
        = ((IData)(vlTOPp->i_rstn) ? ((0U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))
                                       ? ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_new_packet_en)
                                           ? 1U : 0U)
                                       : ((1U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))
                                           ? (((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_request) 
                                               | ((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_reply) 
                                                  & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet_en) 
                                                     & (~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet)))))
                                               ? 2U
                                               : (((IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet_en) 
                                                   & (IData)(vlTOPp->tcpip_top__DOT__mac_rx_to_arp_rx_bad_packet))
                                                   ? 0U
                                                   : 1U))
                                           : ((2U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))
                                               ? ((IData)(vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy)
                                                   ? 2U
                                                   : 0U)
                                               : 0U)))
            : 0U);
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_len_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_r_done;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_r_done;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_arp_rx_busy 
        = vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_arp_rx_busy 
        = vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_arp_packet_en 
        = vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_en;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_arp_packet_data 
        = vlTOPp->tcpip_top__DOT__arp_tx_arp_packet_data;
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE))))) {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__lookup_ip_latch = 0U;
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE))))) {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch = 0U;
    } else {
        if (vlTOPp->tcpip_top__DOT__arp_rx_need_reply) {
            vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_ip_latch 
                = vlTOPp->tcpip_top__DOT__arp_rx_receive_ip;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE))))) {
        vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch = 0ULL;
    } else {
        if (vlTOPp->tcpip_top__DOT__arp_rx_need_reply) {
            vlTOPp->tcpip_top__DOT__arp_tx0__DOT__src_mac_latch 
                = vlTOPp->tcpip_top__DOT__arp_rx_receive_mac;
        }
    }
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_bad_packet_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_bad_packet_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_bad_packet 
        = vlTOPp->tcpip_top__DOT__mac_rx_bad_packet;
    vlTOPp->tcpip_top__DOT__ip_rx_ip_rx_busy = (0U 
                                                != (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__CUR_STAGE));
    vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done 
        = ((IData)(vlTOPp->i_rstn) & (((IData)(vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_en) 
                                       & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_empty))) 
                                      & ((IData)(vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_stop) 
                                         | (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__last_read))));
    if (vlTOPp->i_rstn) {
        if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx_len_fifo_r_en) 
             & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty)))) {
            if (vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__last_read) {
                vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data 
                    = ((0x17U >= (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr))
                        ? vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q
                       [vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr]
                        : 0U);
                __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr 
                    = (0x1fU & VL_MODDIV_III(32, ((IData)(1U) 
                                                  + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr)), (IData)(0x18U)));
            } else {
                vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data 
                    = ((0x17U >= (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr))
                        ? vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q
                       [vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr]
                        : 0U);
                __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr 
                    = (0x1fU & VL_MODDIV_III(32, ((IData)(1U) 
                                                  + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr)), (IData)(0x18U)));
            }
        } else {
            vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_start_ptr 
                = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr;
            vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data = 0U;
        }
    } else {
        __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr = 0U;
        vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_start_ptr = 0U;
        vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data = 0U;
    }
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_packet_data 
        = vlTOPp->tcpip_top__DOT__mac_rx_packet_data;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_new_packet_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_new_packet_en;
    if (vlTOPp->i_rstn) {
        if (((IData)(vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_en) 
             & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_empty)))) {
            if (vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_stop) {
                vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data = 0U;
                __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr 
                    = (0x3fffU & VL_MODDIV_III(32, 
                                               ((IData)(1U) 
                                                + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_r_end_line)), (IData)(0x2f70U)));
            } else {
                if (vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__last_read) {
                    vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data 
                        = ((0x2f6fU >= (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr))
                            ? vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q
                           [vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr]
                            : 0U);
                    __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr 
                        = (0x3fffU & VL_MODDIV_III(32, 
                                                   ((IData)(1U) 
                                                    + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr)), (IData)(0x2f70U)));
                } else {
                    vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data 
                        = ((0x2f6fU >= (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr))
                            ? vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q
                           [vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr]
                            : 0U);
                    __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr 
                        = (0x3fffU & VL_MODDIV_III(32, 
                                                   ((IData)(1U) 
                                                    + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr)), (IData)(0x2f70U)));
                }
            }
        } else {
            vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_start_ptr 
                = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr;
            vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data = 0U;
        }
    } else {
        vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_start_ptr = 0U;
        vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data = 0U;
        __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr = 0U;
    }
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_eth_type 
        = vlTOPp->tcpip_top__DOT__mac_rx_eth_type;
    vlTOPp->tcpip_top__DOT__ip_packet = (0x800U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx_eth_type));
    vlTOPp->tcpip_top__DOT__arp_packet = (0x806U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx_eth_type));
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (0U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))))) {
        vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done = 0U;
    } else {
        if ((2U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))) {
            if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                          >> 0xdU)))) {
                if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                              >> 0xcU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                  >> 0xbU)))) {
                        if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                      >> 0xaU)))) {
                            if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                          >> 9U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                              >> 8U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                  >> 7U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                    >> 6U)))) {
                                            if ((0x20U 
                                                 & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                         >> 4U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt))) {
                                                                    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done = 1U;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_new_segment 
        = vlTOPp->tcpip_top__DOT__ip_rx_new_segment;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_segment_type 
        = vlTOPp->tcpip_top__DOT__ip_rx_segment_type;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_segment_data 
        = vlTOPp->tcpip_top__DOT__ip_rx_segment_data;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__check_failed 
        = ((0x27U < (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__rx_cnt)) 
           & (0xffffU != (0xffffU & (vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_extend 
                                     + (IData)(vlTOPp->tcpip_top__DOT__ip_rx0__DOT__checksum_latch)))));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_r_done;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_ip_rx_busy 
        = vlTOPp->tcpip_top__DOT__ip_rx_ip_rx_busy;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_ip_rx_busy 
        = vlTOPp->tcpip_top__DOT__ip_rx_ip_rx_busy;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__ip_rx_clear 
        = (1U & (~ ((IData)(vlTOPp->tcpip_top__DOT__arp_rx_arp_rx_busy) 
                    | (IData)(vlTOPp->tcpip_top__DOT__ip_rx_ip_rx_busy))));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr 
        = __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr 
        = __Vdly__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr;
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
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt 
        = __Vdly__tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt;
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
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_new_packet 
        = vlTOPp->tcpip_top__DOT__arp_rx_new_packet;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_rx_new_packet 
        = vlTOPp->tcpip_top__DOT__arp_rx_new_packet;
    if (vlTOPp->i_rstn) {
        if ((0U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
            vlTOPp->tcpip_top__DOT__arp_rx_receive_ip = 0U;
        } else {
            if ((1U != (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                if ((2U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                    if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy)))) {
                        vlTOPp->tcpip_top__DOT__arp_rx_receive_ip 
                            = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_ip_latch;
                    }
                } else {
                    vlTOPp->tcpip_top__DOT__arp_rx_receive_ip = 0U;
                }
            }
        }
    } else {
        vlTOPp->tcpip_top__DOT__arp_rx_receive_ip = 0U;
    }
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE 
        = ((IData)(vlTOPp->i_rstn) ? (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE)
            : 0U);
    if (vlTOPp->i_rstn) {
        if ((0U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
            vlTOPp->tcpip_top__DOT__arp_rx_need_reply = 0U;
        } else {
            if ((1U != (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                if ((2U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                    if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy)))) {
                        vlTOPp->tcpip_top__DOT__arp_rx_need_reply 
                            = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__arp_request;
                    }
                } else {
                    vlTOPp->tcpip_top__DOT__arp_rx_need_reply = 0U;
                }
            }
        }
    } else {
        vlTOPp->tcpip_top__DOT__arp_rx_need_reply = 0U;
    }
    if (vlTOPp->i_rstn) {
        if ((0U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
            vlTOPp->tcpip_top__DOT__arp_rx_receive_mac = 0ULL;
        } else {
            if ((1U != (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                if ((2U == (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE))) {
                    if ((1U & (~ (IData)(vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy)))) {
                        vlTOPp->tcpip_top__DOT__arp_rx_receive_mac 
                            = vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_mac_latch;
                    }
                } else {
                    vlTOPp->tcpip_top__DOT__arp_rx_receive_mac = 0ULL;
                }
            }
        }
    } else {
        vlTOPp->tcpip_top__DOT__arp_rx_receive_mac = 0ULL;
    }
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_data_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_frame_len 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_data;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_frame_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_data;
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
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__my_frame 
        = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__eth_parse_done) 
           & ((0x183e043329ULL == vlTOPp->tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch) 
              | (0xffffffffffffULL == vlTOPp->tcpip_top__DOT__mac_rx0__DOT__dst_mac_latch)));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE 
        = ((IData)(vlTOPp->i_rstn) ? (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__NXT_STAGE)
            : 0U);
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_ip_rx_drop 
        = vlTOPp->tcpip_top__DOT__ip_rx_drop_packet;
    vlTOPp->tcpip_top__DOT__ip_rx0__DOT__o_drop_packet 
        = vlTOPp->tcpip_top__DOT__ip_rx_drop_packet;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_ip_latch 
        = __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_ip_latch;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE 
        = __Vdly__tcpip_top__DOT__arp_tx0__DOT__NXT_STAGE;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__src_mac_latch 
        = __Vdly__tcpip_top__DOT__arp_rx0__DOT__src_mac_latch;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE 
        = __Vdly__tcpip_top__DOT__arp_rx0__DOT__CUR_STAGE;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_r_done 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_r_done;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_data;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_data 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_data;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__gather_done 
        = ((IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__new_packet_latch) 
           & (IData)(vlTOPp->tcpip_top__DOT__arp_rx0__DOT__correct_packet));
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_arp_receive_ip 
        = vlTOPp->tcpip_top__DOT__arp_rx_receive_ip;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_receive_ip 
        = vlTOPp->tcpip_top__DOT__arp_rx_receive_ip;
    vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy = (0U 
                                                  != (IData)(vlTOPp->tcpip_top__DOT__arp_tx0__DOT__CUR_STAGE));
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_arp_need_reply 
        = vlTOPp->tcpip_top__DOT__arp_rx_need_reply;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_need_reply 
        = vlTOPp->tcpip_top__DOT__arp_rx_need_reply;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__o_arp_receive_mac 
        = vlTOPp->tcpip_top__DOT__arp_rx_receive_mac;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_receive_mac 
        = vlTOPp->tcpip_top__DOT__arp_rx_receive_mac;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache_w_en 
        = ((IData)(vlTOPp->tcpip_top__DOT__arp_rx_new_packet) 
           & ((0xc0a80106U != vlTOPp->tcpip_top__DOT__arp_rx_receive_ip) 
              | (0x107c4fa2a003ULL != vlTOPp->tcpip_top__DOT__arp_rx_receive_mac)));
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
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_check 
        = (3U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_start 
        = ((2U == (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)) 
           & (0xfU < (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__frame_recieved_cnt)));
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_ip 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_receive_ip;
    vlTOPp->tcpip_top__DOT__arp_rx0__DOT__i_arp_tx_busy 
        = vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__o_arp_tx_busy 
        = vlTOPp->tcpip_top__DOT__arp_tx_arp_tx_busy;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_mac 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__i_receive_mac;
    vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache0__DOT__i_cache_w_en 
        = vlTOPp->tcpip_top__DOT__arp_tx0__DOT__arp_cache_w_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__i_crc_done 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_check;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_comp 
        = ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_check)
            ? vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__lfsr_q
            : 0U);
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_en = 
        ((IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_cnt) 
         & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_data_start));
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__crc32_0__DOT__o_fcs 
        = vlTOPp->tcpip_top__DOT__mac_rx0__DOT__fcs_comp;
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
}

VL_INLINE_OPT void Vtcpip_top::_sequent__TOP__7(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_sequent__TOP__7\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0) {
        vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q[vlTOPp->__Vdlyvdim0__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0] 
            = vlTOPp->__Vdlyvval__tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_q__v0;
    }
    if (vlTOPp->__Vdlyvset__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0) {
        vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q[vlTOPp->__Vdlyvdim0__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0] 
            = vlTOPp->__Vdlyvval__tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_q__v0;
    }
}

VL_INLINE_OPT void Vtcpip_top::_multiclk__TOP__8(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_multiclk__TOP__8\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_full 
        = (VL_MODDIV_III(32, ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr)), (IData)(0x18U)) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr));
    vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__w_ptr) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr));
    vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_empty 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr));
    vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_full 
        = (VL_MODDIV_III(32, ((IData)(1U) + (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__w_ptr)), (IData)(0x2f70U)) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_full 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_full;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__i_len_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo_len_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_full 
        = vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_full;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_full 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_full;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__o_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_len_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_empty 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_empty;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__o_fifo_full 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__o_data_fifo_full;
}

VL_INLINE_OPT void Vtcpip_top::_combo__TOP__9(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_combo__TOP__9\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_en = 
        ((IData)(vlTOPp->i_rstn) & ((2U & (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE))
                                     ? ((~ (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)) 
                                        & (~ (IData)(vlTOPp->tcpip_top__DOT__eth_fifo_data_fifo_r_done)))
                                     : (IData)(vlTOPp->tcpip_top__DOT__mac_rx0__DOT__CUR_STAGE)));
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
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_en;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_en;
    vlTOPp->tcpip_top__DOT__mac_rx0__DOT__o_data_fifo_r_line 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_line 
        = vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line;
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__end_line 
        = (0x3fffU & (((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_start_ptr) 
                       + (IData)(vlTOPp->tcpip_top__DOT__mac_rx_data_fifo_r_line)) 
                      - (IData)(1U)));
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
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__i_fifo_r_en 
        = vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__i_data_fifo_r_en;
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
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__last_read 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__r_ptr) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_data_fifo0__DOT__fifo_r_end_line));
    vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__last_read 
        = ((IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__r_ptr) 
           == (IData)(vlTOPp->tcpip_top__DOT__eth_fifo0__DOT__eth_len_fifo1__DOT__fifo_r_end_line));
}

void Vtcpip_top::_eval(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_eval\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
    if ((((IData)(vlTOPp->i_mii_rx_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_mii_rx_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->i_mii_tx_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_mii_tx_clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)) 
         | ((IData)(vlTOPp->i_sys_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_sys_clk))))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if ((((IData)(vlTOPp->i_mii_rx_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_mii_rx_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if (((((IData)(vlTOPp->i_mii_rx_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_mii_rx_clk))) 
          | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn))) 
         | ((IData)(vlTOPp->i_sys_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_sys_clk))))) {
        vlTOPp->_multiclk__TOP__8(vlSymsp);
    }
    vlTOPp->_combo__TOP__9(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__i_mii_rx_clk = vlTOPp->i_mii_rx_clk;
    vlTOPp->__Vclklast__TOP__i_rstn = vlTOPp->i_rstn;
    vlTOPp->__Vclklast__TOP__i_mii_tx_clk = vlTOPp->i_mii_tx_clk;
    vlTOPp->__Vclklast__TOP__i_sys_clk = vlTOPp->i_sys_clk;
}

VL_INLINE_OPT QData Vtcpip_top::_change_request(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_change_request\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtcpip_top::_change_request_1(Vtcpip_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_change_request_1\n"); );
    Vtcpip_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtcpip_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtcpip_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_sys_clk & 0xfeU))) {
        Verilated::overWidthError("i_sys_clk");}
    if (VL_UNLIKELY((i_mii_tx_clk & 0xfeU))) {
        Verilated::overWidthError("i_mii_tx_clk");}
    if (VL_UNLIKELY((i_mii_rx_clk & 0xfeU))) {
        Verilated::overWidthError("i_mii_rx_clk");}
    if (VL_UNLIKELY((i_rstn & 0xfeU))) {
        Verilated::overWidthError("i_rstn");}
}
#endif  // VL_DEBUG
