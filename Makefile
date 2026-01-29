CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker tx_parser

all: $(TARGETS)

tx_parser: tx_parser.cpp
	$(CXX) $(CXXFLAGS) tx_parser.cpp -o tx_parser

clean:
	rm -f $(TARGETS)
