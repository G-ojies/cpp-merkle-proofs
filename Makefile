CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGETS = merkle_proof merkle_odd merkle_verify

all: $(TARGETS)

merkle_proof: merkle_proof.cpp
	$(CXX) $(CXXFLAGS) merkle_proof.cpp -o merkle_proof

merkle_odd: merkle_odd.cpp
	$(CXX) $(CXXFLAGS) merkle_odd.cpp -o merkle_odd

merkle_verify: merkle_verify.cpp
	$(CXX) $(CXXFLAGS) merkle_verify.cpp -o merkle_verify

clean:
	rm -f $(TARGETS)
