// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VASCON_AEAD.h for the primary calling header

#include "VASCON_AEAD_ASCON_SBOX.h"
#include "VASCON_AEAD__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(VASCON_AEAD_ASCON_SBOX) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VASCON_AEAD_ASCON_SBOX::__Vconfigure(VASCON_AEAD__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VASCON_AEAD_ASCON_SBOX::~VASCON_AEAD_ASCON_SBOX() {
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_SBOX::_sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__1(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VASCON_AEAD_ASCON_SBOX::_sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__1\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa0 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg0 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg4);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa4 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg4 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg3);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc4 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa4 
           ^ ((~ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa0) 
              & vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg1));
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4 
        = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc4;
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_SBOX::_sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__2(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VASCON_AEAD_ASCON_SBOX::_sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__2\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa2 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xark2 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg1);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc2 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa2 
           ^ ((~ vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg3) 
              & vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa4));
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc0 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa0 
           ^ ((~ vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg1) 
              & vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa2));
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
        = (~ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc2);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3 
        = ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg3 
            ^ ((~ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa4) 
               & vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa0)) 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc2);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
        = ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg1 
            ^ ((~ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa2) 
               & vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg3)) 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc0);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc0 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc4);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p2 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p1 
        = ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0 
            ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2) 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p0 
        = ((((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0 
              ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1) 
             ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2) 
            ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3) 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4);
}

void VASCON_AEAD_ASCON_SBOX::_settle__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__3(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VASCON_AEAD_ASCON_SBOX::_settle__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__3\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa4 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg4 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg3);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa0 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg0 
           ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg4);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc4 
        = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa4 
           ^ ((~ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xa0) 
              & vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg1));
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4 
        = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__PVT__Xc4;
}

void VASCON_AEAD_ASCON_SBOX::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VASCON_AEAD_ASCON_SBOX::_ctor_var_reset\n"); );
    // Body
    __PVT__Xark0 = VL_RAND_RESET_Q(64);
    __PVT__Xark1 = VL_RAND_RESET_Q(64);
    __PVT__Xark2 = VL_RAND_RESET_Q(64);
    __PVT__Xark3 = VL_RAND_RESET_Q(64);
    __PVT__Xark4 = VL_RAND_RESET_Q(64);
    Xsb0 = VL_RAND_RESET_Q(64);
    Xsb1 = VL_RAND_RESET_Q(64);
    Xsb2 = VL_RAND_RESET_Q(64);
    Xsb3 = VL_RAND_RESET_Q(64);
    Xsb4 = VL_RAND_RESET_Q(64);
    p0 = VL_RAND_RESET_Q(64);
    p1 = VL_RAND_RESET_Q(64);
    p2 = VL_RAND_RESET_Q(64);
    __PVT__Xa0 = VL_RAND_RESET_Q(64);
    __PVT__Xa2 = VL_RAND_RESET_Q(64);
    __PVT__Xa4 = VL_RAND_RESET_Q(64);
    __PVT__Xc0 = VL_RAND_RESET_Q(64);
    __PVT__Xc2 = VL_RAND_RESET_Q(64);
    __PVT__Xc4 = VL_RAND_RESET_Q(64);
}
