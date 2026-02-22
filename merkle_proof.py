import hashlib

def dsha256(data):
    """Double SHA-256 hash"""
    return hashlib.sha256(hashlib.sha256(data).digest()).digest()

def generate_merkle_proof(txids, target_txid):
    if target_txid not in txids:
        return "Error: TXID not found in the list."

    # 1. Convert hex strings (big-endian display) to little-endian bytes
    level = [bytes.fromhex(txid)[::-1] for txid in txids]
    target_idx = txids.index(target_txid)
    
    proof = []
    
    print(f"🎯 Target TXID: {target_txid}")
    print("=" * 60)

    # 2. Build the tree level by level
    while len(level) > 1:
        next_level = []
        next_target_idx = target_idx // 2
        
        for i in range(0, len(level), 2):
            left = level[i]
            # Handle odd number of items by duplicating the last one
            right = level[i+1] if i + 1 < len(level) else left
            
            # 3. If our target is in this pair, save its sibling for the proof
            if i == target_idx or (i + 1 == target_idx):
                is_left = (target_idx % 2 == 0)
                sibling = right if is_left else left
                direction = "Right" if is_left else "Left "
                
                # Store the direction and the hex (converted back to big-endian for display)
                proof.append((direction.strip(), sibling[::-1].hex()))
                
                print(f"Level {len(proof)}:")
                print(f"  Target Hash : {level[target_idx][::-1].hex()[:16]}...")
                print(f"  Sibling ({direction}): {sibling[::-1].hex()[:16]}...")
                print("-" * 60)
            
            # Hash the pair together
            next_level.append(dsha256(left + right))
            
        level = next_level
        target_idx = next_target_idx
        
    print(f"🌳 Merkle Root: {level[0][::-1].hex()}")
    return proof

if __name__ == "__main__":
    # A small block of 5 transactions
    tx_list = [
        "8c14f0db3df150123e6f3defd38446ab05e810cb994f72db352c383e29f10926", # Target
        "fff2525b8931402dd09222c50775608f75787bd2b87e56995a7bdd30f79702c4",
        "6359f0868171b1d194cbee1af2f16ea598ae8fad666d9b012c8ed2b79a236ec4",
        "e9a66845e05d5abc0ad04ec80f774a7e585c6e8db975962d069a522137b80c1d",
        "a1b2c3d4e5f6a7b8c9d0e1f2a3b4c5d6e7f8a9b0c1d2e3f4a5b6c7d8e9f0a1b2"
    ]

    # Generate the proof for the first transaction
    generate_merkle_proof(tx_list, tx_list[0])
