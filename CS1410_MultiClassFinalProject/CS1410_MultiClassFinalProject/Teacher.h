#pragma once
#include <iostream>
#include "Class.h"
using namespace std;

class Teacher{
private:
	string teachername;
	string teachingclass;
	string schoolname;	// filler
protected:
	bool InClass(string classname, string classid, string teachername) {	// checks if teacher is in a class given class info and teacher name
		cout << classname << " " << classid << " " << teachername << " InClass is functinoal" << endl;
		return true;
	}
public:
	// constructor
	Teacher(string teachername, string schoolname, string teachingclass) : teachername(teachername), schoolname(schoolname), teachingclass(teachingclass) {}
};

