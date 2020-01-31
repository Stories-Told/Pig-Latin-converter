#include <iostream>
#include <string>

using namespace std;

// Forward declarations
void CheckForError(string word, size_t foundEnd);

int main()
{
	// Test word for vowel pig latin converter
	string wordVowel = "elephant?";
	string yayEnding = "yay";

	// FoundEnd looks for any of the punctuation ends in the word
	// foundVowel looks for the first vowel and returns a 0
	size_t foundEndPunctuation = wordVowel.find_first_of(",.?;:");
	size_t foundVowel = wordVowel.find_first_of("aAiIeEoOuU");

	

	if (foundEndPunctuation >= 1 && foundEndPunctuation < 100)
	{
		// Takes the last character in the word and saves it
		char lastLetter = wordVowel[wordVowel.length() - 1];

		// Checks to make sure the punctuation is at the end
		CheckForError(wordVowel, foundEndPunctuation);

		// Erases the punctuation in order to add -yay onto the end
		// of the word
		wordVowel.erase(wordVowel.begin() + wordVowel.length() - 1);
		
		// Check and make sure the word has vowel beginning
		// if it does, append -yay onto the end and move the
		// punctuation to the end
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
	// Takes the place where the punctuation should be in the word
	int puncAtTheEndPlace = word.length() - 1;

	// Checks that where the punctuation should be and matches it 
	// with where the punctuation was actually found
	// if they don't equal, throw an error
	if (puncAtTheEndPlace != foundEnd)
	{
		cerr << "ERROR: punctuation not at end of word" << endl;

		exit(1);
	}
}
