CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc block_hasher pow_validator miner_mt \
          miner_perf merkle_verify mempool_sorter header_assembler coinbase_gen

all: $(TARGETS)

coinbase_gen: coinbase_gen.cpp
	$(CXX) $(CXXFLAGS) coinbase_gen.cpp -o coinbase_gen

clean:
	rm -f $(TARGETS)
