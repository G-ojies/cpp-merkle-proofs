#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HeaderParser {
public:
    // Helper to reverse hex for Little-Endian representation
    std::string reverseEndian(std::string hex) {
        std::string result = "";
        for (int i = hex.length() - 2; i >= 0; i -= 2) {
            result += hex.substr(i, 2);
        }
        return result;
    }

    void parse(std::string headerHex) {
        if (headerHex.length() != 160) { // 80 bytes = 160 hex chars
            std::cout << "Error: Invalid header length." << std::endl;
            return;
        }

        std::cout << "--- Greyat Labs Block Header Parser ---" << std::endl;
        std::cout << "Version:    " << reverseEndian(headerHex.substr(0, 8)) << std::endl;
        std::cout << "Prev Hash:  " << reverseEndian(headerHex.substr(8, 64)) << std::endl;
        std::cout << "Merkle Root:" << reverseEndian(headerHex.substr(72, 64)) << std::endl;
        std::cout << "Timestamp:  " << reverseEndian(headerHex.substr(136, 8)) << std::endl;
        std::cout << "Bits (Diff):" << reverseEndian(headerHex.substr(144, 8)) << std::endl;
        std::cout << "Nonce:      " << reverseEndian(headerHex.substr(152, 8)) << std::endl;
        std::cout << "---------------------------------------" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    HeaderParser hp;
    hp.parse(argv[1]);
    return 0;
}
