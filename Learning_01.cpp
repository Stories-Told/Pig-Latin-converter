#include <iostream>
#include <string>

using namespace std;

int main()
{
	char vowels[] = { 'a', 'i', 'e', 'o', 'u' };
	char puncucation[] = { ',','.','?',';',':', };

	string word = "elephant.";

	char firstLetter = word[0];
	char lastLetter = word[word.length() - 1];

	for (int i = 0, ii = 0; i <= sizeof(vowels); i++)
	{
		while (firstLetter == vowels[i])
		{
			if (firstLetter == vowels[i] && lastLetter == puncucation[i])
			{
				char newPuncucationEnding = lastLetter;
				firstLetter = { 't' };
				word.erase(word.length() - 1);

				cout << word << "yay" << newPuncucationEnding << endl;
			}
			else if (firstLetter == vowels[i] && puncucation[i] != lastLetter)
			{
				firstLetter = { 't' };
				cout << word << "yay" << endl;

				cout << i;
			}
			else
			{
				firstLetter = word[0];
			}
		}
			
			
	}




	return 0;
}