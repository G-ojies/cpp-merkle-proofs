#include <iostream>
#include <string>
#include <vector>
#include <cstdint> // Required for uint32_t

struct Transaction {
    std::string txid;
    int fee;
    int vbytes;
    uint32_t sequence; // Use unsigned 32-bit int to match Bitcoin protocol

    double feeRate() const { return static_cast<double>(fee) / vbytes; }
};

class RBFSimulator {
public:
    void evaluateReplacement(Transaction existing, Transaction candidate) {
        std::cout << "--- Greyat Labs RBF Simulator ---" << std::endl;
        
        // Rule: Existing must signal RBF (Sequence < 0xffffffff)
        bool signalsRBF = (existing.sequence < 0xffffffffU); // Added 'U' for unsigned literal
        bool higherFee = (candidate.fee > existing.fee);
        bool higherRate = (candidate.feeRate() > existing.feeRate());

        if (signalsRBF && higherFee && higherRate) {
            std::cout << "✅ STATUS: REPLACEMENT ACCEPTED" << std::endl;
        } else {
            std::cout << "❌ STATUS: REPLACEMENT REJECTED" << std::endl;
        }
    }
};

int main() {
    // 0xfffffffd correctly signals RBF participation
    Transaction oldTx = {"tx_stuck", 500, 250, 0xfffffffdU}; 
    Transaction newTx = {"tx_bumped", 1500, 250, 0xffffffffU}; 

    RBFSimulator sim;
    sim.evaluateReplacement(oldTx, newTx);
    return 0;
}
