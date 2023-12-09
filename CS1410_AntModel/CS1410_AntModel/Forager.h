#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Forager : public Worker{
public:
	Forager(string designation = "Forager", int capacity = 2) : Worker(designation, capacity) {}

	// Overridden Funciton
	void Work(int value) {
		cout << designation << " searches for " << value << " minutes" << endl;
		Worker::Work(value);	// Function Chaining
	}
};