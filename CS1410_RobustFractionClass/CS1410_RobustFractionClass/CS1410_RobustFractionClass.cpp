#include <iostream>
using namespace std;

class Fraction {
private:
	int numerator;

	int denominator;
	
	int GreatestCommonDivisor(int a, int b) {
		if (b == 0) {
			return abs(a);
		}
		return abs(GreatestCommonDivisor(b, a % b));
	}
	
	void Simplify() {
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
		int gcd = GreatestCommonDivisor(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}
public:
	Fraction(int numerator, int denominator = 1) {
	
	}

	friend ostream& operator<<(ostream& out, const Fraction& fraction) {
		if (fraction.denominator == 1) {
			out << fraction.numerator;
		}
		else if (fraction.numerator > fraction.denominator) {
			int whole = fraction.numerator / fraction.denominator;
			int num = fraction.numerator % fraction.denominator;
			out << whole << " and " << num << "/" << fraction.denominator;
		}
		else {
			out << fraction.numerator << "/" << fraction.denominator;
		}
	}

	friend istream& operator>>(istream& in, Fraction& fraction) {
		char slash;
		cout << "Enter a fraction (n/d): ";
		in >> fraction.numerator >> slash >> fraction.denominator;
		return in;
	}

	friend Fraction operator+(Fraction op1, Fraction op2) {
		int num = (op1.numerator * op2.denominator) + (op2.numerator * op1.denominator);
		int den = op1.denominator * op2.denominator;
		return Fraction(num, den);
	}

	friend Fraction operator-(Fraction op1, Fraction op2) {
		int num = (op1.numerator * op2.denominator) - (op2.numerator * op1.denominator);
		int den = op1.denominator * op2.denominator;
		return Fraction(num, den);
	}

	friend Fraction operator*(Fraction op1, Fraction op2) {
		int num = op1.numerator * op2.numerator;
		int den = op1.denominator * op2.denominator;
		return Fraction(num, den);
	}

	friend Fraction operator/(Fraction op1, Fraction op2) {
		int num = op1.numerator * op2.denominator;
		int den = op1.denominator * op2.numerator;
		return Fraction(num, den);
	}

	operator double() {
		return double(numerator / denominator);
	}

	Fraction& operator+=(Fraction fraction) {

	}

	Fraction& operator-=(Fraction fraction) {
		*this = *this - fraction;
		return *this;
	}

	Fraction& operator*=(Fraction fraction) {

	}

	Fraction& operator/=(Fraction fraction) {

	}

	Fraction& operator++() {

	}

	Fraction operator++(int) {

	}

	Fraction& operator--() {

	}

	Fraction operator--(int) {

	}
};

int main()
{


}

