#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// p = principle amount, n = number of months, r = rate
	int p, n;
	double r;

	// Prompt for user input for each variable to assign values required for necessary math
	cout << "Principle Loan amount: ";
	cin >> p;
	cout << "Number of Months: ";
	cin >> n;
	cout << "Interest Rate (i.e. 6.2%): ";
	cin >> r;

	// Convert percentage to decimal value
	r /= 100;

	// Calculations
	double Numerator = (r / 12) * pow(1 + r / 12, n);
	double Denominator = pow(1 + r / 12, n) - 1;
	double m = p * Numerator / Denominator;

	// Final result
	cout << "Monthly payment: " << m << endl;
}
