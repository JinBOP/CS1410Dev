#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
T absolute(T x) {	// Absolute Value Template Function
	if (x >= 0) {
		return x;
	}
	else {
		return (x * -1);
	}
}

int main()
{
	// Absolute Value
	cout << "My abs(-1):" << absolute(-1) << endl;
	cout << "std::abs(-1):" << abs(-1) << endl;
	cout << "My abs(12):" << absolute(12) << endl;
	cout << "std::abs(12):" << abs(12) << endl;
	cout << "My abs(0):" << absolute(0) << endl;
	cout << "std::abs(0):" << abs(0) << endl;
	cout << "My abs(-3.6):" << absolute(-3.6) << endl;
	cout << "std::abs(-3.6):" << abs(-3.6) << endl << endl;

	// Integer Power


}

