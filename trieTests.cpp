/*
Authors: Joshua Brody, Jacob Xu
CS3505 Assignment 5, 2/15/2024
*/
#include <cassert>
#include <gtest/gtest.h>
#include"trie.h"

// Test case to verify basic functionality of addWord and isWord methods
TEST(TrieTest, BasicFunctionality) {
    Trie trie;
    // Add words to the trie
    trie.addWord("hello");
    trie.addWord("world");

    // Check if words are present in the trie
    EXPECT_TRUE(trie.isWord("hello"));
    EXPECT_TRUE(trie.isWord("world"));
    EXPECT_FALSE(trie.isWord("foo"));
}

// Test case to verify behavior with empty trie
TEST(TrieTest, EmptyTrie) {
    Trie trie;
    // Check if empty trie correctly handles word check
    EXPECT_FALSE(trie.isWord("hello"));
}

// Test case to verify behavior with words starting with a common prefix
TEST(TrieTest, WordsWithCommonPrefix) {
    Trie trie;
    // Add words with common prefix to the trie
    trie.addWord("apple");
    trie.addWord("app");
    trie.addWord("application");

    // Check words with common prefix
    EXPECT_TRUE(trie.isWord("apple"));
    EXPECT_TRUE(trie.isWord("app"));
    EXPECT_TRUE(trie.isWord("application"));
}

// Test case to verify behavior with words starting with a common prefix
TEST(TrieTest, WordsWithCommonPrefixIndex) {
    Trie trie;
    // Add words with common prefix to the trie
    trie.addWord("apple");
    trie.addWord("app");
    trie.addWord("application");

    // Check words with common prefix
    EXPECT_EQ("apple", trie[0]);
}

// Test case to verify behavior of allWordsStartingWithPrefix method
TEST(TrieTest, AllWordsStartingWithPrefix) {
    Trie trie;
    // Add words to the trie
    trie.addWord("apple");
    trie.addWord("app");
    trie.addWord("application");

    // Get words starting with prefix "app"
    std::vector<std::string> wordsWithPrefix = trie.allWordsStartingWithPrefix("app");

    // Debugging output to print the words returned by the method
    std::cout << "Words starting with prefix 'app': ";
    for (const auto& word : wordsWithPrefix) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Check if the correct words are returned
    EXPECT_EQ(wordsWithPrefix.size(), 3);
    EXPECT_TRUE(std::find(wordsWithPrefix.begin(), wordsWithPrefix.end(), "app") != wordsWithPrefix.end());
    EXPECT_TRUE(std::find(wordsWithPrefix.begin(), wordsWithPrefix.end(), "application") != wordsWithPrefix.end());
}


// Test case to verify copy constructor and assignment operator behavior
TEST(TrieTest, CopyConstructorAndAssignment) {
    Trie trie;
    // Add words to the original trie
    trie.addWord("hello");
    trie.addWord("world");

    // Create a new trie using copy constructor
    Trie copiedTrie(trie);

    // Check if the copied trie contains the same words
    EXPECT_TRUE(copiedTrie.isWord("hello"));
    EXPECT_TRUE(copiedTrie.isWord("world"));

    // Modify the original trie
    trie.addWord("foo");

    // Check if modification in original trie affects copied trie
    EXPECT_FALSE(copiedTrie.isWord("foo"));

    // Create another trie and assign the original trie to it
    Trie assignedTrie;
    assignedTrie = trie;

    // Check if the assigned trie contains the same words
    EXPECT_TRUE(assignedTrie.isWord("hello"));
    EXPECT_TRUE(assignedTrie.isWord("world"));
    EXPECT_TRUE(assignedTrie.isWord("foo"));
}

TEST(trieTest, basicTest){
    Trie trie;
    Trie testTrie;
    testTrie.addWord("joshua");
    
    EXPECT_TRUE(testTrie.isWord("joshua")) << "failed testTrie.isWord('joshua')";
}

// Main function to run all the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


