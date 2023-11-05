#include <iostream>
using namespace std;

struct Person {
	string name = "Johnny";
};

void AddFive(int* m) {	// Pass-By-Reference: (int &m), Pass-By-Pointer: (int* m)
	*m += 5;
}

int Add(int a, int b) {
	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}

int Mult(int a, int b) {
	return a * b;
}

int Divd(int a, int b) {
	return a / b;
}

int compute(int(*op)(int, int), int a, int b) {	// Passing a Function as an argument for another Function
	return op(a, b);
}
int main()
{
	/* Pointer: variable that stores the memory address
	* a Pointer is its own thing but not the whole thing, much like a desktop shortcut
	* Pointers are used to:
	* 1 - Allocate objects on the Heap
	* 2 - Pass Functions to other Functions
	* 3 - Iterate over elements in Arrays and other data structures
	* 4 - Memory management (pass-by-value, pass-by-pointer)
	* 
	* Variables are made up of 3 parts:
	* 1 - Name
	* 2 - Content
	* 3 - Address
	* 
	* rather than the Variable Name used to access Content of the Variable, a Pointer references the Memory Address of the Variable
	* 
	* 6 Operators regarding Pointers:
	* new		defines an object on the heap
	* delete	reallocate heap space
	* ->		"member access" operator
	* &			"address of" operator
	* *			Pointer definition
	* *			Dereference operator
	*/

	int i;	// Variable used to store an Integer
	int* p;	// Pointer to store an Address of an Integer

	i = 9;	// Stores Integer i
	p = &i;	// Stores Address of i

	*p = 15;	// Updates the Content of the Variable the Pointer is referencing

	cout << i << endl;	// shows the Content of the Variable
	cout << &i << endl;	// shows the Address of i
	cout << p << endl;	// shows the Address of the Content of the Variable
	cout << *p << endl;	// shows the Content of the Address

	Person person;						// Defined on the Stack
	Person* personpointer = new Person;	// Defined on the Heap

	delete personpointer;

	/* Stack: Memory allocated on top, LIFO (Last In, First Out), Automatic Variables
	*  Heap: Memory allocated anywhere, can have "holes", slower than Stack
	*/

	// common delete errors
	Person* p1;
	//delete p1; can't delete because p1 is not initialized and thus on the Stack, not the Heap

	Person p2 = Person();
	Person* pointer2 = &p2;
	//delete pointer2; can't delete because p2 is not initialized and is on the Stack, not the Heap

	Person sperson = { "Jimmy" };	// stored on the Stack
	cout << sperson.name << endl;	// Member Access Operator (dot)
	Person* spointer = new Person{ "Jacob" };	// stored on the Heap
	cout << (*spointer).name << endl;
	cout << spointer->name << endl;		// Member Access Operator (arrow)
	delete spointer;

	// Relational Operators (==, !=)
	int i1 = 64; // Contents are the same
	int i2 = 64;

	int* ip1 = &i1;	// Memory Addresses are different
	int* ip2 = &i2;

	if (ip1 == ip2) {	// comparing Memory Addresses NOT Contents
		cout << "i1 and i2 are at the same location" << endl;
	}
	if (ip1 != ip2) {	// comparing Memory Addresses NOT Contents
		cout << "i1 and i2 are NOT at the same location" << endl;
	}

	int n[] = { 2,4,6,8,10,12 };	// each Integer takes up 4 Bytes (32-bits) of Memory
	cout << n + 0 << endl;
	cout << n + 1 << endl;
	cout << n + 2 << endl;

	cout << "Starting Names:" << endl;
	string names[] = { "John","Jacob","Jingle","Hymer","Smith" };	// each String takes up 28 Bytes of Memory
	for (int i = 0; i < 5; i++) {	// iteration through the Array items
		cout << *(names) << endl;
	}

	Person* nperson = nullptr;	// Null Pointer : can set nullptr in the event data is not known

	// Additional Examples
	int m = 10;
	AddFive(&m);
	cout << m << endl;

	int a = 10;
	int b = 5;

	cout << compute(Add, a, b) << endl;
	cout << compute(Sub, a, b) << endl;
	cout << compute(Mult, a, b) << endl;
	cout << compute(Divd, a, b) << endl;
}

