/*
Authors: Joshua Brody, Jacob
CS3505 Assignment 5, 2/15/2024
*/
#include <cassert>
#include <gtest/gtest.h>
#include"trie.h"

TEST(trieTest, basicTest){
    Trie testTrie;
    testTrie.addWord("joshua");
    
    EXPECT_TRUE(testTrie.isWord("joshua")) << "failed testTrie.isWord('joshua')";
}

