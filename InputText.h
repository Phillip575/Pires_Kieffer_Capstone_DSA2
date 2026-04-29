#ifndef INPUTTEXT_H
#define INPUTTEXT_H

#include "BinaryTrie.h"
#include <string>

using namespace std;

class InputText
{
private:
    string convertWordToLowercase(const string& word) const;
    string removePunctuation(const string& word) const;
    string normalizeWord(const string& word) const;
    bool isWordValid(const string& word) const;
    void processWord(const string& word, BinaryTrie& trie) const;

public:
    bool processTheFile(const string& fileName, BinaryTrie& trie) const;
};

#endif