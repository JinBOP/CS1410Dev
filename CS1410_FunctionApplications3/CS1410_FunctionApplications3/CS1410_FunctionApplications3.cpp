#include <iostream>
using namespace std;

int stones, amount, player, computer;
int turn = 1;
bool start = true;
bool validmove(int, int);
void playerstones(int, int);
int comstones(int);

int main()
{	
	while (stones > 0 || start == true) {
		if (start == true) {
			stones = rand() % 14 + 7; // generates number of stones
			start = false;
		}
		while (turn == 1) {
			cout << "Current stones: " << stones << endl; // display number of stones in the pile
			cout << "How many stones will you take? (1-3): " << endl; // ask for user input
			cin >> player;
			validmove(player, stones);
		}
		playerstones(player, stones);
		stones = stones - player;
		comstones(stones);
		stones = stones - computer;
		cout << "Computer took " << computer << endl << endl;
	}
	if (turn == 0) { // determines the winner when all stones are gone
		cout << "You win!";
	}
	else {
		cout << "You lose!";
	}
}

bool validmove(int player, int stones) { // checks if user input is a valid option
	if (player < 1 || player > 3 || player > stones) {
		cout << "That is not a valid amount" << endl;
		return false;
	}
	else {
		turn = 0;
		return true;
	}
}

void playerstones(int player, int stones) { // handles player move
	turn = 1;
}

int comstones(int stones) { // handles computer move
	if (stones == 4) {
		computer = 3;
		return computer;
	}
	else if (stones == 3) {
		computer = 2;
		return computer;
	}
	else if (stones == 2) {
		computer = 1;
		return computer;
	}
	else if (stones == 1) {
		computer = 1;
		return computer;
	}
	else {
		computer = rand() % 3 + 1;
		return computer;
	}
}