#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Loops repeat a section of code
	// requiered for a loop:
	// init (variable)
	// condition
	// update

	// While repeats as many times as it needs and MAY NEVER RUN (used for when you or the program don't know how many times it will loop)
	int number = 1;
	while (number <= 10) {
		cout << "The number is " << number << endl;
		number++;
	}

	// Do While repeats as many times as it needs and WILL ALWAYS RUN AT LEAST ONCE (used for when you want a loop to run at least once but many times more if needed)
	number = 100;
	do {
		cout << "Number is " << number << endl;
		number++;
	} while (number <= 10);

	// For (used for when you or the program knows how many times to loop)
	for (int number = 1; number <= 10; number++) {
		cout << "Number " << number << endl;
	}
	
	int value;
	cout << "Enter a number: ";
	cin >> value;
	// loop used to find all the factors of the given number
	for (int i = 1; i <= value; i++) {
		if (value % i == 0) {
			cout << i << ", " << number / i << endl;
		}
	}
	// Nested Loops
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 12; j++) {
			cout << setw(5) << i * j;
		}
		cout << endl;
	}

	// For Range (used for iterations)
	string s = "Hello world";
	for (char c : s) {
		cout << c << ", ";
	}
	cout << endl;
	// Fence Post Problem (missing or having extra at the beginning or end of an iteration where there should or shouldn't be)
	string student[] = { "first","second","third","fourth","fifth" };
	for (string name : student) {
		cout << name << ","; // adds an extra comma at the end where we don't want
	}
	cout << endl;

	for (int i = 0; i < 4; i++) {
		cout << student[i] << ", ";
	}
	cout << student[4]; // displays the first four in a for loop, then displays the final on its own
	cout << endl;

	// Break is used to terminate a loop or switch prematurely
	for (int i = 0; i < 10; i++) {
		cout << i << ", ";
		if (i == 6) {
			break; // ends the loop
		}
	}
	cout << endl;

	// Continue is used to skip up to the next iteration of the loop
	for (int i = 0; i < 10; i++) {
		if (i == 6) {
			continue; // jumps back up to the beginning of the loop
		}
		cout << i << ", ";
	}
	cout << endl;

	// Null statements
	for (int i = 0; i < 10; i++); // This semicolon Nullifies the statement, cutting off the loop midway through
	{
		cout << i << endl;
	}

	// Tricky Scope
	cout << "You are standing at the cabin." << endl; // Cabin Senario

	char response;

	do {
		cout << "To the left is the Lake, to the right is the Mountain." << endl;

		cout << "\nWhich way? (L/M): ";
		cin >> response;

		if (toupper(response) == 'L') {
			cout << "You travel to the Lake..." << endl;
			cout << "After a while, you find yourself back at the Cabin." << endl;
		}
		else {
			cout << "You travel to the Mountain..." << endl;
		}
	} while (toupper(response) == 'L');
	
}