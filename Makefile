CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_benchmarker tx_parser varint_decoder

all: $(TARGETS)

varint_decoder: varint_decoder.cpp
	$(CXX) $(CXXFLAGS) varint_decoder.cpp -o varint_decoder

clean:
	rm -f $(TARGETS)
