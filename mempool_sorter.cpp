#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Transaction {
    std::string txid;
    int fee;    // in satoshis
    int size;   // in vbytes
    
    double getFeeRate() const { return (double)fee / size; }
};

class MempoolSorter {
public:
    void sortAndPrint(std::vector<Transaction>& mempool) {
        // Sort by fee rate (highest first)
        std::sort(mempool.begin(), mempool.end(), [](const Transaction& a, const Transaction& b) {
            return a.getFeeRate() > b.getFeeRate();
        });

        std::cout << "--- Greyat Labs Mempool Prioritizer ---" << std::endl;
        std::cout << std::left << std::setw(10) << "TXID" << std::setw(10) << "Fee" << std::setw(10) << "Rate (sat/vB)" << std::endl;
        for (const auto& tx : mempool) {
            std::cout << std::left << std::setw(10) << tx.txid 
                      << std::setw(10) << tx.fee 
                      << std::setw(10) << std::fixed << std::setprecision(2) << tx.getFeeRate() << std::endl;
        }
    }
};

int main() {
    std::vector<Transaction> mempool = {
        {"tx_low", 500, 250},   // 2 sat/vB
        {"tx_high", 5000, 200}, // 25 sat/vB
        {"tx_med", 1200, 300}   // 4 sat/vB
    };

    MempoolSorter sorter;
    sorter.sortAndPrint(mempool);
    return 0;
}
