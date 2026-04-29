#ifndef BINARYTRIE_H
#define BINARYTRIE_H

#include "TrieNode.h"
#include <string>

using namespace std;

class BinaryTrie
{
private:
    // Starting point of the trie.
    TrieNode* root;

    // Number of different words stored.
    int uniqueWordCount;

    // Number of valid words processed, including repeats.
    int totalWordCount;

    // Converts one uppercase letter to lowercase.
    char convertCharacterToLowercase(char character) const;

    // Converts one lowercase letter to uppercase for display.
    char convertCharacterToUppercase(char character) const;

    // Checks whether a character is an English letter.
    bool isLetterCharacter(char character) const;

    // Converts a letter into an array position from 0 to 25.
    int getChildIndex(char character) const;

    // Cleans a word before storing or searching it.
    string normalizeWord(const string& word) const;

    // Finds the node where a word or prefix ends.
    TrieNode* findPrefixNode(const string& prefix) const;

    // Deletes every node under the given node.
    void deleteTrieNodes(TrieNode* node);

    // Counts every node under the given node.
    int countTrieNodes(TrieNode* node) const;

    // Displays stored words found under the given node.
    void displayStoredWordsInTrie(TrieNode* node, const string& currentWord) const;

    // Displays the trie branches after the typed prefix.
    void displayAutocompleteBranches(TrieNode* node, const string& currentWord, const string& indent) const;

    // Displays each complete word represented by the tree.
    void displayWordPathsFromTrie(TrieNode* node, const string& currentWord) const;

    // Displays one word as a character path.
    void displayWordPath(const string& word, int count) const;

public:
    BinaryTrie();
    ~BinaryTrie();

    // Adds a word to the trie.
    void insertWordIntoTrie(const string& word);

    // Checks whether a complete word exists.
    bool containsWord(const string& word) const;

    // Returns how many times a word was found in the text.
    int getFrequencyOfWord(const string& word) const;

    // Returns the number of different words.
    int getUniqueWordCount() const;

    // Returns the number of valid words processed.
    int getTotalWordCount() const;

    // Returns the number of nodes in the trie.
    int getNodeCount() const;

    // Displays every stored word with its count.
    void displayAllStoredWords() const;

    // Displays autocomplete possibilities as a tree.
    void displayAutocompleteTree(const string& prefix) const;
};

#endif
