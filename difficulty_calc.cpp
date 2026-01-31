#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

class DifficultyCalc {
public:
    /**
     * Unpacks nBits (Compact format) to a 256-bit Target.
     * Logic: First byte is the exponent, next 3 bytes are the coefficient.
     * Formula: target = coefficient * 2^(8 * (exponent - 3))
     */
    void calculateTarget(std::string bitsHex) {
        unsigned int exponent = std::stoul(bitsHex.substr(0, 2), nullptr, 16);
        unsigned int coefficient = std::stoul(bitsHex.substr(2, 6), nullptr, 16);

        std::cout << "--- Greyat Labs Difficulty Calculator ---" << std::endl;
        std::cout << "nBits: 0x" << bitsHex << std::endl;
        std::cout << "Exponent: " << exponent << " | Coefficient: 0x" << std::hex << coefficient << std::dec << std::endl;

        // Visualizing the leading zeros requirement
        int totalBytes = 32;
        int usedBytes = exponent;
        int zeroBytes = totalBytes - usedBytes;

        std::cout << "Required Leading Zero Bytes: " << zeroBytes << std::endl;
        std::cout << "Target Logic: Any hash < coefficient * 256^(exponent-3) is valid." << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./difficulty_calc [nbits_hex]\nExample: ./difficulty_calc 1d00ffff" << std::endl;
        return 1;
    }
    DifficultyCalc dc;
    dc.calculateTarget(argv[1]);
    return 0;
}
