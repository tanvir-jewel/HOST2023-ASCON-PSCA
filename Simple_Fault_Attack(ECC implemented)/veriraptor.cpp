#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <assert.h>
#include <memory>
#include <iomanip>
#include <chrono>
#include <random>
#include <fstream>
#include <bitset>

#include "VASCON_AEAD.h"
#include "VASCON_AEAD_ASCON_AEAD.h"
#include "VASCON_AEAD_ASCON_SBOX.h"
#include "VASCON_AEAD_ASCON_ROUND_FUNCTION.h"
#include "VASCON_AEAD_ASCON_DATAPATH.h"
vluint64_t sim_time = 0;
#define MAX_TIME 200

template <typename T>

void userIn(const char * var_name, T & var)
{
    unsigned tmp;
    std::cout << var_name << " = ";
    std::cin >> tmp;
    assert(tmp <= 0xffffffff);
    var = tmp;
}

void userOut(const char * var_name, unsigned value)
{
    std::cout << var_name << " = " << std::hex << value << '\n';
}
void write_result_for_ecc_parity(std::unique_ptr<VASCON_AEAD>& top, std::ofstream& file, bool verbose) {
    std::bitset<64> x5(top->p0);
    file << x5 << " ";
    std::bitset<64> x6(top->p1);
    file << x6 << " ";
    std::bitset<64> x7(top->p2);
    file << x7 << "\n";
    // file << std::hex << top->Xsbox0 << " ";
    // file << std::hex << top->Xsbox1 << " ";
    // file << std::hex << top->Xsbox2 << " ";
    // file << std::hex << top->Xsbox3 << " ";
    // file << std::hex << top->Xsbox4 << " ";
    // file << std::hex << top->p0 << " ";
    // file << std::hex << top->p1 << " ";
    // file << std::hex << top->p2 << '\n';
    if (verbose) {
        std::cout << top->XsboxIN0 << " ";
        std::cout << top->XsboxIN1 << " ";
        std::cout << top->XsboxIN2 << " ";
        std::cout << top->XsboxIN3 << " ";
        std::cout << top->XsboxIN4 << " ";
        std::cout << top->p0 << " ";
        std::cout << top->p1 << " ";
        std::cout << top->p2 << '\n';
    }
}

void write_result_for_ecc_in(std::unique_ptr<VASCON_AEAD>& top, std::ofstream& file, bool verbose) {
    std::bitset<64> x(top->XsboxIN0);
    file << x << " ";
    std::bitset<64> x1(top->XsboxIN1);
    file << x1 << " ";
    std::bitset<64> x2(top->XsboxIN2);
    file << x2 << " ";
    std::bitset<64> x3(top->XsboxIN3);
    file << x3 << " ";
    std::bitset<64> x4(top->XsboxIN4);
    file << x4 << " ";
    // file << std::hex << top->XsboxIN0 << " ";
    // file << std::hex << top->XsboxIN1 << " ";
    // file << std::hex << top->XsboxIN2 << " ";
    // file << std::hex << top->XsboxIN3 << " ";
    // file << std::hex << top->XsboxIN4 << " ";

    if (verbose) {
        std::cout << top->XsboxIN0 << " ";
        std::cout << top->XsboxIN1 << " ";
        std::cout << top->XsboxIN2 << " ";
        std::cout << top->XsboxIN3 << " ";
        std::cout << top->XsboxIN4 << " ";
        std::cout << top->p0 << " ";
        std::cout << top->p1 << " ";
        std::cout << top->p2 << '\n';
    }
}

void write_result_for_ecc(std::unique_ptr<VASCON_AEAD>& top, std::ofstream& file, bool verbose) {
    std::bitset<64> x(top->XsboxIN0);
    file << x << " ";
    std::bitset<64> x1(top->XsboxIN1);
    file << x1 << " ";
    std::bitset<64> x2(top->XsboxIN2);
    file << x2 << " ";
    std::bitset<64> x3(top->XsboxIN3);
    file << x3 << " ";
    std::bitset<64> x4(top->XsboxIN4);
    file << x4 << " ";
    // // std::bitset<64> x02(top->Xsbox0);
    // // file << x02 << " ";
    // // std::bitset<64> x12(top->Xsbox1);
    // // file << x12 << " ";
    // // std::bitset<64> x22(top->Xsbox2);
    // // file << x22 << " ";
    // // std::bitset<64> x32(top->Xsbox3);
    // // file << x32 << " ";
    // // std::bitset<64> x42(top->Xsbox4);
    // // file << x42 << " ";
    std::bitset<64> x5(top->p0);
    file << x5 << " ";
    std::bitset<64> x6(top->p1);
    file << x6 << " ";
    std::bitset<64> x7(top->p2);
    file << x7 << "\n";
    // file << std::hex << top->XsboxIN0 << " ";
    // file << std::hex << top->XsboxIN1 << " ";
    // file << std::hex << top->XsboxIN2 << " ";
    // file << std::hex << top->XsboxIN3 << " ";
    // file << std::hex << top->XsboxIN4 << " ";
    // // file << std::hex << top->Xsbox0 << " ";
    // // file << std::hex << top->Xsbox1 << " ";
    // // file << std::hex << top->Xsbox2 << " ";
    // // file << std::hex << top->Xsbox3 << " ";
    // // file << std::hex << top->Xsbox4 << " ";
    // file << std::hex << top->p0 << " ";
    // file << std::hex << top->p1 << " ";
    // file << std::hex << top->p2 << '\n';

    if (verbose) {
        std::cout << top->XsboxIN0 << " ";
        std::cout << top->XsboxIN1 << " ";
        std::cout << top->XsboxIN2 << " ";
        std::cout << top->XsboxIN3 << " ";
        std::cout << top->XsboxIN4 << " ";
        std::cout << top->p0 << " ";
        std::cout << top->p1 << " ";
        std::cout << top->p2 << '\n';
    }
}

void write_result(std::unique_ptr<VASCON_AEAD>& top, std::ofstream& file, bool verbose) {
    file << std::setw(8) << std::setfill('0') << std::hex << top->T[3];
    file << std::setw(8) << std::setfill('0') << std::hex << top->T[2];
    file << std::setw(8) << std::setfill('0') << std::hex << top->T[1];
    file << std::setw(8) << std::setfill('0') << std::hex << top->T[0] << '\n';

    if (verbose) {
        std::cout << std::setw(8) << std::setfill('0') << std::hex << top->T[3];
        std::cout << std::setw(8) << std::setfill('0') << std::hex << top->T[2];
        std::cout << std::setw(8) << std::setfill('0') << std::hex << top->T[1];
        std::cout << std::setw(8) << std::setfill('0') << std::hex << top->T[0] << '\n';
    }
}

// Generating fault at Finalization round 12
// It can be doable at round 11
void tick_fault_r12(std::unique_ptr<VASCON_AEAD>& top, bool verbose, std::ofstream& final_file, int value0, int value1, int value2, int value3, int value4) {


    top->clk = 0;
    top->eval();

    top->clk = 1;
    write_result_for_ecc_in(top, final_file, verbose);
    
    top->eval();

    auto sbox = top->ASCON_AEAD->ascondatapath1->asconRF1->asconsbox1;
    //std::cout << std::hex << "\nBefore " << sbox->Xsb0 << "\n";
    sbox->Xsb0 = sbox->Xsb0 ^ value0;
    //std::cout << std::hex << "After XOR " << sbox->Xsb0 << "\n";
    //std::cout << std::hex << "Before " << sbox->Xsb1 << "\n";
    sbox->Xsb1 = sbox->Xsb1 ^ value1;
    //std::cout << std::hex << "After XOR " << sbox->Xsb1 << "\n";
    //std::cout << std::hex << "Before " << sbox->Xsb2 << "\n";
    sbox->Xsb2 = sbox->Xsb2 ^ value2;
    //std::cout << std::hex << "After XOR " << sbox->Xsb2 << "\n";
    //std::cout << std::hex << "Before " << sbox->Xsb3 << "\n";
    sbox->Xsb3 = sbox->Xsb3 ^ value3;
    //std::cout << std::hex << "After XOR " << sbox->Xsb3 << "\n";
    //std::cout << std::hex << "Before " << sbox->Xsb4 << "\n";
    sbox->Xsb4 = sbox->Xsb4 ^ value4;
    //std::cout << std::hex << "After XOR " << sbox->Xsb4 << "\n";


    top->clk = 0;
    write_result_for_ecc_parity(top, final_file, verbose);
}


void tick(std::unique_ptr<VASCON_AEAD>& top) {
    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();
    top->clk = 0;
}

void aes_encrypt(std::unique_ptr<VASCON_AEAD>& top, std::ofstream& file, bool verbose) {
    tick(top);
    top->rst = 0x1;
    top->start = 0x0;
    tick(top);
    top->rst = 0x0;
    top->start = 0x1;
    tick(top);
    auto sbox = top->ASCON_AEAD->ascondatapath1->asconRF1->asconsbox1;

    unsigned int i = 0;
    while (top->Tv == 0) {
        // if (i < 0x16) {
        //     tick(top);
        //     write_result_for_ecc(top, file, verbose);
        // }
        // else {
            tick(top);
            write_result_for_ecc(top, file, verbose);
        // }
        // i++;
    }
}


void aes_encrypt_fault_r12(std::unique_ptr<VASCON_AEAD>& top, std::ofstream& file, bool verbose, int value0, int value1, int value2, int value3, int value4) {

    unsigned int i = 0;
    tick(top);
    top->rst = 0x1;
    top->start = 0x0;
    tick(top);
    top->rst = 0x0;
    top->start = 0x1;
    tick(top);

    auto sbox = top->ASCON_AEAD->ascondatapath1->asconRF1->asconsbox1;

    while (top->Tv == 0) {
        if (i < 0x16) { // From simulation should be 24 
        // but as wasting one clock cycle at reset
            tick(top);
            write_result_for_ecc(top, file, verbose);
        } else {
            tick_fault_r12(top ,verbose, file, value0, value1, value2, value3, value4);
        }
        i++;
    }
}

int main(int argc, char ** argv)
{
    bool verbose = false;

    if (argc > 1) {
        if (std::string(argv[1]) == "-v") {
            verbose = true;
        }
    }

    /* Initialize Verilator variables */
    Verilated::commandArgs(argc, argv);

    /* Create top module instance */
    auto top = std::make_unique<VASCON_AEAD>();
    /* PRNG */
    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 
    // std::mt19937 g1 (seed);
    int i=0;
    std::ofstream fault_file;
    std::cout << "[+] Fault simulation with Verilator\n";

    top->key[3] = 0x00010203;
    top->key[2] = 0x04050607;
    top->key[1] = 0x08090a0b;
    top->key[0] = 0x0c0d0e0f;

    top->nonce[3] = 0x00010203;
    top->nonce[2] = 0x04050607;
    top->nonce[1] = 0x08090a0b;
    top->nonce[0] = 0x0c0d0e0f;

    top->ADblock = 0;
    // top->ADblock[0] = 0x00000000;
    
    top->PTblock = 0;
    // top->PTblock[0] = 0x00000000;

    top->ADlen = 0x0;
    top->PTlen = 0x0;

    top->startAD = 0;

    std::cout << "Using key:\n";
    for (i=3;i>=0;i--) {
        std::cout << std::setw(8) << std::setfill('0') << std::hex << top->key[i];
    }

    std::cout << "\nUsing nonce:\n";
    for (i=3;i>=0;i--) {
        std::cout << std::setw(8) << std::setfill('0') << std::hex << top->nonce[i];
    }

    fault_file.open("tracefile_r11");

    std::ofstream org_file;
    org_file.open("org_sequence.txt");
    // Golden sample
    for (int k=0;k<1;k++) {
        aes_encrypt(top, org_file, verbose);
        std::cout << "\nGetting Tag:\n";
        for (i=3;i>=0;i--) {
            std::cout << std::setw(8) << std::setfill('0') << std::hex << top->T[i];
        }
        std::cout << "\n\n";
        write_result(top, fault_file, verbose);        
        k++;
    }
    org_file.close();


    std::ofstream sbox_file;
    sbox_file.open("faulty_sequence.txt");
    
    for (int j=0;j<1;j++) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 
        std::mt19937 g0 (seed);
        //std::cout << "\n"  <<"g0 =>" << g0() << " ";
        std::mt19937 g1 (seed*seed);
        //std::cout << "g1 =>" << g1() << " ";
        std::mt19937 g2 (seed*seed*seed);
        //std::cout << "g2 =>" << g2() << " ";
        std::mt19937 g3 (seed*seed*seed*seed);
        //std::cout << "g3 =>" << g3() << " ";
        std::mt19937 g4 (seed*seed*seed*seed*seed);
        //std::cout << "g4 =>" << g4() << " ";
        aes_encrypt_fault_r12(top, sbox_file ,verbose, g0() % 4, g1() % 4, g2() % 4, g3() % 4, g4() % 4);
        std::cout << "\nGetting Tag After fault:\n";
        for (int i=3;i>=0;i--) {
            std::cout << std::setw(8) << std::setfill('0') << std::hex << top->T[i];
        }
        std::cout << "\n\n";
        write_result(top, fault_file, verbose);
        j++;
    }  
    sbox_file.close();
    fault_file.close();
    top->final();

    return 0;
}
