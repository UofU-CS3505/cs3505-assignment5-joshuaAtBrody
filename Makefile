

all: trieTest

trieTest: trie.o trieTest.o
	g++ -Wall -fsanitize=address -fsanitize=undefined trie.o trieTest.o -o $@

trie.o: trie.cpp trie.h
	g++ -Wall -fsanitize=address -fsanitize=undefined -c $< -o $@

trieTest.o: trieTest.cpp trie.h
	g++ -Wall -fsanitize=address -fsanitize=undefined -c $< -o $@

clean:
	rm -f trieTest trie.o trieTest.o

test: trieTest
	trieTest words.txt queries.txt

.PHONY: all clean test