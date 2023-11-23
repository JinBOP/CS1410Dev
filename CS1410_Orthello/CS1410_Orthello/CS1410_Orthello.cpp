#include <iostream>
using namespace std;

const char black = char(1);	// black smiley face Windows character
const char white = char(2);	// white smiley face Windows character
const char blank = char(32);
char board[8][8]{};	// 8x8 game board

struct GridSquare {	// computer move structure
	int row = -1;
	int col = -1;
};

void ResetBoard();	// board reset function prototype
void PrintBoard();	// board formatting function prototype
int CountFlips(char, int, int, int, int);	
int CountFlips(char, int, int);
void FlipPieces(char, int, int);	// piece flipping function prototype
GridSquare BestMove(char);
int main()
{
	ResetBoard();
	bool computeravailable, playeravailable;

	do {
		computeravailable = true, playeravailable = true;
		PrintBoard();

		char col;
		int row;
		int valid = (BestMove(black).row >= 0);

		if (valid) {
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
		else {	// skips turn when no valid moves available
			cout << "\nNo valid moves available for player" << endl;
			playeravailable = false;
		}
		
		GridSquare ComputerMove = BestMove(white);
		if (ComputerMove.row >= 0) {	// computer makes a move if valid move is available
			cout << "\nComputer Move: ";
			cout << char(ComputerMove.col + 97) << ComputerMove.row + 1 << endl;
			FlipPieces(white, ComputerMove.row, ComputerMove.col);
		}
		else {	// skips turn when no valid moves available 
			cout << "\nNo valid moves available for computer" << endl;
			computeravailable = false;
		}

		system("pause");	// Windows command
	} while (playeravailable || computeravailable);
}

void ResetBoard() {	// clears and builds board for new game
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			board[row][col] = blank;
		}
	}
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

void FlipPieces(char piece, int row, int col) {	// piece interaction function
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

GridSquare BestMove(char piece) {	// structure funciton for computer to decide best move available
	GridSquare best;
	int mostflipped = 0;

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			int currentflips = CountFlips(piece, row, col);

			if (currentflips > mostflipped) {
				mostflipped = currentflips;
				best.row = row;
				best.col = col;
			}
		}
	}
	return best;
}