/*
This file is a the header that contains the Trie class with its method declarations.
The Trie class has methods to add words, lookup words, and find words with the same prefix 
in the trie.

By Nandhini Ramanathan
February 4, 2025
*/

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

/**
 * The trie class is represented as a C-style array of pointers to trie nodes with various 
 * methods to retrieve and add words to a trie.
 */
class Trie {
private:

    // map that maps characters to Trie nodes 
    map<char, Trie> branches;
    bool isCompleteWord;

    /**
     * recursive method that checks if a given word exists in the file.
     * 
     * @param word - word to search for
     * @return any character in the string not made up of characters 'a'-'z' cause an immediate return of false. 
     *         If the word is found in the Trie, the method returns true, otherwise returns false. 
     */
    bool isWordRecursive(const string& word) const;

    /**
     * recursive method that retrieves all words in the trie that start with a given prefix
     * 
     * @param word - prefix to search for
     * @return A vector collectionof words that start with the given prefix
     */
    vector<string> allWordsStartingWithPrefixRecursive(const string& prefix) const;

    /**
     * private recursive helper method to get words stored in the trie
     * 
     * @param node - current trie node being processed
     * @param prefix - prefix constructed so far (until iscomplete flag reached)
     * @param words - vector where words are stored
     */
    void getWords(const Trie* node, string prefix, vector<string>& words) const;

public:
    /**
     * Default contstructor for the trie class that initializes all branches to nullptr and 
     * marks the node as an incomplete word, by setting its flag to false.
     */
    Trie();

    /**
     *  Destructor deletes all dynamically allocated Trie nodes.
     */
    ~Trie();

    /**
     * Copy constructor that allocates new memeory for a new trie with the same instance variables as this trie.
     * 
     * @param other - the trie object to copy
     */
    Trie(const Trie& other);

    /**
     * Assignment operator that swaps the contents of two trie objects.
     * 
     * @param other - the other trie on teh right hand sign 
     * @return reference to the assigned trie object
     */
    Trie& operator=(Trie other);

    /**
     * Method adds a word to the trie recursively.
     * 
     * @param word - new word to be added
     */
    void addWord(const string& word);

    /**
     * Driver method that validates the word passed is composed of lowercase alphabet characters and 
     * calls a helper recursive method to determine if a word is in the trie.
     * 
     * @param word - word to search for
     * @return any character in the string not made up of characters 'a'-'z' cause an immediate return of false. 
     *         If the word is found in the Trie, the method returns true, otherwise returns false. 
     */
    bool isWord(const string& word) const;

    /**
     * Driver method that validates prefix is composed of lowercase alphabet characters and calls a helper
     * recursive method to retrieve all words in the trie that start with a given prefix
     * 
     * @param prefix - prefix to search for
     * @return A vector collectionof words that start with the given prefix
     */
    vector<string> allWordsStartingWithPrefix(const string& prefix) const;
};

#endif