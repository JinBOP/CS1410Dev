#pragma once
#include <iostream>
#include "Resident.h"
//#include "District.h"
using namespace std;

class Student /* : public Resident */ {
private:
	string homeaddress;
	// filler
	string firstname;
	string middlename;
	string lastname;
protected:
	int studentid;
	bool InClass(string classname, int classid, int studentid) {	// checks if student is in a class given the class info and studentid
		cout << classname << classid << studentid << "InClass is functional" << endl;
		return true;
	}
public:
	// constructors
	Student(string firstname, string middlename, string lastname, int studentid) : firstname(firstname), middlename(middlename), lastname(lastname) {}
	
	string StudentName(string firstname, string middlename, string lastname) {	// returns student full name passed down from resident class
		string fullname = firstname + " " + middlename + " " + lastname;
		return fullname;
	}
};

