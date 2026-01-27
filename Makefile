CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGETS = MerkleTree bloom_filter script_debugger wif_converter bitcoin_crypto

all: $(TARGETS)

MerkleTree: MerkleTree.cpp
	$(CXX) $(CXXFLAGS) MerkleTree.cpp -o MerkleTree

bloom_filter: bloom_filter.cpp
	$(CXX) $(CXXFLAGS) bloom_filter.cpp -o bloom_filter

script_debugger: script_debugger.cpp
	$(CXX) $(CXXFLAGS) script_debugger.cpp -o script_debugger

wif_converter: wif_converter.cpp
	$(CXX) $(CXXFLAGS) wif_converter.cpp -o wif_converter

bitcoin_crypto: bitcoin_crypto.cpp
	$(CXX) $(CXXFLAGS) bitcoin_crypto.cpp -o bitcoin_crypto

clean:
	rm -f $(TARGETS)
