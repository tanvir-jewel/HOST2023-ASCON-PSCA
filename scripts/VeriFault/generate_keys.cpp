#include <iostream>
#include <fstream>
#include <random>

int main() {
    std::ofstream key_file("nonce.txt");
    if (!key_file.is_open()) {
        std::cerr << "Error: Unable to create key.txt" << std::endl;
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dist;

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 4; ++j) {
            uint32_t random_key_part = dist(gen);
            key_file << std::hex << std::uppercase << random_key_part;
            if (j < 3) {
                key_file << " ";
            }
        }
        key_file << std::endl;
    }

    key_file.close();
    std::cout << "Generated 100 random keys in nonce.txt" << std::endl;
    return 0;
}

