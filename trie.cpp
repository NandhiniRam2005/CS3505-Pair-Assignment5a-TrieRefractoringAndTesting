/*
This file is the cpp that contains the Trie class' method implementation.
The Trie class has methods to add words, lookup words, and find words with the same prefix 
in the trie.

By Nandhini Ramanathan
February 4, 2025
*/

#include "trie.h"

using std::swap;

// Constructor
Trie::Trie() {
    for (int i = 0; i < 26; i++) {
        branches[i] = nullptr;
    }
    isCompleteWord = false;
}

// Destructor
Trie::~Trie() {
    for (int i = 0; i < 26; i++) {
        if (branches[i]) {
            delete branches[i];
        }
    }
}

// Copy contrsuctor
Trie::Trie(const Trie& other) {
    for (int i = 0; i < 26; i++) {
        if (other.branches[i]) {
            branches[i] = new Trie(*(other.branches[i]));
        } else {
            branches[i] = nullptr;
        }
    }
    isCompleteWord = other.isCompleteWord;
}

// Assignment Operator
Trie& Trie::operator=(Trie other) {
    swap(isCompleteWord, other.isCompleteWord);
    swap(branches, other.branches);
    return *this;
}

// Add Word
void Trie::addWord(const string& word) {
    if (word.empty()) {
        isCompleteWord = true;
        return;
    }

    // Determine the index for the current character ('a' = 0 to 'z' = 25)
    int pathIndex = word[0] - 'a';

    if (!branches[pathIndex]) {
        branches[pathIndex] = new Trie();
    }

    // Passes the remaining wird recursively (skipping the current character (0) processed)
    branches[pathIndex]->addWord(word.substr(1));
}

// Is Word Driver
bool Trie::isWord(const string& word) const {
    for (char character : word) {
        if (character < 'a' || character > 'z') {
            return false;
        }
    }

    return isWordRecursive(word);
}

// Is Word Recursive
bool Trie::isWordRecursive(const string& word) const {
    if (word.empty()) {
        return isCompleteWord;
    }

    // Determine the index for the current character ('a' = 0 to 'z' = 25)
    int pathIndex = word[0] - 'a';
    if (!branches[pathIndex]) {
        return false;
    }

    // Passes the remaining wird recursively (skipping the current character (0) processed)
    return branches[pathIndex]->isWordRecursive(word.substr(1));
}

// allWordsStartingWithPrefix Driver
vector<string> Trie::allWordsStartingWithPrefix(const string& prefix) const {
     for (char character : prefix) {
        if (character < 'a' || character > 'z') {
            return {};
        }
    }

    return allWordsStartingWithPrefixRecursive(prefix);
}

// allWordsStartingWithPrefix Recursive
vector<string> Trie::allWordsStartingWithPrefixRecursive(const string& prefix) const {
    const Trie* currentNode = this;
    for (char character : prefix) {
        // Determine the index for the current character ('a' = 0 to 'z' = 25)
        int pathIndex = character - 'a';
        if (!currentNode->branches[pathIndex]) {
            return {};
        }
        currentNode = currentNode->branches[pathIndex];
    }

    // Collect words from the last node of the prefix till a isCompleteWord flag
    vector<string> words;
    getWords(currentNode, prefix, words);
    return words;
}

// Private helper get words
void Trie::getWords(const Trie* node, string prefix, vector<string>& words) const {
    if (node->isCompleteWord) {
        words.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        // Convert index back to character
        char characterAtIndex = char('a' + i);

        if (node->branches[i]) {
            getWords(node->branches[i], prefix + characterAtIndex, words);
        }
    }
}