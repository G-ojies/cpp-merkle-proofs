#include <iostream>
#include <vector>
#include <string>

// Mock SHA-256 for protocol logic demonstration
std::string sha256_mock(std::string data) {
    return "{" + data + "}"; 
}

/**
 * Verifies if a leaf belongs to a Merkle Root using a proof path.
 * @param leaf The transaction ID to verify.
 * @param proof A vector of sibling hashes.
 * @param root The known Merkle Root from the block header.
 * @return True if the transaction is verified.
 */
bool verifyTransaction(std::string leaf, const std::vector<std::string>& proof, std::string root) {
    std::string currentHash = sha256_mock(leaf);
    
    std::cout << "Starting verification for: " << leaf << "\n";
    
    for (const std::string& sibling : proof) {
        std::cout << "  Hashing " << currentHash << " with sibling " << sibling << "...\n";
        // Bitcoin logic: pair and hash. (Simplified: always pairing sibling to the right)
        currentHash = sha256_mock(currentHash + sibling);
    }
    
    return currentHash == root;
}

int main() {
    // 1. Inputs provided by a Full Node to a Light Client
    std::string myTx = "tx1";
    std::string knownRoot = "{{{tx1}tx2}{tx3}tx3}"; // Result of 3-tx block with duplication
    std::vector<std::string> myProof = {"{tx2}", "{tx3}tx3"}; // Sibling hashes

    // 2. Perform Verification
    if (verifyTransaction(myTx, myProof, knownRoot)) {
        std::cout << "\n[SUCCESS] Transaction verified! It is part of the block.\n";
    } else {
        std::cout << "\n[FAILED] Verification failed. Data may be tampered with.\n";
    }

    return 0;
}
