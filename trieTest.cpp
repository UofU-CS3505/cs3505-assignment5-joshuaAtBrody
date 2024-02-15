/*
    By Joshua Brody u1351827
    CS3810 Assignment 4
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "trie.h"

using namespace std;

// Function to read words from a file and add them to the Trie

/// @brief Reads words from a file and add them to the Trie
/// @param filename the name of the file that contains a list of lowercase words (for Makefile, it is "words.txt")
/// @param trie the trie we want to add the words to
void buildTrieFromFile(const string& filename, Trie& trie) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string word;
    while (getline(file, word)) {

        // Check for capital letters
        for (char ch : word) {
            if (isupper(ch)) {
                throw invalid_argument("Capital letters are not allowed.");
            }
        }

        trie.addWord(word);
    }

    file.close();
}

// Function to test words from a file against the Trie and print results

/// @brief Checks whether the words given in the queries.txt file are in the trie
/// @param filename A file with a list of lowercase words, used to check if those words are in the trie.
/// @param trie the trie to be checked against
void testWordsAgainstTrie(const string& filename, Trie& trie) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string query;
    while (getline(file, query)) {
        // Checking for capital letters
        for (char ch : query) {
            if (isupper(ch)) {
                throw invalid_argument("Capital letters are not allowed in the query file.");
            }
        }


        cout << "Checking " << query << ":" << endl;

        if (trie.isWord(query)) {
            cout << "Word found" << endl;

            vector<string> wordsWithPrefix = trie.allWordsStartingWithPrefix(query);
            for (const string& word : wordsWithPrefix) {
                cout << word << " ";
            }
            cout << endl;
        } else {
            cout << "Word not found" << endl << endl;
        }
    }

    file.close();
}


/// @brief the Main Testing function
/// @param argc word count, trieTest, the words file, and the queries file.
/// @param argv a character list of the given parameters
/// @return Checking Queries, and the resulting words fount from that query.
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <words_file> <queries_file>" << endl;
        return EXIT_FAILURE;
    }

    string wordsFilename = argv[1];
    string queriesFilename = argv[2];

    Trie trie;
    buildTrieFromFile(wordsFilename, trie);

    testWordsAgainstTrie(queriesFilename, trie);
    
    // Test Rule-of-Three
    Trie copiedTrie = trie; // Copy constructor
    Trie assignedTrie;
    assignedTrie = trie; // Assignment operator

    // Adding a word to one Trie and checking if it appears in the other
    copiedTrie.addWord("hello");
    cout << "Is 'hello' in original trie? " << (trie.isWord("hello") ? "Yes" : "No") << endl; // Should print "No"
    cout << "Is 'hello' in copied trie? " << (copiedTrie.isWord("hello") ? "Yes" : "No") << endl; // Should print "Yes"



    return EXIT_SUCCESS;
}




