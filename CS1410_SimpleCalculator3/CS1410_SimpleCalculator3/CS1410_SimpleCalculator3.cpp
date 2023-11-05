#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	/* a = coefficient "a", 
	b = coefficient "b",
	c = coefficient "c",
	x1 = x - intercept from positive equation,
	x2 = x-intercept from negative equation
	comma = placeholder representing a comma */
	double a, b, c, x1, x2;
	char comma;

	// asks for user to input values to use for calculations
	cout << "Enter coefficients (a,b,c): ";
	cin >> a >> comma >> b >> comma >> c;

	// calculates the quadratic equation with a +
	x1 = ((-1 * b) + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

	// calculates the quadratic equation with a -
	x2 = ((-1 * b) - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

	// displays results
	cout << "X-intercept 1: " << x1 << endl;
	cout << "X-intercept 2: " << x2 << endl;

	/* Test Cases:
	* Input				Output
	* a     b     c     x1     x2
	* 1     5     6     -2     -3     
	* 2    -7    -3     3.886  -0.386
	* 1    -4    -21    7      -3
	* 1     9     18    -3     -6
	* 2     5     1     -0.219 -2.280
	*/
}