CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker \
          tx_parser varint_decoder tx_analyzer bit_visualizer header_parser \
          difficulty_calc reward_calc

all: $(TARGETS)

reward_calc: reward_calc.cpp
	$(CXX) $(CXXFLAGS) reward_calc.cpp -o reward_calc

clean:
	rm -f $(TARGETS)
