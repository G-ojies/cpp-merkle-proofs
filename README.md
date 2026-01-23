# 🛡️ MerkleTree-Cpp: A Bitcoin-Standard Library
**Developed by Greyat Labs | Stephen**

A professional C++ implementation of the **Merkle Tree** data structure, specifically optimized to follow the Bitcoin protocol's rules for Simplified Payment Verification (SPV).



## 🚀 Key Features
- **Bitcoin Compliance:** Implements the specific "last-hash duplication" rule for blocks with an odd number of transactions.
- **SPV Verification:** Includes a logarithmic-time ($O(log_2 N)$) verification function for light client transaction proof.
- **Unified Class Architecture:** Refactored from procedural scripts into a clean, reusable C++ class for better scalability.
- **Interoperability:** Includes a Python bridge (`merkle_bridge.py`) for automated testing and scripting.

## 🛠️ Installation & Usage
Ensure you have `g++` and `make` installed on your Linux system.

```bash
# Clone the repository
git clone [https://github.com/G-ojies/cpp-merkle-proofs.git](https://github.com/G-ojies/cpp-merkle-proofs.git)
cd cpp-merkle-proofs

# Build the library
make

# Run the C++ example
./MerkleTree

# Run the Python test bridge
python3 merkle_bridge.py
