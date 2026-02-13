#include <iostream>
#include <string>
#include <set>
#include <vector>

struct Transaction {
    std::string txid;
    std::string inputSource; // The TXID of the output it is spending
};

class UTXOAuditor {
private:
    std::set<std::string> utxoSet; // Valid, unspent outputs

public:
    void addUTXO(std::string txid) {
        utxoSet.insert(txid);
    }

    bool validateTransaction(Transaction tx) {
        std::cout << "--- Greyat Labs UTXO Auditor ---" << std::endl;
        std::cout << "Checking TX: " << tx.txid << " | Spending: " << tx.inputSource << std::endl;

        // Check if the source output is in the UTXO set
        if (utxoSet.find(tx.inputSource) != utxoSet.end()) {
            std::cout << "✅ VALID: Output is unspent. Updating UTXO set..." << std::endl;
            utxoSet.erase(tx.inputSource); // Output is now spent
            utxoSet.insert(tx.txid);       // New output created
            return true;
        } else {
            std::cout << "❌ REJECTED: Double-spend detected or output does not exist!" << std::endl;
            return false;
        }
    }
};

int main() {
    UTXOAuditor auditor;
    
    // 1. Initial State: Miner gets a coinbase reward
    auditor.addUTXO("coinbase_tx");

    // 2. First spend (Valid)
    Transaction tx1 = {"user_a_payment", "coinbase_tx"};
    auditor.validateTransaction(tx1);

    // 3. Second spend of the same input (Invalid/Double-Spend)
    Transaction tx2 = {"malicious_tx", "coinbase_tx"};
    auditor.validateTransaction(tx2);

    return 0;
}
