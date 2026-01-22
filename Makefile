all: merkle_proof merkle_odd

merkle_proof: merkle_proof.cpp
	g++ -std=c++17 merkle_proof.cpp -o merkle_proof

merkle_odd: merkle_odd.cpp
	g++ -std=c++17 merkle_odd.cpp -o merkle_odd

clean:
	rm -f merkle_proof merkle_odd
