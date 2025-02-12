# This is the Makefile that compiles and executes trieTest with the necesary .o files
# It also contains a clean command

CC = g++
CFLAGS = -Wall -std=c++2a
GOOGLETEST ?= /root/cs3505/cs3505-assignment5a-NandhiniRam2005/googletest

TrieTests: trieTests.o trie.o
	$(CC) $(CFLAGS) -L$(GOOGLETEST)/lib -o TrieTests trieTests.o trie.o -lgtest -lgtest_main -pthread

trieTests.o: trieTests.cpp trie.h
	$(CC) $(CFLAGS) -I$(GOOGLETEST)/googletest/include -c trieTests.cpp

trie.o: trie.cpp trie.h
	$(CC) $(CFLAGS) -c trie.cpp

test: TrieTests
	./TrieTests

clean:
	rm -f TrieTests *.o