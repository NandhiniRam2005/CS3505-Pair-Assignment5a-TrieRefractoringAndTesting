# This is the Makefile that compiles and executes trieTest with the necesary .o files
# It also contains a clean command.
# By Nandhini Ramanathan and Ishan Sharma
# February 17, 2025

CC = g++
CFLAGS = -Wall -std=c++2a
GOOGLETEST ?= ./googletest

TrieTests: trieTests.o trie.o
	$(CC) $(CFLAGS) -o TrieTests trieTests.o trie.o -L$(GOOGLETEST)/lib -lgtest -lgtest_main -lpthread

trieTests.o: trieTests.cpp
	$(CC) $(CFLAGS) -c trieTests.cpp -I$(GOOGLETEST)/googletest/include

trie.o: trie.cpp trie.h
	$(CC) $(CFLAGS) -c trie.cpp

test: TrieTests
	./TrieTests

clean:
	rm -f TrieTests *.o