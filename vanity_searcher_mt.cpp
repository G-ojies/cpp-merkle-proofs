#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <thread>
#include <atomic>

std::atomic<bool> found(false);
const std::string ALPHABET = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

std::string mockAddress(std::string seed) {
    std::string addr = "1";
    for(int i=0; i<8; ++i) addr += ALPHABET[seed[i] % 58];
    return addr;
}

void searchWorker(int id, std::string prefix) {
    long attempts = 0;
    while (!found) {
        attempts++;
        std::string seed = std::to_string(std::time(0)) + std::to_string(id) + std::to_string(attempts);
        std::string addr = mockAddress(seed);

        if (addr.substr(1, prefix.length()) == prefix) {
            found = true;
            std::cout << "\n[SUCCESS] Thread " << id << " found a match!" << std::endl;
            std::cout << "Address: " << addr << " | Seed: " << seed << std::endl;
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    std::string prefix = argv[1];
    
    // Get the number of CPU cores available
    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "Greyat Labs Multi-Threaded Searcher starting on " << cores << " cores...\n";

    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < cores; ++i) {
        threads.emplace_back(searchWorker, i, prefix);
    }

    for (auto& t : threads) t.join();
    return 0;
}
