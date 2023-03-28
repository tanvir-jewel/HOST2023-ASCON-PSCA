// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VASCON_AEAD.h for the primary calling header

#ifndef _VASCON_AEAD_ASCON_AEAD_H_
#define _VASCON_AEAD_ASCON_AEAD_H_  // guard

#include "verilated.h"
#include "VASCON_AEAD__Dpi.h"

//==========

class VASCON_AEAD__Syms;
class VASCON_AEAD_ASCON_DATAPATH;


//----------

VL_MODULE(VASCON_AEAD_ASCON_AEAD) {
  public:
    // CELLS
    VASCON_AEAD_ASCON_DATAPATH* ascondatapath1;
    
    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(start,0,0);
    VL_IN8(startAD,0,0);
    VL_IN8(PTlen,3,0);
    VL_IN8(ADlen,3,0);
    VL_OUT8(CTv,0,0);
    VL_OUT8(Tv,0,0);
    VL_OUT8(read,0,0);
    VL_INW(key,127,0,4);
    VL_INW(nonce,127,0,4);
    VL_OUTW(T,127,0,4);
    VL_IN64(ADblock,63,0);
    VL_IN64(PTblock,63,0);
    VL_OUT64(CTblock,63,0);
    VL_OUT64(XsboxIN0,63,0);
    VL_OUT64(XsboxIN1,63,0);
    VL_OUT64(XsboxIN2,63,0);
    VL_OUT64(XsboxIN3,63,0);
    VL_OUT64(XsboxIN4,63,0);
    VL_OUT64(Xsbox0,63,0);
    VL_OUT64(Xsbox1,63,0);
    VL_OUT64(Xsbox2,63,0);
    VL_OUT64(Xsbox3,63,0);
    VL_OUT64(Xsbox4,63,0);
    VL_OUT64(p0,63,0);
    VL_OUT64(p1,63,0);
    VL_OUT64(p2,63,0);
    
    // LOCAL SIGNALS
    CData/*0:0*/ __PVT__intial;
    CData/*0:0*/ __PVT__inc;
    CData/*3:0*/ __PVT__consti;
    CData/*5:0*/ __PVT__asconcont1__DOT__cstate;
    CData/*5:0*/ __PVT__asconcont1__DOT__nstate;
    CData/*3:0*/ __PVT__asconcont1__DOT__datalen;
    CData/*0:0*/ __PVT__asconcont1__DOT__lastassoq;
    WData/*127:0*/ __PVT__asconcont1__DOT__keyreg[4];
    QData/*63:0*/ __PVT__Xi0;
    QData/*63:0*/ __PVT__Xi1;
    QData/*63:0*/ __PVT__Xi2;
    QData/*63:0*/ __PVT__Xi4;
    QData/*63:0*/ __PVT__asconcont1__DOT__datablock;
    QData/*63:0*/ __PVT__asconcont1__DOT__pado;
    
    // INTERNAL VARIABLES
  private:
    VASCON_AEAD__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VASCON_AEAD_ASCON_AEAD);  ///< Copying not allowed
  public:
    VASCON_AEAD_ASCON_AEAD(const char* name = "TOP");
    ~VASCON_AEAD_ASCON_AEAD();
    
    // INTERNAL METHODS
    void __Vconfigure(VASCON_AEAD__Syms* symsp, bool first);
    static void _combo__TOP__ASCON_AEAD__6(VASCON_AEAD__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__ASCON_AEAD__1(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _sequent__TOP__ASCON_AEAD__2(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _settle__TOP__ASCON_AEAD__3(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__ASCON_AEAD__4(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__ASCON_AEAD__5(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
