#include <iostream>
using namespace std;

class Student {
private:
	int id;
	string name = "Smith";
	double gpa;
public:
	string GetName() {
		return name;
	}
};

int main()
{
	// Arrays of objects w/Pointers
	
	// Array of 10 Objects
	Student studenta[10];	// all Student Objects on the Stack
	cout << studenta[0].GetName() << endl;

	// Pointer to Array of 10 Objects
	Student* studentb;			// Pointer on Stack
	studentb = new Student[10];	// Student Objects on Heap
	cout << studentb[0].GetName() << endl;

	// Array of 10 Pointers
	Student* studentc[10];	// Pointers on the Stack
	for (int i = 0; i < 10; i++) {
		studentc[i] = new Student;	// each Student created on the Heap
	}
	// either display method works
	cout << studentc[0]->GetName() << endl;		// using Arrow Operator
	cout << (*studentc[0]).GetName() << endl;	// using Dealocate and Dot Operator

	// Pointer to an Array of 10 Pointers
	Student** studentd;				// Pointer on Stack
	studentd = new Student * [10];	// Pointers on Heap
	for (int i = 0; i < 10; i++) {
		studentd[i] = new Student;	// Students on Heap
	}
}

