#include <iostream>
#include <vector>
#include <string>

class MerkleTree {
private:
    std::string hash(std::string data) { return "{" + data + "}"; }

public:
    std::string computeRoot(std::vector<std::string> txs) {
        if (txs.empty()) return "";
        while (txs.size() > 1) {
            if (txs.size() % 2 != 0) txs.push_back(txs.back());
            std::vector<std::string> nextLevel;
            for (size_t i = 0; i < txs.size(); i += 2) {
                nextLevel.push_back(hash(txs[i] + txs[i + 1]));
            }
            txs = nextLevel;
        }
        return txs[0];
    }

    bool verify(std::string leaf, const std::vector<std::string>& proof, std::string root) {
        std::string currentHash = hash(leaf);
        for (const std::string& sibling : proof) {
            currentHash = hash(currentHash + sibling);
        }
        return currentHash == root;
    }
};

int main() {
    MerkleTree bt;
    std::vector<std::string> txs = {"tx1", "tx2", "tx3"};
    std::string root = bt.computeRoot(txs);
    std::cout << "Merkle Root: " << root << std::endl;
    return 0;
}
