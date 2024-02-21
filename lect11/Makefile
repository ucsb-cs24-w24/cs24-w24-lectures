# Makefile
# Include -g flag to get debugging information
# valgrind: memory check and produces a report
all: test twosum

test: stl_hashtable.cpp
	g++ -g --std=c++11 stl_hashtable.cpp -o test

twosum: twosum.cpp
	g++ -g --std=c++11 twosum.cpp -o twosum

clean:
	rm test
