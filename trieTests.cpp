#include "trie.h"
#include <gtest/gtest.h>
#include <vector>
using namespace std;


TEST(TrieTest, AddWord) {
    Trie trie;
    trie.addWord("hello");
    EXPECT_TRUE(trie.isWord("hello"));  
}


TEST(TrieTest, IsWordFalseInEmptyTrie) {
    Trie trie;
    EXPECT_FALSE(trie.isWord("hello"));  
}

TEST(TrieTest, AllWordsStartingWithPrefix) {
    Trie trie;
    trie.addWord("car");
    vector<string> result = trie.allWordsStartingWithPrefix("car");

    EXPECT_EQ(1, result.size());           
    EXPECT_EQ("car", result[0]);          
}

TEST(TrieTest, IsWordNotAtoZ) {
    Trie trie;
    trie.addWord("car1");
             
    EXPECT_FALSE(trie.isWord("car1"));          
}

TEST(TrieTest, StartWithPrefixNotAtoZ) {
    Trie trie;
    trie.addWord("car1");
    vector<string> result = trie.allWordsStartingWithPrefix("car1");
             
    EXPECT_EQ(0, result.size());          
}

TEST(TrieTest, StartWithPrefixTrue) {
    Trie trie;
    trie.addWord("cats");
    vector<string> result = trie.allWordsStartingWithPrefix("cat");
             
    EXPECT_EQ(1, result.size()) << "Size is not 1 when testing cats only";
    EXPECT_EQ("cats", result[0]) << "Cats are not in result when testing cat prefix";
}


TEST(TrieTest, StartWithPrefixNotIncluded) {
    Trie trie;
    trie.addWord("cat");
    vector<string> result = trie.allWordsStartingWithPrefix("cats");
    
    EXPECT_EQ(0, result.size()) << "Size is not 0 when testing cat only";
}
