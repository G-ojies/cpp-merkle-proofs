#include <iostream>
#include <vector>
#include <string>
#include <set>

class INVHandler {
private:
    std::set<std::string> knownHashes; // Simulates our local database

public:
    void processINV(std::vector<std::pair<int, std::string>> invList) {
        std::cout << "--- Greyat Labs INV Message Handler ---" << std::endl;
        std::cout << "Received INV with " << invList.size() << " items.\n" << std::endl;

        for (const auto& item : invList) {
            int type = item.first; // 1 for TX, 2 for Block
            std::string hash = item.second;

            std::cout << "Inspecting " << (type == 1 ? "TX: " : "Block: ") << hash;

            if (knownHashes.find(hash) == knownHashes.end()) {
                std::cout << " -> [NEW] Sending GETDATA request... 🚀" << std::endl;
                knownHashes.insert(hash); // Add to known after requesting
            } else {
                std::cout << " -> [EXISTS] Ignoring." << std::endl;
            }
        }
        std::cout << "---------------------------------------" << std::endl;
    }
};

int main() {
    INVHandler node;
    
    // Simulate some initial data already in our database
    std::vector<std::pair<int, std::string>> inventory = {
        {1, "tx_001"}, // Transaction
        {1, "tx_002"},
        {2, "block_abc"} // Block
    };

    node.processINV(inventory);
    
    // Second round - tx_001 should now be ignored
    std::cout << "\n--- Peer sends inventory update ---" << std::endl;
    node.processINV({{1, "tx_001"}, {1, "tx_003"}});

    return 0;
}
