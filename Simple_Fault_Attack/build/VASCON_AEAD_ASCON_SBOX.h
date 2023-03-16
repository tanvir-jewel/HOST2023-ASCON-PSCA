// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VASCON_AEAD.h for the primary calling header

#ifndef _VASCON_AEAD_ASCON_SBOX_H_
#define _VASCON_AEAD_ASCON_SBOX_H_  // guard

#include "verilated.h"
#include "VASCON_AEAD__Dpi.h"

//==========

class VASCON_AEAD__Syms;

//----------

VL_MODULE(VASCON_AEAD_ASCON_SBOX) {
  public:
    
    // PORTS
    VL_IN64(__PVT__Xark0,63,0);
    VL_IN64(__PVT__Xark1,63,0);
    VL_IN64(__PVT__Xark2,63,0);
    VL_IN64(__PVT__Xark3,63,0);
    VL_IN64(__PVT__Xark4,63,0);
    VL_OUT64(Xsb0,63,0);
    VL_OUT64(Xsb1,63,0);
    VL_OUT64(Xsb2,63,0);
    VL_OUT64(Xsb3,63,0);
    VL_OUT64(Xsb4,63,0);
    VL_OUT64(p0,63,0);
    VL_OUT64(p1,63,0);
    VL_OUT64(p2,63,0);
    
    // LOCAL SIGNALS
    QData/*63:0*/ __PVT__Xa0;
    QData/*63:0*/ __PVT__Xa2;
    QData/*63:0*/ __PVT__Xa4;
    QData/*63:0*/ __PVT__Xc0;
    QData/*63:0*/ __PVT__Xc2;
    QData/*63:0*/ __PVT__Xc4;
    
    // INTERNAL VARIABLES
  private:
    VASCON_AEAD__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VASCON_AEAD_ASCON_SBOX);  ///< Copying not allowed
  public:
    VASCON_AEAD_ASCON_SBOX(const char* name = "TOP");
    ~VASCON_AEAD_ASCON_SBOX();
    
    // INTERNAL METHODS
    void __Vconfigure(VASCON_AEAD__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__1(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__2(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _settle__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__3(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
