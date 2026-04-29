using namespace std;
#include "BinaryTrie.h"
#include "BinaryTrie.h"
#include <iostream>

// written by Amanda Kieffer with help from Copilot

TrieNode::TrieNode()
{
	TrieNode()
};

BinaryTrie::BinaryTrie()
{
	BinaryTrie()
	TrieNode()
};

BinaryTrie::~BinaryTrie()
{
	// destructor for BinaryTrie
	// release all dynamically allocated trie nodes by traversing the trie and deleting allocated nodes
	// prevent memory leaks when the BinaryTrie object is destroyed
};

string BinaryTrie::convertWordToBinaryPath(const string& word) const
{
	// initialize empty binary tree
	// convert a regular string word into a binary path string
	// map character to a sequence of bits that determine left/right child choices
	// return path
};

void BinaryTrie::insertWordIntoTrie(const string& word)
{
	// insert word into the binary trie
	// steps typically performed by this method:
	//    convert the word to a binary path
	//    traverse/extend the trie following the path, creating nodes as necessary
	//    update frequency counters at the terminal node and the trie's total/unique word counts
	// if duplicate insertion is found, increment the frequency, do not increase the unique word count
};

bool BinaryTrie::containsWord(const string& word) const
{
	// check if word exists in the trie
	// if the word has been inserted previously, return true 
	// else, return false
};

int BinaryTrie::getFrequencyOfWord(const string& word) const
{
	// return the stored frequency of word in the trie
	// locate terminal node for the word's binary path 
	// if the word is not present, return 0
};

void BinaryTrie::deleteTrieNodes(TrieNode* node)
{
	// recursively delete the subtree rooted at node
	// traverse child nodes, delete them, and delete node itself 
	// free all dynamically allocated nodes 
};

int BinaryTrie::getUniqueWordCount() const
{
	// return the number of unique words stored in the trie
	// value is tracked during insertions/deletions, not recomputed each call for efficiency
};

int BinaryTrie::getTotalWordCount() const
{
	// Return the total number of words inserted into the trie,
	// counting duplicates. For example, inserting the same word
	// three times increases this count by 3.
};

int BinaryTrie::countTrieNodes(TrieNode* node) const
{
	// count and return the number of nodes in the subtree rooted at node
	// implemented recursively as 1 + count(left) + count(right)
};

int BinaryTrie::getNodeCount() const
{
	// return the total number of nodes currently allocated in the trie
	// this can be returned from a cached member or computed by calling countTrieNodes on the root
};

void BinaryTrie::displayStoredWordsInTrie(TrieNode* node) const
{
	// Recursively traverse the trie from node and print each stored word
};

void BinaryTrie::displayAllStoredWords() const
{
	// display all words stored in the trie
};
