#ifndef INPUTTEXT_H
#define INPUTTEXT_H

#include "BinaryTrie.h"
#include <string>

using namespace std;

class InputText
{
private:
    // Converts uppercase letters to lowercase letters.
    string convertWordToLowercase(const string& word) const;

    // Keeps only lowercase letters from a word.
    string removePunctuation(const string& word) const;

    // Cleans a word before it is added to the trie.
    string normalizeWord(const string& word) const;

    // Checks whether the cleaned word contains letters.
    bool isWordValid(const string& word) const;

    // Cleans one word and sends it to the trie.
    void processWord(const string& word, BinaryTrie& trie) const;

public:
    // Reads a file and adds each valid word to the trie.
    bool processTheFile(const string& fileName, BinaryTrie& trie) const;
};

#endif
