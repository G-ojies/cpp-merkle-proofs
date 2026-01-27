CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGETS = MerkleTree bloom_filter script_debugger bitcoin_wif_lib

all: $(TARGETS)

MerkleTree: MerkleTree.cpp
	$(CXX) $(CXXFLAGS) MerkleTree.cpp -o MerkleTree

bloom_filter: bloom_filter.cpp
	$(CXX) $(CXXFLAGS) bloom_filter.cpp -o bloom_filter

script_debugger: script_debugger.cpp
	$(CXX) $(CXXFLAGS) script_debugger.cpp -o script_debugger

bitcoin_wif_lib: bitcoin_wif_lib.cpp
	$(CXX) $(CXXFLAGS) bitcoin_wif_lib.cpp -o bitcoin_wif_lib

clean:
	rm -f $(TARGETS)
