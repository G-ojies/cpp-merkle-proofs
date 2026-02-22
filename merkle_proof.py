import hashlib

def dsha256(data):
    """Double SHA-256 hash"""
    return hashlib.sha256(hashlib.sha256(data).digest()).digest()

def generate_merkle_proof(txids, target_txid):
    """Generates the proof path for a specific TXID."""
    if target_txid not in txids:
        return None, "Error: TXID not found."

    level = [bytes.fromhex(txid)[::-1] for txid in txids]
    target_idx = txids.index(target_txid)
    proof = []

    print(f"🎯 Target TXID: {target_txid}")
    print("=" * 60)

    while len(level) > 1:
        next_level = []
        next_target_idx = target_idx // 2
        
        for i in range(0, len(level), 2):
            left = level[i]
            right = level[i+1] if i + 1 < len(level) else left
            
            # If our target is in this pair, save its sibling
            if i == target_idx or (i + 1 == target_idx):
                is_left = (target_idx % 2 == 0)
                sibling = right if is_left else left
                direction = "Right" if is_left else "Left"
                
                proof.append((direction, sibling[::-1].hex()))
                
                print(f"Level {len(proof)}: Hash with {direction} Sibling -> {sibling[::-1].hex()[:16]}...")
            
            next_level.append(dsha256(left + right))
            
        level = next_level
        target_idx = next_target_idx
        
    root = level[0][::-1].hex()
    print("-" * 60)
    print(f"🌳 Generated Root: {root}\n")
    return proof, root

def verify_merkle_proof(target_txid, proof, expected_root):
    """Verifies the proof path against the expected Merkle Root."""
    print("🔍 Verifying Proof...")
    
    # Start with the target TXID in little-endian
    current_hash = bytes.fromhex(target_txid)[::-1]
    
    for direction, sibling_hex in proof:
        sibling_hash = bytes.fromhex(sibling_hex)[::-1]
        
        # Order matters! Concatenate based on the sibling's position
        if direction == "Right":
            combined = current_hash + sibling_hash
        else:
            combined = sibling_hash + current_hash
            
        # Hash the pair to move up one level
        current_hash = dsha256(combined)
        
    calculated_root = current_hash[::-1].hex()
    
    print(f"Calculated Root: {calculated_root}")
    print(f"Expected Root:   {expected_root}")
    
    is_valid = (calculated_root == expected_root)
    print(f"✅ VALID!" if is_valid else f"❌ INVALID!")
    return is_valid

if __name__ == "__main__":
    # A small block of 5 transactions
    tx_list = [
        "8c14f0db3df150123e6f3defd38446ab05e810cb994f72db352c383e29f10926", # Target
        "fff2525b8931402dd09222c50775608f75787bd2b87e56995a7bdd30f79702c4",
        "6359f0868171b1d194cbee1af2f16ea598ae8fad666d9b012c8ed2b79a236ec4",
        "e9a66845e05d5abc0ad04ec80f774a7e585c6e8db975962d069a522137b80c1d",
        "a1b2c3d4e5f6a7b8c9d0e1f2a3b4c5d6e7f8a9b0c1d2e3f4a5b6c7d8e9f0a1b2"
    ]

    target = tx_list[0]
    
    # Node generates the proof
    proof_path, actual_root = generate_merkle_proof(tx_list, target)
    
    # Wallet verifies the proof
    verify_merkle_proof(target, proof_path, actual_root)
