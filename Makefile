CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: MerkleTree bloom_filter

MerkleTree: MerkleTree.cpp
	$(CXX) $(CXXFLAGS) MerkleTree.cpp -o MerkleTree

bloom_filter: bloom_filter.cpp
	$(CXX) $(CXXFLAGS) bloom_filter.cpp -o bloom_filter

clean:
	rm -f MerkleTree bloom_filter
