#include <iostream>
#include <string> // for casting integer as string
using namespace std;

string hexvalue1(int);
string hexvalue2(int);

bool loop = true; // keeps code going so it can be used more than once
int red, green, blue;

int main()
{
	while (loop == true) { // Allows endless numbers to be converted
		cout << "Enter an RGB color value (r): "; // prompts user for Red color value
		cin >> red;
		cout << "Enter an RGB color value (g): "; // prompts user for Green color value
		cin >> green;
		cout << "Enter an RGB color value (b): "; // prompts user for Blue color value
		cin >> blue;
		cout << "Hexadecimal equivalent is: #" << hexvalue1(red) << hexvalue2(red) << hexvalue1(green) << hexvalue2(green) << hexvalue1(blue) << hexvalue2(blue) << endl; // Displays final result
	}
}

string hexvalue1(int color) { // Calculates Hex equivalent for first digit
	int digit1 = (color/16);
	
	switch (digit1) {
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
		return to_string(digit1);
	}
}

string hexvalue2(int color) { // Calculates Hex equivalent for second digit
	int digit2 = (color % 16);

	switch (digit2) {
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
		return to_string(digit2);
	}
}