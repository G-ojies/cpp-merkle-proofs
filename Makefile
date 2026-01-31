CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker tx_parser varint_decoder tx_analyzer bit_visualizer header_parser difficulty_calc

all: $(TARGETS)

difficulty_calc: difficulty_calc.cpp
	$(CXX) $(CXXFLAGS) difficulty_calc.cpp -o difficulty_calc

clean:
	rm -f $(TARGETS)
