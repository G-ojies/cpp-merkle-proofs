#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

class P2PNode {
public:
    void sendVersion(std::string nodeID, int blockHeight) {
        std::cout << "--- Greyat Labs P2P Handshake ---" << std::endl;
        std::cout << "[" << nodeID << "] Sending VERSION message..." << std::endl;
        
        // Protocol fields: Version (70015), Services, Timestamp, Height
        std::cout << "  -> Protocol Version: 70015" << std::endl;
        std::cout << "  -> Timestamp: " << std::time(0) << std::endl;
        std::cout << "  -> Best Block: " << blockHeight << std::endl;
    }

    void receiveVerack(std::string nodeID) {
        std::cout << "[" << nodeID << "] Received VERACK. Connection Established! ✅" << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }
};

int main() {
    P2PNode localNode;
    
    // Simulate connecting to a peer at current block height
    localNode.sendVersion("Greyat_Labs_Node", 830000);
    localNode.receiveVerack("Remote_Peer_01");
    
    return 0;
}
