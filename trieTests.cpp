#include "trie.h"
#include <gtest/gtest.h>

bool IsEqualVector(vector<string> firstVector, vector<string> secondVector) {
    if (firstVector.size() != secondVector.size()){
        return false;
    }

    for (string string : firstVector) {
        auto iterator = std::find(secondVector.begin(), secondVector.end(), string);
        if(iterator == secondVector.end()){
            return false;
        }
    }

    return true;
}

TEST(TrieTest, AddOneWordIsWordTrue) {
    Trie trie;
    trie.addWord("hello");
    EXPECT_TRUE(trie.isWord("hello"));
}

TEST(TrieTest, AddOneWordIsWordFalse) {
    Trie trie;
    trie.addWord("hello");
    EXPECT_FALSE(trie.isWord("hell"));
}

TEST(TrieTest, AddDuplicateWordIsWordTrue) {
    Trie trie;
    trie.addWord("hello");
    trie.addWord("hello");
    EXPECT_TRUE(trie.isWord("hello"));
}

TEST(TrieTest, AddMultipleWordsIsWordsTrue) {
    Trie trie;
    trie.addWord("hello");
    trie.addWord("hi");
    trie.addWord("car");
    trie.addWord("bike");
    trie.addWord("shoes");
    trie.addWord("laptop");
    EXPECT_TRUE(trie.isWord("hello"));
    EXPECT_TRUE(trie.isWord("hi"));
    EXPECT_TRUE(trie.isWord("car"));
    EXPECT_TRUE(trie.isWord("bike"));
    EXPECT_TRUE(trie.isWord("shoes"));
    EXPECT_TRUE(trie.isWord("laptop"));

    EXPECT_FALSE(trie.isWord("monkey"));
}

TEST(TrieTest, AddWordsWithSamePrefixIsWordTrue) {
    Trie trie;
    trie.addWord("cats");
    trie.addWord("catastrophe");

    vector<string> expected = {"cats", "catastrophe"};
    vector<string> actual = trie.allWordsStartingWithPrefix("cat");

    EXPECT_TRUE(IsEqualVector(expected, actual));                   
}

TEST(TrieTest, IsWordFalseInEmptyTrie) {
    Trie trie;
    EXPECT_FALSE(trie.isWord("hello"));  
}

TEST(TrieTest, IsTrueOneLetterWord) {
    Trie trie;
    trie.addWord("u");
    EXPECT_TRUE(trie.isWord("u"));  
}

TEST(TrieTest, IsWordIncompleteVersionsofAddedWord) {
    Trie trie;
    trie.addWord("positivity");
    trie.addWord("positive");
    trie.addWord("posit");
    EXPECT_TRUE(trie.isWord("positivity"));  
    EXPECT_FALSE(trie.isWord("pos"));
}

TEST(TrieTest, AllWordsStartingWithPrefixSameWord) {
    Trie trie;
    trie.addWord("car");

    vector<string> expected = {"car"};
    vector<string> actual = trie.allWordsStartingWithPrefix("car");

    EXPECT_TRUE(IsEqualVector(expected, actual));         
}

TEST(TrieTest, AllWordsStartingWithPrefixNormalCaseMultipleWords) {
    Trie trie;
    trie.addWord("cats");
    trie.addWord("cat");
    trie.addWord("catra");
    trie.addWord("cater");
    trie.addWord("catering");
    trie.addWord("caty");

    vector<string> expected = {"cats", "cat", "catra", "cater", "catering", "caty"};
    vector<string> actual = trie.allWordsStartingWithPrefix("cat");

    EXPECT_TRUE(IsEqualVector(expected, actual));   
}

TEST(TrieTest, AllWordsStartingWithPrefixSomeAreFalse) {
    Trie trie;
    trie.addWord("cats");
    trie.addWord("cat");
    trie.addWord("catra");
    trie.addWord("cater");
    trie.addWord("car");
    trie.addWord("c");
    trie.addWord("a");

    vector<string> expected = {"cats", "cat", "catra", "cater"};
    vector<string> actual = trie.allWordsStartingWithPrefix("cat");

    EXPECT_TRUE(IsEqualVector(expected, actual));        
}

TEST(TrieTest, AllWordsStartingWithOneWordPrefix) {   
    Trie trie;
    trie.addWord("cats");
    trie.addWord("cat");
    trie.addWord("catra");
    trie.addWord("cater");
    trie.addWord("car");
    trie.addWord("c");
    trie.addWord("cocktail");
    trie.addWord("case");
    trie.addWord("a");

    vector<string> expected = {"cats", "cat", "catra", "cater", "car", "c", "case", "cocktail"};
    vector<string> actual = trie.allWordsStartingWithPrefix("c");

    EXPECT_TRUE(IsEqualVector(expected, actual));        
}

TEST(TrieTest, IsWordNotAtoZ) {
    Trie trie;
    trie.addWord("car1");
             
    EXPECT_FALSE(trie.isWord("car1"));          
}

TEST(TrieTest, IsWordWeirdCharacters) {      
    Trie trie;
    trie.addWord("paper");
    EXPECT_FALSE(trie.isWord("p@p$^"));
}

TEST(TrieTest, StartWithPrefixNotAtoZ) {
    Trie trie;
    trie.addWord("car1");
    
    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("car1");

    EXPECT_TRUE(IsEqualVector(expected, actual));
}

TEST(TrieTest, StartWithPrefixWeirdCharacters) {
    Trie trie;
    trie.addWord("paper");
    
    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("p@p$^");

    EXPECT_TRUE(IsEqualVector(expected, actual));
}

TEST(TrieTest, PrefixNotAtoZCapitalLetters) {
    Trie trie;
    trie.addWord("paper");
    
    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("PAPER");

    EXPECT_TRUE(IsEqualVector(expected, actual));
}

TEST(TrieTest, IsWordNotAtoZCapitalLetters) {
    Trie trie;
    trie.addWord("paper");

    EXPECT_FALSE(trie.isWord("PAPER"));    
}

TEST(TrieTest, IsWordBoundaryCasesAAndZ) {  
    Trie trie;
    trie.addWord("apple");
    trie.addWord("zebra");

    EXPECT_FALSE(trie.isWord("Apple"));
    EXPECT_FALSE(trie.isWord("Zebra"));
}

TEST(TrieTest, IsWordBoundaryCasesBAndY) { 
    Trie trie;
    trie.addWord("bat");
    trie.addWord("yo");

    EXPECT_FALSE(trie.isWord("Bat"));
    EXPECT_FALSE(trie.isWord("Yo"));
}

TEST(TrieTest, IsWordEdgeCasesAsciiValueRightBeforeAAndZ) {
    Trie trie;
    trie.addWord("ace");
    trie.addWord("moon");

    EXPECT_FALSE(trie.isWord("`"));
    EXPECT_FALSE(trie.isWord("{"));
}

TEST(TrieTest, StartPrefixBoundaryCasesAAndZ) {     
    Trie trie;
    trie.addWord("apple");
    trie.addWord("zebra");

    vector<string> expected = {};
    vector<string> actual1 = trie.allWordsStartingWithPrefix("App");
    vector<string> actual2 = trie.allWordsStartingWithPrefix("Ze");

    EXPECT_EQ(expected, actual1);
    EXPECT_EQ(expected, actual2);
}

TEST(TrieTest, StartPrefixBoundaryCasesBAndY) {     
    Trie trie;
    trie.addWord("banana");
    trie.addWord("yolo");

    vector<string> expected = {};
    vector<string> actual1 = trie.allWordsStartingWithPrefix("Ban");
    vector<string> actual2 = trie.allWordsStartingWithPrefix("Yo");

    EXPECT_EQ(expected, actual1);
    EXPECT_EQ(expected, actual2);
}

TEST(TrieTest, StartPrefixEdgeCasesAsciiValueRightBeforeAAndZ) {     
    Trie trie;
    trie.addWord("ace");
    trie.addWord("moon");

    vector<string> expected = {};
    vector<string> actual1 = trie.allWordsStartingWithPrefix("`");
    vector<string> actual2 = trie.allWordsStartingWithPrefix("{");

    EXPECT_EQ(expected, actual1);
    EXPECT_EQ(expected, actual2);
}

TEST(TrieTest, StartWithPrefixNotAtoZCapitalLetters) {    
    Trie trie;
    trie.addWord("paper");

    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("Pap");

    EXPECT_EQ(expected, actual);
}

TEST(TrieTest, StartWithPrefixNotAtoZEmptyStringGetAllWords) {   
    Trie trie;
    trie.addWord("cats");
    trie.addWord("cat");
    trie.addWord("catra");
    trie.addWord("cater");
    trie.addWord("car");
    trie.addWord("c");
    trie.addWord("cocktail");
    trie.addWord("case");
    trie.addWord("a");

    vector<string> expected = {"cats", "cat", "catra", "cater", "car", "c", "case", "cocktail", "a"};
    vector<string> actual = trie.allWordsStartingWithPrefix("");

    EXPECT_TRUE(IsEqualVector(expected, actual));  
}

TEST(TrieTest, PrefixdNotAtoZEmptyVector) {       
    Trie trie;

    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("");

    EXPECT_TRUE(IsEqualVector(expected, actual));  
}

TEST(TrieTest, StartWithPrefixTrue) {
    Trie trie;
    trie.addWord("cats");
    
    vector<string> expected = {"cats"};
    vector<string> actual = trie.allWordsStartingWithPrefix("cat");
             
    EXPECT_TRUE(IsEqualVector(expected, actual));
}

TEST(TrieTest, StartWithPrefixNotIncludedEmptyVector) {
    Trie trie;
    trie.addWord("cat");

    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("cats");
    
    EXPECT_TRUE(IsEqualVector(expected, actual));
}

TEST(TrieTest, CopyConstructorIsWordTrue) {
    Trie trie1;
    trie1.addWord("cats");
    trie1.addWord("cat");

    Trie trie2(trie1);

    trie1.addWord("cater");

    vector<string> expected = {"cats", "cat"};
    vector<string> actual = trie2.allWordsStartingWithPrefix("cat");
    
    EXPECT_TRUE(IsEqualVector(expected, actual));
}

TEST(TrieTest, CopyConstructorEmptyTrie) {
    Trie trie1;

    Trie trie2(trie1);

    vector<string> expected = {};
    vector<string> actual1 = trie1.allWordsStartingWithPrefix("");
    vector<string> actual2 = trie2.allWordsStartingWithPrefix("");
    
    EXPECT_TRUE(IsEqualVector(expected, actual1));
    EXPECT_TRUE(IsEqualVector(expected, actual2));
}

TEST(TrieTest, CopyConstructorIsWordFalse) {
    Trie trie1;
    trie1.addWord("cats");
    trie1.addWord("cat");

    Trie trie2(trie1);

    trie2.addWord("cater");

    vector<string> expected = {"cats", "cat"};
    vector<string> actual = trie2.allWordsStartingWithPrefix("cat");
    
    EXPECT_FALSE(IsEqualVector(expected, actual));
}

TEST(TrieTest, AssignmentOperatorIsWordTrue) {
    Trie trie1;
    trie1.addWord("cats");
    trie1.addWord("cat");

    Trie trie2;
    trie2 = trie1;

    trie1.addWord("cater");

    vector<string> expected = {"cats", "cat"};
    vector<string> actual = trie2.allWordsStartingWithPrefix("cat");
    
    EXPECT_TRUE(IsEqualVector(expected, actual));
}

TEST(TrieTest, AssignmentOperatorEmptyTrie) {
    Trie trie1;

    Trie trie2;
    trie2 = trie1;

    vector<string> expected = {};
    vector<string> actual1 = trie1.allWordsStartingWithPrefix("");
    vector<string> actual2 = trie2.allWordsStartingWithPrefix("");
    
    EXPECT_TRUE(IsEqualVector(expected, actual1));
    EXPECT_TRUE(IsEqualVector(expected, actual2));
}

TEST(TrieTest, AssignmentOperatorIsWordFalse) {
    Trie trie1;
    trie1.addWord("cats");
    trie1.addWord("cat");

    Trie trie2;
    trie2 = trie1;

    trie1.addWord("cater");

    EXPECT_FALSE(trie2.isWord("cater"));
}