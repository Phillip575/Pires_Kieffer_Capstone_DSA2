#include "BinaryTrie.h"
#include <iostream>

using namespace std;

// Creates an empty trie.
BinaryTrie::BinaryTrie()
{
    root = new TrieNode();
    uniqueWordCount = 0;
    totalWordCount = 0;
}

// Releases all nodes owned by the trie.
BinaryTrie::~BinaryTrie()
{
    deleteTrieNodes(root);
}

// Converts uppercase letters to lowercase letters.
char BinaryTrie::convertCharacterToLowercase(char character) const
{
    if (character >= 'A' && character <= 'Z')
    {
        return static_cast<char>(character - 'A' + 'a');
    }

    return character;
}

// Converts lowercase letters to uppercase letters for output.
char BinaryTrie::convertCharacterToUppercase(char character) const
{
    if (character >= 'a' && character <= 'z')
    {
        return static_cast<char>(character - 'a' + 'A');
    }

    return character;
}

// Checks for English alphabet characters.
bool BinaryTrie::isLetterCharacter(char character) const
{
    char lowercaseCharacter = convertCharacterToLowercase(character);
    return lowercaseCharacter >= 'a' && lowercaseCharacter <= 'z';
}

// Converts a letter into the matching child array index.
int BinaryTrie::getChildIndex(char character) const
{
    char lowercaseCharacter = convertCharacterToLowercase(character);

    if (lowercaseCharacter < 'a' || lowercaseCharacter > 'z')
    {
        return -1;
    }

    return lowercaseCharacter - 'a';
}

// Removes punctuation and converts letters to lowercase.
string BinaryTrie::normalizeWord(const string& word) const
{
    string normalizedWord = "";

    for (int index = 0; index < static_cast<int>(word.length()); index++)
    {
        char character = word[index];

        if (isLetterCharacter(character))
        {
            normalizedWord += convertCharacterToLowercase(character);
        }
    }

    return normalizedWord;
}

// Follows the trie path for a word or prefix.
TrieNode* BinaryTrie::findPrefixNode(const string& prefix) const
{
    string normalizedPrefix = normalizeWord(prefix);
    TrieNode* currentNode = root;

    if (normalizedPrefix.length() == 0)
    {
        return nullptr;
    }

    for (int index = 0; index < static_cast<int>(normalizedPrefix.length()); index++)
    {
        int childIndex = getChildIndex(normalizedPrefix[index]);

        if (childIndex < 0 || currentNode->children[childIndex] == nullptr)
        {
            return nullptr;
        }

        currentNode = currentNode->children[childIndex];
    }

    return currentNode;
}

// Adds a word to the trie or increments its existing count.
void BinaryTrie::insertWordIntoTrie(const string& word)
{
    string normalizedWord = normalizeWord(word);

    if (normalizedWord.length() == 0)
    {
        return;
    }

    TrieNode* currentNode = root;

    for (int index = 0; index < static_cast<int>(normalizedWord.length()); index++)
    {
        int childIndex = getChildIndex(normalizedWord[index]);

        if (currentNode->children[childIndex] == nullptr)
        {
            currentNode->children[childIndex] = new TrieNode(normalizedWord[index]);
        }

        currentNode = currentNode->children[childIndex];
    }

    if (currentNode->isWord)
    {
        currentNode->count++;
    }
    else
    {
        currentNode->isWord = true;
        currentNode->count = 1;
        uniqueWordCount++;
    }

    totalWordCount++;
}

// Searches for a complete word in the trie.
bool BinaryTrie::containsWord(const string& word) const
{
    TrieNode* wordNode = findPrefixNode(word);

    if (wordNode == nullptr)
    {
        return false;
    }

    return wordNode->isWord;
}

// Returns the stored count for a complete word.
int BinaryTrie::getFrequencyOfWord(const string& word) const
{
    TrieNode* wordNode = findPrefixNode(word);

    if (wordNode == nullptr || !wordNode->isWord)
    {
        return 0;
    }

    return wordNode->count;
}

// Deletes a node and all child paths.
void BinaryTrie::deleteTrieNodes(TrieNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    for (int index = 0; index < 26; index++)
    {
        deleteTrieNodes(node->children[index]);
    }

    delete node;
}

// Counts a node and all child paths.
int BinaryTrie::countTrieNodes(TrieNode* node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    int totalNodes = 1;

    for (int index = 0; index < 26; index++)
    {
        totalNodes += countTrieNodes(node->children[index]);
    }

    return totalNodes;
}

// Prints every terminal word node.
void BinaryTrie::displayStoredWordsInTrie(TrieNode* node, const string& currentWord) const
{
    if (node == nullptr)
    {
        return;
    }

    string nextWord = currentWord;

    if (node != root)
    {
        nextWord += node->letter;
    }

    if (node->isWord)
    {
        cout << nextWord << ": " << node->count << endl;
    }

    for (int index = 0; index < 26; index++)
    {
        displayStoredWordsInTrie(node->children[index], nextWord);
    }
}

// Displays the letter branches that continue from the typed prefix.
void BinaryTrie::displayAutocompleteBranches(TrieNode* node, const string& currentWord, const string& indent) const
{
    if (node == nullptr)
    {
        return;
    }

    string nextWord = currentWord + node->letter;

    cout << indent << "|-- " << convertCharacterToUppercase(node->letter) << endl;

    if (node->isWord)
    {
        cout << indent << "|   |-- (end) " << nextWord << " (" << node->count << ")" << endl;
    }

    for (int index = 0; index < 26; index++)
    {
        displayAutocompleteBranches(node->children[index], nextWord, indent + "|   ");
    }
}

// Prints every word represented under a node.
void BinaryTrie::displayWordPathsFromTrie(TrieNode* node, const string& currentWord) const
{
    if (node == nullptr)
    {
        return;
    }

    string nextWord = currentWord + node->letter;

    if (node->isWord)
    {
        displayWordPath(nextWord, node->count);
    }

    for (int index = 0; index < 26; index++)
    {
        displayWordPathsFromTrie(node->children[index], nextWord);
    }
}

// Prints one completed word as A -> B -> C = ABC.
void BinaryTrie::displayWordPath(const string& word, int count) const
{
    for (int index = 0; index < static_cast<int>(word.length()); index++)
    {
        cout << convertCharacterToUppercase(word[index]);

        if (index < static_cast<int>(word.length()) - 1)
        {
            cout << " -> ";
        }
    }

    cout << " = ";

    for (int index = 0; index < static_cast<int>(word.length()); index++)
    {
        cout << convertCharacterToUppercase(word[index]);
    }

    cout << " (" << count << ")" << endl;
}

// Returns the number of different words stored.
int BinaryTrie::getUniqueWordCount() const
{
    return uniqueWordCount;
}

// Returns the total number of valid words processed.
int BinaryTrie::getTotalWordCount() const
{
    return totalWordCount;
}

// Returns the total number of nodes in the trie.
int BinaryTrie::getNodeCount() const
{
    return countTrieNodes(root);
}

// Displays all stored words and their frequencies.
void BinaryTrie::displayAllStoredWords() const
{
    displayStoredWordsInTrie(root, "");
}

// Displays autocomplete words that start with the typed prefix.
void BinaryTrie::displayAutocompleteTree(const string& prefix) const
{
    string normalizedPrefix = normalizeWord(prefix);
    TrieNode* prefixNode = findPrefixNode(normalizedPrefix);

    if (normalizedPrefix.length() == 0)
    {
        cout << "Enter at least one letter." << endl;
        return;
    }

    if (prefixNode == nullptr)
    {
        cout << "No words start with " << normalizedPrefix << "." << endl;
        return;
    }

    cout << endl;
    cout << "Below is the structure words form in a trie:" << endl;
    cout << normalizedPrefix << endl;
    cout << endl;
    cout << "(*)" << endl;

    for (int index = 0; index < static_cast<int>(normalizedPrefix.length()); index++)
    {
        cout << "|" << endl;
        cout << convertCharacterToUppercase(normalizedPrefix[index]) << endl;
    }

    if (prefixNode->isWord)
    {
        cout << "|-- (end) " << normalizedPrefix << " (" << prefixNode->count << ")" << endl;
    }

    for (int index = 0; index < 26; index++)
    {
        displayAutocompleteBranches(prefixNode->children[index], normalizedPrefix, "");
    }

    cout << endl;
    cout << "Words represented" << endl;

    if (prefixNode->isWord)
    {
        displayWordPath(normalizedPrefix, prefixNode->count);
    }

    for (int index = 0; index < 26; index++)
    {
        displayWordPathsFromTrie(prefixNode->children[index], normalizedPrefix);
    }
}
