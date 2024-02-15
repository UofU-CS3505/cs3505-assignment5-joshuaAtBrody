/* 
    By Joshua Brody u1351827
    CS3810 Assignment 4
*/

#include <iostream>
#include "trie.h"

// Default constructor

/// @brief Default Constructor, makes an empty root node.
Trie::Trie() : root(new Node()) {}

// Destructor

/// @brief uses the clearTrie method to delete the dynamic trie.
Trie::~Trie() {
    delete root;
    //clearTrie(root);
}

// Copy constructor

/// @brief Copy Constructor that makes a copy of the other without changing other.
/// @param other trie to be copied from
Trie::Trie(const Trie& other) {
    root = new Node();
    // for (int i = 0; i < 26; ++i) {
    //     if (other.root->branches[i] != nullptr) {
    //         root->branches[i] = new Node(*(other.root->branches[i]));
    //     }
    // }
    copyNodes(other.root, root);
}

// Assignment operator

/// @brief Assignment Operator that copies other and then deletes other.
/// @param other trie to be copied from and deleted
/// @return A copy of other
Trie& Trie::operator=(Trie other) {

    std::swap(root, other.root);
    return *this;
}

void Trie::copyNodes(Node* src, Node* dest) {
    if (src == nullptr || dest == nullptr) {
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (src->branches[i] != nullptr) {
            dest->branches[i] = new Node();
            copyNodes(src->branches[i], dest->branches[i]);
        }
    }
    dest->isEndOfWord = src->isEndOfWord;
}


// Method to add a word to the trie

/// @brief Method to a word to the trie
/// @param word a lowercase string to be added
void Trie::addWord(const std::string& word) {
    Node* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (current->branches[index] == nullptr) {
            current->branches[index] = new Node();
        }
        current = current->branches[index];
    }
    current->isEndOfWord = true;
}

// Method to check if a word is in the trie

/// @brief Check if a word is in the trie
/// @param word the lowercase string to be found in the trie
/// @return false is word is not found, true otherwise
bool Trie::isWord(const std::string& word) {
    Node* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (current->branches[index] == nullptr) {
            return false;
        }
        current = current->branches[index];
    }
    return current->isEndOfWord;
}

// Method to get all words starting with a given prefix

/// @brief will return a group of words that begin with the given prefix
/// @param prefix a lowercase string to be compared in the trie
/// @return a vector string that contains all the words that start with the given prefix
std::vector<std::string> Trie::allWordsStartingWithPrefix(const std::string& prefix) {
    std::vector<std::string> result;
    Node* current = root;

    // Traverse the trie until the end of the prefix
    for (char ch : prefix) {
        int index = ch - 'a';
        if (current->branches[index] == nullptr) {
            return result; // Prefix not found
        }
        current = current->branches[index];
    }

    // Perform DFS to get all words starting with the prefix
    // using a recursive helper function
    std::string currentWord = prefix;
    allWordsStartingWithPrefixHelper(current, currentWord, result);

    return result;
}


// Recursive helper function for DFS to get all words

/// @brief Helper method to recursively search whether the current word branches to the next correct letter of the prefix
/// @param node the letter node given from the previous function the contains the next letter in the prefix to search for
/// @param currentWord the current branch we are searching for the letter
/// @param result a lowercase string with the correct word that begins with the prefix
void Trie::allWordsStartingWithPrefixHelper(Node* node, std::string& currentWord, std::vector<std::string>& result) {
    if (node->isEndOfWord) {
        result.push_back(currentWord);
    }

    for (int i = 0; i < 26; ++i) {
        if (node->branches[i] != nullptr) {
            char ch = 'a' + i;
            currentWord.push_back(ch);
            allWordsStartingWithPrefixHelper(node->branches[i], currentWord, result);
            currentWord.pop_back();
        }
    }
}








