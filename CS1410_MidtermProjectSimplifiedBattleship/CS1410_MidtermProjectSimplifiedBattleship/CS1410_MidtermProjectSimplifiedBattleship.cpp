// by: H. 'Jin' Starks
#include <iostream>
#include <string>
using namespace std;

struct Enemy {	// Structure for keeping track of Enemy locations on the board
	int x;
	int y;
};

int Validate(string cordinate);	// Input validation Function
int Shoot(string array[11][11], int x, int y, int target1x, int target1y, int target2x, int target2y, int target3x, int target3y, int target4x, int target4y, int target5x, int target5y, int target6x, int target6y, int target7x, int target7y, int target8x, int target8y, int target9x, int target9y, int target10x, int target10y, int target11x, int target11y, int target12x, int target12y, int target13x, int target13y, int target14x, int target14y, int target15x, int target15y, int target16x, int target16y, int target17x, int target17y);	// Used to determine if repreated shot, hit, or miss

int shots, targets;	// Universal variables for tracking number of shots (tries) the player has and how many targets remain

int main()
{
	// Setdressing and Rules explanation
	cout << "	Welcome to Shore Defense!" << endl << endl;
	cout << "	You have been assigned to ensure the secret island base your team is using " << endl << "	to spy on the city of R'lyeh stays safe and hidden from the forces of Cthulhu." << endl << endl;
	cout << "	Cthulhu has amassed a small platoon of 17 scouting troops to occupy" << endl << "	the nearby island where your team is hiding." << endl << endl;
	cout << "	You have just enough time to load and fire 50 shots from your cannon" << endl << "	before the platoon reaches the surface of the water, take them out or you're toast!" << endl << endl;
	cout << "Objective: Protect your team by warding off all enemies and keeping your base from being found!" << endl;

	// Generates Enemy locations
	Enemy target1 = { 1,1 };
	Enemy target2 = { 1,1 };
	Enemy target3 = { 1,1 };
	Enemy target4 = { 1,1 };
	Enemy target5 = { 1,1 };
	Enemy target6 = { 1,1 };
	Enemy target7 = { 1,1 };
	Enemy target8 = { 1,1 };
	Enemy target9 = { 1,1 };
	Enemy target10 = { 1,1 };
	Enemy target11 = { 1,1 };
	Enemy target12 = { 1,1 };
	Enemy target13 = { 1,1 };
	Enemy target14 = { 1,1 };
	Enemy target15 = { 1,1 };
	Enemy target16 = { 1,1 };
	Enemy target17 = { 1,1 };

	// While loops ensure none of the targets overlap
	while ((target2.x == target1.x && target2.y == target1.y) || (target2.x == target3.x && target2.y == target3.y) || (target2.x == target4.x && target2.y == target4.y) || (target2.x == target5.x && target2.y == target5.y) || (target2.x == target6.x && target2.y == target6.y) || (target2.x == target7.x && target2.y == target7.y) || (target2.x == target8.x && target2.y == target8.y) || (target2.x == target9.x && target2.y == target9.y) || (target2.x == target10.x && target2.y == target10.y) || (target2.x == target11.x && target2.y == target11.y) || (target2.x == target12.x && target2.y == target12.y) || (target2.x == target13.x && target2.y == target13.y) || (target2.x == target14.x && target2.y == target14.y) || (target2.x == target15.x && target2.y == target15.y) || (target2.x == target16.x && target2.y == target16.y) || (target2.x == target17.x && target2.y == target17.y)) {
		target2.x = rand() % 10 + 1;
		target2.y = rand() % 10 + 1;
	}
	while ((target3.x == target1.x && target3.y == target1.y) || (target3.x == target2.x && target3.y == target2.y) || (target3.x == target4.x && target3.y == target4.y) || (target3.x == target5.x && target3.y == target5.y) || (target3.x == target6.x && target3.y == target6.y) || (target3.x == target7.x && target3.y == target7.y) || (target3.x == target8.x && target3.y == target8.y) || (target3.x == target9.x && target3.y == target9.y) || (target3.x == target10.x && target3.y == target10.y) || (target3.x == target11.x && target3.y == target11.y) || (target3.x == target12.x && target3.y == target12.y) || (target3.x == target13.x && target3.y == target13.y) || (target3.x == target14.x && target3.y == target14.y) || (target3.x == target15.x && target3.y == target15.y) || (target3.x == target16.x && target3.y == target16.y) || (target3.x == target17.x && target3.y == target17.y)) {
		target3.x = rand() % 10 + 1;
		target3.y = rand() % 10 + 1;
	}
	while ((target4.x == target1.x && target4.y == target1.y) || (target4.x == target2.x && target4.y == target2.y) || (target4.x == target3.x && target4.y == target3.y) || (target4.x == target5.x && target4.y == target5.y) || (target4.x == target6.x && target4.y == target6.y) || (target4.x == target7.x && target4.y == target7.y) || (target4.x == target8.x && target4.y == target8.y) || (target4.x == target9.x && target4.y == target9.y) || (target4.x == target10.x && target4.y == target10.y) || (target4.x == target11.x && target4.y == target11.y) || (target4.x == target12.x && target4.y == target12.y) || (target4.x == target13.x && target4.y == target13.y) || (target4.x == target14.x && target4.y == target14.y) || (target4.x == target15.x && target4.y == target15.y) || (target4.x == target16.x && target4.y == target16.y) || (target4.x == target17.x && target4.y == target17.y)) {
		target4.x = rand() % 10 + 1;
		target4.y = rand() % 10 + 1;
	}
	while ((target5.x == target1.x && target5.y == target1.y) || (target5.x == target2.x && target5.y == target2.y) || (target5.x == target3.x && target5.y == target3.y) || (target5.x == target4.x && target5.y == target4.y) || (target5.x == target6.x && target5.y == target6.y) || (target5.x == target7.x && target5.y == target7.y) || (target5.x == target8.x && target5.y == target8.y) || (target5.x == target9.x && target5.y == target9.y) || (target5.x == target10.x && target5.y == target10.y) || (target5.x == target11.x && target5.y == target11.y) || (target5.x == target12.x && target5.y == target12.y) || (target5.x == target13.x && target5.y == target13.y) || (target5.x == target14.x && target5.y == target14.y) || (target5.x == target15.x && target5.y == target15.y) || (target5.x == target16.x && target5.y == target16.y) || (target5.x == target17.x && target5.y == target17.y)) {
		target5.x = rand() % 10 + 1;
		target5.y = rand() % 10 + 1;
	}
	while ((target6.x == target1.x && target6.y == target1.y) || (target6.x == target2.x && target6.y == target2.y) || (target6.x == target3.x && target6.y == target3.y) || (target6.x == target4.x && target6.y == target4.y) || (target6.x == target5.x && target6.y == target5.y) || (target6.x == target7.x && target6.y == target7.y) || (target6.x == target8.x && target6.y == target8.y) || (target6.x == target9.x && target6.y == target9.y) || (target6.x == target10.x && target6.y == target10.y) || (target6.x == target11.x && target6.y == target11.y) || (target6.x == target12.x && target6.y == target12.y) || (target6.x == target13.x && target6.y == target13.y) || (target6.x == target14.x && target6.y == target14.y) || (target6.x == target15.x && target6.y == target15.y) || (target6.x == target16.x && target6.y == target16.y) || (target6.x == target17.x && target6.y == target17.y)) {
		target6.x = rand() % 10 + 1;
		target6.y = rand() % 10 + 1;
	}
	while ((target7.x == target1.x && target7.y == target1.y) || (target7.x == target2.x && target7.y == target2.y) || (target7.x == target3.x && target7.y == target3.y) || (target7.x == target4.x && target7.y == target4.y) || (target7.x == target5.x && target7.y == target5.y) || (target7.x == target6.x && target7.y == target6.y) || (target7.x == target8.x && target7.y == target8.y) || (target7.x == target9.x && target7.y == target9.y) || (target7.x == target10.x && target7.y == target10.y) || (target7.x == target11.x && target7.y == target11.y) || (target7.x == target12.x && target7.y == target12.y) || (target7.x == target13.x && target7.y == target13.y) || (target7.x == target14.x && target7.y == target14.y) || (target7.x == target15.x && target7.y == target15.y) || (target7.x == target16.x && target7.y == target16.y) || (target7.x == target17.x && target7.y == target17.y)) {
		target7.x = rand() % 10 + 1;
		target7.y = rand() % 10 + 1;
	}
	while ((target8.x == target1.x && target8.y == target1.y) || (target8.x == target2.x && target8.y == target2.y) || (target8.x == target3.x && target8.y == target3.y) || (target8.x == target4.x && target8.y == target4.y) || (target8.x == target5.x && target8.y == target5.y) || (target8.x == target6.x && target8.y == target6.y) || (target8.x == target7.x && target8.y == target7.y) || (target8.x == target9.x && target8.y == target9.y) || (target8.x == target10.x && target8.y == target10.y) || (target8.x == target11.x && target8.y == target11.y) || (target8.x == target12.x && target8.y == target12.y) || (target8.x == target13.x && target8.y == target13.y) || (target8.x == target14.x && target8.y == target14.y) || (target8.x == target15.x && target8.y == target15.y) || (target8.x == target16.x && target8.y == target16.y) || (target8.x == target17.x && target8.y == target17.y)) {
		target8.x = rand() % 10 + 1;
		target8.y = rand() % 10 + 1;
	}
	while ((target9.x == target1.x && target9.y == target1.y) || (target9.x == target2.x && target9.y == target2.y) || (target9.x == target3.x && target9.y == target3.y) || (target9.x == target4.x && target9.y == target4.y) || (target9.x == target5.x && target9.y == target5.y) || (target9.x == target6.x && target9.y == target6.y) || (target9.x == target7.x && target9.y == target7.y) || (target9.x == target8.x && target9.y == target8.y) || (target9.x == target10.x && target9.y == target10.y) || (target9.x == target11.x && target9.y == target11.y) || (target9.x == target12.x && target9.y == target12.y) || (target9.x == target13.x && target9.y == target13.y) || (target9.x == target14.x && target9.y == target14.y) || (target9.x == target15.x && target9.y == target15.y) || (target9.x == target16.x && target9.y == target16.y) || (target9.x == target17.x && target9.y == target17.y)) {
		target9.x = rand() % 10 + 1;
		target9.y = rand() % 10 + 1;
	}
	while ((target10.x == target1.x && target10.y == target1.y) || (target10.x == target2.x && target10.y == target2.y) || (target10.x == target3.x && target10.y == target3.y) || (target10.x == target4.x && target10.y == target4.y) || (target10.x == target5.x && target10.y == target5.y) || (target10.x == target6.x && target10.y == target6.y) || (target10.x == target7.x && target10.y == target7.y) || (target10.x == target8.x && target10.y == target8.y) || (target10.x == target9.x && target10.y == target9.y) || (target10.x == target11.x && target10.y == target11.y) || (target10.x == target12.x && target10.y == target12.y) || (target10.x == target13.x && target10.y == target13.y) || (target10.x == target14.x && target10.y == target14.y) || (target10.x == target15.x && target10.y == target15.y) || (target10.x == target16.x && target10.y == target16.y) || (target10.x == target17.x && target10.y == target17.y)) {
		target10.x = rand() % 10 + 1;
		target10.y = rand() % 10 + 1;
	}
	while ((target11.x == target1.x && target11.y == target1.y) || (target11.x == target2.x && target11.y == target2.y) || (target11.x == target3.x && target11.y == target3.y) || (target11.x == target4.x && target11.y == target4.y) || (target11.x == target5.x && target11.y == target5.y) || (target11.x == target6.x && target11.y == target6.y) || (target11.x == target7.x && target11.y == target7.y) || (target11.x == target8.x && target11.y == target8.y) || (target11.x == target9.x && target11.y == target9.y) || (target11.x == target10.x && target11.y == target10.y) || (target11.x == target12.x && target11.y == target12.y) || (target11.x == target13.x && target11.y == target13.y) || (target11.x == target14.x && target11.y == target14.y) || (target11.x == target15.x && target11.y == target15.y) || (target11.x == target16.x && target11.y == target16.y) || (target11.x == target17.x && target11.y == target17.y)) {
		target11.x = rand() % 10 + 1;
		target11.y = rand() % 10 + 1;
	}
	while ((target12.x == target1.x && target12.y == target1.y) || (target12.x == target2.x && target12.y == target2.y) || (target12.x == target3.x && target12.y == target3.y) || (target12.x == target4.x && target12.y == target4.y) || (target12.x == target5.x && target12.y == target5.y) || (target12.x == target6.x && target12.y == target6.y) || (target12.x == target7.x && target12.y == target7.y) || (target12.x == target8.x && target12.y == target8.y) || (target12.x == target9.x && target12.y == target9.y) || (target12.x == target10.x && target12.y == target10.y) || (target12.x == target11.x && target12.y == target11.y) || (target12.x == target13.x && target12.y == target13.y) || (target12.x == target14.x && target12.y == target14.y) || (target12.x == target15.x && target12.y == target15.y) || (target12.x == target16.x && target12.y == target16.y) || (target12.x == target17.x && target12.y == target17.y)) {
		target12.x = rand() % 10 + 1;
		target12.y = rand() % 10 + 1;
	}
	while ((target13.x == target1.x && target13.y == target1.y) || (target13.x == target2.x && target13.y == target2.y) || (target13.x == target3.x && target13.y == target3.y) || (target13.x == target4.x && target13.y == target4.y) || (target13.x == target5.x && target13.y == target5.y) || (target13.x == target6.x && target13.y == target6.y) || (target13.x == target7.x && target13.y == target7.y) || (target13.x == target8.x && target13.y == target8.y) || (target13.x == target9.x && target13.y == target9.y) || (target13.x == target10.x && target13.y == target10.y) || (target13.x == target11.x && target13.y == target11.y) || (target13.x == target12.x && target13.y == target12.y) || (target13.x == target14.x && target13.y == target14.y) || (target13.x == target15.x && target13.y == target15.y) || (target13.x == target16.x && target13.y == target16.y) || (target13.x == target17.x && target13.y == target17.y)) {
		target13.x = rand() % 10 + 1;
		target13.y = rand() % 10 + 1;
	}
	while ((target14.x == target1.x && target14.y == target1.y) || (target14.x == target2.x && target14.y == target2.y) || (target14.x == target3.x && target14.y == target3.y) || (target14.x == target4.x && target14.y == target4.y) || (target14.x == target5.x && target14.y == target5.y) || (target14.x == target6.x && target14.y == target6.y) || (target14.x == target7.x && target14.y == target7.y) || (target14.x == target8.x && target14.y == target8.y) || (target14.x == target9.x && target14.y == target9.y) || (target14.x == target10.x && target14.y == target10.y) || (target14.x == target11.x && target14.y == target11.y) || (target14.x == target12.x && target14.y == target12.y) || (target14.x == target13.x && target14.y == target13.y) || (target14.x == target15.x && target14.y == target15.y) || (target14.x == target16.x && target14.y == target16.y) || (target14.x == target17.x && target14.y == target17.y)) {
		target14.x = rand() % 10 + 1;
		target14.y = rand() % 10 + 1;
	}
	while ((target15.x == target1.x && target15.y == target1.y) || (target15.x == target2.x && target15.y == target2.y) || (target15.x == target3.x && target15.y == target3.y) || (target15.x == target4.x && target15.y == target4.y) || (target15.x == target5.x && target15.y == target5.y) || (target15.x == target6.x && target15.y == target6.y) || (target15.x == target7.x && target15.y == target7.y) || (target15.x == target8.x && target15.y == target8.y) || (target15.x == target9.x && target15.y == target9.y) || (target15.x == target10.x && target15.y == target10.y) || (target15.x == target11.x && target15.y == target11.y) || (target15.x == target12.x && target15.y == target12.y) || (target15.x == target13.x && target15.y == target13.y) || (target15.x == target14.x && target15.y == target14.y) || (target15.x == target16.x && target15.y == target16.y) || (target15.x == target17.x && target15.y == target17.y)) {
		target15.x = rand() % 10 + 1;
		target15.y = rand() % 10 + 1;
	}
	while ((target16.x == target1.x && target16.y == target1.y) || (target16.x == target2.x && target16.y == target2.y) || (target16.x == target3.x && target16.y == target3.y) || (target16.x == target4.x && target16.y == target4.y) || (target16.x == target5.x && target16.y == target5.y) || (target16.x == target6.x && target16.y == target6.y) || (target16.x == target7.x && target16.y == target7.y) || (target16.x == target8.x && target16.y == target8.y) || (target16.x == target9.x && target16.y == target9.y) || (target16.x == target10.x && target16.y == target10.y) || (target16.x == target11.x && target16.y == target11.y) || (target16.x == target12.x && target16.y == target12.y) || (target16.x == target13.x && target16.y == target13.y) || (target16.x == target14.x && target16.y == target14.y) || (target16.x == target15.x && target16.y == target15.y) || (target16.x == target17.x && target16.y == target17.y)) {
		target16.x = rand() % 10 + 1;
		target16.y = rand() % 10 + 1;
	}
	while ((target17.x == target1.x && target17.y == target1.y) || (target17.x == target2.x && target17.y == target2.y) || (target17.x == target3.x && target17.y == target3.y) || (target17.x == target4.x && target17.y == target4.y) || (target17.x == target5.x && target17.y == target5.y) || (target17.x == target6.x && target17.y == target6.y) || (target17.x == target7.x && target17.y == target7.y) || (target17.x == target8.x && target17.y == target8.y) || (target17.x == target9.x && target17.y == target9.y) || (target17.x == target10.x && target17.y == target10.y) || (target17.x == target11.x && target17.y == target11.y) || (target17.x == target12.x && target17.y == target12.y) || (target17.x == target13.x && target17.y == target13.y) || (target17.x == target14.x && target17.y == target14.y) || (target17.x == target15.x && target17.y == target15.y) || (target17.x == target16.x && target17.y == target16.y)) {
		target17.x = rand() % 10 + 1;
		target17.y = rand() % 10 + 1;
	}
	cout << "   target1:" << target1.y << "," << target1.x << "   target2:" << target2.y << "," << target2.x << "   target3:" << target3.y << "," << target3.x << "   target4:" << target4.y << "," << target4.x << "   target5:" << target5.y << "," << target5.x << "   target6:" << target6.y << "," << target6.x << "   target7:" << target7.y << "," << target7.x << "   target8:" << target8.y << "," << target8.x << endl << "   target9:" << target9.y << "," << target9.x << "   target10:" << target10.y << "," << target10.x << "   target11:" << target11.y << "," << target11.x << "   target12:" << target12.y << "," << target12.x << "   target13:" << target13.y << "," << target13.x << "   target14:" << target14.y << "," << target14.x << "   target15:" << target15.y << "," << target15.x << endl << "   target16:" << target16.y << "," << target16.x << "   target17:" << target17.y << "," << target17.x << endl << endl;	  // Displays all target locations for debugging purposes
	
	const int grid = 121;	// Establishes the total number of spaces in the array

	string playerboard[11][11] = {"   ","x1 ", "x2 ","x3 ", "x4 ", "x5 ","x6 ","x7 ","x8 ","x9 ","x10",	// Gameboard
								  "y1 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y2 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y3 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y4 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y5 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y6 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y7 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y8 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y9 ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ",
								  "y10","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] ","[] "};

	shots = 50;	// Total number of guesses
	targets = 17;	// Total number of targets

		while ((shots > 0 && targets > 0) && (shots > targets)) {	// While Loop continues until player wins or runs out of shots
			string xcord;
			string ycord;
			for (int row = 0; row < 11; row++) { // Prints out the game board
				for (int col = 0; col < 11; col++) {
					cout << playerboard[row][col];
				}
				cout << endl;
			}

			cout << shots << " shots and " << targets << " targets left, which space do you fire at?" << endl << "X-cordinate: ";	// Prompts player for X cordinate value
			getline(cin, xcord);
			int vertcord = Validate(xcord);
			if (vertcord == 1 || vertcord == 2 || vertcord == 3 || vertcord == 4 || vertcord == 5 || vertcord == 6 || vertcord == 7 || vertcord == 8 || vertcord == 9 || vertcord == 10) {  // Keeps asking until valid input given
				cout << "Y-cordinate: ";	// Prompts player for Y cordinate value
				getline(cin, ycord);
				int horzcord = Validate(ycord);
				if (horzcord == 1 || horzcord == 2 || horzcord == 3 || horzcord == 4 || horzcord == 5 || horzcord == 6 || horzcord == 7 || horzcord == 8 || horzcord == 9 || horzcord == 10) {	 // Keeps asking until valid input given
					shots--;
					if (Shoot(playerboard, horzcord, vertcord, target1.x, target1.y, target2.x, target2.y, target3.x, target3.y, target4.x, target4.y, target5.x, target5.y, target6.x, target6.y, target7.x, target7.y, target8.x, target8.y, target9.x, target9.y, target10.x, target10.y, target11.x, target11.y, target12.x, target12.y, target13.x, target13.y, target14.x, target14.y, target15.x, target15.y, target16.x, target16.y, target17.x, target17.y) == 2) {	   // Occurs if player fires at the same spot more than once
						cout << "You already tried that spot, conserve ammo and try somewhere else!" << endl << endl;
						shots++;
					}
					else if (Shoot(playerboard, horzcord, vertcord, target1.x, target1.y, target2.x, target2.y, target3.x, target3.y, target4.x, target4.y, target5.x, target5.y, target6.x, target6.y, target7.x, target7.y, target8.x, target8.y, target9.x, target9.y, target10.x, target10.y, target11.x, target11.y, target12.x, target12.y, target13.x, target13.y, target14.x, target14.y, target15.x, target15.y, target16.x, target16.y, target17.x, target17.y) == 1) {	  // Occurs if player hits a target
						targets--;

						cout << "HIT!" << endl << endl;
					}
					else {	// Occurs if player misses
						cout << "MISS!" << endl << endl;
					}
					
				}
			}

		}

		// After game ends
		if (targets > 0) {	// Loss message
			cout << "You weren't able to eleminate all enemies in time!" << endl << "You lose!";
		}
		else {	// Win message
			cout << "You have stopped Cthulhu's forces and kept you and your team safe!" << endl << "You win!";
		}
}

int Validate(string cordinate) {	// Function that checks if user input is valid
	if (!cordinate.empty()) {	// .empty() reads the string and returns true if nothing is found
		if (!isdigit(cordinate[0])) {	// checks if input is a number
			cout << "Input numbers only!" << endl << endl;
		}
		else {
			int valid = stod(cordinate);	// converts cordinate from string to integer
			return valid;
		}
	}
}

int Shoot(string array[11][11], int x, int y, int target1x, int target1y, int target2x, int target2y, int target3x, int target3y, int target4x, int target4y, int target5x, int target5y, int target6x, int target6y, int target7x, int target7y, int target8x, int target8y, int target9x, int target9y, int target10x, int target10y, int target11x, int target11y, int target12x, int target12y, int target13x, int target13y, int target14x, int target14y, int target15x, int target15y, int target16x, int target16y, int target17x, int target17y) {	// Function for checking if the player chooses a cordinate pair more than once, hits, misses
	if (array[x][y] == "O  " || array[x][y] == "X  ") {	// Occurs if the cordinates have been chosen already 
		return 2;
	}
	else if ((x == target1x && y == target1y) || (x == target2x && y == target2y) || (x == target3x && y == target3y) || (x == target4x && y == target4y) || (x == target5x && y == target5y) || (x == target6x && y == target6y) || (x == target7x && y == target7y) || (x == target8x && y == target8y) || (x == target9x && y == target9y) || (x == target10x && y == target10y) || (x == target11x && y == target11y) || (x == target12x && y == target12y) || (x == target13x && y == target13y) || (x == target14x && y == target14y) || (x == target15x && y == target15y) || (x == target16x && y == target16y) || (x == target17x && y == target17y)) {	 // Occurs if the player got a hit
		array[x][y] = {"X  "};
		return 1;
	}
	else {
		array[x][y] = { "O  " };	// Occurs if player misses
		return 0;
	}
	
}