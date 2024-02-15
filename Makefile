# Define the directory where googletest is located
GOOGLETEST ?= ./googletest

# Include directories for googletest
GTEST_INCLUDE_DIR = $(GOOGLETEST)/googletest/include
GTEST_LIB_DIR = $(GOOGLETEST)/lib

# Define compiler and flags
CXX = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -I$(GTEST_INCLUDE_DIR) -I.
LDFLAGS = -L$(GTEST_LIB_DIR) -lgtest_main -lgtest -pthread

# Target for the test executable
TrieTests: trieTests.cpp trie.o
	$(CXX) $(CPPFLAGS) $^ $(LDFLAGS) -o $@

# Target to run the tests
test: TrieTests
	./TrieTests

# Phony target to ensure test is always run
.PHONY: test

# Target to clean the directory
clean:
	rm -f *.o TrieTests