#include <iostream>
using namespace std;

int main()
{
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
