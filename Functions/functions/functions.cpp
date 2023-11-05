#include <iostream>
using namespace std;

int randint(int low, int high);	// Prototype (function declaration)

void showrandomdicepair();

void shownrandomdicepair(int n);

void showexactdicepair(int d1, int d2);

int getrandomdicepair();

int getnrandomdice(int n);

int main()
{
	// Function: reusable piece of code
	// a function is a "machine" that can have variety of inputs (or no inputs at all)
	// does some work behind the scenes
	// provides some sort of output

	// Example 1: Random number generator
	srand(time(0));
	cout << randint(13, 19) << endl;	// Function Call
	showrandomdicepair();
	shownrandomdicepair(7);
	showexactdicepair(6, 6);
	int total = getrandomdicepair();
	cout << "Total:" << total << endl;
	int sum = getnrandomdice(10);
	cout << "Total:" << sum << endl;
}

// a function can not be inside another function
// Bottom-Up Programming: getting the smaller pieces to work before the larger project
// Top-Down Programming: focusing on the larger project and using filler to get it to work before finishing smaller pieces

int randint(int low, int high) {	// Function Definition
	int random = rand() % (high - low + 1) + low;
	return random;
}

// int					- return type
// randint				- identifier (name of the function)
// int low, int high	- parameters (data necessary to use the function)
// { }					- function body (where the work goes)
// return random		- return statement (the one piece of data given back to the call)
// (13, 19)				- arguments (the data plugged in to the function)

// Procedure: a function that does not return a value

void showrandomdicepair() { // No parameters, No return
	int d1 = randint(1, 6);
	int d2 = randint(1, 6);
	cout << "[" << d1 << "][" << d2 << "]" << endl;
}

void shownrandomdicepair(int n) { // One parameter, No return
	for (int i = 0; i < n; i++) {
		int d = randint(1, 6);
		cout << "[" << d << "]";
	}
	cout << endl;
}

void showexactdicepair(int d1, int d2) { // Two parameters, No return
	cout << "[" << d1 << "][" << d2 << "]" << endl;
}

int getrandomdicepair() { // No parameters, One return
	int d1 = randint(1, 6);
	int d2 = randint(1, 6);
	cout << "[" << d1 << "][" << d2 << "]" << endl;
	return d1 + d2;
}

int getnrandomdice(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int d = randint(1, 6);
		cout << "[" << d << "]";
		sum += d;
	}
	cout << endl;
	return sum;
}