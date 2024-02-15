# Set the default value of GOOGLETEST if not provided
GOOGLETEST ?= /cs3505-assignment5-joshuaAtBrody/googletest

# Set the compiler flags
CXXFLAGS = -std=c++2a -Wall -fsanitize=address -fsanitize=undefined
LDFLAGS = -L$(GOOGLETEST)/lib
LIBS = -lgtest -lgtest_main -lpthread

# Targets
all: trieTest TrieTests test

trieTest: trie.o trieTest.o
	g++ $(CXXFLAGS) $(LDFLAGS) trie.o trieTest.o -o $@

trie.o: trie.cpp trie.h
	g++ $(CXXFLAGS) -c $< -o $@

trieTest.o: trieTest.cpp trie.h
	g++ $(CXXFLAGS) -c $< -o $@

# Build the test executable
TrieTests: trie.o trieTest.o
	g++ $(CXXFLAGS) $(LDFLAGS) trie.o trieTest.o $(LIBS) -o $(BINDIR)/$@

# Run the tests
test:
	./$(BINDIR)/TrieTests

clean:
	rm -f trieTest trie.o trieTest.o $(BINDIR)/TrieTests

.PHONY: all clean test TrieTests