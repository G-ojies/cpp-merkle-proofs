#!/bin/bash

# 1. Build the tools
echo "--- Step 1: Compiling SPV Toolkit ---"
make clean && make

# 2. Run the Bloom Filter (The Search)
echo -e "\n--- Step 2: Simulating Wallet Search (Bloom Filter) ---"
./bloom_filter

# 3. Run the Merkle Tree (The Proof)
echo -e "\n--- Step 3: Generating Merkle Proof for Match ---"
./MerkleTree

echo -e "\n--- Workflow Complete: Transaction Found and Verified ---"
