#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// a = area, r = radius, pi = first 11 digits of pi
	double a, r, pi;
	pi = 3.1415926535;

	// Prompts user for input to use as radius
	cout << "Enter the Radius of the circle: ";
	cin >> r;
	
	// Calculates area with given variable
	a = pi * pow(r, 2);

	// Displays results
	cout << "The Area of the circle is : " << fixed << setprecision(10) << a ;

	// Test Cases:
	// Radius	Area
	// 5		 78.5398163375	
	// 10		314.1592653500
	// 7		153.9380400215
	// 3.6		 40.7150407894
	// 0.85		  2.2698006922
}