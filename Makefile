# Makefile for lecture 10, CS 3505
# involves googletest
# By Eric Heisler
# 2025-2-6
CC = g++
CFLAGS = -Wall
GOOGLETEST ?= ../googletest

trieTests: trieTests.o trie.o
	$(CC) $(CFLAGS) -o trieTests -I$(GOOGLETEST)/googletest/include -L$(GOOGLETEST)/lib trieTests.o trie.o -lgtest -lgtest_main

trieTests.o: trieTests.cpp trie.h
	$(CC) $(CFLAGS) -c trieTests.cpp

trie.o: trie.cpp trie.h
	$(CC) $(CFLAGS) -c trie.cpp

test: trieTest
	./trieTest

clean:
	rm -f trieTest *.o
