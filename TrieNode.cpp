#include "TrieNode.h"

TrieNode::TrieNode()
{
    initializeNode('\0');
}

TrieNode::TrieNode(char value)
{
    initializeNode(value);
}

void TrieNode::initializeNode(char value)
{
    letter = value;
    isWord = false;
    count = 0;

    for (int index = 0; index < 26; index++)
    {
        children[index] = nullptr;
    }
}
