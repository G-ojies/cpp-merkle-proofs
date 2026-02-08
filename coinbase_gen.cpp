#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

class CoinbaseGen {
public:
    void createCoinbase(long height, double reward, std::string minerMessage) {
        std::cout << "--- Greyat Labs Coinbase Generator ---" << std::endl;
        
        // 1. Block Height (Required in Coinbase script since BIP34)
        std::cout << "Block Height: " << height << std::endl;
        
        // 2. Output Value (Reward in Satoshis)
        long long sats = static_cast<long long>(reward * 100000000);
        std::cout << "Reward Value: " << sats << " Satoshis (" << reward << " BTC)" << std::endl;
        
        // 3. Coinbase Script (Miners can add custom data here)
        std::cout << "Coinbase Message: " << minerMessage << std::endl;
        
        // 4. Simplified Hex Representation
        std::stringstream ss;
        ss << "01000000" << "00" << "ffffffff" << "01" << std::hex << sats << "1976a914...";
        std::cout << "\nGenerated Coinbase Hex: " << ss.str().substr(0, 40) << "..." << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./coinbase_gen [block_height] [reward_amount]" << std::endl;
        return 1;
    }
    
    long height = std::stol(argv[1]);
    double reward = std::stod(argv[2]);
    
    CoinbaseGen gen;
    gen.createCoinbase(height, reward, "Mined by Greyat Labs");
    
    return 0;
}
