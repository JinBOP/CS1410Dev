#include <iostream>
#include "Person.h"
#include "Resident.h"
#include "Student.h"
#include "Teacher.h"
#include "Class.h"
#include "District.h"
#include "School.h"
using namespace std;

int main()
{
	Person person("John", "Fitzgerald", "Kennedy", "Texas");
	person.Profile();

	Resident resident("Martin", "Luther", "King", "Tennessee");
	resident.Home("Martin", "Luther", "King");
	
	Student student("Howard", "Phillips","Lovecraft", 03512);
	//student.InClass("Ocean Studies", 20000, 03512);

	Teacher teacher("Professor Einstein", "School of schooling", "Relativity 101");
	//teacher.Inclass("Relativity 101", 31415, classestaught);
	
	//Class class("Relativity 101", 31415, 28, "Professor Einstein");
	//class.FindEmptySeats(31415, 28, 03512);

	School school("Pigblemishes", "Europe");
	school.CalculateSchoolCapacity("Pigblemishes", 666, 057);

	District district("magic school bus district");
	district.GetSchoolsInDistrict("magic school bus district", "community college");

}

