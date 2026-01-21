# C++ Merkle Proof Generator

A systems-level implementation of **Simplified Payment Verification (SPV)** logic. This tool demonstrates how a Merkle Proof (a "Proof Path") can verify that a specific transaction exists within a block without requiring the full block data.

### 🚀 Key Features
- **Merkle Tree Construction:** Recursively hashes transaction pairs to reach a single Merkle Root.
- **Proof Path Generation:** Identifies the minimum set of sibling hashes needed to reconstruct the root from a single leaf.
- **Light Client Verification:** Simulates the process used by mobile wallets to verify inclusion using only $O(log_2 N)$ data.
- **Memory Safety:** Built using modern C++ standards to ensure efficient resource management.

### 🛠 Technical Highlights
- **Algorithm:** Uses a binary Merkle tree structure.
- **Efficiency:** Verification complexity is $O(log_2 N)$, where N is the number of transactions.
- **Language:** Written in pure C++ (Standard 17) with a dedicated Makefile for automated builds.

### 📖 Why this project?
As part of my preparation for **Summer of Bitcoin 2026**, this project serves as a deep dive into the cryptographic foundations of the Bitcoin protocol, specifically focusing on how the network maintains trust and efficiency for non-full-node participants.
