#include <iostream>
#include <fstream> // input filestream for reading from english.txt file
#include <vector> // dynamic lists
#include <string> // string manipulation
using namespace std;
// be sure to understand the problem you're trying to solve before starting to code

bool stringcontains(string, char);
void updateword(char, string, string&);
void showscore();
void updatedisplay(string, string, int);
int maxstrikes = 7, win = 0, loss = 0, score = 0;

int main()
{
	srand(time(0));

	string line;
	vector<string> dictionary; // keeps track of all available words

	ifstream file("english.txt");
	while (getline(file, line)) {
		dictionary.push_back(line);
	}

	cout << "Hangman!\n";
	char response;
	do {
		// think of a word
		string actualword = dictionary[rand() % dictionary.size()];

		// display blank space for each letter
		string completedword = "", lettersused = "";
		for (char letter : actualword) {
			completedword += "_";
		}

		int strikes = maxstrikes; // keep track of how many guesses left

		// keep playing until finished or lost
		while (stringcontains(completedword, '_') && strikes > 0) {
			showscore();
			updatedisplay(lettersused, completedword, strikes);

			// allow player to guess a letter
			char guess;
			cout << "Your guess: ";
			cin >> guess;
			guess = tolower(guess);

			system("cls"); //Windows only command

			if (guess >= 97 && guess <= 122) { // checks if guess is a letter
				// determine if guess is right, wrong, repeat, or invalid
				if (stringcontains(lettersused, guess) || stringcontains(completedword, guess)) { // keep track of letters guessed
					cout << "Already tried that letter!" << endl;
				}
				else if (stringcontains(actualword, guess)) {
					cout << "Correct!" << endl;
					updateword(guess, actualword, completedword);

				}
				else {
					cout << "Incorrect!" << endl;
					lettersused += guess;
					strikes--;
				}
			}
			else {
				cout << "Type letters only" << endl; // make them try again if repeat or invalid
			}
		}

		if (strikes > 0) {
			win++;
			score += actualword.size() * 5 + strikes * 10;
		}
		else {
			loss++;
		}

		showscore();
		updatedisplay(lettersused, completedword, strikes);
		cout << "Correct word: " << actualword << endl;

		cout << "Play again? (Y/N) ";
		cin >> response;
	} while (toupper(response == 'Y'));
}

bool stringcontains(string text, char letter) { // function to check if letter guessed is correct
	for (char character : text) { // for range loop
		if (character == letter) {
			return true;
		}
	}
	return false;
}

void updateword(char guess, string actualword, string& completedword) { // update space if guessed right
	for (int i = 0; i < actualword.size(); i++) {
		if (actualword.at(i) == guess) {
			completedword = completedword.substr(0,i) + guess + completedword.substr(i + 1, completedword.length()); // creates new string with new information
		}
	}
}

void showscore() { // Procedures with global variables
	cout << "\nWins: " << win << endl;
	cout << "Losses: " << loss << endl;
	cout << "Score: " << score;
}

void updatedisplay(string lettersused, string completedword, int strikes) {
	cout << "\nLetters Guessed: " << lettersused << endl;
	cout << "Strikes left: " << strikes << "of" << maxstrikes << endl;
	cout << completedword << endl;
}