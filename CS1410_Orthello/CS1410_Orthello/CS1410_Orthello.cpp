#include <iostream>
using namespace std;

const char black = char(1);	// black smiley face Windows character
const char white = char(2);	// white smiley face Windows character
const char blank = char(32);
char board[8][8]{};	// 8x8 game board

void ResetBoard();	// board reset function prototype

int main()
{
	ResetBoard();

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