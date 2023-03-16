// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VASCON_AEAD.h for the primary calling header

#ifndef _VASCON_AEAD_ASCON_ROUND_FUNCTION_H_
#define _VASCON_AEAD_ASCON_ROUND_FUNCTION_H_  // guard

#include "verilated.h"
#include "VASCON_AEAD__Dpi.h"

//==========

class VASCON_AEAD__Syms;
class VASCON_AEAD_ASCON_SBOX;


//----------

VL_MODULE(VASCON_AEAD_ASCON_ROUND_FUNCTION) {
  public:
    // CELLS
    VASCON_AEAD_ASCON_SBOX* asconsbox1;
    
    // PORTS
    VL_IN8(__PVT__Roundconstant,7,0);
    VL_IN64(__PVT__Xi0,63,0);
    VL_IN64(__PVT__Xi1,63,0);
    VL_IN64(__PVT__Xi2,63,0);
    VL_IN64(__PVT__Xi3,63,0);
    VL_IN64(__PVT__Xi4,63,0);
    VL_OUT64(__PVT__Xo0,63,0);
    VL_OUT64(__PVT__Xo1,63,0);
    VL_OUT64(__PVT__Xo2,63,0);
    VL_OUT64(__PVT__Xo3,63,0);
    VL_OUT64(__PVT__Xo4,63,0);
    VL_OUT64(__PVT__XsboxIN0,63,0);
    VL_OUT64(__PVT__XsboxIN1,63,0);
    VL_OUT64(__PVT__XsboxIN2,63,0);
    VL_OUT64(__PVT__XsboxIN3,63,0);
    VL_OUT64(__PVT__XsboxIN4,63,0);
    VL_OUT64(__PVT__Xsbox0,63,0);
    VL_OUT64(__PVT__Xsbox1,63,0);
    VL_OUT64(__PVT__Xsbox2,63,0);
    VL_OUT64(__PVT__Xsbox3,63,0);
    VL_OUT64(__PVT__Xsbox4,63,0);
    VL_OUT64(__PVT__p0,63,0);
    VL_OUT64(__PVT__p1,63,0);
    VL_OUT64(__PVT__p2,63,0);
    
    // LOCAL SIGNALS
    QData/*63:0*/ __PVT__Xark2;
    
    // INTERNAL VARIABLES
  private:
    VASCON_AEAD__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VASCON_AEAD_ASCON_ROUND_FUNCTION);  ///< Copying not allowed
  public:
    VASCON_AEAD_ASCON_ROUND_FUNCTION(const char* name = "TOP");
    ~VASCON_AEAD_ASCON_ROUND_FUNCTION();
    
    // INTERNAL METHODS
    void __Vconfigure(VASCON_AEAD__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__1(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__2(VASCON_AEAD__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
