#pragma once
#include <iostream>
using namespace std;

class School{
private:
	string schoolname;
	string districtname; //filler
public:
	// constructor
	School(string schoolname, string districtname) : schoolname(schoolname), districtname(districtname) {}
	int CalculateSchoolCapacity(string schoolname, int availableseats, int classid) { // determines how many students can enroll at a certain school according to the number of availble seats in all classes hosted there
		cout << schoolname << " " << availableseats << " " << classid << " CalculateSchoolCapacity is functional" << endl;
		return 0;
	}
};

