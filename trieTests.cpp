#include "trie.h"
#include <gtest/gtest.h>
#include <vector>
using namespace std;

TEST(TrieTest, AddOneWordIsWordTrue) {
    Trie trie;
    trie.addWord("hello");
    EXPECT_TRUE(trie.isWord("hello"));
}

TEST(TrieTest, AddOneWordIsWordFalse) {
}

TEST(TrieTest, AddDuplicateWordIsWordTrue) {
}

TEST(TrieTest, AddMultipleWordsIsWordsTrue) {
}

TEST(TrieTest, AddWordsWithSamePrefixIsWordFalse) {
}

TEST(TrieTest, IsWordFalseInEmptyTrie) {
    Trie trie;
    EXPECT_FALSE(trie.isWord("hello"));  
}

TEST(TrieTest, IsTrueOneLetterWord) {
}

TEST(TrieTest, IsWordIncompleteVersionsofAddedWord) {
}

TEST(TrieTest, AllWordsStartingWithPrefixSameWord) {
    Trie trie;
    trie.addWord("car");
    vector<string> result = trie.allWordsStartingWithPrefix("car");

    EXPECT_EQ(1, result.size());           
    EXPECT_EQ("car", result[0]);          
}

TEST(TrieTest, AllWordsStartingWithPrefixNormalCaseMultipleWords) {     
}

TEST(TrieTest, AllWordsStartingWithPrefixSomeAreFalse) {     
}

TEST(TrieTest, AllWordsStartingWithOneWordPrefix) {     
}

TEST(TrieTest, IsWordNotAtoZ) {
    Trie trie;
    trie.addWord("car1");
             
    EXPECT_FALSE(trie.isWord("car1"));          
}

TEST(TrieTest, IsWordWeirdCharacters) {       
}

TEST(TrieTest, StartWithPrefixNotAtoZ) {
    Trie trie;
    trie.addWord("car1");
    vector<string> result = trie.allWordsStartingWithPrefix("car1");
             
    EXPECT_EQ(0, result.size());          
}

TEST(TrieTest, StartWithPrefixWeirdCharacters) {       
}

TEST(TrieTest, IsWordNotAtoZCapitalLetters) {     
}

TEST(TrieTest, IsWordBoundaryCasesAAndZ) {     
}

TEST(TrieTest, IsWordBoundaryCasesBAndY) {     
}

TEST(TrieTest, IsWordEdgeCasesBLABLABLALA) {     
}

TEST(TrieTest, StartPrefixBoundaryCasesAAndZ) {     
}

TEST(TrieTest, StartPrefixBoundaryCasesBAndY) {     
}

TEST(TrieTest, StartPrefixEdgeCasesBLABLABLALA) {     
}

TEST(TrieTest, StartWithPrefixNotAtoZCapitalLetters) {    
}

TEST(TrieTest, StartWithPrefixNotAtoZEmptyStringGetAllWords) {     
}

TEST(TrieTest, IsWordNotAtoZEmptyString) {       
}

TEST(TrieTest, StartWithPrefixTrue) {
    Trie trie;
    trie.addWord("cats");
    vector<string> result = trie.allWordsStartingWithPrefix("cat");
             
    EXPECT_EQ(1, result.size()) << "Size is not 1 when testing cats only";
    EXPECT_EQ("cats", result[0]) << "Cats are not in result when testing cat prefix";
}

TEST(TrieTest, StartWithPrefixNotIncludedEmptyVector) {
    Trie trie;
    trie.addWord("cat");
    vector<string> result = trie.allWordsStartingWithPrefix("cats");
    
    EXPECT_EQ(0, result.size()) << "Size is not 0 when testing cat only";
}

TEST(TrieTest, CopyConstructorIsWordTrue) {
}

TEST(TrieTest, CopyConstructorEmptyTrie) {
}

TEST(TrieTest, CopyConstructorIsWordFalse) {
}

TEST(TrieTest, AssignmentOperatorIsWordTrue) {
}

TEST(TrieTest, AssignmentOperatorEmptyTrie) {
}

TEST(TrieTest, AssignmentOperatorIsWordFalse) {
}