#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

class VarIntDecoder {
public:
    /**
     * Decodes a Bitcoin VarInt from a hex string.
     * Logic: 
     * < 0xFD: 1 byte value
     * 0xFD: Next 2 bytes (uint16_t)
     * 0xFE: Next 4 bytes (uint32_t)
     * 0xFF: Next 8 bytes (uint64_t)
     */
    unsigned long decode(std::string hex, int& bytesRead) {
        unsigned int firstByte = std::stoul(hex.substr(0, 2), nullptr, 16);
        
        if (firstByte < 0xFD) {
            bytesRead = 1;
            return firstByte;
        } else if (firstByte == 0xFD) {
            bytesRead = 3;
            return std::stoul(hex.substr(2, 4), nullptr, 16); // Simplified Little-Endian
        } else if (firstByte == 0xFE) {
            bytesRead = 5;
            return std::stoul(hex.substr(2, 8), nullptr, 16);
        } else {
            bytesRead = 9;
            return std::stoull(hex.substr(2, 16), nullptr, 16);
        }
    }
};

int main() {
    VarIntDecoder decoder;
    int bytesRead = 0;
    
    // Example: 0xFD followed by 0x01FF (511 in decimal)
    std::string testHex = "fdff01"; 
    unsigned long value = decoder.decode(testHex, bytesRead);
    
    std::cout << "--- Greyat Labs VarInt Decoder ---" << std::endl;
    std::cout << "Raw Hex: " << testHex << std::endl;
    if (bytesRead > 0) {
        std::cout << "Decoded Value: " << value << std::endl;
        std::cout << "Bytes Consumed: " << bytesRead << std::endl;
    }
    
    return 0;
}
