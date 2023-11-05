#include <iostream>
using namespace std;

int main()
{
	// Sequentially means 1 then 2 then 3

	// Control Structures
	// Relational Expressions evaluate True or False
	// Relational Operators (> < >= <= == != bool)

	int student = 16;
	bool section = student > 20;

	int missing = 4;
	bool pass = missing <= 3;
	
	cout << section << endl;

	// if statement (all-or-nothing)
	char play;
	cout << "Do you want to play a game? (y/n) ";
	cin >> play;

	if (play == 'y')
	{
		cout << "Lets play!" << endl;
		cout << "You will pick a cup." << endl;


		// if-else (one or the other)
		cout << "I will hide a seed under one of the cups" << endl;

		srand(time(0));
		int cup = rand() % 3 + 1;

		int choice;
		cout << "Which cup will you choose? (1-3): ";
		cin >> choice;

		if (choice == cup)
			cout << "Correct!";
		else
			cout << "Wrong, it was in cup " << cup << endl;
	}

	// if-else if (shades of grey)
	srand(time(0));
	int player = rand() % 13 + 2;
	int computer = rand() % 13 + 2;

	cout << "Your card: " << player << endl;
	cout << "My card: " << computer << endl;

	if (player > computer)
		cout << "You Win!" << endl;
	else if (computer > player)
		cout << "You Lose!" << endl;
	else
		cout << "War!" << endl;

	// Logical Operators (And &&, Or ||, Not !)

	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;

	cout << "[" << dice1 << "]" << "[" << dice2 << "]" << endl;

	// NOT operator (!)
	// want to check for anything except for 7
	if (!(dice1 + dice2 == 7))
		cout << "Keep rolling!" << endl;

	// And operator (&&) all must be true for whole to be true
	if (dice1 == 4 && dice2 == 4)
		cout << "Hard 8" << endl;

	// Or operator (||) at least one must be true for whole to be true
	// Win 7 or 11
	// Lose 2 or 3 or 12
	
	if (dice1 + dice2 == 7 || dice1 + dice2 == 11)
		cout << "You won!" << endl;
	else if (dice1 + dice2 == 2 || dice1 + dice2 == 3 || dice1 + dice2 == 12)
		cout << "You lost!" << endl;
	else
		cout << "Keep playing" << endl;

	// Short-Circuit Evaluation (compiler is lazy) means if an expression within an if statement is true the rest will be ignored

	// Nested if statements and Scope
	srand(time(0));

	int guess;
	cout << "Into which cup will the ball fall into? (1,2,3,4) "; // Iron Sword: Skull and Cup
	cin >> guess;

	int roll1 = rand() % 2; // Between 0 and 1
	int roll2;

	if (roll1 == 0) {
		cout << "Ball rolls left" << endl;
		int roll2 = rand() % 2 + 1; // Between 1 and 2
		if (roll2 == 1) {
			cout << "Ball rolls left and falls into cup 1" << endl;
		}
		else {
			cout << "Ball rolls right and falls into cup 2" << endl;
		}
	}
	else {
		cout << "Ball rolls right" << endl;
		int roll2 = rand() % 2 + 2;
		if (roll2 == 2) {
			cout << "Ball rolls left and lands in cup 3" << endl;
		}
		else {
			cout << "Ball rolls right and lands in cup 4" << endl;
		}
	}

	if (roll1 + roll2 == guess)
		cout << "You win!" << endl;
	else
		cout << "You lose!" << endl;

	// Switches (everything you can do with a switch can be done with an if statement)
	// uses a single variable for decisions

	int choice = rand() % 3; // between 0 and 2

	switch (choice) {
	case 0:
		cout << "Rock" << endl;
		break;
	case 1:
		cout << "Paper" << endl;
		break;
	case 2:
		cout << "Scissors" << endl;
		break;
	}

	cout << "There was an old lady who swallowed a..." << endl; // Old lady who swallowed a fly

	int start = 6;

	switch (start) {
	case 7:
		cout << "... horse. She died of course." << endl;
		break;
	case 6:
		cout << "...cow to catch the..." << endl;
	case 5:
		cout << "...goat to catch the..." << endl;
	case 4:
		cout << "...dog to catch the..." << endl;
	case 3:
		cout << "...cat to catch the..." << endl;
	case 2:
		cout << "...bird to catch the..." << endl;
	case 1:
		cout << "...spider to catch the..." << endl;
	case 0:
		cout << "...fly..." << endl;
	}
}
