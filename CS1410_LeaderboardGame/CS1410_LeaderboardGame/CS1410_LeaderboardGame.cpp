#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string LeaderboardNames = "leaderboard/names.txt";		// file containing the names of the top players
string LeaderboardScores = "leaderboard/scores.txt";	// file containing the scores of the top players
int guesses;

void DisplayLeaderboard(vector<string> name, vector<string> score);	// function prototype for displaying leaderboard
bool CoinTossGame(char choice);	// function prototype for handling the game

int main()
{
	// Read leaderboard names line-by-line
	ifstream NamesIn(LeaderboardNames);

	if (!NamesIn.good()) {	// checks if program is able to access names.txt File
		cout << "unable to locate leaderboard names";
		exit(1);	// Returns error code
	}

	string line;
	vector<string> LeadersName;
	while (getline(NamesIn, line)) {
		LeadersName.push_back(line);	// adds the line from names.txt to LeadersName vector string
	}
	NamesIn.close();

	// Read leaderboard scores line-by-line
	ifstream ScoresIn(LeaderboardScores);

	if (!ScoresIn.good()) {	// checks if program is able to access scores.txt File
		cout << "unable to locate leaderboard scores";
		exit(1);	// Returns error code
	}

	string line1;
	vector<string> LeadersScore;
	while (getline(ScoresIn, line1)) {
		LeadersScore.push_back(line1);	// adds the line from scores.txt to LeadersScore vector string
	}
	ScoresIn.close();

	DisplayLeaderboard(LeadersName, LeadersScore);

	char choice;
	bool result;
	do {
		cout << "(H)eads or (T)ails? ";
		cin >> choice;
		result = CoinTossGame(toupper(choice));
	} while (result != false);
}

void DisplayLeaderboard(vector<string> name, vector<string> score) {	// displays the current leaderboard to the player
	cout << "  Coin Toss Game Leaderboard  " << endl << endl;
	cout << "  Rank  |  Names  |  Guesses  " << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "   " << i + 1 << "    |  " << name[i] << " |    " << score[i] << endl;
	}
	cout << endl;
}

bool CoinTossGame(char choice) {
	char coin;
	int face = rand() % 10 + 1;

	if (face <= 5) {
		coin = 'H';
	}
	else if (face > 5) {
		coin = 'T';
	}

	if (choice == coin) {
		guesses++;
		cout << "Correct!" << endl << endl;
		return true;
	}
	else {
		cout << "Wrong!" << endl << endl;
		return false;
	}
}