# Makefile
CXXFLAGS = --std=c++20 -Wall

all : test_intlist complex
	./test_intlist
	./complex

test_intlist: intlist.cpp
	g++ $(CXXFLAGS) intlist.cpp -o test_intlist

complex: complex.cpp
	g++ $(CXXFLAGS) complex.cpp -o complex


clean: 
	rm test_intlist complex