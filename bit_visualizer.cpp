#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <sstream>

class BitVisualizer {
public:
    void visualize(std::string hex) {
        std::cout << "--- Greyat Labs Bit Visualizer ---" << std::endl;
        std::cout << "Hex Input: 0x" << hex << std::endl << std::endl;

        for (size_t i = 0; i < hex.length(); i += 2) {
            // Convert 2-hex chars to 1 byte
            std::string byteHex = hex.substr(i, 2);
            unsigned int byteVal = std::stoul(byteHex, nullptr, 16);
            
            // Convert byte to 8 bits
            std::bitset<8> bits(byteVal);
            
            std::cout << "Byte " << (i/2) << " [0x" << byteHex << "]: " 
                      << bits << " (Dec: " << byteVal << ")" << std::endl;
        }
        std::cout << "----------------------------------" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./bit_visualizer [hex_string]" << std::endl;
        return 1;
    }
    BitVisualizer bv;
    bv.visualize(argv[1]);
    return 0;
}
