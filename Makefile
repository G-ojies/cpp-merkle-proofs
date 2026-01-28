CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_searcher_mt

all: $(TARGETS)

vanity_searcher_mt: vanity_searcher_mt.cpp
	$(CXX) $(CXXFLAGS) vanity_searcher_mt.cpp -o vanity_searcher_mt

clean:
	rm -f $(TARGETS)
