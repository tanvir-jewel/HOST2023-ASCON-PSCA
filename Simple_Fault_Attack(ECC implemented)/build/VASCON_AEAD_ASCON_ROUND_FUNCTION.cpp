// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VASCON_AEAD.h for the primary calling header

#include "VASCON_AEAD_ASCON_ROUND_FUNCTION.h"
#include "VASCON_AEAD__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(VASCON_AEAD_ASCON_ROUND_FUNCTION) {
    VL_CELL(asconsbox1, VASCON_AEAD_ASCON_SBOX);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VASCON_AEAD_ASCON_ROUND_FUNCTION::__Vconfigure(VASCON_AEAD__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VASCON_AEAD_ASCON_ROUND_FUNCTION::~VASCON_AEAD_ASCON_ROUND_FUNCTION() {
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_ROUND_FUNCTION::_sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__1(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VASCON_AEAD_ASCON_ROUND_FUNCTION::_sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__1\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xark2 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg2 
           ^ (QData)((IData)(((0xf0U & ((~ (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__asconRC1__DOT__consttq)) 
                                        << 4U)) | (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__asconRC1__DOT__consttq)))));
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
        = ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4 
            ^ (((QData)((IData)((0x7fU & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4)))) 
                << 0x39U) | (VL_ULL(0x1ffffffffffffff) 
                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4 
                                >> 7U)))) ^ ((VL_ULL(0xffffffffff800000) 
                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4 
                                                 << 0x17U)) 
                                             | (QData)((IData)(
                                                               (0x7fffffU 
                                                                & (IData)(
                                                                          (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4 
                                                                           >> 0x29U)))))));
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_ROUND_FUNCTION::_sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__2(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VASCON_AEAD_ASCON_ROUND_FUNCTION::_sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__2\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3 
        = ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3 
            ^ (((QData)((IData)((0x3ffU & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3)))) 
                << 0x36U) | (VL_ULL(0x3fffffffffffff) 
                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3 
                                >> 0xaU)))) ^ (((QData)((IData)(
                                                                (0x1ffffU 
                                                                 & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3)))) 
                                                << 0x2fU) 
                                               | (VL_ULL(0x7fffffffffff) 
                                                  & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3 
                                                     >> 0x11U))));
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0 
        = ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0 
            ^ (((QData)((IData)((0x7ffffU & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0)))) 
                << 0x2dU) | (VL_ULL(0x1fffffffffff) 
                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0 
                                >> 0x13U)))) ^ (((QData)((IData)(
                                                                 (0xfffffffU 
                                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0)))) 
                                                 << 0x24U) 
                                                | (VL_ULL(0xfffffffff) 
                                                   & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0 
                                                      >> 0x1cU))));
}

void VASCON_AEAD_ASCON_ROUND_FUNCTION::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VASCON_AEAD_ASCON_ROUND_FUNCTION::_ctor_var_reset\n"); );
    // Body
    __PVT__Xi0 = VL_RAND_RESET_Q(64);
    __PVT__Xi1 = VL_RAND_RESET_Q(64);
    __PVT__Xi2 = VL_RAND_RESET_Q(64);
    __PVT__Xi3 = VL_RAND_RESET_Q(64);
    __PVT__Xi4 = VL_RAND_RESET_Q(64);
    __PVT__Roundconstant = VL_RAND_RESET_I(8);
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
    __PVT__Xark2 = VL_RAND_RESET_Q(64);
}
