#include <iostream>
#include <cmath>
#include <iomanip>

class RewardCalc {
public:
    /**
     * Calculates the block subsidy (reward) for a given block height.
     * Logic: Starts at 50 BTC and halves every 210,000 blocks.
     */
    double getBlockReward(long height) {
        int halvings = height / 210000;
        if (halvings >= 64) return 0; // Subsidy ends after 64 halvings

        double initialReward = 50.0;
        // Using bitwise shift logic like Bitcoin Core
        return initialReward / std::pow(2, halvings);
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./reward_calc [block_height]" << std::endl;
        return 1;
    }
    
    long height = std::stol(argv[1]);
    RewardCalc rc;
    
    std::cout << "--- Bitcoin Block Reward Calculator ---" << std::endl;
    std::cout << "Block Height: " << height << std::endl;
    std::cout << "Block Subsidy: " << std::fixed << std::setprecision(8) 
              << rc.getBlockReward(height) << " BTC" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    return 0;
}
