CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

TARGETS = MerkleTree bloom_filter script_debugger wif_converter vanity_searcher_mt vanity_benchmarker

all: $(TARGETS)

vanity_benchmarker: vanity_benchmarker.cpp
	$(CXX) $(CXXFLAGS) vanity_benchmarker.cpp -o vanity_benchmarker

clean:
	rm -f $(TARGETS)
