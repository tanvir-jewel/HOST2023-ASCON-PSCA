// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VASCON_AEAD.h for the primary calling header

#include "VASCON_AEAD_ASCON_AEAD.h"
#include "VASCON_AEAD__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(VASCON_AEAD_ASCON_AEAD) {
    VL_CELL(ascondatapath1, VASCON_AEAD_ASCON_DATAPATH);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VASCON_AEAD_ASCON_AEAD::__Vconfigure(VASCON_AEAD__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VASCON_AEAD_ASCON_AEAD::~VASCON_AEAD_ASCON_AEAD() {
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_AEAD::_sequent__TOP__ASCON_AEAD__1(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VASCON_AEAD_ASCON_AEAD::_sequent__TOP__ASCON_AEAD__1\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->rst) {
        vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq = 0U;
    } else {
        if ((0xdU == (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq 
                = (1U & (~ ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen) 
                            >> 3U)));
        }
    }
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_AEAD::_sequent__TOP__ASCON_AEAD__2(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VASCON_AEAD_ASCON_AEAD::_sequent__TOP__ASCON_AEAD__2\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->rst) {
        vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U] = 0U;
        vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U] = 0U;
        vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U] = 0U;
        vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U] = 0U;
    } else {
        if ((0x2bU == (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U] 
                = vlTOPp->key[0U];
            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U] 
                = vlTOPp->key[1U];
            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U] 
                = vlTOPp->key[2U];
            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U] 
                = vlTOPp->key[3U];
        }
    }
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate 
        = ((IData)(vlTOPp->rst) ? 0U : (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__nstate));
    vlSymsp->TOP__ASCON_AEAD.Tv = (1U & ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                              >> 4U) 
                                             | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                 >> 3U) 
                                                & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 2U) 
                                                   | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 1U) 
                                                      & (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))))
                                          : (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                              >> 4U) 
                                             & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                 >> 3U) 
                                                & ((4U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((~ 
                                                     ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                      >> 1U)) 
                                                    | (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))
                                                    : 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 1U) 
                                                    | (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__inc = (1U & ((0x20U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? 
                                                 ((~ 
                                                   ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 4U)) 
                                                  & ((~ 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 3U)) 
                                                     | ((~ 
                                                         ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                          >> 2U)) 
                                                        & (~ 
                                                           ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                            >> 1U)))))
                                                  : 
                                                 ((0x10U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 2U) 
                                                    & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 1U) 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))
                                                    : 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 2U) 
                                                    | ((~ 
                                                        ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                         >> 1U)) 
                                                       | (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))
                                                   : 
                                                  ((8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((~ 
                                                     ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                      >> 2U)) 
                                                    | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 1U) 
                                                       | (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))
                                                    : 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 2U) 
                                                    | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 1U) 
                                                       | (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__intial = (1U & 
                                              ((0x20U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 4U) 
                                                   | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 3U) 
                                                      & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                          >> 2U) 
                                                         | ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                            >> 1U))))
                                                : (
                                                   (0x10U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 2U)) 
                                                     | ((~ 
                                                         ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                          >> 1U)) 
                                                        | (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))
                                                     : 
                                                    ((~ 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 2U)) 
                                                     & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                         >> 1U) 
                                                        & (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))))
                                                    : 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 3U) 
                                                    & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 2U) 
                                                       & ((~ 
                                                           ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                            >> 1U)) 
                                                          & (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))))));
}

void VASCON_AEAD_ASCON_AEAD::_settle__TOP__ASCON_AEAD__3(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VASCON_AEAD_ASCON_AEAD::_settle__TOP__ASCON_AEAD__3\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD.Tv = (1U & ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                              >> 4U) 
                                             | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                 >> 3U) 
                                                & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 2U) 
                                                   | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 1U) 
                                                      & (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))))
                                          : (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                              >> 4U) 
                                             & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                 >> 3U) 
                                                & ((4U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((~ 
                                                     ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                      >> 1U)) 
                                                    | (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))
                                                    : 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 1U) 
                                                    | (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))))));
    if ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
        vlSymsp->TOP__ASCON_AEAD.read = 0U;
    } else {
        if ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
            if ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                vlSymsp->TOP__ASCON_AEAD.read = (1U 
                                                 & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 2U) 
                                                    & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 1U) 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))));
            } else {
                if ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                    vlSymsp->TOP__ASCON_AEAD.read = 0U;
                } else {
                    if ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                        if ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                            vlSymsp->TOP__ASCON_AEAD.read = 1U;
                        } else {
                            vlSymsp->TOP__ASCON_AEAD.read = 0U;
                            if (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq) {
                                if ((8U != (IData)(vlTOPp->PTlen))) {
                                    if ((8U == (IData)(vlTOPp->PTlen))) {
                                        vlSymsp->TOP__ASCON_AEAD.read = 0U;
                                    }
                                }
                            }
                        }
                    } else {
                        vlSymsp->TOP__ASCON_AEAD.read = 0U;
                    }
                }
            }
        } else {
            if ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                if ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                    if ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                        vlSymsp->TOP__ASCON_AEAD.read 
                            = ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                               & (IData)(vlTOPp->startAD));
                    } else {
                        if ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                            vlSymsp->TOP__ASCON_AEAD.read = 0U;
                        } else {
                            vlSymsp->TOP__ASCON_AEAD.read = 0U;
                            if ((1U & (~ (IData)(vlTOPp->startAD)))) {
                                if ((8U != (IData)(vlTOPp->PTlen))) {
                                    if ((8U == (IData)(vlTOPp->PTlen))) {
                                        vlSymsp->TOP__ASCON_AEAD.read = 0U;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    vlSymsp->TOP__ASCON_AEAD.read = 0U;
                }
            } else {
                vlSymsp->TOP__ASCON_AEAD.read = 0U;
            }
        }
    }
    vlSymsp->TOP__ASCON_AEAD.__PVT__inc = (1U & ((0x20U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? 
                                                 ((~ 
                                                   ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 4U)) 
                                                  & ((~ 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 3U)) 
                                                     | ((~ 
                                                         ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                          >> 2U)) 
                                                        & (~ 
                                                           ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                            >> 1U)))))
                                                  : 
                                                 ((0x10U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 2U) 
                                                    & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 1U) 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))
                                                    : 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 2U) 
                                                    | ((~ 
                                                        ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                         >> 1U)) 
                                                       | (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))
                                                   : 
                                                  ((8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((~ 
                                                     ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                      >> 2U)) 
                                                    | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 1U) 
                                                       | (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))
                                                    : 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 2U) 
                                                    | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 1U) 
                                                       | (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__intial = (1U & 
                                              ((0x20U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 4U) 
                                                   | (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 3U) 
                                                      & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                          >> 2U) 
                                                         | ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                            >> 1U))))
                                                : (
                                                   (0x10U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((~ 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 2U)) 
                                                     | ((~ 
                                                         ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                          >> 1U)) 
                                                        | (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))
                                                     : 
                                                    ((~ 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                       >> 2U)) 
                                                     & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                         >> 1U) 
                                                        & (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)))))
                                                    : 
                                                   (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 3U) 
                                                    & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 2U) 
                                                       & ((~ 
                                                           ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                            >> 1U)) 
                                                          & (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
        = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
            ? ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? vlTOPp->PTblock : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                      ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? vlTOPp->PTblock
                                          : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                              ? ((1U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? 
                                                 ((IData)(vlTOPp->startAD)
                                                   ? vlTOPp->ADblock
                                                   : vlTOPp->PTblock)
                                                  : vlTOPp->PTblock)
                                              : vlTOPp->PTblock))
                                      : vlTOPp->PTblock))
            : ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? vlTOPp->PTblock : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? vlTOPp->PTblock
                                          : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                              ? ((1U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? vlTOPp->PTblock
                                                  : 
                                                 ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                   ? vlTOPp->PTblock
                                                   : vlTOPp->ADblock))
                                              : vlTOPp->ADblock)))
                : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? vlTOPp->ADblock : ((1U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? vlTOPp->ADblock
                                                  : 
                                                 ((IData)(vlTOPp->startAD)
                                                   ? vlTOPp->ADblock
                                                   : vlTOPp->PTblock)))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock))))
                    : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : VL_ULL(0)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen 
        = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
            ? ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? (IData)(vlTOPp->PTlen) : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                             ? ((4U 
                                                 & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                 ? (IData)(vlTOPp->PTlen)
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 
                                                  ((IData)(vlTOPp->startAD)
                                                    ? (IData)(vlTOPp->ADlen)
                                                    : (IData)(vlTOPp->PTlen))
                                                   : (IData)(vlTOPp->PTlen))
                                                  : (IData)(vlTOPp->PTlen)))
                                             : (IData)(vlTOPp->PTlen)))
            : ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? (IData)(vlTOPp->PTlen) : ((4U 
                                                 & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                 ? (IData)(vlTOPp->PTlen)
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? (IData)(vlTOPp->PTlen)
                                                   : 
                                                  ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                    ? (IData)(vlTOPp->PTlen)
                                                    : (IData)(vlTOPp->ADlen)))
                                                  : (IData)(vlTOPp->ADlen))))
                : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? (IData)(vlTOPp->ADlen)
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? (IData)(vlTOPp->ADlen)
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen)))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen)))))
                    : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen)))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen)))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : 0U))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__Xi4 = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                            ? ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        vlTOPp->nonce[1U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlTOPp->nonce[0U])))
                                                       : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4))
                                                    : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4))
                                            : ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        (VL_ULL(1) 
                                                         ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (VL_ULL(1) 
                                                          ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)
                                                          : 
                                                         (VL_ULL(1) 
                                                          ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)))
                                                        : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4))
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 
                                                       (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        (VL_ULL(1) 
                                                         ^ 
                                                         (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U])))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (VL_ULL(1) 
                                                          ^ 
                                                          (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U])))))
                                                          : 
                                                         (VL_ULL(1) 
                                                          ^ 
                                                          (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))))))))
                                                     : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                       : VL_ULL(0)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__nstate 
        = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
            ? ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? 0U : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                         ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                             ? 0U : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                      ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? 1U : 0U)
                                      : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? 0x2aU : 0x29U)))
                         : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                             ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                 ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0x28U : 0x27U)
                                 : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0x26U : 0x25U))
                             : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                 ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0x24U : 0x23U)
                                 : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0x22U : 0x21U)))))
            : ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 0x20U : 0U) : 0U)
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? 0U : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0U : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                              ? 0x13U
                                              : 0x1fU))))
                    : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 0x18U : 0x17U) : 
                           ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                             ? 0x16U : 0x15U)) : ((2U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 0x14U
                                                    : 
                                                   ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                     ? 
                                                    ((8U 
                                                      == (IData)(vlTOPp->PTlen))
                                                      ? 0x13U
                                                      : 0x1fU)
                                                     : 0xdU))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 0x12U
                                                    : 0x11U))))
                : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 0x10U : 0xfU) : (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 0xeU
                                                    : 
                                                   ((IData)(vlTOPp->startAD)
                                                     ? 0xdU
                                                     : 
                                                    ((8U 
                                                      == (IData)(vlTOPp->PTlen))
                                                      ? 0x13U
                                                      : 0x1fU))))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 0xcU : 0xbU) : ((1U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 0xaU
                                                   : 9U)))
                    : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 8U : 7U) : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                               ? 6U
                                               : 5U))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 4U : 3U) : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                               ? 2U
                                               : ((IData)(vlTOPp->start)
                                                   ? 0x2bU
                                                   : 0U)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__consti = ((0x20U 
                                               & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                               ? 0U
                                               : ((0x10U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 0U
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                                        ? 6U
                                                        : 0U))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 6U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 6U
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 6U
                                                         : 0U)
                                                        : 6U))
                                                      : 6U)))
                                                   : 
                                                  ((8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 6U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 6U
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 6U
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 6U
                                                         : 0U))))
                                                     : 0U)
                                                    : 0U)));
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado 
        = ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
            ? vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock
            : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                    ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                        ? (VL_ULL(0x80) | (VL_ULL(0xffffffffffffff00) 
                                           & vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock))
                        : (VL_ULL(0x8000) | (VL_ULL(0xffffffffffff0000) 
                                             & vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock)))
                    : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                        ? (VL_ULL(0x800000) | (VL_ULL(0xffffffffff000000) 
                                               & vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock))
                        : (VL_ULL(0x80000000) | ((QData)((IData)(
                                                                 (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
                                                                  >> 0x20U))) 
                                                 << 0x20U))))
                : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                    ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                        ? (VL_ULL(0x8000000000) | ((QData)((IData)(
                                                                   (0xffffffU 
                                                                    & (IData)(
                                                                              (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
                                                                               >> 0x28U))))) 
                                                   << 0x28U))
                        : (VL_ULL(0x800000000000) | 
                           ((QData)((IData)((0xffffU 
                                             & (IData)(
                                                       (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
                                                        >> 0x30U))))) 
                            << 0x30U))) : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                            ? (VL_ULL(0x80000000000000) 
                                               | ((QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(
                                                                             (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
                                                                              >> 0x38U))))) 
                                                  << 0x38U))
                                            : VL_ULL(0x8000000000000000)))));
}

void VASCON_AEAD_ASCON_AEAD::_settle__TOP__ASCON_AEAD__4(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VASCON_AEAD_ASCON_AEAD::_settle__TOP__ASCON_AEAD__4\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD.__PVT__Xi2 = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                            ? ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                    ^ 
                                                    (((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                      << 0x3fU) 
                                                     | (VL_ULL(0x7fffffffffffffff) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                           >> 1U)))) 
                                                   ^ 
                                                   (((QData)((IData)(
                                                                     (0x3fU 
                                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                     << 0x3aU) 
                                                    | (VL_ULL(0x3ffffffffffffff) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                          >> 6U))))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        vlTOPp->key[1U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlTOPp->key[0U])))
                                                       : 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U)))))
                                                      : 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U))))))
                                                    : 
                                                   ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (1U 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3fU) 
                                                      | (VL_ULL(0x7fffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 1U)))) 
                                                    ^ 
                                                    (((QData)((IData)(
                                                                      (0x3fU 
                                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                      << 0x3aU) 
                                                     | (VL_ULL(0x3ffffffffffffff) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                           >> 6U))))))
                                            : ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U))))
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                                        ? 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (1U 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3fU) 
                                                          | (VL_ULL(0x7fffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 1U)))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (0x3fU 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3aU) 
                                                         | (VL_ULL(0x3ffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 6U))))
                                                        : 
                                                       (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            (1U 
                                                                             & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                            << 0x3fU) 
                                                           | (VL_ULL(0x7fffffffffffffff) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                 >> 1U)))) 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (0x3fU 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3aU) 
                                                          | (VL_ULL(0x3ffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 6U)))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U))))
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            (1U 
                                                                             & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                            << 0x3fU) 
                                                           | (VL_ULL(0x7fffffffffffffff) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                 >> 1U)))) 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (0x3fU 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3aU) 
                                                          | (VL_ULL(0x3ffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 6U))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            ^ 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                              << 0x3fU) 
                                                             | (VL_ULL(0x7fffffffffffffff) 
                                                                & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                   >> 1U)))) 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             (0x3fU 
                                                                              & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                             << 0x3aU) 
                                                            | (VL_ULL(0x3ffffffffffffff) 
                                                               & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                  >> 6U)))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))
                                                          : 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            ^ 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                              << 0x3fU) 
                                                             | (VL_ULL(0x7fffffffffffffff) 
                                                                & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                   >> 1U)))) 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             (0x3fU 
                                                                              & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                             << 0x3aU) 
                                                            | (VL_ULL(0x3ffffffffffffff) 
                                                               & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                  >> 6U)))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))))
                                                        : 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (1U 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3fU) 
                                                          | (VL_ULL(0x7fffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 1U)))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (0x3fU 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3aU) 
                                                         | (VL_ULL(0x3ffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 6U))))))
                                                      : 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U)))))))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U))))
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (1U 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3fU) 
                                                          | (VL_ULL(0x7fffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 1U)))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (0x3fU 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3aU) 
                                                         | (VL_ULL(0x3ffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 6U))))
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            (1U 
                                                                             & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                            << 0x3fU) 
                                                           | (VL_ULL(0x7fffffffffffffff) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                 >> 1U)))) 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (0x3fU 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3aU) 
                                                          | (VL_ULL(0x3ffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 6U))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            ^ 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                              << 0x3fU) 
                                                             | (VL_ULL(0x7fffffffffffffff) 
                                                                & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                   >> 1U)))) 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             (0x3fU 
                                                                              & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                             << 0x3aU) 
                                                            | (VL_ULL(0x3ffffffffffffff) 
                                                               & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                  >> 6U)))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))
                                                          : 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            ^ 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                              << 0x3fU) 
                                                             | (VL_ULL(0x7fffffffffffffff) 
                                                                & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                   >> 1U)))) 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             (0x3fU 
                                                                              & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                             << 0x3aU) 
                                                            | (VL_ULL(0x3ffffffffffffff) 
                                                               & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                  >> 6U)))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U])))))))))
                                                     : 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U)))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U))))
                                                       : VL_ULL(0)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__Xi1 = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                            ? ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                    ^ 
                                                    ((VL_ULL(0xfffffffffffffff8) 
                                                      & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         << 3U)) 
                                                     | (QData)((IData)(
                                                                       (7U 
                                                                        & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                   ^ 
                                                   ((VL_ULL(0xfffffffffe000000) 
                                                     & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        << 0x19U)) 
                                                    | (QData)((IData)(
                                                                      (0x1ffffffU 
                                                                       & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        vlTOPp->key[3U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlTOPp->key[2U])))
                                                       : 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))))
                                                      : 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))))
                                                    : 
                                                   ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffffffff8) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 3U)) 
                                                      | (QData)((IData)(
                                                                        (7U 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                    ^ 
                                                    ((VL_ULL(0xfffffffffe000000) 
                                                      & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         << 0x19U)) 
                                                     | (QData)((IData)(
                                                                       (0x1ffffffU 
                                                                        & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))))
                                            : ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                                        ? 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffffffff8) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 3U)) 
                                                          | (QData)((IData)(
                                                                            (7U 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffe000000) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 0x19U)) 
                                                         | (QData)((IData)(
                                                                           (0x1ffffffU 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                        : 
                                                       (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          ^ 
                                                          ((VL_ULL(0xfffffffffffffff8) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                               << 3U)) 
                                                           | (QData)((IData)(
                                                                             (7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffe000000) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 0x19U)) 
                                                          | (QData)((IData)(
                                                                            (0x1ffffffU 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          ^ 
                                                          ((VL_ULL(0xfffffffffffffff8) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                               << 3U)) 
                                                           | (QData)((IData)(
                                                                             (7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffe000000) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 0x19U)) 
                                                          | (QData)((IData)(
                                                                            (0x1ffffffU 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            ^ 
                                                            ((VL_ULL(0xfffffffffffffff8) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                 << 3U)) 
                                                             | (QData)((IData)(
                                                                               (7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                           ^ 
                                                           ((VL_ULL(0xfffffffffe000000) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                << 0x19U)) 
                                                            | (QData)((IData)(
                                                                              (0x1ffffffU 
                                                                               & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))
                                                          : 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            ^ 
                                                            ((VL_ULL(0xfffffffffffffff8) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                 << 3U)) 
                                                             | (QData)((IData)(
                                                                               (7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                           ^ 
                                                           ((VL_ULL(0xfffffffffe000000) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                << 0x19U)) 
                                                            | (QData)((IData)(
                                                                              (0x1ffffffU 
                                                                               & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))))
                                                        : 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffffffff8) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 3U)) 
                                                          | (QData)((IData)(
                                                                            (7U 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffe000000) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 0x19U)) 
                                                         | (QData)((IData)(
                                                                           (0x1ffffffU 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))))
                                                      : 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))))))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffffffff8) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 3U)) 
                                                          | (QData)((IData)(
                                                                            (7U 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffe000000) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 0x19U)) 
                                                         | (QData)((IData)(
                                                                           (0x1ffffffU 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          ^ 
                                                          ((VL_ULL(0xfffffffffffffff8) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                               << 3U)) 
                                                           | (QData)((IData)(
                                                                             (7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffe000000) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 0x19U)) 
                                                          | (QData)((IData)(
                                                                            (0x1ffffffU 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            ^ 
                                                            ((VL_ULL(0xfffffffffffffff8) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                 << 3U)) 
                                                             | (QData)((IData)(
                                                                               (7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                           ^ 
                                                           ((VL_ULL(0xfffffffffe000000) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                << 0x19U)) 
                                                            | (QData)((IData)(
                                                                              (0x1ffffffU 
                                                                               & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))
                                                          : 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            ^ 
                                                            ((VL_ULL(0xfffffffffffffff8) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                 << 3U)) 
                                                             | (QData)((IData)(
                                                                               (7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                           ^ 
                                                           ((VL_ULL(0xfffffffffe000000) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                << 0x19U)) 
                                                            | (QData)((IData)(
                                                                              (0x1ffffffU 
                                                                               & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U])))))))))
                                                     : 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                       : VL_ULL(0)))))));
}

void VASCON_AEAD_ASCON_AEAD::_settle__TOP__ASCON_AEAD__5(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VASCON_AEAD_ASCON_AEAD::_settle__TOP__ASCON_AEAD__5\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__ASCON_AEAD.CTblock = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0 
                                        ^ vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado);
    vlSymsp->TOP__ASCON_AEAD.__PVT__Xi0 = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                            ? ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? VL_ULL(0x80400c0600000000)
                                                       : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0))
                                                    : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0))
                                            : ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                                        ? vlSymsp->TOP__ASCON_AEAD.CTblock
                                                        : 
                                                       (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado 
                                                        ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? vlSymsp->TOP__ASCON_AEAD.CTblock
                                                        : 
                                                       (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado 
                                                        ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)))
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 
                                                       (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado 
                                                        ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)
                                                        : vlSymsp->TOP__ASCON_AEAD.CTblock)))
                                                     : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                       : VL_ULL(0)))))));
}

VL_INLINE_OPT void VASCON_AEAD_ASCON_AEAD::_combo__TOP__ASCON_AEAD__6(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VASCON_AEAD_ASCON_AEAD::_combo__TOP__ASCON_AEAD__6\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
        vlSymsp->TOP__ASCON_AEAD.read = 0U;
    } else {
        if ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
            if ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                vlSymsp->TOP__ASCON_AEAD.read = (1U 
                                                 & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 2U) 
                                                    & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                        >> 1U) 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))));
            } else {
                if ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                    vlSymsp->TOP__ASCON_AEAD.read = 0U;
                } else {
                    if ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                        if ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                            vlSymsp->TOP__ASCON_AEAD.read = 1U;
                        } else {
                            vlSymsp->TOP__ASCON_AEAD.read = 0U;
                            if (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq) {
                                if ((8U != (IData)(vlTOPp->PTlen))) {
                                    if ((8U == (IData)(vlTOPp->PTlen))) {
                                        vlSymsp->TOP__ASCON_AEAD.read = 0U;
                                    }
                                }
                            }
                        }
                    } else {
                        vlSymsp->TOP__ASCON_AEAD.read = 0U;
                    }
                }
            }
        } else {
            if ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                if ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                    if ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                        vlSymsp->TOP__ASCON_AEAD.read 
                            = ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                               & (IData)(vlTOPp->startAD));
                    } else {
                        if ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))) {
                            vlSymsp->TOP__ASCON_AEAD.read = 0U;
                        } else {
                            vlSymsp->TOP__ASCON_AEAD.read = 0U;
                            if ((1U & (~ (IData)(vlTOPp->startAD)))) {
                                if ((8U != (IData)(vlTOPp->PTlen))) {
                                    if ((8U == (IData)(vlTOPp->PTlen))) {
                                        vlSymsp->TOP__ASCON_AEAD.read = 0U;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    vlSymsp->TOP__ASCON_AEAD.read = 0U;
                }
            } else {
                vlSymsp->TOP__ASCON_AEAD.read = 0U;
            }
        }
    }
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
        = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
            ? ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? vlTOPp->PTblock : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                      ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? vlTOPp->PTblock
                                          : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                              ? ((1U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? 
                                                 ((IData)(vlTOPp->startAD)
                                                   ? vlTOPp->ADblock
                                                   : vlTOPp->PTblock)
                                                  : vlTOPp->PTblock)
                                              : vlTOPp->PTblock))
                                      : vlTOPp->PTblock))
            : ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? vlTOPp->PTblock : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? vlTOPp->PTblock
                                          : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                              ? ((1U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? vlTOPp->PTblock
                                                  : 
                                                 ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                   ? vlTOPp->PTblock
                                                   : vlTOPp->ADblock))
                                              : vlTOPp->ADblock)))
                : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? vlTOPp->ADblock : ((1U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? vlTOPp->ADblock
                                                  : 
                                                 ((IData)(vlTOPp->startAD)
                                                   ? vlTOPp->ADblock
                                                   : vlTOPp->PTblock)))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock))))
                    : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? vlTOPp->ADblock
                                    : vlTOPp->PTblock)
                                : VL_ULL(0)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen 
        = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
            ? ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? (IData)(vlTOPp->PTlen) : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                             ? ((4U 
                                                 & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                 ? (IData)(vlTOPp->PTlen)
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 
                                                  ((IData)(vlTOPp->startAD)
                                                    ? (IData)(vlTOPp->ADlen)
                                                    : (IData)(vlTOPp->PTlen))
                                                   : (IData)(vlTOPp->PTlen))
                                                  : (IData)(vlTOPp->PTlen)))
                                             : (IData)(vlTOPp->PTlen)))
            : ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? (IData)(vlTOPp->PTlen) : ((4U 
                                                 & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                 ? (IData)(vlTOPp->PTlen)
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? (IData)(vlTOPp->PTlen)
                                                   : 
                                                  ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                    ? (IData)(vlTOPp->PTlen)
                                                    : (IData)(vlTOPp->ADlen)))
                                                  : (IData)(vlTOPp->ADlen))))
                : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? (IData)(vlTOPp->ADlen)
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? (IData)(vlTOPp->ADlen)
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen)))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen)))))
                    : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen)))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen)))
                            : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? ((IData)(vlTOPp->startAD)
                                    ? (IData)(vlTOPp->ADlen)
                                    : (IData)(vlTOPp->PTlen))
                                : 0U))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__Xi4 = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                            ? ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        vlTOPp->nonce[1U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlTOPp->nonce[0U])))
                                                       : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4))
                                                    : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4))
                                            : ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        (VL_ULL(1) 
                                                         ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (VL_ULL(1) 
                                                          ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)
                                                          : 
                                                         (VL_ULL(1) 
                                                          ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)))
                                                        : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4))
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 
                                                       (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        (VL_ULL(1) 
                                                         ^ 
                                                         (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U])))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (VL_ULL(1) 
                                                          ^ 
                                                          (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U])))))
                                                          : 
                                                         (VL_ULL(1) 
                                                          ^ 
                                                          (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))))))))
                                                     : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4)
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4
                                                       : VL_ULL(0)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__nstate 
        = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
            ? ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? 0U : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                         ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                             ? 0U : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                      ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? 1U : 0U)
                                      : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                          ? 0x2aU : 0x29U)))
                         : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                             ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                 ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0x28U : 0x27U)
                                 : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0x26U : 0x25U))
                             : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                 ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0x24U : 0x23U)
                                 : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0x22U : 0x21U)))))
            : ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                ? ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 0x20U : 0U) : 0U)
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? 0U : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                     ? 0U : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                              ? 0x13U
                                              : 0x1fU))))
                    : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 0x18U : 0x17U) : 
                           ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                             ? 0x16U : 0x15U)) : ((2U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 0x14U
                                                    : 
                                                   ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                     ? 
                                                    ((8U 
                                                      == (IData)(vlTOPp->PTlen))
                                                      ? 0x13U
                                                      : 0x1fU)
                                                     : 0xdU))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 0x12U
                                                    : 0x11U))))
                : ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                    ? ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 0x10U : 0xfU) : (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 0xeU
                                                    : 
                                                   ((IData)(vlTOPp->startAD)
                                                     ? 0xdU
                                                     : 
                                                    ((8U 
                                                      == (IData)(vlTOPp->PTlen))
                                                      ? 0x13U
                                                      : 0x1fU))))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 0xcU : 0xbU) : ((1U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 0xaU
                                                   : 9U)))
                    : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                        ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 8U : 7U) : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                               ? 6U
                                               : 5U))
                        : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                            ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                ? 4U : 3U) : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                               ? 2U
                                               : ((IData)(vlTOPp->start)
                                                   ? 0x2bU
                                                   : 0U)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__Xi2 = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                            ? ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                    ^ 
                                                    (((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                      << 0x3fU) 
                                                     | (VL_ULL(0x7fffffffffffffff) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                           >> 1U)))) 
                                                   ^ 
                                                   (((QData)((IData)(
                                                                     (0x3fU 
                                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                     << 0x3aU) 
                                                    | (VL_ULL(0x3ffffffffffffff) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                          >> 6U))))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        vlTOPp->key[1U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlTOPp->key[0U])))
                                                       : 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U)))))
                                                      : 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U))))))
                                                    : 
                                                   ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (1U 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3fU) 
                                                      | (VL_ULL(0x7fffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 1U)))) 
                                                    ^ 
                                                    (((QData)((IData)(
                                                                      (0x3fU 
                                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                      << 0x3aU) 
                                                     | (VL_ULL(0x3ffffffffffffff) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                           >> 6U))))))
                                            : ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U))))
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                                        ? 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (1U 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3fU) 
                                                          | (VL_ULL(0x7fffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 1U)))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (0x3fU 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3aU) 
                                                         | (VL_ULL(0x3ffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 6U))))
                                                        : 
                                                       (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            (1U 
                                                                             & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                            << 0x3fU) 
                                                           | (VL_ULL(0x7fffffffffffffff) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                 >> 1U)))) 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (0x3fU 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3aU) 
                                                          | (VL_ULL(0x3ffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 6U)))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U))))
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            (1U 
                                                                             & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                            << 0x3fU) 
                                                           | (VL_ULL(0x7fffffffffffffff) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                 >> 1U)))) 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (0x3fU 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3aU) 
                                                          | (VL_ULL(0x3ffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 6U))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            ^ 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                              << 0x3fU) 
                                                             | (VL_ULL(0x7fffffffffffffff) 
                                                                & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                   >> 1U)))) 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             (0x3fU 
                                                                              & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                             << 0x3aU) 
                                                            | (VL_ULL(0x3ffffffffffffff) 
                                                               & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                  >> 6U)))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))
                                                          : 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            ^ 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                              << 0x3fU) 
                                                             | (VL_ULL(0x7fffffffffffffff) 
                                                                & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                   >> 1U)))) 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             (0x3fU 
                                                                              & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                             << 0x3aU) 
                                                            | (VL_ULL(0x3ffffffffffffff) 
                                                               & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                  >> 6U)))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))))
                                                        : 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (1U 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3fU) 
                                                          | (VL_ULL(0x7fffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 1U)))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (0x3fU 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3aU) 
                                                         | (VL_ULL(0x3ffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 6U))))))
                                                      : 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U)))))))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U))))
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (1U 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3fU) 
                                                          | (VL_ULL(0x7fffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 1U)))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (0x3fU 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3aU) 
                                                         | (VL_ULL(0x3ffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 6U))))
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            (1U 
                                                                             & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                            << 0x3fU) 
                                                           | (VL_ULL(0x7fffffffffffffff) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                 >> 1U)))) 
                                                         ^ 
                                                         (((QData)((IData)(
                                                                           (0x3fU 
                                                                            & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                           << 0x3aU) 
                                                          | (VL_ULL(0x3ffffffffffffff) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                >> 6U))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            ^ 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                              << 0x3fU) 
                                                             | (VL_ULL(0x7fffffffffffffff) 
                                                                & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                   >> 1U)))) 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             (0x3fU 
                                                                              & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                             << 0x3aU) 
                                                            | (VL_ULL(0x3ffffffffffffff) 
                                                               & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                  >> 6U)))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]))))
                                                          : 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            ^ 
                                                            (((QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                              << 0x3fU) 
                                                             | (VL_ULL(0x7fffffffffffffff) 
                                                                & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                   >> 1U)))) 
                                                           ^ 
                                                           (((QData)((IData)(
                                                                             (0x3fU 
                                                                              & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                             << 0x3aU) 
                                                            | (VL_ULL(0x3ffffffffffffff) 
                                                               & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                                  >> 6U)))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U])))))))))
                                                     : 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U)))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3fU) 
                                                       | (VL_ULL(0x7fffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 1U)))) 
                                                     ^ 
                                                     (((QData)((IData)(
                                                                       (0x3fU 
                                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                       << 0x3aU) 
                                                      | (VL_ULL(0x3ffffffffffffff) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                            >> 6U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3fU) 
                                                        | (VL_ULL(0x7fffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 1U)))) 
                                                      ^ 
                                                      (((QData)((IData)(
                                                                        (0x3fU 
                                                                         & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                        << 0x3aU) 
                                                       | (VL_ULL(0x3ffffffffffffff) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                             >> 6U))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                          << 0x3fU) 
                                                         | (VL_ULL(0x7fffffffffffffff) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                               >> 1U)))) 
                                                       ^ 
                                                       (((QData)((IData)(
                                                                         (0x3fU 
                                                                          & (IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2)))) 
                                                         << 0x3aU) 
                                                        | (VL_ULL(0x3ffffffffffffff) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2 
                                                              >> 6U))))
                                                       : VL_ULL(0)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__Xi1 = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                            ? ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                    ^ 
                                                    ((VL_ULL(0xfffffffffffffff8) 
                                                      & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         << 3U)) 
                                                     | (QData)((IData)(
                                                                       (7U 
                                                                        & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                   ^ 
                                                   ((VL_ULL(0xfffffffffe000000) 
                                                     & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        << 0x19U)) 
                                                    | (QData)((IData)(
                                                                      (0x1ffffffU 
                                                                       & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        vlTOPp->key[3U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlTOPp->key[2U])))
                                                       : 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))))
                                                      : 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))))
                                                    : 
                                                   ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffffffff8) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 3U)) 
                                                      | (QData)((IData)(
                                                                        (7U 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                    ^ 
                                                    ((VL_ULL(0xfffffffffe000000) 
                                                      & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         << 0x19U)) 
                                                     | (QData)((IData)(
                                                                       (0x1ffffffU 
                                                                        & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))))
                                            : ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                                        ? 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffffffff8) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 3U)) 
                                                          | (QData)((IData)(
                                                                            (7U 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffe000000) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 0x19U)) 
                                                         | (QData)((IData)(
                                                                           (0x1ffffffU 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                        : 
                                                       (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          ^ 
                                                          ((VL_ULL(0xfffffffffffffff8) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                               << 3U)) 
                                                           | (QData)((IData)(
                                                                             (7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffe000000) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 0x19U)) 
                                                          | (QData)((IData)(
                                                                            (0x1ffffffU 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                        ^ 
                                                        (((QData)((IData)(
                                                                          vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          ^ 
                                                          ((VL_ULL(0xfffffffffffffff8) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                               << 3U)) 
                                                           | (QData)((IData)(
                                                                             (7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffe000000) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 0x19U)) 
                                                          | (QData)((IData)(
                                                                            (0x1ffffffU 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            ^ 
                                                            ((VL_ULL(0xfffffffffffffff8) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                 << 3U)) 
                                                             | (QData)((IData)(
                                                                               (7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                           ^ 
                                                           ((VL_ULL(0xfffffffffe000000) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                << 0x19U)) 
                                                            | (QData)((IData)(
                                                                              (0x1ffffffU 
                                                                               & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))
                                                          : 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            ^ 
                                                            ((VL_ULL(0xfffffffffffffff8) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                 << 3U)) 
                                                             | (QData)((IData)(
                                                                               (7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                           ^ 
                                                           ((VL_ULL(0xfffffffffe000000) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                << 0x19U)) 
                                                            | (QData)((IData)(
                                                                              (0x1ffffffU 
                                                                               & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))))
                                                        : 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffffffff8) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 3U)) 
                                                          | (QData)((IData)(
                                                                            (7U 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffe000000) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 0x19U)) 
                                                         | (QData)((IData)(
                                                                           (0x1ffffffU 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))))
                                                      : 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))))))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 
                                                       ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffffffff8) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 3U)) 
                                                          | (QData)((IData)(
                                                                            (7U 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffe000000) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 0x19U)) 
                                                         | (QData)((IData)(
                                                                           (0x1ffffffU 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 
                                                        ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          ^ 
                                                          ((VL_ULL(0xfffffffffffffff8) 
                                                            & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                               << 3U)) 
                                                           | (QData)((IData)(
                                                                             (7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                         ^ 
                                                         ((VL_ULL(0xfffffffffe000000) 
                                                           & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                              << 0x19U)) 
                                                          | (QData)((IData)(
                                                                            (0x1ffffffU 
                                                                             & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                         : 
                                                        ((8U 
                                                          != (IData)(vlTOPp->PTlen))
                                                          ? 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            ^ 
                                                            ((VL_ULL(0xfffffffffffffff8) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                 << 3U)) 
                                                             | (QData)((IData)(
                                                                               (7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                           ^ 
                                                           ((VL_ULL(0xfffffffffe000000) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                << 0x19U)) 
                                                            | (QData)((IData)(
                                                                              (0x1ffffffU 
                                                                               & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]))))
                                                          : 
                                                         (((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            ^ 
                                                            ((VL_ULL(0xfffffffffffffff8) 
                                                              & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                 << 3U)) 
                                                             | (QData)((IData)(
                                                                               (7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                           ^ 
                                                           ((VL_ULL(0xfffffffffe000000) 
                                                             & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                << 0x19U)) 
                                                            | (QData)((IData)(
                                                                              (0x1ffffffU 
                                                                               & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))) 
                                                          ^ 
                                                          (((QData)((IData)(
                                                                            vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U])))))))))
                                                     : 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U))))))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffffffff8) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 3U)) 
                                                       | (QData)((IData)(
                                                                         (7U 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                     ^ 
                                                     ((VL_ULL(0xfffffffffe000000) 
                                                       & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                          << 0x19U)) 
                                                      | (QData)((IData)(
                                                                        (0x1ffffffU 
                                                                         & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffffffff8) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 3U)) 
                                                        | (QData)((IData)(
                                                                          (7U 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                      ^ 
                                                      ((VL_ULL(0xfffffffffe000000) 
                                                        & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                           << 0x19U)) 
                                                       | (QData)((IData)(
                                                                         (0x1ffffffU 
                                                                          & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 
                                                      ((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                        ^ 
                                                        ((VL_ULL(0xfffffffffffffff8) 
                                                          & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                             << 3U)) 
                                                         | (QData)((IData)(
                                                                           (7U 
                                                                            & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x3dU))))))) 
                                                       ^ 
                                                       ((VL_ULL(0xfffffffffe000000) 
                                                         & (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                            << 0x19U)) 
                                                        | (QData)((IData)(
                                                                          (0x1ffffffU 
                                                                           & (IData)(
                                                                                (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1 
                                                                                >> 0x27U)))))))
                                                       : VL_ULL(0)))))));
    vlSymsp->TOP__ASCON_AEAD.__PVT__consti = ((0x20U 
                                               & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                               ? 0U
                                               : ((0x10U 
                                                   & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 0U
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                                        ? 6U
                                                        : 0U))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 6U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 6U
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 6U
                                                         : 0U)
                                                        : 6U))
                                                      : 6U)))
                                                   : 
                                                  ((8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 6U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? 6U
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 6U
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlTOPp->PTlen))
                                                         ? 6U
                                                         : 0U))))
                                                     : 0U)
                                                    : 0U)));
    vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado 
        = ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
            ? vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock
            : ((4U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                ? ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                    ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                        ? (VL_ULL(0x80) | (VL_ULL(0xffffffffffffff00) 
                                           & vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock))
                        : (VL_ULL(0x8000) | (VL_ULL(0xffffffffffff0000) 
                                             & vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock)))
                    : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                        ? (VL_ULL(0x800000) | (VL_ULL(0xffffffffff000000) 
                                               & vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock))
                        : (VL_ULL(0x80000000) | ((QData)((IData)(
                                                                 (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
                                                                  >> 0x20U))) 
                                                 << 0x20U))))
                : ((2U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                    ? ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                        ? (VL_ULL(0x8000000000) | ((QData)((IData)(
                                                                   (0xffffffU 
                                                                    & (IData)(
                                                                              (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
                                                                               >> 0x28U))))) 
                                                   << 0x28U))
                        : (VL_ULL(0x800000000000) | 
                           ((QData)((IData)((0xffffU 
                                             & (IData)(
                                                       (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
                                                        >> 0x30U))))) 
                            << 0x30U))) : ((1U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                            ? (VL_ULL(0x80000000000000) 
                                               | ((QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(
                                                                             (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datablock 
                                                                              >> 0x38U))))) 
                                                  << 0x38U))
                                            : VL_ULL(0x8000000000000000)))));
    vlSymsp->TOP__ASCON_AEAD.CTblock = (vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0 
                                        ^ vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado);
    vlSymsp->TOP__ASCON_AEAD.__PVT__Xi0 = ((0x20U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                            ? ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? VL_ULL(0x80400c0600000000)
                                                       : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0))
                                                    : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0))
                                            : ((0x10U 
                                                & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                       : 
                                                      ((8U 
                                                        & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__datalen))
                                                        ? vlSymsp->TOP__ASCON_AEAD.CTblock
                                                        : 
                                                       (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado 
                                                        ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                       : 
                                                      ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq)
                                                        ? vlSymsp->TOP__ASCON_AEAD.CTblock
                                                        : 
                                                       (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado 
                                                        ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)))
                                                      : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                       : 
                                                      ((IData)(vlTOPp->startAD)
                                                        ? 
                                                       (vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__pado 
                                                        ^ vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)
                                                        : vlSymsp->TOP__ASCON_AEAD.CTblock)))
                                                     : vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0)
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                     ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                      ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                                       ? vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo0
                                                       : VL_ULL(0)))))));
}

void VASCON_AEAD_ASCON_AEAD::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VASCON_AEAD_ASCON_AEAD::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    start = VL_RAND_RESET_I(1);
    startAD = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, key);
    VL_RAND_RESET_W(128, nonce);
    ADblock = VL_RAND_RESET_Q(64);
    PTblock = VL_RAND_RESET_Q(64);
    PTlen = VL_RAND_RESET_I(4);
    ADlen = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(128, T);
    CTblock = VL_RAND_RESET_Q(64);
    CTv = VL_RAND_RESET_I(1);
    Tv = VL_RAND_RESET_I(1);
    read = VL_RAND_RESET_I(1);
    XsboxIN0 = VL_RAND_RESET_Q(64);
    XsboxIN1 = VL_RAND_RESET_Q(64);
    XsboxIN2 = VL_RAND_RESET_Q(64);
    XsboxIN3 = VL_RAND_RESET_Q(64);
    XsboxIN4 = VL_RAND_RESET_Q(64);
    Xsbox0 = VL_RAND_RESET_Q(64);
    Xsbox1 = VL_RAND_RESET_Q(64);
    Xsbox2 = VL_RAND_RESET_Q(64);
    Xsbox3 = VL_RAND_RESET_Q(64);
    Xsbox4 = VL_RAND_RESET_Q(64);
    p0 = VL_RAND_RESET_Q(64);
    p1 = VL_RAND_RESET_Q(64);
    p2 = VL_RAND_RESET_Q(64);
    __PVT__intial = VL_RAND_RESET_I(1);
    __PVT__inc = VL_RAND_RESET_I(1);
    __PVT__consti = VL_RAND_RESET_I(4);
    __PVT__Xi0 = VL_RAND_RESET_Q(64);
    __PVT__Xi1 = VL_RAND_RESET_Q(64);
    __PVT__Xi2 = VL_RAND_RESET_Q(64);
    __PVT__Xi4 = VL_RAND_RESET_Q(64);
    __PVT__asconcont1__DOT__cstate = VL_RAND_RESET_I(6);
    __PVT__asconcont1__DOT__nstate = VL_RAND_RESET_I(6);
    __PVT__asconcont1__DOT__datablock = VL_RAND_RESET_Q(64);
    __PVT__asconcont1__DOT__datalen = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(128, __PVT__asconcont1__DOT__keyreg);
    __PVT__asconcont1__DOT__pado = VL_RAND_RESET_Q(64);
    __PVT__asconcont1__DOT__lastassoq = VL_RAND_RESET_I(1);
}
