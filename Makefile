CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc block_hasher

all: $(TARGETS)

block_hasher: block_hasher.cpp
	$(CXX) $(CXXFLAGS) block_hasher.cpp -o block_hasher

clean:
	rm -f $(TARGETS)
