#include <iostream>
#include <string>
using namespace std;

void Print(double set[], int size);
void Sort(double[], int);
double Mean(double set[], int size);
double Median(double set[], int size);
double Range(double set[], int size);
double Variance(double set[], int size, double average);
double Deviation(double variance);
int Mode(double set[], int size, int value);

int main()
{
	cout << "Descriptive Statistics Calculator" << endl;
	const int start = 300;	// Sets the size of the Array
	double set1[start][start];
	int index = 0;

	string input1;
	do {
		cout << "Enter data point, leave blank to quit: ";
		getline(cin, input1);

		if (!input1.empty()) {	// .empty() reads the string and returns true if nothing is found
			if (!isdigit(input1[0]) && !(input1[0] == '-' && isdigit(input1[1]))) {	// checks if first thing typed is a number or negative sign
				cout << "Input numbers only!" << endl;
			}
			else {
				set1[0][index++] = stod(input1);	// Adds value input to the Array
				cout << stod(input1) << " Added" << endl;	// Displays value input to the Array
			}
		}
	} while (!input1.empty());

	cout << "Original Dataset:";
	Print(set1[0], index);	// Displays Original Dataset

	double copy[2][start];	// Copies Original Dataset
	for (int i = 0; i < index; i++) {
		copy[0][i] = set1[0][i];
	}

	Sort(copy[0], index);	// Sorts copied Dataset
	cout << "Sorted Dataset:";
	Print(copy[0], index);	// Displays Sorted Dataset

	double average = Mean(copy[0], index);	// Calculates Average
	cout << "Average: " << average << endl;

	double middle = Median(copy[0], index);	// Calculates Middle value
	cout << "Middle Value: " << middle << endl;

	double range = Range(copy[0], index);	// Calculates the Range
	cout << "Range: " << range << endl;

	double variance = Variance(copy[0], index, average);	// Calculates the Variance
	cout << "Sample Variance: " << variance << endl;

	double deviation = Deviation(variance);	// Calculates the Deviation
	cout << "Sample Standard Deviation: " << deviation << endl;

	for (int i = 0; i < index; i++) {	// Calculates the frequency of each value
		int count = Mode(copy[0], index, copy[0][i]);
		copy[1][count]++;
	}
	cout << "Value: ";
	Print(copy[0], index);
	cout << "Count: ";
	Print(copy[1], index);
}

void Print(double set[], int size) {	// Function for printing out every item in an Array
	for (int i = 0; i < size; i++) {
		cout << "[" << set[i] << "]";
	}
	cout << endl;
}

void Sort(double dataset[], int size) {	// Function for sorting the values in an Array
	for (int i = 0; i < size; i++) {
		int minindex = i;
		for (int j = i; j < size; j++) {
			if (dataset[j] < dataset[minindex]) {
				minindex = j;
			}
		}
		double tempvalue = dataset[i];
		dataset[i] = dataset[minindex];
		dataset[minindex] = tempvalue;
	}
}

double Mean(double set[], int size) {	// Function for calculating the average
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += set[i];	// Adds together all values
	}
	return total / size;	// Divides total by number of values to get average then returns result
}

double Median(double set[], int size) {	// Function for calculating the median
	int items = size % 2;
	if (items == 0) {
		int index1 = (size / 2) - 1;
		int index2 = (size / 2);
		double value1 = set[index1];
		double value2 = set[index2];
		double sum = (value1 + value2) / 2;
		return sum;
	}
	else {
		int i = size / 2;
		return set[i];
	}
}

double Range(double set[], int size) {	// Function for calculating the range
	double lowest = set[0];
	double highest = set[size];
	double distance = highest - lowest;
	return distance;
}

double Variance(double set[], int size, double average) {	// Function for calculating Sample Variance
	double sum = 0;
	for (int i = 0; i < size; i++) {
		double step1 = set[i] - average;
		double step2 = pow(step1, 2);
		double step3 = step2 / (size - 1);
		sum += step3;
	}
	return sum;
}

double Deviation(double variance) {	// Function for calculating Standard Deviation
	double result = sqrt(variance);
	return result;
}

int Mode(double set[], int size, int value) {	// Function for finding the Mode
	for (int i = 0; i < size; i++) {
		if (set[i] == value) {
			return i;
		}
	}
	return -1;
}