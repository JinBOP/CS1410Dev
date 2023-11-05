#include <iostream>
using namespace std;

int findmax(int, int);

double findmax(double, double);

string input(string, string, string);
string input(string, string, string, string);

void decoborder(int = 75, char = '-'); // Contains Default Argument 

// Inline Function: quick and dirty way to replace function calls in a project
int findmin(int x, int y) { return (x < y) ? x : y; };

void song(int n = 99);

long factorial(int);

double sine(int x, int n = 0);

string greaterword(string, string, int = 0);

int main()
{
	/* Overloaded Function: two or more functions with the same name
	* each must have different number of parameters or different types of paramerters
	*/
	int n = findmax(7, 2);
	double r = findmax(7.9, 2.3);
	cout << n << endl;
	cout << r << endl;

	input("Go to work or stay home?", "work", "home");

	/* Default arguments: 
	* if required + default, then default always to the right
	* if some but not others, then can only skip to the right
	* if defaults specified in the prototype, 
	* if overloaded functions with defaults, then they can't be ambiguous
	*/
	decoborder();
	decoborder(45);
	
	/*Recursion: when a function calls itself
	* Must have:
	* function calls itself path
	* argument that changes
	* Base Case where no recursion happens
	*/
	song(5);

	cout << factorial(5);

	cout << sin(1) << endl;
	cout << sine(1) << endl;

	// apples > bananas
	string compareword = greaterword("apple", "banana");
	cout << compareword << endl;
	/* string compareword = greaterword("apple", "aardvark");
	cout << compareword << endl;
	string compareword = greaterword("apple", "applean");
	cout << compareword << endl;
	string compareword = greaterword("apple", "APPLE");
	cout << compareword << endl;
	*/
}

int findmax(int a, int b) {
	return (a > b) ? a : b;

	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

double findmax(double a, double b) {
	return (a > b) ? a : b;
}

string input(string message, string option1, string option2) {
	cout << message  << option1  << "," << option2 << endl;
	return "bruh";
}

string input(string message, string option1, string option2, string option3) {
	cout << message << option1 << "," << option2 << option3 << endl;
	return "dude";
}

void decoborder(int length, char character) {
	for (int i = 0; i < length; i++) {
		cout << character;
	}
	cout << endl;
}

void song(int n) {
	cout << n << " cans of soda on the wall..." << endl;
	if (n > 1) {
		song(n - 1);
	}
	else {
		cout << "...no more cans of soda on the wall" << endl;
	}
}

long factorial(int n) {
	if (n >= 1) {
		return n * factorial(n - 1);
	}
	else {
		return 1;
	}
}

double sine(int x, int n) {
	if (n < 10) {
		return sine(x, n + 1) + pow((-1), n) * ((pow(x, 2 * n + 1) / factorial(2 * n + 1)));
	}
	return 0;
}

string greaterword(string a, string b, int index) {
	if (index < a.size() && index < b.size()) { // Ensures within range
		// word 'a' letter is greater
		if (tolower(a.at(index)) > tolower(b.at(index))) {
			return a;
		}
		// word 'a' letter is lesser
		else if (tolower(a.at(index)) < tolower(b.at(index))) {
			return b;
		}
		// letters are the same
		else {
			return greaterword(a, b, index + 1);
		}
	}
	else if (a.size() != b.size()) {
		return a.size() > b.size() ? a : b;
	}
	else {
		return a;
	}
}