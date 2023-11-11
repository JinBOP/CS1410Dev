#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
T Absolute(T x) {	// Absolute Value Template Function
	if (x >= 0) {
		return x;
	}
	else {
		return (x * -1);
	}
}

double p;
template<typename T>
T Power(T x,int n) {	// Integer Power Template Function
	p = x;
	for (int i = 0; i < n - 1; i++) {
		p *= x;
	}
	return p;
}

long Factorial(int n) {	// Long Factorial Function
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		int x = n;
		for (int i = 1; i < n; i++) {
			x *= (n - i);
		}
		return x;
	}
}

template<typename T>
double SquareRoot(T a) {	// Square Root Template Function
	
	if (a == 0) {
		return 0;
	}
	else if (a < 0) {
		return nan("");
	}
	else {
		T n = a;	// sets the starting estimate to the parameter number
		T x;		// tracks the current estimate value
		T e;		// tracks how close the estimate is to an acceptable margin
		int c = 0;	// tracks the number of estimate attempts to keep program from getting stuck
		do {
			x = (n + (a / n)) / 2;
			n = x;
			if ((e = a - x * x) < 0) {
				e = (a - x * x) * -1;
			}
			else {
				e = a - x * x;
			}
			c++;
		} while (e > 0.00001 && c < 100);
		return x;
	}
}

int main()
{
	// Absolute Value
	cout << "My Absolute(-1):" << Absolute(-1) << endl;
	cout << "std::abs(-1):" << abs(-1) << endl;
	cout << "My Absolute(12):" << Absolute(12) << endl;
	cout << "std::abs(12):" << abs(12) << endl;
	cout << "My Absolute(0):" << Absolute(0) << endl;
	cout << "std::abs(0):" << abs(0) << endl;
	cout << "My Absolute(-3.6):" << Absolute(-3.6) << endl;
	cout << "std::abs(-3.6):" << abs(-3.6) << endl << endl;

	// Integer Power
	cout << "My Power(2,2):" << Power(2, 2) << endl;
	cout << "std::pow(2,2):" << pow(2, 2) << endl;
	cout << "My Power(1.5, 5):" << Power(1.5, 5) << endl;
	cout << "std::pow(1.5, 5):" << pow(1.5, 5) << endl;
	cout << "My Power(-4, 6):" << Power(-4, 6) << endl;
	cout << "std::pow(-4, 6):" << pow(-4, 6) << endl;
	cout << "My Power(10, 1):" << Power(10, 1) << endl;
	cout << "std::pow(10, 1):" << pow(10, 1) << endl << endl;

	// Factorial
	cout << "My Factorial(0):" << Factorial(0) << endl;
	cout << "My Factorial(1):" << Factorial(1) << endl;
	cout << "My Factorial(2):" << Factorial(2) << endl;
	cout << "My Factorial(3):" << Factorial(3) << endl << endl;

	// Square Root
	cout << "My SquareRoot(9):" << SquareRoot(9) << endl;
	cout << "std::sqrt(9):" << sqrt(9) << endl;
	cout << "My SquareRoot(0):" << SquareRoot(0) << endl;
	cout << "std::sqrt(0):" << sqrt(0) << endl;
	cout << "My SquareRoot(-9):" << SquareRoot(-9) << endl;
	cout << "std::sqrt(-9):" << sqrt(-9) << endl;
	cout << "My SquareRoot(100):" << SquareRoot(100) << endl;
	cout << "std::sqrt(100):" << sqrt(100) << endl;
	
}