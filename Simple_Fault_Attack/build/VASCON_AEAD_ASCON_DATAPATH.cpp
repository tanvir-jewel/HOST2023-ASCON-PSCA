// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VASCON_AEAD.h for the primary calling header

#include "VASCON_AEAD_ASCON_DATAPATH.h"
#include "VASCON_AEAD__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(VASCON_AEAD_ASCON_DATAPATH) {
    VL_CELL(asconRF1, VASCON_AEAD_ASCON_ROUND_FUNCTION);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VASCON_AEAD_ASCON_DATAPATH::__Vconfigure(VASCON_AEAD__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VASCON_AEAD_ASCON_DATAPATH::~VASCON_AEAD_ASCON_DATAPATH() {
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_DATAPATH::_sequent__TOP__ASCON_AEAD__ascondatapath1__1(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VASCON_AEAD_ASCON_DATAPATH::_sequent__TOP__ASCON_AEAD__ascondatapath1__1\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg0 
        = ((IData)(vlTOPp->rst) ? VL_ULL(0) : vlSymsp->TOP__ASCON_AEAD.__PVT__Xi0);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg1 
        = ((IData)(vlTOPp->rst) ? VL_ULL(0) : vlSymsp->TOP__ASCON_AEAD.__PVT__Xi1);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg2 
        = ((IData)(vlTOPp->rst) ? VL_ULL(0) : vlSymsp->TOP__ASCON_AEAD.__PVT__Xi2);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg4 
        = ((IData)(vlTOPp->rst) ? VL_ULL(0) : vlSymsp->TOP__ASCON_AEAD.__PVT__Xi4);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg3 
        = ((IData)(vlTOPp->rst) ? VL_ULL(0) : ((0x20U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (0x10U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         vlTOPp->nonce[3U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlTOPp->nonce[2U])))
                                                        : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3)
                                                       : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3))
                                                     : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3))
                                                : (
                                                   (0x10U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                        ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3
                                                        : 
                                                       (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))))
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3)
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                        ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3
                                                        : VL_ULL(0))))))));
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__asconRC1__DOT__consttq 
        = ((IData)(vlTOPp->rst) ? 0U : (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__asconRC1__DOT__consttd));
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_DATAPATH::_settle__TOP__ASCON_AEAD__ascondatapath1__2(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VASCON_AEAD_ASCON_DATAPATH::_settle__TOP__ASCON_AEAD__ascondatapath1__2\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__asconRC1__DOT__consttd 
        = (0xfU & ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__intial)
                    ? (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__consti)
                    : ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__inc)
                        ? ((IData)(1U) + (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__asconRC1__DOT__consttq))
                        : (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__asconRC1__DOT__consttq))));
}

void VASCON_AEAD_ASCON_DATAPATH::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VASCON_AEAD_ASCON_DATAPATH::_ctor_var_reset\n"); );
    // Body
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__rst = VL_RAND_RESET_I(1);
    __PVT__intial = VL_RAND_RESET_I(1);
    __PVT__inc = VL_RAND_RESET_I(1);
    __PVT__constti = VL_RAND_RESET_I(4);
    __PVT__Xi0 = VL_RAND_RESET_Q(64);
    __PVT__Xi1 = VL_RAND_RESET_Q(64);
    __PVT__Xi2 = VL_RAND_RESET_Q(64);
    __PVT__Xi3 = VL_RAND_RESET_Q(64);
    __PVT__Xi4 = VL_RAND_RESET_Q(64);
    __PVT__Xo0 = VL_RAND_RESET_Q(64);
    __PVT__Xo1 = VL_RAND_RESET_Q(64);
    __PVT__Xo2 = VL_RAND_RESET_Q(64);
    __PVT__Xo3 = VL_RAND_RESET_Q(64);
    __PVT__Xo4 = VL_RAND_RESET_Q(64);
    __PVT__XsboxIN0 = VL_RAND_RESET_Q(64);
    __PVT__XsboxIN1 = VL_RAND_RESET_Q(64);
    __PVT__XsboxIN2 = VL_RAND_RESET_Q(64);
    __PVT__XsboxIN3 = VL_RAND_RESET_Q(64);
    __PVT__XsboxIN4 = VL_RAND_RESET_Q(64);
    __PVT__Xsbox0 = VL_RAND_RESET_Q(64);
    __PVT__Xsbox1 = VL_RAND_RESET_Q(64);
    __PVT__Xsbox2 = VL_RAND_RESET_Q(64);
    __PVT__Xsbox3 = VL_RAND_RESET_Q(64);
    __PVT__Xsbox4 = VL_RAND_RESET_Q(64);
    __PVT__p0 = VL_RAND_RESET_Q(64);
    __PVT__p1 = VL_RAND_RESET_Q(64);
    __PVT__p2 = VL_RAND_RESET_Q(64);
    __PVT__Xreg0 = VL_RAND_RESET_Q(64);
    __PVT__Xreg1 = VL_RAND_RESET_Q(64);
    __PVT__Xreg2 = VL_RAND_RESET_Q(64);
    __PVT__Xreg3 = VL_RAND_RESET_Q(64);
    __PVT__Xreg4 = VL_RAND_RESET_Q(64);
    __PVT__asconRC1__DOT__consttd = VL_RAND_RESET_I(4);
    __PVT__asconRC1__DOT__consttq = VL_RAND_RESET_I(4);
}
