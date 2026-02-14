#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

struct UTXO {
    std::string txid;
    double amount;
    std::string owner;
};

class UTXOVisualizer {
private:
    std::map<std::string, UTXO> utxoDatabase;

public:
    void addUTXO(std::string txid, double amount, std::string owner) {
        utxoDatabase[txid] = {txid, amount, owner};
    }

    void displayLedger() {
        std::cout << "--- Greyat Labs UTXO State Visualizer ---" << std::endl;
        std::cout << std::left << std::setw(15) << "TXID" << std::setw(10) << "Amount" << "Owner" << std::endl;
        std::cout << std::string(40, '-') << std::endl;

        double totalCirculation = 0;
        for (const auto& [id, utxo] : utxoDatabase) {
            std::cout << std::left << std::setw(15) << utxo.txid 
                      << std::setw(10) << utxo.amount << utxo.owner << std::endl;
            totalCirculation += utxo.amount;
        }

        std::cout << std::string(40, '-') << std::endl;
        std::cout << "Total Simulated Supply: " << totalCirculation << " BTC" << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }
};

int main() {
    UTXOVisualizer viz;
    
    // Simulating the result of several blocks
    viz.addUTXO("tx_001", 3.125, "Miner_A");
    viz.addUTXO("tx_002", 0.5, "User_B");
    viz.addUTXO("tx_003", 2.625, "User_C");

    viz.displayLedger();
    return 0;
}
