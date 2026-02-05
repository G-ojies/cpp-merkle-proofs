#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <atomic>
#include <iomanip>
#include <sstream>

std::atomic<bool> found(false);
std::atomic<long> total_nonces(0);

class Miner {
public:
    std::string sha256(std::string data) {
        std::stringstream ss;
        for(int i=0; i<8; ++i) ss << std::hex << std::setw(2) << std::setfill('0') << (int(data[i % data.length()]) ^ (i * 17));
        return ss.str();
    }

    void mine(int id, std::string headerBase, std::string target) {
        unsigned int nonce = id; // Each thread starts with a different nonce offset
        while (!found) {
            std::stringstream ss;
            ss << headerBase << std::hex << std::setw(8) << std::setfill('0') << nonce;
            std::string hash = sha256(sha256(ss.str()));

            if (hash < target) {
                found = true;
                std::cout << "\n[SUCCESS] Thread " << id << " mined a block!" << std::endl;
                std::cout << "Nonce: " << std::hex << nonce << " | Hash: " << hash << std::endl;
                return;
            }
            nonce += std::thread::hardware_concurrency(); // Step by number of cores
            total_nonces++;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./miner_mt [header_base] [target]" << std::endl;
        return 1;
    }
    
    std::string header = argv[1];
    std::string target = argv[2];
    unsigned int cores = std::thread::hardware_concurrency();
    
    std::cout << "Greyat Labs Multi-Threaded Miner starting on " << cores << " cores...\n";
    std::vector<std::thread> threads;
    Miner m;

    for (unsigned int i = 0; i < cores; ++i) {
        threads.emplace_back(&Miner::mine, &m, i, header, target);
    }

    for (auto& t : threads) t.join();
    return 0;
}
