#include <iostream>
#include <string>

using namespace std;

// Forward declarations
void CheckForError(string word, size_t foundEnd);

int main()
{
	string wordVowel = "elephant?";
	string yayEnding = "yay";

	size_t foundEnd = wordVowel.find_first_of(",.?;:");
	size_t foundVowel = wordVowel.find_first_of("aAiIeEoOuU");

	char lastLetter = wordVowel[wordVowel.length() - 1];

	if (foundEnd >= 1 && foundEnd < 100)
	{
		CheckForError(wordVowel, foundEnd);
		char newEnd = lastLetter;
		wordVowel.erase(wordVowel.begin() + wordVowel.length() - 1);
		
		if (foundVowel == 0)
		{
			cout << wordVowel.append(yayEnding) << lastLetter << endl;
		}

	}

	return 0;
}

// Checks to make sure that the punctuation is at the end of word
// if not closes the console
void CheckForError(string word, size_t foundEnd)
{
	int puncAtTheEndPlace = word.length() - 1;

	if (puncAtTheEndPlace != foundEnd)
	{
		cerr << "ERROR: punctuation not at end of word" << endl;

		exit(1);
	}
}
