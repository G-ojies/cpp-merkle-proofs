CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker tx_parser varint_decoder tx_analyzer bit_visualizer header_parser

all: $(TARGETS)

header_parser: header_parser.cpp
	$(CXX) $(CXXFLAGS) header_parser.cpp -o header_parser

clean:
	rm -f $(TARGETS)
