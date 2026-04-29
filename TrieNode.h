#ifndef TRIENODE_H
#define TRIENODE_H

#include <string>

using namespace std;

struct TrieNode
{
    TrieNode* zero;
    TrieNode* one;
    bool isWord;
    string storedWord;
    int count;

    TrieNode();
};

#endif
