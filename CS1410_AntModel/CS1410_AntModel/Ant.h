#pragma once
#include <string>
#include "FoodPile.h"
using namespace std;

class Ant {	// Generic Ant Class
private:
	int stamina = 0;
protected:	// private to this class and any class derived from this class
	string designation;
	bool survive(int value);
public:
	Ant(string designation);
	void Eat(int amount, FoodPile pile);
};