## 🎓 Certifications
- **CS120: Bitcoin for Developers I** - Saylor Academy 
  - **Grade:** 100% 
  - **Issue Date:** January 31, 2026 
  - **Topics:** Bitcoin Protocol, Cryptography, Scripting, and Network Consensus 

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

## Example Usage
You can run the tool with real-world Bitcoin Transaction IDs to verify the Merkle Root calculation.

### Even Set (4 Transactions)
`./MerkleTree f4184fc596403b9d638783cf57adfe4c75c605f6356fbc91338530e9831e9e16 6cd9ff242a04dbb6b0683c2b8576c397f341b7f0c1747b206f878db597a4cd01 8c14f0db3df150123e6f3dbbf30f8b955a8249b62ac1d1ff16284aefa3d06d87 f66f6ab609d242edf266782139ddd6214777c4e5080f017d15cb9aa431dda351`

### Odd Set (5 Transactions - Testing Duplication Logic)
`./MerkleTree f4184fc596403b9d638783cf57adfe4c75c605f6356fbc91338530e9831e9e16 6cd9ff242a04dbb6b0683c2b8576c397f341b7f0c1747b206f878db597a4cd01 8c14f0db3df150123e6f3dbbf30f8b955a8249b62ac1d1ff16284aefa3d06d87 f66f6ab609d242edf266782139ddd6214777c4e5080f017d15cb9aa431dda351 50ba87bdd484f07c8c55f76a22982f987c0465fdc345381b4634a70dc0ea0b38`
