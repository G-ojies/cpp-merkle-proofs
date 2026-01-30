#include <iostream>
#include <string>
#include <vector>

class TxAnalyzer {
public:
    // Decodes Bitcoin VarInt (CompactSize)
    unsigned long decodeVarInt(std::string hex, int& bytesRead) {
        unsigned int first = std::stoul(hex.substr(0, 2), nullptr, 16);
        if (first < 0xFD) { bytesRead = 1; return first; }
        if (first == 0xFD) { bytesRead = 3; return std::stoul(hex.substr(2, 4), nullptr, 16); }
        bytesRead = 5; return std::stoul(hex.substr(2, 8), nullptr, 16);
    }

    void analyze(std::string rawTx) {
        std::cout << "--- Greyat Labs TX Analyzer ---" << std::endl;
        
        // 1. Version: 4 bytes (8 hex chars)
        std::cout << "Version: " << rawTx.substr(0, 8) << std::endl;

        // 2. Input Count (VarInt starts at index 8)
        int bytesRead = 0;
        unsigned long inCount = decodeVarInt(rawTx.substr(8), bytesRead);
        std::cout << "Inputs: " << inCount << " (VarInt size: " << bytesRead << " bytes)" << std::endl;

        // 3. Finding Output Count
        // Real parsing requires skipping each input's variable length.
        // For this demo, we show the structural logic.
        std::cout << "Status: Linear parsing initialized. Ready for deep scan." << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    TxAnalyzer analyzer;
    analyzer.analyze(argv[1]);
    return 0;
}
