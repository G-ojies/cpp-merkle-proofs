#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

struct Holder {
    std::string address;
    double balance;
};

class RichListGenerator {
public:
    void generate(const std::map<std::string, double>& ledger) {
        std::vector<Holder> richList;
        for (auto const& [addr, bal] : ledger) {
            richList.push_back({addr, bal});
        }

        // Sort by balance descending
        std::sort(richList.begin(), richList.end(), [](const Holder& a, const Holder& b) {
            return a.balance > b.balance;
        });

        std::cout << "--- Greyat Labs Rich List (Top Holders) ---" << std::endl;
        std::cout << std::left << std::setw(5) << "Rank" << std::setw(15) << "Address" << "Balance (BTC)" << std::endl;
        std::cout << std::string(40, '-') << std::endl;

        for (size_t i = 0; i < richList.size(); ++i) {
            std::cout << std::left << std::setw(5) << i + 1 
                      << std::setw(15) << richList[i].address 
                      << std::fixed << std::setprecision(8) << richList[i].balance << std::endl;
        }
        std::cout << "--------------------------------------------" << std::endl;
    }
};

int main() {
    // Simulated aggregated data from your UTXO set
    std::map<std::string, double> ledger = {
        {"Miner_A", 12.50000000},
        {"User_B", 0.54002000},
        {"User_C", 2.10000000},
        {"Exchange_X", 150.00000000}
    };

    RichListGenerator rg;
    rg.generate(ledger);
    return 0;
}
