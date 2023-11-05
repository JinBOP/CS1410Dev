#include <iostream>
using namespace std;

class Time {
private:
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
public:
	Time() {};	// Default Constructor

	Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {};	// Paramatized Constructor

	Time(int seconds) { 	// Conversion Constructor
		hours = seconds / 3600;
		seconds %= 3600;
		minutes = seconds / 60;
		this->seconds = seconds % 60;
	};

	/*Time operator+(Time time) {	// Overloaded Operator to Add two Time Objects together
		int seconds1 = this->hours * 3600 + this->minutes * 60 + this->seconds;	// breaks down the initial Time Object to seconds for math
		int seconds2 = time.hours * 3600 + time.minutes * 60 + time.seconds;	// breaks down the passed-in Time Object to seconds for math
		return Time(seconds1 + seconds2);	// Adds both totals and converts back to h:m:s using Conversion Constructor
	}*/

	/*Time operator+(int seconds) {	// Overloaded Operator to add Time (left) and int (right)
		int seconds1 = hours * 3600 + minutes * 60 + this->seconds;
		return Time(0, 0, seconds1 + seconds);
	}*/

	/*friend Time operator+(int seconds, Time time) {	// 
		int seconds1 = time.hours * 3600 + time.minutes * 60 + time.seconds;
		return Time(0, 0, seconds1 + seconds);	// Adds both totals and converts back to h:m:s using Conversion Constructor
	}*/

	operator int() {	// converts to seconds
		return hours * 3600 + minutes * 60 + seconds;
	}

	operator double() {	// converts to hours
		return double(int(*this)) / 3600;	// plugs the given Object into Overloaded Int() Function, then changes the Integer into a Double, then divides it by 3600 (seconds per hour) and returns the fractional result
	}

	friend Time operator+(Time time1, Time time2) {	// "friend" allows access to Private member Variables
		int seconds1 = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
		int seconds2 = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;
		return Time(seconds1 + seconds2);
	}

	// Compound Assignment: +=, -=, *=, /=
	Time& operator+=(Time time) {
		*this = *this + time;
		return *this;
	}

	Time& operator++() {	// Prefix Notation
		this->hours += 1;
		return *this;
	}

	Time operator++(int) {	// Suffix Notation
		Time copy(int(*this));
		this->hours += 1;
		return copy;
	}

	void Print() {	// Temp print Function
		if (hours < 10) {
			cout << "0";
		}
		cout << hours << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << ":";
		if (seconds < 10) {
			cout << "0";
		}
		cout << seconds << endl;
	};

	friend ostream& operator<<(ostream& out, const Time& time);	// "ostream" means output stream, similar to cout, the return allows results to be chained 
	friend istream& operator>>(istream& in, Time& time);	// "istream" means input stream, similar to cin, the return allows results to be chained

};

ostream& operator<<(ostream& out, const Time& time) {	// first parameter (outstream& out) is what is on the left of the Operator symbol, second parameter (const Time& time) is what is on the right of the Operator symbol
	if (time.hours < 10) {
		out << "0";
	}
	out << time.hours << ":";
	if (time.minutes < 10) {
		out << "0";
	}
	out << time.minutes << ":";
	if (time.seconds < 10) {
		out << "0";
	}
	out << time.seconds;
	return out;
}

istream& operator>>(istream& in, Time& time) {	//
	char c;
	cout << "Enter a time (HH:MM:SS) ";
	in >> time.hours >> c >> time.minutes >> c >> time.seconds;
	return in;
}

int main()
{
	/* Overloaded Operators: 
	* Rules:
	*	1 - should not change the meaning of a prebuilt Operator (don't make stupid changes like making '+' do subtraction)
	*	2 - cannot change the precedence of the Operator or associativity (can't change the order of things like PEMDAS)
	*	3 - cannot change number of Operands ()
	*	4 - cannot create a new Operator (can only Overload existing Operators)
	*	5 - cannot Overload an Operator without using some Class ()
	*	6 - should be intuitive (things should make logical sense)
	* 
	* commonly Overloaded Operators: +, -, *, /, +=, -=, *=, /=, <<, >>, type conversions, (), []
	* CANNOT Overload: ::, ., new
	*/

	Time time1(5400);	// defined total Seconds are converted into H:M:S
	time1.Print();

	Time time2(5, 4, 39);	// defined Hours, Minutes, and Seconds
	time2.Print();

	Time time3 = time1 + time2;	// Adds times together
	time3.Print();

	/*Time time4 = 55 + time1;	// Adds 55 Seconds
	time4.Print();
	(time1 + 55).Print();	// compressed version
	// Time time4 = 55 + time1; Does not work because the Overloaded Operator needs 'Object + Object or Int' cannot do 'Int + Object'
	*/
	// Insertion
	cout << time1 << endl;

	// Extraction
	Time time5;
	cin >> time5;
	cout << time5 << endl;

	// Overloaded Type Conversion
	cout << int(time1) << endl;	// converting to total seconds

	cout << double(time1) << endl;	// converting to total hours

	// Overloaded Compound Assignment
	time1 += time2;
	cout << time1 << endl;

	int x = 10;
	cout << x++ << endl;	// displays then Increments
	cout << ++x << endl;	// Increments then displays

	cout << ++time5 << endl;
	cout << time5++ << endl;
	cout << time5 << endl;
}

