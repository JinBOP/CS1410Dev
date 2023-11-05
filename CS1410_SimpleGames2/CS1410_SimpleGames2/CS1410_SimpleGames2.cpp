#include <iostream>
using namespace std;

int main()
{
	cout << "Let's play Rock, Paper, Scissors, Lizard, Spock!" << endl;

	int play = 1;
	int player;

	do {
		cout << "Which will you choose?" << endl << "(1) Rock, (2) Paper, (3) Scissors, (4) Spock, (5) Lizard ";
		cin >> player;
		int computer = rand() % 5;
		
		switch (player) { // Displays Player's choice
		case 1:
			cout << "You chose Rock" << endl;
			break;
		case 2:
			cout << "You chose Paper" << endl;
			break;
		case 3:
			cout << "You chose Scissors" << endl;
			break;
		case 4:
			cout << "You chose Spock" << endl;
			break;
		case 5:
			cout << "You chose Lizard" << endl;
			break;
		}

		switch (computer) { // Displays Computer's choice
		case 1:
			cout << "Computer chose Rock" << endl;
			break;
		case 2:
			cout << "Computer chose Paper" << endl;
			break;
		case 3:
			cout << "Computer chose Scissors" << endl;
			break;
		case 4:
			cout << "Computer chose Spock" << endl;
			break;
		case 5:
			cout << "Computer chose Lizard" << endl;
			break;
		}

		if  ((player == 1 && computer == 2) || (player == 1 && computer == 4) || (player == 2 && computer == 3) || (player == 2 && computer == 5) || (player == 3 && computer == 4) || (player == 3 && computer == 1) || (player == 4 && computer == 5) || (player == 4 && computer == 2) || (player == 5 && computer == 3) || (player == 5 && computer == 1)) { // All possible lose conditions
			cout << "You lost!" << endl << endl;
		}
		else if ((computer == 1 && player == 2) || (computer == 1 && player == 4) || (computer == 2 && player == 3) || (computer == 2 && player == 5) || (computer == 3 && player == 4) || (computer == 3 && player == 1) || (computer == 4 && player == 5) || (computer == 4 && player == 2) || (computer == 5 && player == 3) || (computer == 5 && player == 1)) { // All possible win conditions
			cout << "You won!" << endl << endl;
		}
		else {
			cout << "Its a tie!" << endl << endl;
		}

		cout << "Play again? (1 - Yes, 2 - No) " << endl; // Asks if player would like to play again
		cin >> play;
	} while (play == 1);
}