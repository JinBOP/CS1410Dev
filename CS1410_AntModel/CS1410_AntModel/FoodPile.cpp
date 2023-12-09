#include <iostream>
#include "FoodPile.h" // connects header file to class file
using namespace std;

FoodPile::FoodPile(int amount) {
	this->amount = amount;
};

void FoodPile::AddFood(int amount) {
	cout << "Adding " << amount << " food to pile" << endl;
	this->amount = amount;
};