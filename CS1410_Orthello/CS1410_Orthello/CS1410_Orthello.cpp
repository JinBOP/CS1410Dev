#include <iostream>
using namespace std;

const char black = char(1);	// black smiley face Windows character
const char white = char(2);	// white smiley face Windows character
const char blank = char(32);
char board[8][8]{};	// 8x8 game board

void ResetBoard();	// board reset function prototype
void PrintBoard();	// board formatting function prototype

int main()
{
	ResetBoard();
	PrintBoard();
}

void ResetBoard() {	// function that sets up the game board at the beginning of a new game
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			board[row][col] = blank;
		}
	}
	// places initial 4 pieces, 2 black and 2 white, in the center of the game board
	board[3][3] = white;
	board[3][4] = black;
	board[4][3] = black;
	board[4][4] = white;
}

void PrintBoard() {	// function that displays a formatted version of the game board to the player
	system("cls");	// Windows command

	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (row == 0 && col == 0) {	// leaves the upper-left corner empty
				cout << "  ";
			}
			else if (row == 0) {	// adds top row letter labels
				cout << " " << char(col + 96) << " ";
			}
			else {
				if (col == 0) {	// adds left column number labels
					cout << row << " ";
				}
				else {	// adds styling for grid square
					cout << "[" << board[row - 1][col - 1] << "]";
				}
			}
		}
		cout << endl;
	}
}