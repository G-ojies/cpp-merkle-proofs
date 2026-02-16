#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

class HDWallet {
public:
    // Simulates HMAC-SHA512 derivation logic
    // Parent Key + Index -> Child Key
    std::string deriveChildKey(std::string parentKey, int index) {
        std::stringstream ss;
        ss << std::hex << std::setw(8) << std::setfill('0') << index;
        std::string indexHex = ss.str();

        // In reality, this is: HMAC-SHA512(ChainCode, ParentKey || Index)
        // For our simulation, we mix the parent string with the index
        std::string childKey = parentKey;
        for (size_t i = 0; i < childKey.length(); ++i) {
            // Simple rotation cipher based on index to simulate change
            childKey[i] = ((childKey[i] + index) % 126); 
            if (childKey[i] < 33) childKey[i] += 33; // Keep readable
        }
        
        return childKey + "_child_" + indexHex;
    }

    void generateTree(std::string masterKey) {
        std::cout << "--- Greyat Labs BIP32 Derivation Tree ---" << std::endl;
        std::cout << "Master Key (m): " << masterKey << "\n" << std::endl;

        // Deriving Account 0 (m/0')
        std::string account0 = deriveChildKey(masterKey, 0);
        std::cout << "Account 0 (m/0'): " << account0 << std::endl;

        // Deriving Receiving Address 0 (m/0'/0)
        std::string recv0 = deriveChildKey(account0, 0);
        std::cout << "  -> Receive 0 (m/0'/0): " << recv0 << std::endl;

        // Deriving Change Address 0 (m/0'/1)
        std::string change0 = deriveChildKey(account0, 1);
        std::cout << "  -> Change 0  (m/0'/1): " << change0 << std::endl;
        
        std::cout << "-----------------------------------------" << std::endl;
    }
};

int main() {
    HDWallet wallet;
    // Simulating a master key derived from your BIP39 seed
    wallet.generateTree("xprv9s21ZrQH143K..."); 
    return 0;
}
