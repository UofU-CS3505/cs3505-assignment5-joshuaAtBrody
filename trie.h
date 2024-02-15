/*
    By Joshua Brody u1351827
    CS3810 Assignment 4
*/

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include <vector>


/// @brief A class for storing words by connection their letters with Nodes using a trie. 
class Trie{
    private:

    /// @brief A private Node struct to act as the tree/trie and checks if the current node is the end of some word.
    struct Node {
        Node* branches[26];
        bool isEndOfWord;

        Node() : isEndOfWord(false) {
            for (int i = 0; i < 26; ++i) {
                branches[i] = nullptr;
            }
        }

        ~Node() { // Destructor for Node class
            for (int i = 0; i < 26; ++i) {
                if (branches[i] != nullptr) {
                    delete branches[i]; // Recursively delete child nodes
                }
            }
        }
    };

    /// @brief the first letter of any given word
    Node* root;

    void copyNodes(Node* src, Node* dest);

    public:
    Trie();  // Default constructor
    ~Trie(); // Destructor
    Trie(const Trie& other); // Copy constructor
    Trie& operator=(Trie other); // Assignment operator

    void addWord(const std::string& word);
    bool isWord(const std::string& word);
    std::vector<std::string> allWordsStartingWithPrefix(const std::string& prefix);

    void allWordsStartingWithPrefixHelper(Node* node, std::string& currentWord, std::vector<std::string>& result);


};


#endif