#pragma once
#include "Resident.h"
#include "District.h"
using namespace std;

class Student : public Resident{
private:
	Resident homeaddress;
protected:
	int studentid;
	bool InClass(string classname, int classid, int studentid) {
		// checks if student is in a class given the class info and studentid
	}
public:
	string StudentName(Resident firstname, Resident middlename, Resident lastname) {
		// returns student full name passed down from resident class
	}
	// constructors
	Student(string StudentName, int studentid) : StudentName(StudentName), studentid(studentid) {}
	Student(string StudentName, int studentid, District districtname) : StudentName(StudentName), studentid(studentid), districtname(districtname) {}
};

