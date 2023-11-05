#include <iostream>
using namespace std;

class Person {
private:
	string name;
	double height;
	int weight;
	static int instances;

	string GetAddress() {};
public:
	Person(string aname, double aheight, int aweight) {}	// Constructor

	// Member Functions
	bool PayTaxes() {}
	void CatchBus() {}

	static int GetInstances() {
		return instances;
	}
};

class Time {
private:
	int hours;
	int minutes;
	int seconds;

public:
	// Constructors
	Time() {}
	Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
	Time(int s) {
		this->seconds = s;
	}

	// Member Functions
	Time add(Time t2) {
		Time sum;

		sum.hours = this->hours + t2.hours;
		sum.minutes = this->minutes + t2.minutes;

		return sum;
	}
	Time* add(Time* t2) {}
	void Print() {}
	void Read() {}

};

int main()
{
	/*Class Designers(person making the class); Class Implementers(person using the class)
	* Public Interface: what the class user knows/needs to know to use the class
	* Stable Interface: once part of the interface is public, that public access should not change
	* Data Hiding: member data should only be minipulated through public interface
	* Encapulation: bundles data and functions within a class
	* 
	* Unified Modeling Language (UML)
	* 3 parts:
	*	Top: Class Name
	*	Middle: Attributes
	*	Bottom: Operations
	*/

	Time time;
	Time time2(4, 34, 56);
	Time time3(35000);

	time.add(time2);
	time.Print();
	time.Read();
}