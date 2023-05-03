#include <stdlib.h> // rand and srand 
#include <iostream> // std::cout         
#include <verilated.h> // defines common routines 
#include <verilated_vcd_c.h> // Trace file format header 
#include <assert.h> // assert macro has been used for debugging purposes 
#include <memory> // std::unique_ptr has been used for memory management 
#include <iomanip> // std::setw has been used for formatting output
#include <chrono> // std::chrono has been used for timing  
#include <random> // std::random_device has been used for seeding the random number generator
#include <fstream> // std::ofstream has been used for writing to a file
#include <bitset> // std::bitset has been used for printing the output in binary
#include <sstream> // Include this header
#include <cstdio> // Include this header for the remove function

#include "VASCON_AEAD.h" // Module header file 
#include "VASCON_AEAD_ASCON_AEAD.h" // Module header file
#include "VASCON_AEAD_ASCON_SBOX.h" // Module header file
#include "VASCON_AEAD_ASCON_ROUND_FUNCTION.h" // Module header file
#include "VASCON_AEAD_ASCON_DATAPATH.h" // Module header file

// The next two lines mean that simulation will start from 0 and end at MAX_TIME. 
vluint64_t sim_time = 0; // Current simulation time
#define MAX_TIME 200 // Maximum simulation time

template <typename T> // Template function for reading input from the user

// The function userIn takes two arguments: the name of the variable and the variable itself.
// The function prints the name of the variable and then reads the value from the user.
void userIn(const char * var_name, T & var) 
{
    unsigned tmp;
    std::cout << var_name << " = ";
    std::cin >> tmp;
    assert(tmp <= 0xffffffff);
    var = tmp;
}

// The function userOut takes two arguments: the name of the variable and the variable itself.
// The function prints the name of the variable and then prints the value of the variable in hexadecimal.
void userOut(const char * var_name, unsigned value)
{
    std::cout << var_name << " = " << std::hex << value << '\n';
}


std::string hex_to_binary(const std::string &hex) {
    std::string binary;
    for (size_t i = 0; i < hex.size(); ++i) {
        uint32_t value;
        std::stringstream ss;
        ss << std::hex << hex.substr(i, 1);
        ss >> value;
        binary += std::bitset<4>(value).to_string();
    }
    return binary;
}


// The function write_result takes two arguments: the name of the variable and the variable itself.
// This function has been used for writing the output to a file. In details, the function opens a file named "result.txt" and writes the value of the variable in hexadecimal.
// For example, if the variable is named "p0" and its value is 0x12345678, the function will write "p0 = 12345678" in the file.
// Additionally, the function prints the name of the variable and its value in hexadecimal on the screen.
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



int main(int argc, char ** argv)
{
    
    // Delete binary.txt if it exists
    if (std::remove("Tag-binary_wo_fault.txt") == 0) {
        std::cout << "Previous binary.txt file has been removed." << std::endl;
    } else {
        std::cout << "No previous binary.txt file found." << std::endl;
    }
    // std::string key_filename = "key.txt";
    // auto keys = read_keys(key_filename);
    std::ofstream tagbinary_file("Tag-binary_wo_fault.txt", std::ios_base::app);
    if (!tagbinary_file.is_open()) {
        std::cerr << "Error: Unable to open binary.txt" << std::endl;
        return 1;
    }

    // Delete binary.txt if it exists
    if (std::remove("Tag-binary.txt") == 0) {
        std::cout << "Previous binary.txt file has been removed." << std::endl;
    } else {
        std::cout << "No previous binary.txt file found." << std::endl;
    }
    // std::string key_filename = "key.txt";
    // auto keys = read_keys(key_filename);
    std::ofstream binary_file("Tag-binary.txt", std::ios_base::app);
    if (!binary_file.is_open()) {
        std::cerr << "Error: Unable to open binary.txt" << std::endl;
        return 1;
    }
    // // Delete binary.txt if it exists
    // if (std::remove("Tag-binary.txt") == 0) {
    //     std::cout << "Previous binary.txt file has been removed." << std::endl;
    // } else {
    //     std::cout << "No previous binary.txt file found." << std::endl;
    // }
    // // std::string key_filename = "key.txt";
    // // auto keys = read_keys(key_filename);
    // std::ofstream binary_file("Tag-binary.txt", std::ios_base::app);
    // if (!binary_file.is_open()) {
    //     std::cerr << "Error: Unable to open binary.txt" << std::endl;
    //     return 1;
    // }
    std::string nonce_filename = "nonce.txt";
    auto nonces = read_keys(nonce_filename);

    for (const auto &nonce : nonces) {
        if (nonce.size() != 4) {
            std::cerr << "Error: Key must be 128 bits long, divided into four 32-bit chunks\n";
            continue;
        }
        // uint32_t key1 = key[0];
        // uint32_t key2 = key[1];
        // uint32_t key3 = key[2];
        // uint32_t key4 = key[3];

        // std::cout << "Key: ";
        // std::cout << std::hex << std::uppercase
        //           << key1 << " "
        //           << key2 << " "
        //           << key3 << " "
        //           << key4 << std::endl;
        uint32_t nonce1 = nonce[0];
        uint32_t nonce2 = nonce[1];
        uint32_t nonce3 = nonce[2];
        uint32_t nonce4 = nonce[3];

        std::cout << "Nonce: ";
        std::cout << std::hex << std::uppercase
                  << nonce1 << " "
                  << nonce2 << " "
                  << nonce3 << " "
                  << nonce4 << std::endl;

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
    int i=0;
    std::ofstream fault_file;
    std::cout << "[+] Fault simulation with Verilator\n";


    top->key[3] = 0x00010203;
    top->key[2] = 0x04050607;
    top->key[1] = 0x08090a0b;
    top->key[0] = 0x0c0d0e0f;

    top->nonce[3] = nonce4;
    top->nonce[2] = nonce3;
    top->nonce[1] = nonce2;
    top->nonce[0] = nonce1;

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
    auto sbox = top->ASCON_AEAD->ascondatapath1->asconRF1->asconsbox1;
    auto after_diffusion = top->ASCON_AEAD->ascondatapath1->asconRF1;
    for (int k=0;k<1;k++) {
        aes_encrypt(top, org_file, verbose);
        std::cout << "\nGetting Tag:\n";
        for (i=3;i>=0;i--) {
            std::stringstream hex_sss;
            std::cout << std::setw(8) << std::setfill('0') << std::hex << top->T[i] << std::endl;
            hex_sss << std::setw(8) << std::setfill('0') << std::hex << top->T[i];
            std::string hex_value = hex_sss.str();
            // std::cout << hex_value;

            // Convert hexadecimal to binary
            std::string tagbinary_value = hex_to_binary(hex_value); // Assuming you have the hex_to_binary function from the previous answer

            // Append binary value to binary.txt
            tagbinary_file << tagbinary_value;
        }
        std::cout << "\n\n";
        write_result(top, fault_file, verbose);        
        k++;
    }
    std::cout << "\nGetting SBOX output 320bit :\n";
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb0;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb1;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb2;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb3;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb4 << std::endl;
    std::cout << "\nGetting Diffusion layer output 320bit :\n";
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo0;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo1;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo2;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo3;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo4 << std::endl;
    std::cout << "\nTrying to finding correlation :\n";
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
            std::stringstream hex_ss;
            std::cout << std::setw(8) << std::hex << top->T[i];
            // std::cout << "New Tag= ";
            hex_ss << std::setw(8) << std::hex << top->T[i];
            // std::cout << hex_value;

            // Convert hexadecimal to binary
            std::string binary_value = hex_to_binary(hex_value); // Assuming you have the hex_to_binary function from the previous answer

            // Append binary value to binary.txt
            binary_file << binary_value;
        }
        std::cout << "\n\n";
        write_result(top, fault_file, verbose);
        j++;
    }  
    std::cout << "\nGetting SBOX output 320bit :\n";
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb0<< std::endl;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb1<< std::endl;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb2<< std::endl;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb3<< std::endl;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << sbox->Xsb4 << std::endl;
    std::cout << "\nGetting Diffusion layer output 320bit :\n";
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo0;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo1;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo2;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo3;
    std::cout << std::setw(8) << std::setfill('0') << std::hex << after_diffusion->Xo4 << std::endl;
    std::cout << "\nTrying to finding correlation :\n";
    org_file.close();
    binary_file << std::endl;
    tagbinary_file << std::endl;
    sbox_file.close();
    fault_file.close();
    top->final();
    }

    // binary_file << std::endl;
    binary_file.close();
    tagbinary_file.close();

    return 0;
}


