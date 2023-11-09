#include <iostream>
#include <algorithm> // imports Algorithm Standard Template Library
using namespace std;

class Word {
private:
	string word;
	int score;
public:
	Word() {
		word = "empty";
		score = rand() % 200;
	}

	Word(string word) : word(word) {
		score = rand() % 200;
	}

	Word(string word, int score) : word(word), score(score) {}

	friend bool operator<(const Word& word1, const Word& word2) {	// Overloaded '<' Operator to be able to effectively compare Word Objects and thus sort them
		return word1.score < word2.score;
	}

	friend bool WordCompare(const Word& word1, const Word& word2);

	string GetWord() {
		return word;
	}

	int GetScore() {
		return score;
	}
};

void PrintSet(Word set[], int size) {
	for (int i = 0; i < size; i++) {
		cout << set[i].GetWord() << "(" << set[i].GetScore() << ") ";
	}
	cout << endl;
}

bool WordCompare(const Word& word1, const Word& word2) {
	return word1.word < word2.word;
}

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

	Time operator++(int) {	// Postfix Notation
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

// Creating a Template
template <typename T> // 'T' is the placeholder Variable similar to 'i' in an Iteration Loop
T add(T a, T b) {	// add Function that works with almost any Object
	return a + b;
}

int main()
{
	/* Templates: 
	* Standard Template Library (STL): a collection of Algorithms, Containers, Iterators, Function Objects (Functors), and Adaptors that can be used and reused to simplify C++ programs
	* 
	*/
	
	// Overloaded Functions : 2 or more Functions with the same name and different parameters
	// Example of an included Overloaded Function
	min(4, 5);	// int min(int a, int b);
	min(4.5, 6.7);	// double min(double a double b);

	const int size = 5;
	Word set[size] = { Word("Banana"), Word("Apple"), Word("Grape"), Word("Orange"), Word("Cherry") };

	sort(set, set + size);	// sort(first location, last location)
	PrintSet(set, size);

	sort(set, set + size, WordCompare);
	PrintSet(set, size);

	add(2, 3);
	add(4.5, 8.9);
	add(Time(360), Time(120));
}

