#include "TrieNode.h"
#include <string>
// Done by phillip pires with help of copilot

using namespace std;

// Creates a trie node.
// Each node can connect to a 0 branch, a 1 branch,
// or represent the end of a stored word.
TrieNode::TrieNode()
{
    TrieNode()
    setZeroChild(TrieNode* childNode)
    setOneChild(TrieNode* childNode)
    hasZeroChild() const
    hasOneChild() const
    getZeroChild() const
    getOneChild() const
};

// Creates a trie node for a specific word.
// This can be used when a node needs to be tied to a word value.
TrieNode::TrieNode(const string& word)
{
    TrieNode(const string& word)
    markAsCompleteWord(const string& word)
    incrementWordFrequency()
    isCompleteWord() const
    getStoredWord() const
    getWordFrequency() const
};


void TrieNode::markAsCompleteWord(const string& word)
{
    // Marks this node as the end of a complete word.
    // This identifies the node as one that stores a full word.
};


void TrieNode::incrementWordFrequency()
{
    // Increases the count for the word stored at this node.
    // This is used when the same word appears again.
};


bool TrieNode::hasZeroChild() const
{
    // Checks whether this node has a child on the 0 branch.
};


bool TrieNode::hasOneChild() const
{
    // Checks whether this node has a child on the 1 branch.
};


TrieNode* TrieNode::getZeroChild() const
{
    // Returns the child node on the 0 branch.
};


TrieNode* TrieNode::getOneChild() const
{
    // Returns the child node on the 1 branch.
};


void TrieNode::setZeroChild(TrieNode* childNode)
{
    // Sets the child node on the 0 branch.
};


void TrieNode::setOneChild(TrieNode* childNode)
{
    // Sets the child node on the 1 branch.
};


bool TrieNode::isCompleteWord() const
{
    // Checks whether this node marks the end of a complete word.
};


string TrieNode::getStoredWord() const
{
    // Returns the word stored at this node.
};


int TrieNode::getWordFrequency() const
{
    // Returns how many times the stored word appears.
};
