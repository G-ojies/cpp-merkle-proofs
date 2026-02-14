#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class MerkleProver {
public:
    // Simple XOR-based hash to maintain the "Greyat Labs" mock toolkit consistency
    std::string hashPair(std::string a, std::string b) {
        std::string combined = a + b;
        for (char &c : combined) c = (c ^ 0x5A); 
        return combined.substr(0, 8); // 8-char mock hash
    }

    void proveInclusion(std::string txHash, std::vector<std::string> path, std::string expectedRoot) {
        std::cout << "--- Greyat Labs Merkle Path Prover ---" << std::endl;
        std::cout << "Target TX: " << txHash << std::endl;
        
        std::string currentHash = txHash;
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << "Step " << i + 1 << ": Hashing with sibling [" << path[i] << "]" << std::endl;
            // In a real tree, order (left/right) is determined by the leaf index
            currentHash = hashPair(currentHash, path[i]);
        }

        std::cout << "\nCalculated Root: " << currentHash << std::endl;
        std::cout << "Expected Root:   " << expectedRoot << std::endl;

        if (currentHash == expectedRoot) {
            std::cout << "✅ SUCCESS: Transaction inclusion verified!" << std::endl;
        } else {
            std::cout << "❌ FAILURE: Proof invalid or corrupted." << std::endl;
        }
        std::cout << "---------------------------------------" << std::endl;
    }
};

int main() {
    MerkleProver prover;
    
    std::string myTx = "tx_003";
    std::string root = "root_abc";
    std::vector<std::string> proofPath = {"sib_1", "sib_2"}; // Sibling hashes

    prover.proveInclusion(myTx, proofPath, "root_abc"); // Note: Using mock values for logic flow
    return 0;
}
