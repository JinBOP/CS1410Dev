#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Function Prototypes
void AddLetter(string, int, int, int, int, const vector<vector<char>>&, const vector<string>&);
vector<string> MakePrefixSet(string, const vector<string>&);

string solutionfile = "solutions/solutions.txt";
string puzzlefile = "puzzles/earth.txt";

int main()
{
	// Read english dictionary line-by-line
	ifstream DictIn("dictionary/english.txt");

	if (!DictIn.good()) {	// checks if program is able to access english.txt File
		cout << "unable to locate dictionary";
		exit(1);	// Returns error code
	}

	string line;
	vector<string> dictionary;	// a Vector is an adjustable Array
	while (getline(DictIn, line)) {
		dictionary.push_back(line);	// adds the line from english.txt to dictionary vector string
	}
	DictIn.close();

	// Read word search puzzle char-by-char
	ifstream PuzzleIn("puzzles/earth.txt");

	if (!PuzzleIn.good()) {	// checks if program is able to access earth.txt File
		cout << "unable to locate dictionary";
		exit(1);
	}

	// check if able to write results
	ofstream SolutionOut;
	SolutionOut.open(solutionfile);
	if (!SolutionOut.good()) {
		cout << "unable to locate solution file";
		exit(1);
	}
	SolutionOut.close();

	char letter;
	vector<vector<char>> puzzle;	// 2 dimensional Vector
	puzzle.push_back(vector<char>());	// first row
	int row = 0;
	while (PuzzleIn.get(letter)) {
		if (letter == '\n' || letter == '\r\n') {
			puzzle.push_back(vector<char>());
			row++;
		}
		else {
			puzzle[row].push_back(letter);
		}
	}

	// Display the puzzle
	for (vector<char> row : puzzle) {
		for (char letter : row) {
			cout << letter << ' ';
		}
		cout << endl;
	}

	// For every letter
	for (int row = 0; row < puzzle.size(); row++) {
		for (int col = 0; col < puzzle[row].size(); col++) {
			// check in all 8 directions
			for (int v = -1; v <= 1; v++) {
				for(int h = -1; h <= 1; h++) {
					if (!(v == 0 && h == 0)) {
						string word = string(1, tolower(puzzle[row][col]));
						AddLetter(word, row, col, v, h, puzzle, dictionary);
					}
				}
			}
		}
	}
}

void AddLetter(string word, int r, int c, int v, int h, const vector<vector<char>>& puzzle, const vector<string>& dictionary) {
	if (r + v >= 0 && r + v < puzzle.size() && c + h >= 0 && c + h < puzzle[r].size()) {	// checks if still within bounds of the vector
		word += tolower(puzzle[r + v][c + h]);

		if (word.size() >= 4) {	// adds at minimum 4 letters
			if (count(dictionary.begin(), dictionary.end(), word)) {	// checks if word is in dictionary
				cout << word << " (Row:" << (r + v) + 1 << ", Col:" << (c + h) + 1 << ")" << endl;

				ofstream SolutionOut;	// creates new file to write solutions into
				SolutionOut.open(solutionfile, ios::app);	// Appends the new word found to the solution text File
				if (!SolutionOut.good()) {	// checks if able to write to File and displays error message if otherwise
					cerr << "Unable to write to file!" << endl;
				}
				else {
					SolutionOut << word << " (Row:" << (r + v) + 1 << ", Col:" << (c + h) + 1 << ")" << endl;
					SolutionOut.close();
				}
			}

			vector<string> WordSublist = MakePrefixSet(word, dictionary); // updates dictionary

			if (WordSublist.size() > 0) {	// keeps going if word is in dictionary
				AddLetter(word, r + v, c + h, v, h, puzzle, WordSublist);
			}
		}
		else {
			AddLetter(word, r + v, c + h, v, h, puzzle, dictionary);
		
		}
	}
}

vector<string> MakePrefixSet(string prefix, const vector<string>& wordlist) {
	vector<string> PrefixList;
	for (string word : wordlist) {
		if (word.substr(0, prefix.size()) == prefix) {
			PrefixList.push_back(word);
		}
	}
	return PrefixList;
}