CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc block_hasher pow_validator miner_mt miner_perf

all: $(TARGETS)

miner_perf: miner_perf.cpp
	$(CXX) $(CXXFLAGS) miner_perf.cpp -o miner_perf

clean:
	rm -f $(TARGETS)
