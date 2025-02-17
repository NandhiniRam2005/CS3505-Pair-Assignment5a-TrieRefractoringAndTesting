/*
This file is the cpp that contains the Trie class' method implementation.
The Trie class has methods to add words, lookup words, and find words with the same prefix 
in the trie, made of a map with character keys and Trie values. 

By Nandhini Ramanathan and Ishan Sharma
February 17, 2025
*/

#include "trie.h"

using std::swap;

// Constructor
Trie::Trie() {
    isCompleteWord = false;
}

// Copy contrsuctor
Trie::Trie(const Trie& other) {
    for (auto branch : other.branches) {
        branches.insert(branch);
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

    if (branches.find(word[0]) == branches.end()) {
        branches[word[0]] = Trie();
    }

    // Passes the remaining word recursively (skipping the current character (0) processed)
    branches[word[0]].addWord(word.substr(1));
}

// Is Word Driver
bool Trie::isWord(const string& word) const {
    if (!isValidWord(word)) {
        return false;
    }

    return isWordRecursive(word);
}

// Is Word Recursive
bool Trie::isWordRecursive(const string& word) const {
    if (word.empty()) {
        return isCompleteWord;
    }

    auto branchEntry = branches.find(word[0]);
    if (branchEntry == branches.end()) {
        return false;
    }

    // Passes the remaining word recursively (skipping the current character (0) processed)
    return branchEntry->second.isWordRecursive(word.substr(1));
}

// allWordsStartingWithPrefix Driver
vector<string> Trie::allWordsStartingWithPrefix(const string& prefix) const {
    if (!isValidWord(prefix)) {
        return {};
    }

    return allWordsStartingWithPrefixRecursive(prefix);
}

// allWordsStartingWithPrefix Recursive
vector<string> Trie::allWordsStartingWithPrefixRecursive(const string& prefix) const {
    const Trie* currentNode = this;
    for (char character : prefix) {

        auto branchEntry = currentNode->branches.find(character);

        if (branchEntry == currentNode->branches.end()) {
            return {};
        }
        currentNode = &branchEntry->second;
    }

    // Collect words from the last node of the prefix till a isCompleteWord flag
    vector<string> words;
    getWords(currentNode, prefix, words);
    return words;
}

// Private helper to test if a word is valid
bool Trie::isValidWord(const string& word) const{
    for (char character : word) {
        if (character < 'a' || character > 'z') {
            return false;
        }
    }

    return true;
}

// Private helper get words
void Trie::getWords(const Trie* node, string prefix, vector<string>& words) const {
    if (node->isCompleteWord) {
        words.push_back(prefix);
    }

    for (const auto& branchEntry : node->branches) {
        getWords(&branchEntry.second, prefix + branchEntry.first, words);
    }
}