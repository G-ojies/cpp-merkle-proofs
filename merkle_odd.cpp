#include <iostream>
#include <vector>
#include <string>

// Simulating a hash function for protocol logic
std::string hash(std::string data) {
    return "[" + data + "]"; 
}

std::string computeMerkleRoot(std::vector<std::string> txs) {
    if (txs.empty()) return "";
    
    while (txs.size() > 1) {
        // If the number of transactions is odd, duplicate the last one
        if (txs.size() % 2 != 0) {
            std::cout << "Odd number detected. Duplicating: " << txs.back() << std::endl;
            txs.push_back(txs.back());
        }

        std::vector<std::string> nextLevel;
        for (size_t i = 0; i < txs.size(); i += 2) {
            nextLevel.push_back(hash(txs[i] + txs[i + 1]));
        }
        txs = nextLevel; // Move up to the next level of the tree
    }
    return txs[0];
}

int main() {
    // Test with 3 transactions (an odd number)
    std::vector<std::string> transactions = {"tx1", "tx2", "tx3"};
    
    std::cout << "Starting Merkle Root calculation for 3 transactions...\n";
    std::string root = computeMerkleRoot(transactions);
    
    std::cout << "\nFinal Merkle Root: " << root << std::endl;
    return 0;
}
