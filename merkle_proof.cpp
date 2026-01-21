#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Mock hash function (for learning/portfolio purposes)
std::string hashPairs(std::string a, std::string b) {
    return "(" + a + "+" + b + ")";
}

int main() {
    // 1. Setup our block with 4 transactions
    std::string txA = "txA", txB = "txB", txC = "txC", txD = "txD";

    // 2. Build the tree levels
    std::string hashAB = hashPairs(txA, txB);
    std::string hashCD = hashPairs(txC, txD);
    std::string merkleRoot = hashPairs(hashAB, hashCD);

    // 3. The Proof Path for txA
    // To prove txA, we need: its sibling (txB) and the other branch's hash (hashCD)
    std::vector<std::string> proofPath = {txB, hashCD};

    std::cout << "--- Merkle Proof Generator ---" << std::endl;
    std::cout << "Target Transaction: " << txA << std::endl;
    std::cout << "Known Merkle Root: " << merkleRoot << std::endl;
    
    // 4. Verification Logic (What a mobile wallet does)
    std::cout << "\nVerifying Proof..." << std::endl;
    std::string currentHash = txA;

    for (const std::string& sibling : proofPath) {
        std::cout << "Combining " << currentHash << " with sibling " << sibling << std::endl;
        // In a real tree, you'd check if sibling is left or right
        currentHash = hashPairs(currentHash, sibling);
    }

    if (currentHash == merkleRoot) {
        std::cout << "\n[SUCCESS] Proof is valid! txA is in the block." << std::endl;
    } else {
        std::cout << "\n[FAILED] Invalid Root." << std::endl;
    }

    return 0;
}
