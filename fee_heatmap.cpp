#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct BlockStats {
    int height;
    double totalFees;
    double subsidy;
    
    double totalReward() const { return totalFees + subsidy; }
};

class FeeHeatmap {
public:
    void analyze(std::vector<BlockStats> chain) {
        std::cout << "--- Greyat Labs Block Profitability Heatmap ---" << std::endl;
        std::cout << std::left << std::setw(10) << "Height" << std::setw(15) << "Fees (BTC)" << "Total Reward (BTC)" << std::endl;
        std::cout << std::string(45, '-') << std::endl;

        for (const auto& block : chain) {
            std::cout << std::left << std::setw(10) << block.height 
                      << std::setw(15) << std::fixed << std::setprecision(4) << block.totalFees
                      << block.totalReward() << " ";
            
            // Generate a simple visual "heat" bar based on fee volume
            int heatLevel = static_cast<int>(block.totalFees * 20); 
            std::cout << std::string(heatLevel, '#') << std::endl;
        }
        std::cout << "-----------------------------------------------" << std::endl;
    }
};

int main() {
    std::vector<BlockStats> simulatedChain = {
        {830000, 0.0520, 3.125},
        {830001, 0.4890, 3.125}, // High activity block
        {830002, 0.1200, 3.125},
        {830003, 0.8500, 3.125}  // Congested network block
    };

    FeeHeatmap heatmap;
    heatmap.analyze(simulatedChain);
    return 0;
}
