/**
 * This file is the cpp that tests the Trie class' implementation.
 * It tests all the methods in Trie, including edge cases
 * 
 * By Nandhini Ramanathan and Ishan Sharma
 * February 13, 2025
 */
#include "trie.h"
#include <gtest/gtest.h>

/**
 * Private helper method that checks if 2 vectors contain only same strings and are the same length
 * 
 * @param firstVector - First string vector being checked
 * @param secondVector - Second string vector being checked
 */
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
    EXPECT_TRUE(trie.isWord("hello")) << "Tried testing addWord with just one word 'hello' and isWord returned false";
}

TEST(TrieTest, AddOneWordIsWordFalse) {
    Trie trie;
    trie.addWord("hello");
    EXPECT_FALSE(trie.isWord("hell")) << "Tried testing addWord with just one word 'hello' and isWord('hell') returned true";
}

TEST(TrieTest, AddDuplicateWordIsWordTrue) {
    Trie trie;
    trie.addWord("hello");
    trie.addWord("hello");
    EXPECT_TRUE(trie.isWord("hello")) << "Tried testing addWord('hello') twice and isWord('hello') returned false";
}

TEST(TrieTest, AddMultipleWordsIsWordsTrue) {
    Trie trie;
    trie.addWord("hello");
    trie.addWord("hi");
    trie.addWord("car");
    trie.addWord("bike");
    trie.addWord("shoes");
    trie.addWord("laptop");
    EXPECT_TRUE(trie.isWord("hello")) << "Tried testing addWord('hello') and isWord('hello') returned false";
    EXPECT_TRUE(trie.isWord("hi")) << "Tried testing addWord('hi') and isWord('hi') returned false";
    EXPECT_TRUE(trie.isWord("car")) << "Tried testing addWord('car') and isWord('car') returned false";
    EXPECT_TRUE(trie.isWord("bike")) << "Tried testing addWord('bike') and isWord('bike') returned false";
    EXPECT_TRUE(trie.isWord("shoes")) << "Tried testing addWord('shoes') and isWord('shoes') returned false";
    EXPECT_TRUE(trie.isWord("laptop")) << "Tried testing addWord('laptop') and isWord('laptop') returned false";

    EXPECT_FALSE(trie.isWord("monkey")) << "Tried testing isWord('monkey') in a trie with multiple words but not monkey and it returned true";
}

TEST(TrieTest, AddWordsWithSamePrefixIsWordTrue) {
    Trie trie;
    trie.addWord("cats");
    trie.addWord("catastrophe");

    vector<string> expected = {"cats", "catastrophe"};
    vector<string> actual = trie.allWordsStartingWithPrefix("cat");

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('cat') in a trie with 'cats' and a 'catastrophe' and it returned false";                   
}

TEST(TrieTest, IsWordFalseInEmptyTrie) {
    Trie trie;
    EXPECT_FALSE(trie.isWord("hello")) << "Tried testing isWord('hello') in an empty trie and it returned true";
}

TEST(TrieTest, IsTrueOneLetterWord) {
    Trie trie;
    trie.addWord("u");
    EXPECT_TRUE(trie.isWord("u")) << "Tried testing one letter input isWord('u') and it returned false";
}

TEST(TrieTest, IsWordIncompleteVersionsofAddedWord) {
    Trie trie;
    trie.addWord("positivity");
    trie.addWord("positive");
    trie.addWord("posit");
    EXPECT_TRUE(trie.isWord("positivity")) << "Tried testing isWord('positivity') in a trie with 'positivity', 'positive', and 'posit' and it returned false";  
    EXPECT_FALSE(trie.isWord("pos")) << "Tried testing isWord('pos') in a trie with 'positivity', 'positive', and 'posit' and it returned true";
}

TEST(TrieTest, AllWordsStartingWithPrefixSameWord) {
    Trie trie;
    trie.addWord("car");

    vector<string> expected = {"car"};
    vector<string> actual = trie.allWordsStartingWithPrefix("car");

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('car') in a trie with 'car' and it failed";         
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

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('cat') in a trie with 'cats', 'cat', 'catra', 'cater', 'catering', and 'caty' and it failed";   
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

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('cat') in a trie with 'cats', 'cat', 'catra', 'cater', 'car', 'c', and 'a' and it failed";
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

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('c') in a trie with 'cats', 'cat', 'catra', 'cater', 'car', 'c', 'case', 'cocktail', and 'a' and it failed";
}

TEST(TrieTest, IsWordNotAtoZ) {
    Trie trie;
    trie.addWord("car1");
             
    EXPECT_FALSE(trie.isWord("car1")) << "Tried testing isWord('car1') in a trie with 'car1' and it returned true";
}

TEST(TrieTest, IsWordWeirdCharacters) {      
    Trie trie;
    trie.addWord("paper");
    EXPECT_FALSE(trie.isWord("p@p$^")) << "Tried testing isWord('p@p$^') in a trie with 'paper' and it returned true";
}

TEST(TrieTest, StartWithPrefixNotAtoZ) {
    Trie trie;
    trie.addWord("car1");
    
    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("car1");

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing addWord with just one word 'hello' and isWord('hell') returned true";
}

TEST(TrieTest, StartWithPrefixWeirdCharacters) {
    Trie trie;
    trie.addWord("paper");
    
    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("p@p$^");

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('p@p$^') in a trie with 'paper' and it failed";
}

TEST(TrieTest, PrefixNotAtoZCapitalLetters) {
    Trie trie;
    trie.addWord("paper");
    
    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("PAPER");

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('PAPER') in a trie with 'paper' and it failed";
}

TEST(TrieTest, IsWordNotAtoZCapitalLetters) {
    Trie trie;
    trie.addWord("paper");

    EXPECT_FALSE(trie.isWord("PAPER")) << "Tried testing isWord('PAPER') in a trie with 'paper' and it returned true";
}

TEST(TrieTest, IsWordBoundaryCasesAAndZ) {  
    Trie trie;
    trie.addWord("apple");
    trie.addWord("zebra");

    EXPECT_FALSE(trie.isWord("Apple")) << "Tried testing isWord('Apple') in a trie with 'apple' and 'zebra' and it returned true";
    EXPECT_FALSE(trie.isWord("Zebra")) << "Tried testing isWord('Zebra') in a trie with 'apple' and 'zebra' and it returned true";
}

TEST(TrieTest, IsWordBoundaryCasesBAndY) { 
    Trie trie;
    trie.addWord("bat");
    trie.addWord("yo");

    EXPECT_FALSE(trie.isWord("Bat")) << "Tried testing isWord('Bat') in a trie with 'bat' and 'yo' and it returned true";
    EXPECT_FALSE(trie.isWord("Yo")) << "Tried testing isWord('Yo') in a trie with 'bat' and 'yo' and it returned true";
}

TEST(TrieTest, IsWordEdgeCasesAsciiValueRightBeforeAAndZ) {
    Trie trie;
    trie.addWord("ace");
    trie.addWord("zoom");

    EXPECT_FALSE(trie.isWord("`")) << "Tried testing isWord('`') in a trie with 'ace' and 'zoom' and it returned true";
    EXPECT_FALSE(trie.isWord("{")) << "Tried testing isWord('{') in a trie with 'ace' and 'zoom' and it returned true";
}

TEST(TrieTest, StartPrefixBoundaryCasesAAndZ) {     
    Trie trie;
    trie.addWord("apple");
    trie.addWord("zebra");

    vector<string> expected = {};
    vector<string> actual1 = trie.allWordsStartingWithPrefix("App");
    vector<string> actual2 = trie.allWordsStartingWithPrefix("Ze");

    EXPECT_EQ(expected, actual1) << "Tried testing if allWordsStartingWithPrefix('App') in a trie with 'apple' and 'zebra' was empty and it failed";
    EXPECT_EQ(expected, actual2) << "Tried testing if allWordsStartingWithPrefix('Ze') in a trie with 'apple' and 'zebra' was empty and it failed";
}

TEST(TrieTest, StartPrefixBoundaryCasesBAndY) {     
    Trie trie;
    trie.addWord("banana");
    trie.addWord("yolo");

    vector<string> expected = {};
    vector<string> actual1 = trie.allWordsStartingWithPrefix("Ban");
    vector<string> actual2 = trie.allWordsStartingWithPrefix("Yo");

    EXPECT_EQ(expected, actual1) << "Tried testing if allWordsStartingWithPrefix('Ban') in a trie with 'banana' and 'yolo' was empty and it failed";
    EXPECT_EQ(expected, actual2) << "Tried testing if allWordsStartingWithPrefix('Yo') in a trie with 'banana' and 'yolo' was empty and it failed";
}

TEST(TrieTest, StartPrefixEdgeCasesAsciiValueRightBeforeAAndZ) {     
    Trie trie;
    trie.addWord("ace");
    trie.addWord("zoom");

    vector<string> expected = {};
    vector<string> actual1 = trie.allWordsStartingWithPrefix("`");
    vector<string> actual2 = trie.allWordsStartingWithPrefix("{");

    EXPECT_EQ(expected, actual1) << "Tried testing if allWordsStartingWithPrefix('`') in a trie with 'ace' and 'zoom' was empty and it failed";
    EXPECT_EQ(expected, actual2) << "Tried testing if allWordsStartingWithPrefix('{') in a trie with 'ace' and 'zoom' was empty and it failed";
}

TEST(TrieTest, StartWithPrefixNotAtoZCapitalLetters) {    
    Trie trie;
    trie.addWord("paper");

    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("Pap");

    EXPECT_EQ(expected, actual) << "Tried testing allWordsStartingWithPrefix('Pap') in a trie with 'paper' and it failed";
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

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('') in a trie with 'cats', 'cat', 'catra', 'cater', 'car', 'c', 'case', 'cocktail', and 'a' and it failed";
}

TEST(TrieTest, PrefixdNotAtoZEmptyVector) {       
    Trie trie;

    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("");

    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('') in an empty trie and it failed";  
}

TEST(TrieTest, StartWithPrefixTrue) {
    Trie trie;
    trie.addWord("cats");
    
    vector<string> expected = {"cats"};
    vector<string> actual = trie.allWordsStartingWithPrefix("cat");
             
    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('cat') in a trie with 'cats' and it failed";
}

TEST(TrieTest, StartWithPrefixNotIncludedEmptyVector) {
    Trie trie;
    trie.addWord("cat");

    vector<string> expected = {};
    vector<string> actual = trie.allWordsStartingWithPrefix("cats");
    
    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('cats') in a trie with 'cat' and it failed";
}

TEST(TrieTest, CopyConstructorIsWordTrue) {
    Trie trie1;
    trie1.addWord("cats");
    trie1.addWord("cat");

    Trie trie2(trie1);

    trie1.addWord("cater");

    vector<string> expected = {"cats", "cat"};
    vector<string> actual = trie2.allWordsStartingWithPrefix("cat");
    
    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing copy constructor, trie2 contained changes made to trie1";
}

TEST(TrieTest, CopyConstructorEmptyTrie) {
    Trie trie1;

    Trie trie2(trie1);

    vector<string> expected = {};
    vector<string> actual1 = trie1.allWordsStartingWithPrefix("");
    vector<string> actual2 = trie2.allWordsStartingWithPrefix("");
    
    EXPECT_TRUE(IsEqualVector(expected, actual1)) << "Tried testing copy constructor, trie1 lost data";
    EXPECT_TRUE(IsEqualVector(expected, actual2)) << "Tried testing copy constructor, trie2 coudln't copy empty";
}

TEST(TrieTest, CopyConstructorIsWordFalse) {
    Trie trie1;
    trie1.addWord("cats");
    trie1.addWord("cat");

    Trie trie2(trie1);

    trie2.addWord("cater");

    vector<string> expected = {"cats", "cat"};
    vector<string> actual = trie2.allWordsStartingWithPrefix("cat");
    
    EXPECT_FALSE(IsEqualVector(expected, actual)) << "Tried testing copy constructor, trie1 contained changes made to trie2";
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
    
    EXPECT_TRUE(IsEqualVector(expected, actual)) << "Tried testing allWordsStartingWithPrefix('cat') in a trie with 'cats', 'cat', and 'cater' and it failed";
}

TEST(TrieTest, AssignmentOperatorEmptyTrie) {
    Trie trie1;

    Trie trie2;
    trie2 = trie1;

    vector<string> expected = {};
    vector<string> actual1 = trie1.allWordsStartingWithPrefix("");
    vector<string> actual2 = trie2.allWordsStartingWithPrefix("");
    
    EXPECT_TRUE(IsEqualVector(expected, actual1)) << "Tried testing allWordsStartingWithPrefix('') in an empty trie and it failed";
    EXPECT_TRUE(IsEqualVector(expected, actual2)) << "Tried testing allWordsStartingWithPrefix('') in an empty trie and it failed";
}

TEST(TrieTest, AssignmentOperatorIsWordFalse) {
    Trie trie1;
    trie1.addWord("cats");
    trie1.addWord("cat");

    Trie trie2;
    trie2 = trie1;

    trie1.addWord("cater");

    EXPECT_FALSE(trie2.isWord("cater")) << "Tried testing isWord('cater') in a trie with 'cats', 'cat', and 'cater' and it returned true";
}