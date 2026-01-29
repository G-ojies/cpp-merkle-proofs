#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class TxParser {
public:
    // Converts a hex string fragment to a long integer
    long hexToLong(std::string hex) {
        long value;
        std::stringstream ss;
        ss << std::hex << hex;
        ss >> value;
        return value;
    }

    void parseRaw(std::string rawTx) {
        std::cout << "--- Greyat Labs Bitcoin TX Parser ---" << std::endl;
        
        // 1. Version (First 4 bytes / 8 hex chars)
        std::string versionHex = rawTx.substr(0, 8);
        std::cout << "Version (Hex): " << versionHex << " | Decimal: " << hexToLong(versionHex) << std::endl;

        // 2. Simplified Locktime (Last 4 bytes / 8 hex chars)
        std::string locktimeHex = rawTx.substr(rawTx.length() - 8);
        std::cout << "Locktime (Hex): " << locktimeHex << " | Decimal: " << hexToLong(locktimeHex) << std::endl;
        
        std::cout << "-------------------------------------" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./tx_parser [raw_hex_tx]" << std::endl;
        return 1;
    }
    
    TxParser parser;
    parser.parseRaw(argv[1]);
    return 0;
}
