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
	Fraction(int n, int d) : numerator(n), denominator(d) {};

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
		return out;
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
		return double(numerator) / double(denominator);
	}

	Fraction& operator+=(Fraction fraction) {
		*this = *this + fraction;
		return *this;
	}

	Fraction& operator-=(Fraction fraction) {
		*this = *this - fraction;
		return *this;
	}

	Fraction& operator*=(Fraction fraction) {
		*this = *this * fraction;
		return *this;
	}

	Fraction& operator/=(Fraction fraction) {
		*this = *this / fraction;
		return *this;
	}

	Fraction& operator++() {
		this->numerator += denominator;
		return *this;
	}

	Fraction operator++(int) {
		Fraction copy(*this);
		this->numerator += denominator;
		return copy;
	}

	Fraction& operator--() {
		this->numerator -= denominator;
		return *this;
	}

	Fraction operator--(int) {
		Fraction copy(*this);
		this->numerator -= denominator;
		return copy;
	}
};

int main()
{
	Fraction fraction();
	Fraction fraction1(1, 2);
	Fraction fraction2(3, 4);
	//cin >> fraction;

	cout << "Fraction 1:" << fraction1 << endl;
	cout << "Fraction 2:" << fraction2 << endl;
	cout << "Addition:" << fraction1 + fraction2 << endl;
	cout << "Subtraction:" << fraction1 - fraction2 << endl;
	cout << "Multiplication:" << fraction1 * fraction2 << endl;
	cout << "Division:" << fraction1 / fraction2 << endl;
	cout << "Conversion:" << double(fraction1) << endl;
	cout << "Conversion:" << double(fraction2) << endl << endl;

	Fraction fraction3(2, 3);
	Fraction fraction4(1, 5);
	cout << "Fraction 3:" << fraction3 << endl;
	cout << "Fraction 4:" << fraction4 << endl;
	fraction3 += fraction4;
	cout <<  "Compound Addition:" << fraction3 << endl;
	fraction4 -= fraction3;
	cout << "Compound Subtraction:" << fraction4 << endl;
	fraction1 *= fraction3;
	cout << "Compound Multiplication:" << fraction1 << endl;
	fraction2 /= fraction4;
	cout << "Compound Division:" << fraction2 << endl << endl;

	Fraction fraction5(4, 9);
	cout << "Fraction 5:" << fraction5 << endl;
	cout << "Prefix Increment:" << ++fraction5 << endl;
	cout << fraction5 << endl;
	cout << "Postfix Increment:" << fraction5++ << endl;
	cout << fraction5 << endl;
	cout << "Prefix Decrement:" << --fraction5 << endl;
	cout << fraction5 << endl;
	cout << "Postfix Decrement:" << fraction5-- << endl;
	cout << fraction5 << endl;
}

