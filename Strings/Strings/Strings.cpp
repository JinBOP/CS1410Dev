#include <iostream>
#include <string>
using namespace std;

int main()
{
	/* Aggregate data
	* Enumerations (Integer Constants)
	* Structures
	*
	* String: any sequence of characters
	* Constructor(s): how you create an instance of an Object
	* 
	*/

	string s1;				// Default Constructor
	string s2("Hello");		// Conversion Constructor
	string s3(s2);			// Copy Constructor
	string s4 = "Yo!";	// Initialization

	cout << s2.size() << endl;		// Shows how many characters the string contains
	cout << s2.capacity() << endl;	// Shows how large the string is

	/* String Operators
	* =		Assignment
	* <, >	Relational
	* ==	Equality
	* !=	Not Equal
	* +		Concatenation (joining 2 or more strings)
	*/
	cout << s2 + " World" << endl;

	// String Input
	/*string name;
	cout << "Type in your full name: " << endl;
	cin >> name; 
	cout << "Welcome, " + name << endl;
	// This method only takes the first string typed in, not the entire name
	*/

	string name;
	cout << "Type in your full name: " << endl;
	getline(cin, name); // ignores new line feed
	cout << "Welcome, " + name << endl;

	// find a substring
	size_t index = name.find("Jin");
	if (index != string::npos) {
		cout << "Jin found at " << index << endl;
	}
	else {
		cout << "Jin not found" << endl;
	}

	// String iteration
	/* .at()
	* []
	* range
	*/
	for (size_t i = 0; i < name.length(); i++) {
		cout << name[i] << "-";
	}
	for (size_t i = 0; i < name.length(); i++) {
		cout << name.at(i) << "_";
	}

	// to_string
	int number = 75;
	cout << "Your number: " + to_string(number) << endl;

	// number conversions
	string number1 = "139";
	double result1 = stoi(number1) / 2;
	cout << result1;
	double result2 = stod(number1) / 2;
	cout << result2;

}

