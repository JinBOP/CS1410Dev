#include <iostream>
using namespace std;

struct Employee {
	string name;
	int id;
};

void UpdateFirst(char array[]){

}

void print(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << a[i] << "]";
	}
}

// Array Decay
void SizeOfArray(char alpha1[]) {
	int howlarge = sizeof(alpha1) / sizeof(char);
	cout << "Size of Array: " << howlarge << endl;
}

// Return Arrays from Functions, fixed by using Static (turns it into a global variable), pass by an argument (GetRandomFive(int random[])), or 
int* GetRandomFive() {
	static int random[5]; // Builds Array
	for (int i = 0; i < 5; i++) { // Assigns values to all 5 slots
		random[i] = rand() % 10;
	}
	cout << "In function: ";
	print(random, 5);
	return random;
 }

int main()
{
	/* Array: data structure that allows for storing multiple values under the same identifier (a collection of data)
	* in C++:
	* NEED TO define how many items are in the Array, C++ Arrays don't know their own size
	* Arrays are static, size cannot change
	* all elements must be the same data type
	* accessing an Array out of bounds may NOT throw an exception
	* brackets are strict
	* 
	* int/double/string/etc. is the data type
	* a1/iq/cost/employees/etc. is the identifier
	* [] defines the number of items in the Array, redundency
	* {1,2,3,...} is the data
	*/
	// defining Arrays
	int a1[4] = { 1,2,3,4 }; 
	int iq[5] = { 150, 115, 85, 90, 95 };
	double cost[3] = { 7.2, 6.1, 3.9 };
	string employees[5] = { "John", "Jacob", "Jingle", "Hymer", "Schmitt" };

	// Accessing Arrays
	cout << employees[1] << endl; // accessing an element via its index number
	cout << iq[6] << endl; // accessing an element out of bounds
	cout << iq[-1] << endl; // accessing an element out of bounds
	cout << iq << endl; // spits out the memory address of the Array

	// Initializing Arrays
	int test1[3] = { 5,0,82 };
	int test2[] = { 16,62,43 };
	int test3[3]{ 155,901,93 };
	int test4[3];
	test4[0] = 17;
	test4[1] = 81;
	test4[2] = 5;
	int* test5 = new int[3] {65, 29, 38}; // * is called a Pointer and points to a specific memory address

	Employee workers[2] = { {"Rhodes", 90573}, {"Peterson", 89372} };
	cout << workers[0].id << endl; // accessing a specific element within a Structure inside an Array
	cout << workers[0].name << endl;

	/* One-Dimensional and Two-Dimensional Arrays
	*  One-Dimensional Arrays are shown above, working like a number line
	*  Two-Dimensional Arrays are shown below, working like a grid
	* 
	*  C++ is a Row Major Language (row is always specified first)
	*/

	int twodims[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 }; // [number of rows][number of columbs]
	cout << twodims[0][0] << endl;
	cout << twodims[2][1] << endl;

	// Other forms of notation for readability
	int twodimexample1[4][3] = { 1,2,3,
							   4,5,6,
							   7,8,9,
							   10,11,12 };
	int twodimexample2[4][3] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };

	// Memory Allocation
	int array1[10]; // Allocated on the Stack (like a neat stack of papers)

	int* array2 = new int[10]; // Allocated on the Heap (like a random pile of clothes, memory leak can happen and waste space, C++ does not have garbage collection)
	delete[] array2; // Must delete

	// Array Sizes
	// Ways of ensuring the array is large enough
	const int SIZE = 10; // Overestimate and have a partially filled Array
	int data[SIZE];

	int half[10] = { 2,7,9,3,0 }; // Overestimate and partially fill

	int size; // Ask
	cout << "Number of data points needed: ";
	cin >> size;
	double* dataset = new double[size];
	for (int i = 0; i < 1; i++) {
		dataset[i] = i * 2;
	}
	delete[] dataset;

	// CANNOT overfill an Array
	//int twice[5] = { 2,39,76,0,74,28,68,41,78,46 };

	// Zeroing Array Elements
	int empty[6] = {}; // Returns all elemets as 0s

	string fruit[] = { "oranges", "bananas", "grapes", "lemons", "limes" };
	int howbig = sizeof(fruit) / sizeof(string); // amount of memory being used divided by the data type to give number of elements

	cout << "Size of fruit:" << sizeof(fruit) << endl;
	cout << "Size pf string:" << sizeof(string) << endl;
	cout << "Number of elements:" << howbig << endl;
	// Will not work when Arrays are passed to a Function
	
	// Iterating through 2D Arrays
	char alpha[3][2] = { 'a','b',
						'c','d',
						'e','f' };
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 2; col++) {
			cout << "[" << alpha[row][col] << "]";
		}
		cout << endl;
	}

	// Iterating through 1D Arrays
	char beta[6] = { 'a','b','c','d','e','f' };
	for (int row = 0; row < 6; row++) {
		cout << "[" << beta[row] << "]";
	}
	cout << endl;

	// Copying Arrays
	char alpha1[3] = { 'a','b','c'};
	// char* alpha2 = alpha1; // Doesn't copy, just makes another identifier that saves the same place where the original saves
	char alpha2[4];
	for (int i = 0; i < 3; i++) {
		alpha2[i] = alpha1[i];
	}
	alpha2[0] = 'f';

	cout << "Alpha1: ";
	for (int row = 0; row < 3; row++) {
		cout << "[" << alpha1[row] << "]";
	}
	cout << endl << "Alpha2: ";
	for (int row = 0; row < 3; row++) {
		cout << "[" << alpha2[row] << "]";
	}

	/* Functions and Arrays
	* Arrays are always pass by pointer
	*/
	UpdateFirst(alpha1);

	int howlarge = sizeof(alpha1) / sizeof(char);
	cout << "Size of Array: " << howlarge << endl;

	SizeOfArray(alpha1);

	int* random = GetRandomFive();
	cout << "In Main: ";
	print(random, 5);
}
