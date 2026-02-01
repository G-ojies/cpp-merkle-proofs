#include <iostream>
#include <string>
#include <vector>

class PoWValidator {
public:
    /**
     * Compares the block hash against the target.
     * In Bitcoin, a hash is valid only if it is LOWER than the target.
     */
    bool isValid(std::string hash, std::string target) {
        // Hexadecimal comparison works alphabetically in C++
        return hash < target;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./pow_validator [block_hash] [target_hash]" << std::endl;
        return 1;
    }

    std::string hash = argv[1];
    std::string target = argv[2];
    PoWValidator validator;

    std::cout << "--- Greyat Labs PoW Validator ---" << std::endl;
    std::cout << "Block Hash: " << hash << std::endl;
    std::cout << "Target:     " << target << std::endl;

    if (validator.isValid(hash, target)) {
        std::cout << "\n[RESULT] VALID: Hash meets the difficulty requirement! 🟢" << std::endl;
    } else {
        std::cout << "\n[RESULT] INVALID: Hash is too high. Keep mining. 🔴" << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;

    return 0;
}
