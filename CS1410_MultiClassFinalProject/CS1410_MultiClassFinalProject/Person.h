#pragma once
#include <iostream>
using namespace std;

class Person{
private:
	string homeaddress;	// stores the home address of the individual
	string firstname;	// stores the first name of the individual
	string middlename;	// stores the middle name of the individual
	string lastname;	// stores the last name of the individual
public:
	Person(string firstname, string middlename, string lastname) : firstname(firstname), middlename(middlename), lastname(lastname) {}
	Person(string firstname, string middlename, string lastname, string homeaddress) : firstname(firstname), middlename(middlename), lastname(lastname), homeaddress(homeaddress) {}
	void Profile() {	// displays all info known about the individual
		cout << "Name: " << firstname << " " << middlename << " " << lastname << endl;
		cout << "Address: " << homeaddress;
	};
};

