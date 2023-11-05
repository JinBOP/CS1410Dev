#include <iostream>
#include <string>
using namespace std;

string dectohexdigit(int n);

void addfiveto(int a);
int addfivetoreturn(int a);
void addfiveref(int &a);
void makenewpart();

int a = 12;	// Global Variable
/* Why to avoid global variables: 
* functions can't be tested in isolation 
* functions can mess with other functions that use the same variables
* coupled functions can increase complexity
* 
* Why to use global variables:
* prevents the need to do a lot of argument passing
* when using some sort of constant accross the whole project
* 
*/
int main()
{
	cout << dectohexdigit(10) << endl;

	int a = 32;	// Local Variable
	addfiveref(a);
	cout << "a in main " << a << endl;

	makenewpart();
}
// you can have more than one return but only the first will occur
string dectohexdigit(int n) {
	if (n >= 0 && n < 16) {
		switch (n) {
		case 15:
			return "F";
		case 14:
			return "E";
		case 13:
			return "D";
		case 12:
			return "C";
		case 11:
			return "B";
		case 10:
			return "A";
		default:
			return to_string(n);
		} // No need for breaks because the funct only returns once
	}
	else {
		return "Not valid input";
	}
}

// Variable scope
/* Pass-By-Value: copy of the data
* 
* Advantages: 
* no concern about accidentally modifying original data
* can pass expressions
*
* Disadvantages:
* cannot modify original data directly
* can be costly to time and memory
*/
void addfiveto(int a) { 
	a += 5;
	cout << "a in function" << a << endl;
}

int addfivetoreturn(int a) { // Pass-By-Value, return updates
	a += 5;
	cout << "a in function" << a << endl;
	return a;
}

/* Pass-By-Reference (reference to memory address of the data)
* 
* Advantages:
* efficient for large amounts of data
* more efficient
* 
* Disadvantages:
* only works with variables, not with expressions
* might mess up original data
*/
void addfiveref(int &a) {
	a += 5;
	cout << "a in function" << a << endl;
}

/* Pass-By-Pointer (C++)
* Pointer: variables where the value is an address
*/

void makenewpart() {
	static int part = 0;	// Static Variable
	cout << "Generating part #" << ++part << endl;
}