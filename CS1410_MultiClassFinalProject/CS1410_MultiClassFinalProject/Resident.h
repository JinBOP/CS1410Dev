#pragma once
#include "Person.h"
class Resident : public Person{
private:
	// inherited variables from Person class
	Person homeaddress;
	Person firstname;
	Person middlename;
	Person lastname;
public:
	Resident(string firstname, string middlename, string lastname) : Person(firstname), Person(middlename), Person(lastname) {}
	Resident(string firstname, string middlename, string lastname, string homeaddress) : Person(firstname), Person(middlename), Person(lastname), Person(homeaddress) {}
	string Home(string firstname, string middlename, string lastname) {	// function to find an individual's home address according to their name
		cout << firstname << " " << lastname << "'s home address is " << homeaddress << endl;
	}
};

