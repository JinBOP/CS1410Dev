#pragma once
#include "Person.h"
using namespace std;

class Resident /* : public Person */{
private:
	// inherited variables from Person class
	string homeaddress;
	string firstname;
	string middlename;
	string lastname;
public:
	// constructors
	Resident(string firstname, string middlename, string lastname) : firstname(firstname), middlename(middlename), lastname(lastname) {}
	Resident(string firstname, string middlename, string lastname, string homeaddress) : firstname(firstname), middlename(middlename), lastname(lastname), homeaddress(homeaddress) {}
	void Home(string firstname, string middlename, string lastname) {	// function to find an individual's home address according to their name
		cout << firstname << middlename << lastname << "Home is functional" << endl;
	}
};

