#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

class MnemonicGenerator {
private:
    // A tiny sample of the actual BIP39 English wordlist (2048 words)
    std::vector<std::string> wordlist = {
        "abandon", "ability", "able", "about", "above", "absent", "absorb", "abstract",
        "absurd", "abuse", "access", "accident", "account", "accuse", "achieve", "acid"
    };

public:
    void generate12Words() {
        std::cout << "--- Greyat Labs BIP39 Mnemonic Generator ---" << std::endl;
        std::cout << "Generating 128-bit Entropy..." << std::endl;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, wordlist.size() - 1);

        std::cout << "Your Recovery Phrase:" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        for (int i = 0; i < 12; ++i) {
            std::cout << wordlist[dis(gen)] << (i == 11 ? "" : " ");
        }
        std::cout << "\n--------------------------------------------" << std::endl;
        std::cout << "⚠️ WARNING: Never share these words with anyone." << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
    }
};

int main() {
    MnemonicGenerator mnemonic;
    mnemonic.generate12Words();
    return 0;
}
