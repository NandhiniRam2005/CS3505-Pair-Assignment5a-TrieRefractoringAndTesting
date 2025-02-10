#include <gtest/gtest.h>
#include "trie.h"

TEST(TrieTest, AddWordS) {
    Trie trie;
    trie.addWord("hello");
    EXPECT_TRUE(trie.isWord("hello"));
}

TEST(TrieTest, AddWordIsWordFalseEmptyTrie) {
    Trie trie;
    EXPECT_FALSE(trie.isWord("hello"));
}

TEST(TrieTest, allWordsStartingWithPrefixISWordTrue) {
    Trie trie;
    trie.addWord("car");
    vector<string> result = trie.allWordsStartingWithPrefix("car");
    EXPECT_EQ(1, result.size());

}