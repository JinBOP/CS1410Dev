#include <iostream>
#include "Person.h"
#include "Resident.h"
using namespace std;

int main()
{
	Person person1("John", "Fitzgerald", "Kennedy", "Whitehouse");
	person1.Profile();

	/* non-functional
	Resident person2("John", "Fitzgerald", "Kennedy", "Whitehouse");
	person2.Home("John", "Fitzgerald", "Kennedy");
	*/


}

