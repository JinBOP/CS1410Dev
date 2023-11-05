#include <iostream>
using namespace std;

int main()
{
	int num, guess; // Initializes variables
	num = rand() % 100 + 1; // Generates number within range 1-100
	cout << "I'm thinking of a number between 1 and 100." << endl;
	guess = 0;
	cout << "The number is: " << num << endl; // Generated number displayed for testing and debugging

	while (guess != num) { // Loop continues until correct number is guessed
		cout << "What is your guess? ";
		cin >> guess;

		if (guess > num) {
			cout << "That guess is too high." << endl;
		}
		else if (guess < num) {
			cout << "That guess is too low." << endl;
		}
	}
	cout << "You got it!" << endl;
	cout << "Thanks for playing!";

}