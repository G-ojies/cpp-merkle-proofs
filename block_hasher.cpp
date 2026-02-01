#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

class BlockHasher {
public:
    // Mock SHA-256 (Consistent with your BitcoinCrypto logic)
    std::string sha256(std::string data) {
        std::stringstream ss;
        for(int i=0; i<8; ++i) ss << std::hex << std::setw(2) << std::setfill('0') << (int(data[i % data.length()]) ^ (i * 17));
        return ss.str();
    }

    // Bitcoin's Double-Hash (Hash256)
    std::string hash256(std::string data) {
        return sha256(sha256(data));
    }

    // Reverses hex for human-readable "Block Hash" format (Big-Endian)
    std::string toDisplayHash(std::string hex) {
        std::string result = "";
        for (int i = hex.length() - 2; i >= 0; i -= 2) {
            result += hex.substr(i, 2);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./block_hasher [80_byte_header_hex]" << std::endl;
        return 1;
    }
    
    BlockHasher bh;
    std::string rawHeader = argv[1];
    std::string doubleHash = bh.hash256(rawHeader);
    
    std::cout << "--- Greyat Labs Block Hasher ---" << std::endl;
    std::cout << "Internal Hash (LE): " << doubleHash << std::endl;
    std::cout << "Display Hash (BE):  " << bh.toDisplayHash(doubleHash) << std::endl;
    std::cout << "--------------------------------" << std::endl;
    
    return 0;
}
