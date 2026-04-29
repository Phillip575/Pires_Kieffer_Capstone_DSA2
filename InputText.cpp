#include "InputText.h"
#include <fstream>
#include <string>

using namespace std;

// Converts uppercase letters to lowercase letters without using library helpers.
string InputText::convertWordToLowercase(const string& word) const
{
    string lowercaseWord = "";

    for (int index = 0; index < static_cast<int>(word.length()); index++)
    {
        char character = word[index];

        if (character >= 'A' && character <= 'Z')
        {
            character = static_cast<char>(character - 'A' + 'a');
        }

        lowercaseWord += character;
    }

    return lowercaseWord;
}

// Removes anything that is not a lowercase letter.
string InputText::removePunctuation(const string& word) const
{
    string cleanWord = "";

    for (int index = 0; index < static_cast<int>(word.length()); index++)
    {
        char character = word[index];

        if (character >= 'a' && character <= 'z')
        {
            cleanWord += character;
        }
    }

    return cleanWord;
}

// Runs all cleanup steps before a word reaches the trie.
string InputText::normalizeWord(const string& word) const
{
    string lowercaseWord = convertWordToLowercase(word);
    return removePunctuation(lowercaseWord);
}

// A word is valid when at least one letter remains after cleanup.
bool InputText::isWordValid(const string& word) const
{
    return word.length() > 0;
}

// Handles one word from the file.
void InputText::processWord(const string& word, BinaryTrie& trie) const
{
    string normalizedWord = normalizeWord(word);

    if (isWordValid(normalizedWord))
    {
        trie.insertWordIntoTrie(normalizedWord);
    }
}

// Opens the input file and sends each word into the trie.
bool InputText::processTheFile(const string& fileName, BinaryTrie& trie) const
{
    ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        return false;
    }

    string word = "";

    while (inputFile >> word)
    {
        processWord(word, trie);
    }

    inputFile.close();
    return true;
}
