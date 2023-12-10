#pragma once
#include <iostream>
#include "Teacher.h"
using namespace std;

class Class{
private:
	string classname;
	int classid;
	int availableseats;
	string teachername;	// filler
public:
	// constructor
	Class(string classname, int classid, int availableseats, string teachername) : classname(classname), classid(classid), availableseats(availableseats), teachername(teachername) {}
	bool FindEmptySeats(int classid, int availableseats, int studentid) {	// iterates through all students in a given class to see if there are any seats available
		cout << classid << " " << availableseats << " " << studentid << " FindEmptySeats is functional" << endl;
		return true;
	}
};

