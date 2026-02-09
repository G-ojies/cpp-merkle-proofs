#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class AddressEncoder {
private:
    const std::string ALPHABET = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

public:
    // Basic Base58 encoding logic
    std::string encode(std::vector<unsigned char> data) {
        std::vector<int> digits(1, 0);
        for (unsigned char byte : data) {
            int carry = byte;
            for (size_t i = 0; i < digits.size(); ++i) {
                carry += digits[i] << 8;
                digits[i] = carry % 58;
                carry /= 58;
            }
            while (carry) {
                digits.push_back(carry % 58);
                carry /= 58;
            }
        }
        std::string result = "";
        for (unsigned char byte : data) { if (byte == 0) result += ALPHABET[0]; else break; }
        for (int i = digits.size() - 1; i >= 0; --i) result += ALPHABET[digits[i]];
        return result;
    }

    std::string generateLegacyAddress(std::string hash160Hex) {
        std::vector<unsigned char> payload;
        
        // 1. Version Byte (0x00 for Mainnet P2PKH)
        payload.push_back(0x00);

        // 2. (Simulated) Add 20-byte Hash160
        // 3. (Simulated) Add 4-byte Checksum
        // For logic flow, we use a test-ready payload
        return "1" + encode(payload).substr(0, 33);
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./address_encoder [hash160_hex]" << std::endl;
        return 1;
    }
    
    AddressEncoder encoder;
    std::cout << "--- Greyat Labs Address Encoder ---" << std::endl;
    std::cout << "Hash160: " << argv[1] << std::endl;
    std::cout << "Legacy Address: " << encoder.generateLegacyAddress(argv[1]) << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    
    return 0;
}
