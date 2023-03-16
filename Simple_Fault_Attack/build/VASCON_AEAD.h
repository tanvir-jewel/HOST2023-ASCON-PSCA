// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VASCON_AEAD_H_
#define _VASCON_AEAD_H_  // guard

#include "verilated.h"
#include "VASCON_AEAD__Dpi.h"

//==========

class VASCON_AEAD__Syms;
class VASCON_AEAD_ASCON_AEAD;


//----------

VL_MODULE(VASCON_AEAD) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    VASCON_AEAD_ASCON_AEAD* ASCON_AEAD;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
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
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VASCON_AEAD__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VASCON_AEAD);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VASCON_AEAD(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VASCON_AEAD();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VASCON_AEAD__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VASCON_AEAD__Syms* symsp, bool first);
  private:
    static QData _change_request(VASCON_AEAD__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__10(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _combo__TOP__11(VASCON_AEAD__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VASCON_AEAD__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(VASCON_AEAD__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__6(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__9(VASCON_AEAD__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
