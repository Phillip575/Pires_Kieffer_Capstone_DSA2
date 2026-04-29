
//

#include "BinaryTrie.h"
#include "InputText.h"
#include <iostream>
#include <string>

using namespace std;

void displaySummary(const BinaryTrie& trie)
{
    cout << endl;
    cout << "Summary" << endl;
    cout << "Total words processed: " << trie.getTotalWordCount() << endl;
    cout << "Unique words found: " << trie.getUniqueWordCount() << endl;
    cout << "Trie nodes created: " << trie.getNodeCount() << endl;
}

int main()
{
    BinaryTrie trie;
    InputText inputText;
    string fileName = "washington_farewell_address.txt";

    cout << "Washington Farewell Address Autocomplete" << endl;

    bool fileLoaded = inputText.processTheFile(fileName, trie);

    if (!fileLoaded)
    {
        fileName = "..\\..\\washington_farewell_address.txt";
        fileLoaded = inputText.processTheFile(fileName, trie);
    }

    if (!fileLoaded)
    {
        cout << "File could not be opened." << endl;
        cout << "The program only uses words from washington_farewell_address.txt." << endl;
        return 1;
    }

    cout << "Washington address loaded." << endl;
    displaySummary(trie);

    while (true)
    {
        string prefix = "";

        cout << endl;
        cout << "Enter one or more letters for autocomplete, or type exit: ";
        getline(cin, prefix);

        if (prefix == "exit")
        {
            break;
        }

        trie.displayAutocompleteTree(prefix);
    }

    return 0;
}
