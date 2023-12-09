#pragma once
#include <iostream>
using namespace std;

class District{
private:
	string districtname;
public:
	// constructor
	District(string districtname) : districtname(districtname) {}
	string GetSchoolsInDistrict(string districtname, string schoolname) {	// iterates through all schools and sees which are in the specified district
		string schools = "school1 school2 school3";
		return schools;
	}
};

