CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGETS = MerkleTree bloom_filter script_debugger

all: $(TARGETS)

MerkleTree: MerkleTree.cpp
	$(CXX) $(CXXFLAGS) MerkleTree.cpp -o MerkleTree

bloom_filter: bloom_filter.cpp
	$(CXX) $(CXXFLAGS) bloom_filter.cpp -o bloom_filter

script_debugger: script_debugger.cpp
	$(CXX) $(CXXFLAGS) script_debugger.cpp -o script_debugger

clean:
	rm -f $(TARGETS)
