// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VASCON_AEAD__Syms.h"
#include "VASCON_AEAD.h"
#include "VASCON_AEAD_ASCON_AEAD.h"
#include "VASCON_AEAD_ASCON_DATAPATH.h"
#include "VASCON_AEAD_ASCON_ROUND_FUNCTION.h"
#include "VASCON_AEAD_ASCON_SBOX.h"



// FUNCTIONS
VASCON_AEAD__Syms::VASCON_AEAD__Syms(VASCON_AEAD* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__ASCON_AEAD(Verilated::catName(topp->name(), "ASCON_AEAD"))
    , TOP__ASCON_AEAD__ascondatapath1(Verilated::catName(topp->name(), "ASCON_AEAD.ascondatapath1"))
    , TOP__ASCON_AEAD__ascondatapath1__asconRF1(Verilated::catName(topp->name(), "ASCON_AEAD.ascondatapath1.asconRF1"))
    , TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1(Verilated::catName(topp->name(), "ASCON_AEAD.ascondatapath1.asconRF1.asconsbox1"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->ASCON_AEAD = &TOP__ASCON_AEAD;
    TOPp->ASCON_AEAD->ascondatapath1 = &TOP__ASCON_AEAD__ascondatapath1;
    TOPp->ASCON_AEAD->ascondatapath1->asconRF1 = &TOP__ASCON_AEAD__ascondatapath1__asconRF1;
    TOPp->ASCON_AEAD->ascondatapath1->asconRF1->asconsbox1 = &TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__ASCON_AEAD.__Vconfigure(this, true);
    TOP__ASCON_AEAD__ascondatapath1.__Vconfigure(this, true);
    TOP__ASCON_AEAD__ascondatapath1__asconRF1.__Vconfigure(this, true);
    TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.__Vconfigure(this, true);
    // Setup scopes
    __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.configure(this, name(), "ASCON_AEAD.ascondatapath1.asconRF1.asconsbox1", "asconsbox1", VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.varInsert(__Vfinal,"Xsb0", &(TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb0), VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.varInsert(__Vfinal,"Xsb1", &(TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb1), VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.varInsert(__Vfinal,"Xsb2", &(TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb2), VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.varInsert(__Vfinal,"Xsb3", &(TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb3), VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.varInsert(__Vfinal,"Xsb4", &(TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.Xsb4), VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.varInsert(__Vfinal,"p0", &(TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p0), VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.varInsert(__Vfinal,"p1", &(TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p1), VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.varInsert(__Vfinal,"p2", &(TOP__ASCON_AEAD__ascondatapath1__asconRF1__asconsbox1.p2), VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,1 ,63,0);
    }
}
