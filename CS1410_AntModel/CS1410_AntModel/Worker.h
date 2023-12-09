#pragma once
#include <iostream>
#include "Ant.h"
using namespace std;

class Worker : public Ant{
private:
	int capacity;
public:
	Worker(string designation, int capacity) : Ant(designation), capacity(capacity) {}

	void Work(int value) {
		cout << designation << " works for " << value << " minutes" << endl;
	}
};