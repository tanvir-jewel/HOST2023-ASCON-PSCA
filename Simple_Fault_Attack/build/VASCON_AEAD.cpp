// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VASCON_AEAD.h for the primary calling header

#include "VASCON_AEAD.h"
#include "VASCON_AEAD__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(VASCON_AEAD) {
    VASCON_AEAD__Syms* __restrict vlSymsp = __VlSymsp = new VASCON_AEAD__Syms(this, name());
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(ASCON_AEAD, VASCON_AEAD_ASCON_AEAD);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VASCON_AEAD::__Vconfigure(VASCON_AEAD__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VASCON_AEAD::~VASCON_AEAD() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VASCON_AEAD::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VASCON_AEAD::eval\n"); );
    VASCON_AEAD__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ASCON_AEAD.v", 23, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VASCON_AEAD::_eval_initial_loop(VASCON_AEAD__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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
            VL_FATAL_MT("ASCON_AEAD.v", 23, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VASCON_AEAD::_sequent__TOP__1(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_sequent__TOP__1\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->XsboxIN0 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg0;
    vlTOPp->XsboxIN1 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg1;
    vlTOPp->XsboxIN4 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg4;
    vlTOPp->XsboxIN3 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg3;
}

VL_INLINE_OPT void VASCON_AEAD::_sequent__TOP__2(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_sequent__TOP__2\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Xsbox4 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4;
    vlTOPp->Tv = vlSymsp->TOP__ASCON_AEAD.Tv;
    vlTOPp->XsboxIN2 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xark2;
}

VL_INLINE_OPT void VASCON_AEAD::_sequent__TOP__3(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_sequent__TOP__3\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Xsbox2 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2;
    vlTOPp->Xsbox3 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3;
    vlTOPp->Xsbox1 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1;
    vlTOPp->Xsbox0 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0;
    vlTOPp->p2 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p2;
    vlTOPp->p1 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p1;
    vlTOPp->p0 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p0;
}

VL_INLINE_OPT void VASCON_AEAD::_sequent__TOP__4(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_sequent__TOP__4\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->T[0U] = ((IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4) 
                     ^ vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[0U]);
    vlTOPp->T[1U] = ((IData)((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo4 
                              >> 0x20U)) ^ vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[1U]);
    vlTOPp->T[2U] = ((IData)(vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3) 
                     ^ vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[2U]);
    vlTOPp->T[3U] = ((IData)((vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xo3 
                              >> 0x20U)) ^ vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__keyreg[3U]);
}

void VASCON_AEAD::_settle__TOP__5(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_settle__TOP__5\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->XsboxIN4 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg4;
    vlTOPp->XsboxIN3 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg3;
    vlTOPp->XsboxIN1 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg1;
    vlTOPp->XsboxIN0 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1.__PVT__Xreg0;
    vlTOPp->CTv = (1U & ((~ ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                             >> 5U)) & ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                         ? ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                             ? ((~ 
                                                 ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                  >> 2U)) 
                                                & ((~ 
                                                    ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 1U)) 
                                                   & (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))
                                             : ((~ 
                                                 ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                  >> 2U)) 
                                                & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 1U) 
                                                   & ((~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)) 
                                                      & ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq) 
                                                         & ((8U 
                                                             == (IData)(vlTOPp->PTlen)) 
                                                            | (8U 
                                                               != (IData)(vlTOPp->PTlen))))))))
                                         : (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                             >> 3U) 
                                            & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                >> 2U) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 1U)) 
                                                  & ((~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)) 
                                                     & ((~ (IData)(vlTOPp->startAD)) 
                                                        & ((8U 
                                                            == (IData)(vlTOPp->PTlen)) 
                                                           | (8U 
                                                              != (IData)(vlTOPp->PTlen)))))))))));
}

void VASCON_AEAD::_settle__TOP__6(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_settle__TOP__6\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Xsbox4 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4;
    vlTOPp->XsboxIN2 = vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1.__PVT__Xark2;
    vlTOPp->Tv = vlSymsp->TOP__ASCON_AEAD.Tv;
    vlTOPp->read = vlSymsp->TOP__ASCON_AEAD.read;
}

void VASCON_AEAD::_settle__TOP__9(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_settle__TOP__9\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->CTblock = vlSymsp->TOP__ASCON_AEAD.CTblock;
}

VL_INLINE_OPT void VASCON_AEAD::_combo__TOP__10(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_combo__TOP__10\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->CTv = (1U & ((~ ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                             >> 5U)) & ((0x10U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                         ? ((8U & (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))
                                             ? ((~ 
                                                 ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                  >> 2U)) 
                                                & ((~ 
                                                    ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                     >> 1U)) 
                                                   & (~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate))))
                                             : ((~ 
                                                 ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                  >> 2U)) 
                                                & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 1U) 
                                                   & ((~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)) 
                                                      & ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__lastassoq) 
                                                         & ((8U 
                                                             == (IData)(vlTOPp->PTlen)) 
                                                            | (8U 
                                                               != (IData)(vlTOPp->PTlen))))))))
                                         : (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                             >> 3U) 
                                            & (((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                >> 2U) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate) 
                                                    >> 1U)) 
                                                  & ((~ (IData)(vlSymsp->TOP__ASCON_AEAD.__PVT__asconcont1__DOT__cstate)) 
                                                     & ((~ (IData)(vlTOPp->startAD)) 
                                                        & ((8U 
                                                            == (IData)(vlTOPp->PTlen)) 
                                                           | (8U 
                                                              != (IData)(vlTOPp->PTlen)))))))))));
}

VL_INLINE_OPT void VASCON_AEAD::_combo__TOP__11(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_combo__TOP__11\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->read = vlSymsp->TOP__ASCON_AEAD.read;
    vlTOPp->CTblock = vlSymsp->TOP__ASCON_AEAD.CTblock;
}

void VASCON_AEAD::_eval(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_eval\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->rst) & (~ (IData)(vlTOPp->__Vclklast__TOP__rst))))) {
        vlSymsp->TOP__ASCON_AEAD._sequent__TOP__ASCON_AEAD__1(vlSymsp);
        vlSymsp->TOP__ASCON_AEAD__ascondatapath1._sequent__TOP__ASCON_AEAD__ascondatapath1__1(vlSymsp);
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1._sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__1(vlSymsp);
        vlSymsp->TOP__ASCON_AEAD._sequent__TOP__ASCON_AEAD__2(vlSymsp);
        vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1._sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__1(vlSymsp);
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1._sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__2(vlSymsp);
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1._sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__2(vlSymsp);
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__10(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD._combo__TOP__ASCON_AEAD__6(vlSymsp);
    vlTOPp->_combo__TOP__11(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1._settle__TOP__ASCON_AEAD__ascondatapath1__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

void VASCON_AEAD::_eval_initial(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_eval_initial\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

void VASCON_AEAD::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::final\n"); );
    // Variables
    VASCON_AEAD__Syms* __restrict vlSymsp = this->__VlSymsp;
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VASCON_AEAD::_eval_settle(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_eval_settle\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1._settle__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__3(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1._sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__1(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD._settle__TOP__ASCON_AEAD__3(vlSymsp);
    vlTOPp->_settle__TOP__6(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1._sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1__2(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1._settle__TOP__ASCON_AEAD__ascondatapath1__2(vlSymsp);
    vlTOPp->_sequent__TOP__3(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD._settle__TOP__ASCON_AEAD__4(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD__ascondatapath1__asconRF1._sequent__TOP__ASCON_AEAD__ascondatapath1__asconRF1__2(vlSymsp);
    vlTOPp->_sequent__TOP__4(vlSymsp);
    vlSymsp->TOP__ASCON_AEAD._settle__TOP__ASCON_AEAD__5(vlSymsp);
    vlTOPp->_settle__TOP__9(vlSymsp);
}

VL_INLINE_OPT QData VASCON_AEAD::_change_request(VASCON_AEAD__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_change_request\n"); );
    VASCON_AEAD* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VASCON_AEAD::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((start & 0xfeU))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY((startAD & 0xfeU))) {
        Verilated::overWidthError("startAD");}
    if (VL_UNLIKELY((PTlen & 0xf0U))) {
        Verilated::overWidthError("PTlen");}
    if (VL_UNLIKELY((ADlen & 0xf0U))) {
        Verilated::overWidthError("ADlen");}
}
#endif  // VL_DEBUG

void VASCON_AEAD::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VASCON_AEAD::_ctor_var_reset\n"); );
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
}
