#include <iostream>
using namespace std;

const char black = char(1);	// black smiley face Windows character
const char white = char(2);	// white smiley face Windows character
const char blank = char(32);
char board[8][8]{};	// 8x8 game board

void ResetBoard();	// board reset function prototype
void PrintBoard();	// board formatting function prototype
int CountFlips(char, int, int, int, int);	
int CountFlips(char, int, int);
void FlipPieces(char, int, int);	// piece flipping function prototype
int main()
{
	ResetBoard();
	PrintBoard();
	cout << CountFlips(black, 2, 3) << endl;
	cout << CountFlips(white, 4, 2) << endl;

	char col;
	int row;
	int valid = 0;

	do {	// allows for player input for them to make a move
		cout << "\nYour Move: ";
		cin >> col >> row;

		if (cin.fail()) {
			cin.clear();
		}

		col = int(col - 97);
		row = row - 1;

		valid = CountFlips(black, row, col);
		if (!valid) {
			cout << "Invalid move!";
		}
	} while (!valid);

	FlipPieces(black, row, col);
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

int CountFlips(char piece, int row, int col, int y, int x) {
	if (board[row][col] != blank) { // handles invalid move where space is already taken
		return 0;
	}
	else {
		int tally = 0;
		row += y;
		col += x;

		while (row >= 0 && row < 8 && col >= 0 && col < 8) {
			if (board[row][col] == blank) {	// handles blank space next to placed piece
				return 0;
			}
			else if (board[row][col] != piece) {	// uptics the tally when opposite piece is found
				tally++;
			}
			else {	// returns total tally when same colored piece found
				return tally;
			}
			row += y;
			col += x;
		}
		// returns 0 when reaching edge of game board
		return 0;
	}
}

int CountFlips(char piece, int row, int col) {	// tally tracker
	int tally = 0;

	for (int y = -1; y <= 1; y++) {
		for (int x = -1; x <= 1; x++) {
			tally += CountFlips(piece, row, col, y, x);
		}
	}
	return tally;
}

void FlipPieces(char piece, int row, int col) {
	for (int y = -1; y <= 1; y++) {
		for (int x = -1; x <= 1; x++) {
			if (CountFlips(piece, row, col, y, x)) {
				int currentrow = row;
				int currentcol = col;

				currentrow += y;
				currentcol += x;

				while (board[currentrow][currentcol] != piece) {
					board[currentrow][currentcol] = piece;
					currentrow += y;
					currentcol += x;
				}
			}
		}
	}
	// adds current piece
	board[row][col] = piece;
}