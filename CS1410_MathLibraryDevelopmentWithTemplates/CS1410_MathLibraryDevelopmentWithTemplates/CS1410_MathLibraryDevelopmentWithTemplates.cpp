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
	cout << "std::pow(10, 1):" << pow(10, 1) << endl;

}

