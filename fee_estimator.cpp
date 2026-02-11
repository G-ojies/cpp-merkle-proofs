#include <iostream>
#include <string>
#include <iomanip>

class FeeEstimator {
public:
    /**
     * Estimates transaction size in vBytes.
     * Legacy P2PKH: ~148 bytes per input, 34 per output
     * SegWit P2WPKH: ~68 vBytes per input, 31 per output
     */
    void compareFees(int inputs, int outputs, double satPerVbyte) {
        int legacySize = (inputs * 148) + (outputs * 34) + 10;
        int segwitSize = (inputs * 68) + (outputs * 31) + 10;
        int multisig2of3 = (inputs * 297) + (outputs * 34) + 10; // P2SH 2-of-3 is bulky

        std::cout << "--- Greyat Labs Fee Estimator ---" << std::endl;
        std::cout << "Inputs: " << inputs << " | Outputs: " << outputs << std::endl;
        std::cout << "Market Rate: " << satPerVbyte << " sat/vB" << std::endl << std::endl;

        std::cout << std::left << std::setw(15) << "Type" << std::setw(10) << "Size(vB)" << "Total Fee (Sats)" << std::endl;
        std::cout << std::setw(15) << "Legacy" << std::setw(10) << legacySize << (legacySize * satPerVbyte) << std::endl;
        std::cout << std::setw(15) << "SegWit" << std::setw(10) << segwitSize << (segwitSize * satPerVbyte) << std::endl;
        std::cout << std::setw(15) << "Multi-Sig" << std::setw(10) << multisig2of3 << (multisig2of3 * satPerVbyte) << std::endl;
        
        std::cout << "\nSavings by using SegWit: " << (((double)legacySize - segwitSize) / legacySize) * 100 << "%" << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    double rate = (argc > 1) ? std::stod(argv[1]) : 25.0; // Default to 25 sat/vB
    FeeEstimator estimator;
    estimator.compareFees(1, 2, rate);
    return 0;
}
