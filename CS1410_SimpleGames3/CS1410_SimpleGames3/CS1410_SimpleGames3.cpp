#include <iostream>
#include <algorithm> // Needed for sort
using namespace std;

int main()
{
	srand(time(0)); // Rolls 5 dice at random
	int dice[5]{};
	for (int i = 0; i < 5; i++)
		dice[i] = rand() % 6 + 1;

	sort(dice, dice + 5); // Sorts the dice lowest to highest

	for (int i = 0; i < 5; i++) // Displays the dice in the console
		cout << "[" << dice[i] << "]";

	int d1 = dice[0], d2 = dice[1], d3 = dice[2], d4 = dice[3], d5 = dice[4];	// Stores the dice in integer variables

	if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5) { // Requirements for a Yahtzee
		cout << "Yahtzee: 50 points!" << endl;
	}
	else if (d1 == d2 - 1 && d2 == d3 - 1 && d3 == d4 - 1 && d4 == d5 - 1) { // Requirements for a Large Straight
		cout << "Large Straight: 40 points" << endl;
	}
	else if ((d1 == d2 - 1 && d2 == d3 - 1 && d3 == d4 - 1) || d2 == d3 - 1 && d3 == d4 - 1 && d4 == d5 - 1) { // Requirements for a Small Straight
		cout << "Small Straight: 30 points" << endl;
	}
	else if ((d1 == d2 && d3 == d4 && d4 == d5) || (d1 == d2 && d2 == d3 && d4 == d5)) { // Requirements for a Full House
		cout << "Full House: 25 points" << endl;
	}
	else if ((d1 == d2 && d2 == d3 && d3 == d4) || (d2 == d3 && d3 == d4 && d4 == d5)) { // Requirements for a 4 of a kind
		cout << "4 of a kind: " << d1 + d2 + d3 + d4 + d5 << " points" << endl;
	}
	else if ((d1 == d2 && d2 == d3) || (d2 == d3 && d3 == d4) || (d3 == d4 && d4 == d5)) { // Requirements for a 3 of a kind
		cout << "3 of a kind: " << d1 + d2 + d3 + d4 + d5 << " points" << endl;
	}
	else { // Requirements for a Chance
		cout << "Chance: " << d1 + d2 + d3 + d4 + d5 << " points" << endl;
	}
}