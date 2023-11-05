#include <iostream>
using namespace std;

void input(string);
string response;
bool repeat = true; // determines of loop continues

int main()
{
	while (repeat == true) { // continues to ask until valid input given
		cout << "Go to the forest or the beach: ";
		cin >> response;
		input(response);
	}
}

void input(string choice) { // checks if valid input
	if (choice == "forest"){
		cout << "You go to the forest";
		repeat = false;
	}
	else if (choice == "beach") {
		cout << "You go to the beach";
		repeat = false;
	}
	else {
		cout << "Not valid input" << endl;
	}
}
