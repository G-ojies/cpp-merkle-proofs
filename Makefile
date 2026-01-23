# Define the compiler and standards
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# The default target that runs when you type 'make'
all: MerkleTree

# The build rule
MerkleTree: MerkleTree.cpp
	$(CXX) $(CXXFLAGS) MerkleTree.cpp -o MerkleTree

# The clean rule
clean:
	rm -f MerkleTree
