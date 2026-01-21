CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = merkle_proof

all: $(TARGET)

$(TARGET): merkle_proof.cpp
	$(CXX) $(CXXFLAGS) merkle_proof.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)
