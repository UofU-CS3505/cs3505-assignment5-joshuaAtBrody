/* 
    By Joshua Brody u1351827, Jacob Xu u1448572
    CS3505 Assignment 5, 2/15/2024
*/

#include <iostream>
#include "trie.h"

/// @brief Default Constructor, makes an empty root node.
Trie::Trie() = default;

/// @brief uses the clearTrie method to delete the dynamic trie.
Trie::~Trie() = default;

/// @brief Copy Constructor that makes a copy of the other without changing other.
/// @param other trie to be copied from
Trie::Trie(const Trie& other) {
    root = other.root;
}

/// @brief Assignment Operator that copies other and then deletes other.
/// @param copyThisTrie trie to be copied from and deleted
/// @return A copy of other
Trie& Trie::operator=(Trie copyThisTrie) {
    std::swap(root, copyThisTrie.root);
    return *this;
}
/// @brief helper method that be able to copy node
/// @param copyFromSource copy from the source
/// @param copyToDestination copy to destination
void Trie::copyNodes(Node* copyFromSource, Node* copyToDestination) {
    if (copyFromSource == nullptr || copyToDestination == nullptr) {
        return;
    }

    for (auto& [key, val] : copyFromSource->branches) {
        copyToDestination->branches[key] = val;
        copyNodes(&(copyFromSource->branches[key]), &(copyToDestination->branches[key]));
    }
    copyToDestination->isEndOfWord = copyFromSource->isEndOfWord;
}

/// @brief Method to a word to the trie
/// @param word a lowercase string to be added
void Trie::addWord(const std::string& word) {
    Node* current = &root;
    for (char ch : word) {
        if (current->branches.find(ch) == current->branches.end()) {
            current->branches[ch] = Node();
        }
        current = &(current->branches[ch]);
    }
    current->isEndOfWord = true;
}

/// @brief Check if a word is in the trie
/// @param word the lowercase string to be found in the trie
/// @return false is word is not found, true otherwise
bool Trie::isWord(const std::string& word) {
    Node* current = &root;
    for (char ch : word) {
        if (current->branches.find(ch) == current->branches.end()) {
            return false;
        }
        current = &(current->branches[ch]);
    }
    return current->isEndOfWord;
}

/// @brief will return a group of words that begin with the given prefix
/// @param prefix a lowercase string to be compared in the trie
/// @return a vector string that contains all the words that start with the given prefix
std::vector<std::string> Trie::allWordsStartingWithPrefix(const std::string& prefix) {
    std::vector<std::string> result;
    Node* current = &root;

    // Traverse the trie until the end of the prefix
    for (char ch : prefix) {
        if (current->branches.find(ch) == current->branches.end()) {
            return result; // Prefix not found
        }
        current = &(current->branches[ch]);
    }

    // Perform DFS to get all words starting with the prefix
    // using a recursive helper function
    std::string currentWord = prefix;
    allWordsStartingWithPrefixHelper(current, currentWord, result);

    return result;
}

/// @brief Helper method to recursively search whether the current word branches to the next correct letter of the prefix
/// @param node the letter node given from the previous function the contains the next letter in the prefix to search for
/// @param currentWord the current branch we are searching for the letter
/// @param result a lowercase string with the correct word that begins with the prefix
void Trie::allWordsStartingWithPrefixHelper(Node* node, std::string& currentWord, std::vector<std::string>& result) {
    if (node->isEndOfWord) {
        result.push_back(currentWord);
    }

    for (auto& [key, val] : node->branches) {
        currentWord.push_back(key);
        allWordsStartingWithPrefixHelper(&(node->branches[key]), currentWord, result);
        currentWord.pop_back();
    }
}








