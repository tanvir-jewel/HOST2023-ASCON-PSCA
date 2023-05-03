#include <iostream>
#include <fstream>
#include <random>
#include <bitset>
#include <sstream> // Include this header

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

int main() {
    std::ofstream output_file("binary_keys.txt");
    if (!output_file.is_open()) {
        std::cerr << "Error: Unable to create binary_keys.txt" << std::endl;
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dist;

    for (int i = 0; i < 10; ++i) {
        std::string hex_key;
        for (int j = 0; j < 4; ++j) {
            uint32_t random_key_part = dist(gen);
            std::stringstream ss;
            ss << std::hex << std::uppercase << random_key_part;
            hex_key += ss.str();
        }
        std::cout<<"hex= " << hex_key<< "\n";
        std::string binary_key = hex_to_binary(hex_key);
        output_file << binary_key << std::endl;
    }

    output_file.close();
    std::cout << "Generated 10 random binary keys in binary_keys.txt" << std::endl;
    return 0;
}

