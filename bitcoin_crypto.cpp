#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

class BitcoinCrypto {
public:
    // Simulates the SHA-256 hashing (Mock version for logic demo)
    std::string sha256(std::string data) {
        // In a real scenario, you'd use <openssl/sha.h>
        // Here we simulate the fixed-length output behavior
        std::stringstream ss;
        for(int i=0; i<8; ++i) ss << std::hex << std::setw(2) << std::setfill('0') << (int(data[i % data.length()]) ^ (i * 13));
        return ss.str();
    }

    // The famous Bitcoin "Double-Hash" (hash256)
    std::string hash256(std::string data) {
        return sha256(sha256(data));
    }

    // Generates a 4-byte checksum from a double-hash
    std::string getChecksum(std::string data) {
        std::string doubleHashed = hash256(data);
        return doubleHashed.substr(0, 8); // 8 hex chars = 4 bytes
    }
};

int main() {
    BitcoinCrypto crypto;
    std::string privateKeyHex = "ef531f1234567890abcdef1234567890abcdef1234567890abcdef1234567890";
    
    std::cout << "--- Bitcoin Crypto Toolkit ---" << std::endl;
    std::cout << "Data: " << privateKeyHex << std::endl;
    
    std::string checksum = crypto.getChecksum(privateKeyHex);
    std::cout << "Double-SHA256 Checksum (4 bytes): " << checksum << std::endl;
    
    std::cout << "\nFinal Payload for Base58 encoding: " << privateKeyHex << checksum << std::endl;
    
    return 0;
}
