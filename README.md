## 🎓 Certifications
- [cite_start]**CS120: Bitcoin for Developers I** - Saylor Academy [cite: 4, 12]
  - [cite_start]**Grade:** 100% [cite: 17]
  - [cite_start]**Issue Date:** January 31, 2026 [cite: 5, 13]
  - [cite_start]**Topics:** Bitcoin Protocol, Cryptography, Scripting, and Network Consensus [cite: 4, 12]

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
make
## 🌐 Protocol Context: BIP-37
This library implements the mathematical foundation of **BIP-37 (Bloom Filters for SPV)**. While BIP-37 manages how Light Clients request data privately, the `MerkleTree` class provided here handles the actual construction of the **MerkleBlock** messages sent by Full Nodes to satisfy those requests.

## 🧪 Automated Testing
Run `./spv_workflow.sh` to simulate a full SPV cycle from Bloom Filter lookup to Merkle Root verification.
