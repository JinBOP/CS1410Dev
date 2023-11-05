#include <iostream>
using namespace std;

class Vial {
private:
	// Data Members
	char contents;	// used to house the "contents" of the vial
	int filled;	// used to track how much of the vial is "filled" with contents
	int label;	// used for the player's reference

public:
	// Constructor
	Vial(char content[], int size, int filled) {
		char contents[] = { 'a','b','c','d' };
		Vial vial = Vial(contents, 4, 4);
	};

	// Member Functions
	bool Add(char content[]) {	// used to add a new character to the contents Array
		if (content[0] == ' ') {
			content[0] = this->contents;
			return true;
		}
		else if (content[1] == ' ') {
			content[1] = this->contents;
			return true;
		}
		else if (content[2] == ' ') {
			content[2] = this->contents;
			return true;
		}
		else if (content[3] == ' ') {
			content[3] = this->contents;
			return true;
		}
		else {
			return true;
		}
	}
	void Display() {	// used to display the contents Array
		for (int i = 0; i < 7; i++) {
			cout << label << " [";
			for (int j = 0; j < 4; j++) {
				cout << contents[&j];
			}
			cout << "]";
		}
	}
	bool IsComplete() {	// used to test if a vial has been correctly sorted by the player 
		int i = 0;
		if ((this->contents[&i] == this->contents[&i + 1]) && (this->contents[&i] == this->contents[&i + 2]) && (this->contents[&i] == this->contents[&i + 3])) {
			return true;
		}
		else {
			return false;
		}
	
	}
	int SetLabel(int alabel) {	// setter function used to set the label of each Vial instance
		label = alabel;
	}
	bool Transfer(Vial& destination) {	// used to move some of the contents from one vial to another
		if (this->contents == ' ') {
			return false;
		}
		else if (this->contents != ' ') {
			return false;
		}
		else if (this->contents - 1 == this->contents + 1) {
			return false;
		}
		else {

			return true;
		}
	}
};

int main()
{
	Vial vial1();
	Vial vial2();
	Vial vial3();
	Vial vial4();
	Vial vial5();
	Vial vial6();
	void Display();

}


