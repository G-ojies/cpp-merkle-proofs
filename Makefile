CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc block_hasher pow_validator miner_mt \
          miner_perf merkle_verify mempool_sorter

all: $(TARGETS)

mempool_sorter: mempool_sorter.cpp
	$(CXX) $(CXXFLAGS) mempool_sorter.cpp -o mempool_sorter

clean:
	rm -f $(TARGETS)
