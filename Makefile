CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker tx_parser varint_decoder tx_analyzer

all: $(TARGETS)

tx_analyzer: tx_analyzer.cpp
	$(CXX) $(CXXFLAGS) tx_analyzer.cpp -o tx_analyzer

clean:
	rm -f $(TARGETS)
