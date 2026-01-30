CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker tx_parser varint_decoder tx_analyzer bit_visualizer

all: $(TARGETS)

bit_visualizer: bit_visualizer.cpp
	$(CXX) $(CXXFLAGS) bit_visualizer.cpp -o bit_visualizer

clean:
	rm -f $(TARGETS)
