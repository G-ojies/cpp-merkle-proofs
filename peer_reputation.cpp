#include <iostream>
#include <string>
#include <map>

struct PeerStats {
    int misbehaviorScore = 0;
    bool isBanned = false;
    std::string lastViolation = "None";
};

class ReputationManager {
private:
    std::map<std::string, PeerStats> peerMap;
    const int BAN_THRESHOLD = 100;

public:
    void reportViolation(std::string ip, int penalty, std::string reason) {
        PeerStats& peer = peerMap[ip];
        
        if (peer.isBanned) return;

        peer.misbehaviorScore += penalty;
        peer.lastViolation = reason;

        std::cout << "⚠️ [VIOLATION] " << ip << " penalized " << penalty 
                  << " points for: " << reason << std::endl;

        if (peer.misbehaviorScore >= BAN_THRESHOLD) {
            peer.isBanned = true;
            std::cout << "🚫 [BAN] Peer " << ip << " has been banned (Score: " 
                      << peer.misbehaviorScore << ")" << std::endl;
        }
    }

    void checkPeer(std::string ip) {
        if (peerMap.count(ip)) {
            std::cout << "Peer " << ip << " | Score: " << peerMap[ip].misbehaviorScore 
                      << " | Status: " << (peerMap[ip].isBanned ? "BANNED" : "OK") << std::endl;
        }
    }
};

int main() {
    ReputationManager netGuard;
    std::string maliciousPeer = "192.168.1.50";

    std::cout << "--- Greyat Labs Peer Reputation System ---" << std::endl;

    // Simulate sequence of violations
    netGuard.reportViolation(maliciousPeer, 20, "Invalid Transaction Signature");
    netGuard.reportViolation(maliciousPeer, 50, "Mangled Merkle Proof");
    netGuard.reportViolation(maliciousPeer, 40, "Invalid Block Header");

    std::cout << "\n--- Final Network Audit ---" << std::endl;
    netGuard.checkPeer(maliciousPeer);
    netGuard.checkPeer("127.0.0.1"); // A good peer

    return 0;
}
