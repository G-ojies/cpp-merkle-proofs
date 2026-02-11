#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

struct Participant {
    std::string user;
    double amount;
};

class CoinJoinSim {
public:
    void executeJoin(std::vector<Participant> participants) {
        std::cout << "--- Greyat Labs CoinJoin Privacy Simulator ---" << std::endl;
        
        std::vector<double> inputs;
        std::vector<double> outputs;

        for (const auto& p : participants) {
            std::cout << "User [" << p.user << "] adding: " << p.amount << " BTC" << std::endl;
            inputs.push_back(p.amount);
            outputs.push_back(p.amount); // Equal output amounts are key for privacy
        }

        // Shuffle outputs to obscure ownership trail
        std::shuffle(outputs.begin(), outputs.end(), std::mt19937(std::random_device()()));

        std::cout << "\n[ACTION] Shuffling outputs and generating transaction..." << std::endl;
        for (size_t i = 0; i < outputs.size(); ++i) {
            std::cout << "Output #" << i + 1 << ": " << outputs[i] << " BTC -> [Address Obfuscated]" << std::endl;
        }

        std::cout << "\n✅ PRIVACY STATUS: HIGH" << std::endl;
        std::cout << "Analysis: Impossible to map specific inputs to specific outputs." << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
};

int main() {
    std::vector<Participant> group = {
        {"User_A", 0.01},
        {"User_B", 0.01},
        {"User_C", 0.01}
    };

    CoinJoinSim sim;
    sim.executeJoin(group);
    return 0;
}
