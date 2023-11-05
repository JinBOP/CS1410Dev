#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// a = first numerator, b = first denominator, c = second numerator, d = second denominator
	// slash = placeholder to represent fraction bar
	int a, b, c, d;
	char slash;

	// asks for user to input values to use for both fractions
	cout << "Enter first fraction (a/b): ";
	cin >> a >> slash >> b;
	cout << "Enter second fraction (c/d): ";
	cin >> c >> slash >> d;

	// num = final numerator
	int num;
	// calculates value in the numerator
	num = a * d + b * c;
	// den = final denominator
	int den;
	// calculates value in the denominator
	den = b * d;

	// displays final results
	cout << "Sum: " << num << "/" << den;

	// Test Cases:
	// Fraction 1	Fraction 2	Sum
	// 1/3			1/2			5/6
	// 2/3			4/5			22/15
	// 8/4			7/10		108/40
	// 7/12			2/5			59/60
	// 1/20			4/17		97/340
}