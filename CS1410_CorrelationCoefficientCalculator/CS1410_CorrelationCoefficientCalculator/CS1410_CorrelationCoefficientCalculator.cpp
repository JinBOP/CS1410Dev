#include <iostream>
#include <string>	// Allows for String manipulation
using namespace std;

// Pearson Correlation Coefficient Lab
double Mean(double set[], int size);
void Print(double set[], int size);
double Correl(double x[], double y[], int size);

int main()
{
	// First set of data
	const int start = 300;	// Sets the size of the Array
	double set1[start];
	int index = 0;

	string input1;
	do {
		cout << "Enter a value for X set, leave blank to quit: ";
		getline(cin, input1);

		if (!input1.empty()) {	// .empty() reads the string and returns true if nothing is found
			if (!isdigit(input1[0]) && !(input1[0] == '-' && isdigit(input1[1]))) {	// checks if first thing typed is a number or negative sign
				cout << "Input numbers only!" << endl;
			}
			else {
				set1[index++] = stod(input1);	// Adds value input to the Array
				cout << stod(input1) << " Added" << endl;	// Displays value input to the Array
			}
		}
	} while (!input1.empty());

	Print(set1, index);

	// Second set of data
	int size = index;
	double* set2 = new double[size];	// Adds Array values to the Heap

	string input2;
	for (int i = 0; i < size; i++) {
		cout << "Enter value " << (i + 1) << " of " << size << " for Y set: ";
		getline(cin, input2);
		if (!isdigit(input2[0]) && !(input2[0] == '-' && isdigit(input2[1]))) {	// checks if first thing typed is a number or negative sign
			cout << "Input numbers only!" << endl;
			i--;	// Steps back to let user try again
		}
		else {
			set2[i] = stod(input2);	// Adds value input to the Array
			cout << stod(input2) << " Added" << endl;	// Displays value input to the Array
		}
	}

	Print(set2, size);

	cout << "Correlation Coefficient: " << Correl(set1, set2, size);

	delete[] set2;
}

double Mean(double set[], int size) {	// Function for calculating the average
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += set[i];	// Adds together all values
	}
	return total / size;	// Divides total by number of values to get average then returns result
}

void Print(double set[], int size) {	// Function for printing out every item in an Array
	for (int i = 0; i < size; i++) {
		cout << "[" << set[i] << "]";
	}
	cout << endl;
}

double Correl(double x[], double y[],int size) {	// Function for calculating the given values

	double meanx = Mean(x, size);
	double meany = Mean(y, size);
	double numsum = 0;
	double xsquaresum = 0;
	double ysquaresum = 0;
	for (int i = 0; i < size; i++) {	// Iterates through each data point
		numsum += (x[i] - meanx) * (y[i] - meany);	// Calculates the Numerator
		xsquaresum += pow(x[i] - meanx, 2);	// Calculates X in Denominator
		ysquaresum += pow(y[i] - meany, 2);	// Calculates Y in Denominator
	}
	return numsum / sqrt(xsquaresum * ysquaresum);	// Calculates final result and returns it
}