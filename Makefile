CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc block_hasher pow_validator

all: $(TARGETS)

pow_validator: pow_validator.cpp
	$(CXX) $(CXXFLAGS) pow_validator.cpp -o pow_validator

clean:
	rm -f $(TARGETS)
