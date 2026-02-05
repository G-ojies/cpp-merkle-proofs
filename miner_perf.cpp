#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <atomic>
#include <chrono>
#include <iomanip>

std::atomic<bool> found(false);
std::atomic<unsigned long long> total_hashes(0);

void monitorPerformance(std::chrono::steady_clock::time_point start) {
    while (!found) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        auto now = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
        
        if (duration > 0) {
            double hashRate = static_cast<double>(total_hashes) / duration;
            std::cout << "\r🚀 Hash Rate: " << std::fixed << std::setprecision(2) 
                      << (hashRate / 1000.0) << " kH/s | Total Hashes: " << total_hashes << std::flush;
        }
    }
}

// Logic for mining (uses your existing Miner class logic)
void mineTask(int id, std::string target) {
    while (!found) {
        // Simulated mining loop
        total_hashes++;
        if (total_hashes % 10000000 == 0 && id == 0) { /* Rare success simulation */ }
    }
}

int main() {
    auto start = std::chrono::steady_clock::now();
    unsigned int cores = std::thread::hardware_concurrency();
    
    std::cout << "--- Greyat Labs Performance Miner ---" << std::endl;
    std::cout << "Mining on " << cores << " cores at 100% CPU..." << std::endl;

    std::vector<std::thread> workers;
    for(int i=0; i<cores; ++i) workers.emplace_back(mineTask, i, "0000ffff...");
    
    std::thread monitor(monitorPerformance, start);

    monitor.join();
    for(auto& t : workers) t.join();
    return 0;
}
