#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> found(false);
std::atomic<long> total_attempts(0);
const std::string ALPHABET = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

std::string mockAddress(std::string seed) {
    std::string addr = "1";
    for(int i=0; i<8; ++i) addr += ALPHABET[seed[i] % 58];
    return addr;
}

void searchWorker(int id, std::string prefix) {
    while (!found) {
        total_attempts++;
        std::string seed = std::to_string(std::time(0)) + std::to_string(id) + std::to_string(total_attempts);
        if (mockAddress(seed).substr(1, prefix.length()) == prefix) {
            found = true;
            std::cout << "\n\n[SUCCESS] Thread " << id << " found a match!" << std::endl;
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    std::string prefix = argv[1];
    unsigned int cores = std::thread::hardware_concurrency();
    
    std::cout << "Greyat Labs Benchmarker starting on " << cores << " cores..." << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < cores; ++i) threads.emplace_back(searchWorker, i, prefix);

    // Monitoring Loop
    while (!found) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        auto now = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start_time).count();
        if (elapsed > 0) {
            std::cout << "\rSpeed: " << (total_attempts / elapsed) / 1000 << " kH/s | Total Attempts: " << total_attempts << std::flush;
        }
    }

    for (auto& t : threads) t.join();
    return 0;
}
