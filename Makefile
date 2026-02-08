CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc block_hasher pow_validator miner_mt \
          miner_perf merkle_verify mempool_sorter header_assembler \
          coinbase_gen block_template_gen

all: $(TARGETS)

block_template_gen: block_template_gen.cpp
	$(CXX) $(CXXFLAGS) block_template_gen.cpp -o block_template_gen

clean:
	rm -f $(TARGETS)
