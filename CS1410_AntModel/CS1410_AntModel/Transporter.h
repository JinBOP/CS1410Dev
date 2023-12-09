#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Transporter : public Worker{
public:
	Transporter(string designation, int capacity) : Worker(designation, capacity) {}

	// Overridden Function
	void Work(int value) {
		cout << designation << " transports for " << value << " minutes" << endl;
	}
};