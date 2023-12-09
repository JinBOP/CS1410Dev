#include <iostream>
#include "Person.h"
#include "Resident.h"
#include "Student.h"
using namespace std;

int main()
{
	Person person("John", "Fitzgerald", "Kennedy", "Texas");
	person.Profile();

	/* non-functional
	Resident resident("Martin", "Luther", "King", "Tennessee");
	resident.Home("Martin", "Luther", "King");
	
	Student student("Howard", "Phillips", "Lovecraft", 03512);
	student.InClass("Ocean Studies", 20000,	03512);
	*/


}

