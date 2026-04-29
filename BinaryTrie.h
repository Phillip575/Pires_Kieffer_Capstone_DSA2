#ifndef BINARYTRIE_H
#define BINARYTRIE_H

#include "TrieNode.h"
#include <string>

using namespace std;

class BinaryTrie
{
private:
    TrieNode* root;
    int uniqueWordCount;
    int totalWordCount;

    string convertWordToBinaryPath(const string& word) const;
    void deleteTrieNodes(TrieNode* node);
    int countTrieNodes(TrieNode* node) const;
    void displayStoredWordsInTrie(TrieNode* node) const;

public:
    BinaryTrie();
    ~BinaryTrie();

    void insertWordIntoTrie(const string& word);
    bool containsWord(const string& word) const;
    int getFrequencyOfWord(const string& word) const;
    int getUniqueWordCount() const;
    int getTotalWordCount() const;
    int getNodeCount() const;
    void displayAllStoredWords() const;
};

#endif