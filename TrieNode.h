#ifndef TRIENODE_H
#define TRIENODE_H

struct TrieNode
{
    // Character stored at this node.
    char letter;

    // True when this node completes a word.
    bool isWord;

    // Number of times this completed word appears.
    int count;

    // One child for each letter from a to z.
    TrieNode* children[26];

    TrieNode();
    TrieNode(char value);

    // Sets the node's starting values.
    void initializeNode(char value);
};

#endif
