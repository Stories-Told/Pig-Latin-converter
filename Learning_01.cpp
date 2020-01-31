#include <iostream>
#include <string>

using namespace std;

// Global Variable
char yesOrNo;

// Forward declarations
void CheckForError(string word, size_t foundEndPunctuation);
char EnterAnotherWord(char yesOrNo);

int main()
{
	// Test word for vowel pig latin converter
	string word = "which?";
	string vowelEnding = "yay";
	string constantEnding = "ay";
	
	// Output what the program is to the user
	cout << "-------------------\n";
	cout << "Pig Latin Converter\n";
	cout << "-------------------\n\n";

	cout << "Enter your word to be converted: ";
	cin >> word;
	cout << endl;

	// FoundEnd looks for any of the punctuation ends in the word
	// foundVowel looks for the first vowel and returns a 0
	size_t foundEndPunctuation = word.find_first_of(",.?;:!");
	size_t foundVowel = word.find_first_of("aAiIeEoOuU");

	// Checks for empty string
	if (word.empty()) return 0;

	// If statement to check for vowel conversion
	if (foundVowel == 0)
	{
		// If statement checking if there is punctuation at the end
		if (foundEndPunctuation >= 1 && foundEndPunctuation < 100)
		{

			// Checks to make sure the punctuation is at the end
			CheckForError(word, foundEndPunctuation);

			// Takes the last character in the word and saves it
			char lastLetter = word[word.length() - 1];

			// Erases the punctuation in order to add -yay onto the end
			// of the word
			word.erase(word.begin() + word.length() - 1);

			cout << word.append(vowelEnding) << lastLetter << endl;

			// Ask to enter another word
			EnterAnotherWord(yesOrNo);
		}
		// If not punctuation found then add -yay onto the end
		else if (foundEndPunctuation > 100)
		{
			cout << word.append(vowelEnding) << endl;

			// Ask to enter another word
			EnterAnotherWord(yesOrNo);
		}
	}

	// If the first letter isn't a vowel then begin constant conversion
	else if (foundVowel != 0)
	{
		// Check if there is punctuation at the end
		if (foundEndPunctuation >= 1 && foundEndPunctuation < 100)
		{
			// Check to make sure punctuation is at the end of word
			CheckForError(word, foundEndPunctuation);

			// Takes the last character in the word and saves it
			// in this case should be punctuation
			char lastLetter = word[word.length() - 1];

			// Erase the punctuation in order to append the string
			word.erase(word.begin() + word.length() - 1);

			// Saves the beginning constant letters and saves them
			string lettersOfConstant = word.substr(0, foundVowel);

			// Delete the constants in order to append correctly
			// deletes up until the first vowel in the word
			string constantsDeleted = word.erase(0, foundVowel);

			// Word now converted into correct pig latin
			string convertedConstantPig = constantsDeleted.append(lettersOfConstant);

			// Output the newly converted contant pig latin word with
			// correct punctuation at end
			cout << convertedConstantPig.append(constantEnding) << lastLetter << endl;

			// Ask to enter another word
			EnterAnotherWord(yesOrNo);
		}
		// If no punctuation is found then convert without any punctuations
		else if (foundEndPunctuation > 100)
		{
			// Saves the constant letters up until the first vowel
			string lettersOfConstant = word.substr(0, foundVowel);
			// Deletes the constants up until the first vowel
			string constantsDeleted = word.erase(0, foundVowel);
			// Word converted in pig latin
			string convertedConstantPig = constantsDeleted.append(lettersOfConstant);

			cout << convertedConstantPig.append(constantEnding) << endl;

			// Ask to enter another word
			EnterAnotherWord(yesOrNo);
		}
	}

	CheckForError(word, foundEndPunctuation);

	return 0;
}

// Checks to make sure that the punctuation is at the end of word
// if not closes the console
void CheckForError(string word, size_t foundEndPunctuation)
{
	// Takes the place where the punctuation should be in the word
	int puncAtTheEndPlace = word.length() - 1;
	int puncAtTheStart = word.at(0);
	// Checks that where the punctuation should be and matches it 
	// with where the punctuation was actually found
	// if they don't equal, throw an error
	if (puncAtTheEndPlace != foundEndPunctuation)
	{
		cerr << "ERROR: punctuation not at end of word" << "\n\n";

		EnterAnotherWord(yesOrNo);
	}
	
}

// Function to ask to main menu
char EnterAnotherWord(char yesOrNo)
{
	cout << "Enter another word? (Y/N): ";
	cin >> yesOrNo;
	cout << endl;

	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		system("CLS");
		return main();
	}
	else if (yesOrNo == 'N' || yesOrNo == 'n')
	{
		cout << "EXITING..." << endl;
		exit(0);
	}

	return 0;
}
