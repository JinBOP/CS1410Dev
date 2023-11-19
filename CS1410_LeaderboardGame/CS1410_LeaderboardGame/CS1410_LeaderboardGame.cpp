#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void DisplayLeaderboard();

string LeaderboardNames = "leaderboard/names.txt";		// file containing the names of the top players
string LeaderboardScores = "leaderboard/scores.txt";	// file containing the scores of the top players

int main()
{
	// Read leaderboard names line-by-line
	ifstream NamesIn("leaderboard/names.txt");

	if (!NamesIn.good()) {	// checks if program is able to access names.txt File
		cout << "unable to locate leaderboard names";
		exit(1);	// Returns error code
	}

	string line;
	vector<string> Leaders;
	while (getline(NamesIn, line)) {
		Leaders.push_back(line);	// adds the line from names.txt to Leaders vector string
	}
	NamesIn.close();

}

void DisplayLeaderboard() {	// displays the current leaderboard to the player
	cout << "Number Guessing Game Leaderboard" << endl << endl;
	cout << "Rank | Names  | Guesses" << endl;
	for (int i = 1; i < 6; i++) {
		cout << i << "    | " << (player name) << " | " << (player score) << endl;
	}
}