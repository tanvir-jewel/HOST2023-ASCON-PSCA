#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<uint32_t>> read_keys(const std::string &filename) {
    std::vector<std::vector<uint32_t>> keys;
    std::ifstream key_file(filename);
    if (key_file.is_open()) {
        std::string line;
        while (std::getline(key_file, line)) {
            std::istringstream iss(line);
            std::vector<uint32_t> current_key;
            uint32_t value;
            while (iss >> std::hex >> value) {
                current_key.push_back(value);
            }
            keys.push_back(current_key);
        }
        key_file.close();
    } else {
        std::cerr << "Error: Unable to open " << filename << "\n";
    }
    return keys;
}

int main() {
    std::string key_filename = "key.txt";
    auto keys = read_keys(key_filename);

    for (const auto &key : keys) {
        if (key.size() != 4) {
            std::cerr << "Error: Key must be 128 bits long, divided into four 32-bit chunks\n";
            continue;
        }
        uint32_t key1 = key[0];
        uint32_t key2 = key[1];
        uint32_t key3 = key[2];
        uint32_t key4 = key[3];

        std::cout << "Key: ";
        std::cout << std::hex << std::uppercase
                  << key1 << " "
                  << key2 << " "
                  << key3 << " "
                  << key4 << std::endl;
    }

    return 0;
}

