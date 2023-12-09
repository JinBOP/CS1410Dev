#pragma once
#include <iostream>
#include "Class.h"
using namespace std;
class Teacher{
private:
	string teachername;
	string teachingclass;
protected:
	bool InClass(Class classname, Class classid, string teachername) {
		// checks if teacher is in a class given class info and teacher name
	}
public:
	// constructor
	Teacher(string teachername, School schoolname, string teachingclass) : teachername(teachername), schoolname(schoolname), teachingclass(teachingclass) {}
};

