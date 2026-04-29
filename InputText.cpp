#include "InputText.h"
#include <string>
// Done by phillip pires with help of copilot

using namespace std;

string InputText::convertWordToLowercase(const string& word) const
{
    // convert a word to lowercase
};

string InputText::removePunctuation(const string& word) const
{
    // remove punctuation from a word
};

string InputText::normalizeWord(const string& word) const
{
    // normalize a word before storing it
};

bool InputText::isWordValid(const string& word) const
{
    // check whether a word should be stored
};

void InputText::processWord(const string& word, BinaryTrie& trie) const
{
    // process one word and pass it to the trie
};

bool InputText::processTheFile(const string& fileName, BinaryTrie& trie) const
{
    // process the file and send words into the trie
};
