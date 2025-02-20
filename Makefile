# This is the Makefile that compiles and executes trieTest with the necesary .o files
# It also contains a clean command.
# By Nandhini Ramanathan and Ishan Sharma
# February 17, 2025

CC = g++
CFLAGS = -Wall -std=c++20
GOOGLETEST ?= googletest

trieTests: trieTests.o trie.o
	$(CC) $(CFLAGS) -o trieTests trieTests.o trie.o -L$(GOOGLETEST)/lib -lgtest -lgtest_main -lpthread

trieTests.o: trieTests.cpp
	$(CC) $(CFLAGS) -c trieTests.cpp -I$(GOOGLETEST)/googletest/include

trie.o: trie.cpp trie.h
	$(CC) $(CFLAGS) -c trie.cpp

test: trieTests
	./trieTests

clean:
	rm -f trieTests *.o