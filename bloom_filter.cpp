#include <iostream>
#include <vector>
#include <string>
#include <functional>

class BloomFilter {
private:
    std::vector<bool> bit_array;
    int size;

    // Two different hash functions to simulate multiple rounds
    size_t hash1(std::string key) { return std::hash<std::string>{}(key) % size; }
    size_t hash2(std::string key) { return (std::hash<std::string>{}(key) >> 3) % size; }

public:
    BloomFilter(int n) : size(n) {
        bit_array.assign(size, false);
    }

    void add(std::string item) {
        bit_array[hash1(item)] = true;
        bit_array[hash2(item)] = true;
        std::cout << "Added: " << item << " to filter.\n";
    }

    bool contains(std::string item) {
        return bit_array[hash1(item)] && bit_array[hash2(item)];
    }
};

int main() {
    BloomFilter walletFilter(100);

    // 1. Wallet adds its address/transaction to the filter
    walletFilter.add("1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");

    // 2. Node checks a block's transactions against the filter
    std::string incomingTx = "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa";
    
    std::cout << "\nChecking Transaction: " << incomingTx << "\n";
    if (walletFilter.contains(incomingTx)) {
        std::cout << "Match Found! Sending Merkle Block to wallet...\n";
    } else {
        std::cout << "No match. Skipping.\n";
    }

    return 0;
}
