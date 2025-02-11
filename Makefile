# Makefile for lecture 10, CS 3505
# involves googletest
# By Eric Heisler
# 2025-2-6


# Compiler and Flags
CC = g++
CFLAGS = -Wall -std=c++2a

# GoogleTest Path (can be overridden via command line)
GOOGLETEST ?= googletest

# Paths to GoogleTest headers and libraries
GTEST_INCLUDE = $(GOOGLETEST)/googletest/include
GTEST_LIB = $(GOOGLETEST)/lib

# Source and Object Files
SRC = trie.cpp trieTests.cpp
OBJ = trie.o trieTests.o
TARGET = TrieTests

# Default target to build everything
all: $(TARGET)

# Build the test executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -I$(GTEST_INCLUDE) -L$(GTEST_LIB) $(OBJ) -lgtest -lgtest_main -pthread -o $(TARGET)

# Compile trie implementation
trie.o: trie.cpp trie.h
	$(CC) $(CFLAGS) -c trie.cpp

# Compile test file
trieTests.o: trieTests.cpp trie.h
	$(CC) $(CFLAGS) -I$(GTEST_INCLUDE) -c trieTests.cpp

# Run the tests
test: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET) *.o