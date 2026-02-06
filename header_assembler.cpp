#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class HeaderAssembler {
public:
    // Helper to format hex for Bitcoin's little-endian requirements
    std::string toLittleEndian(unsigned int value) {
        std::stringstream ss;
        ss << std::hex << std::setw(8) << std::setfill('0') << value;
        std::string hex = ss.str();
        std::string result = "";
        for (int i = 6; i >= 0; i -= 2) result += hex.substr(i, 2);
        return result;
    }

    void assemble(std::string merkleRoot, std::string prevHash) {
        std::string version = toLittleEndian(1); // Version 1
        std::string timestamp = toLittleEndian(std::time(0));
        std::string bits = "ffff001d"; // Genesis-level difficulty
        
        std::cout << "--- Greyat Labs Header Assembler ---" << std::endl;
        std::cout << "Version:    " << version << std::endl;
        std::cout << "Prev Hash:  " << prevHash << std::endl;
        std::cout << "Merkle Root:" << merkleRoot << std::endl;
        std::cout << "Timestamp:  " << timestamp << std::endl;
        std::cout << "Bits:       " << bits << std::endl;
        
        std::cout << "\nReady for Mining: " << version << prevHash << merkleRoot << timestamp << bits << "00000000" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./header_assembler [merkle_root] [prev_hash]" << std::endl;
        return 1;
    }
    HeaderAssembler ha;
    ha.assemble(argv[1], argv[2]);
    return 0;
}
