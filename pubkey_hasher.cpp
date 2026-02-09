#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

class PubKeyHasher {
public:
    // Simulates the SHA-256 round
    std::string sha256(std::string data) {
        std::stringstream ss;
        for(int i=0; i<8; ++i) ss << std::hex << std::setw(2) << std::setfill('0') << (int(data[i % data.length()]) ^ (i * 17));
        return ss.str();
    }

    // Simulates the RIPEMD-160 round
    // In Bitcoin, Hash160 = RIPEMD160(SHA256(PubKey))
    std::string ripemd160(std::string data) {
        std::stringstream ss;
        for(int i=0; i<5; ++i) ss << std::hex << std::setw(2) << std::setfill('0') << (int(data[i % data.length()]) ^ (i * 23));
        return ss.str();
    }

    std::string getHash160(std::string pubKeyHex) {
        return ripemd160(sha256(pubKeyHex));
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./pubkey_hasher [pubkey_hex]" << std::endl;
        return 1;
    }
    
    PubKeyHasher hasher;
    std::string pubKey = argv[1];
    std::string hash160 = hasher.getHash160(pubKey);
    
    std::cout << "--- Greyat Labs PubKey Hasher ---" << std::endl;
    std::cout << "Public Key: " << pubKey << std::endl;
    std::cout << "Hash160:    " << hash160 << std::endl;
    std::cout << "---------------------------------" << std::endl;
    
    return 0;
}
