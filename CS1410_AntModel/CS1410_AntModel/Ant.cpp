#include <iostream>
#include "Ant.h"
using namespace std;

bool Ant::survive(int value) {
	return rand() % value;
};

Ant::Ant(string designation) : designation(designation) {
	cout << "Creating " << designation << endl;
};

void Ant::Eat(int amount, FoodPile pile) {
	cout << designation << " eats " << amount << " food" << endl;
};
