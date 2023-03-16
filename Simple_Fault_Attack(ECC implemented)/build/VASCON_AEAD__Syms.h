// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VASCON_AEAD__SYMS_H_
#define _VASCON_AEAD__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VASCON_AEAD.h"
#include "VASCON_AEAD_ASCON_AEAD.h"
#include "VASCON_AEAD_ASCON_DATAPATH.h"
#include "VASCON_AEAD_ASCON_ROUND_FUNCTION.h"
#include "VASCON_AEAD_ASCON_SBOX.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class VASCON_AEAD__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VASCON_AEAD*                   TOPp;
    VASCON_AEAD_ASCON_AEAD         TOP__ASCON_AEAD;
    VASCON_AEAD_ASCON_DATAPATH     TOP__ASCON_AEAD__ascondatapath1;
    VASCON_AEAD_ASCON_ROUND_FUNCTION TOP__ASCON_AEAD__ascondatapath1__asconRF1;
    VASCON_AEAD_ASCON_SBOX         TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1;
    
    // CREATORS
    VASCON_AEAD__Syms(VASCON_AEAD* topp, const char* namep);
    ~VASCON_AEAD__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
