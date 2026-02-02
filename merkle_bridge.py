import subprocess

class MerkleBridge:
    def __init__(self, binary_path="./MerkleTree"):
        self.binary_path = binary_path

    def run_merkle_tool(self):
        """Calls the compiled C++ Merkle binary and returns the output."""
        try:
            # Running the compiled C++ executable from Python
            result = subprocess.run([self.binary_path], capture_output=True, text=True)
            return result.stdout
        except FileNotFoundError:
            return "Error: Compiled MerkleTree binary not found. Run 'make' first."

if __name__ == "__main__":
    bridge = MerkleBridge()
    print("--- Calling C++ Merkle Library from Python ---")
    print(bridge.run_merkle_tool())
