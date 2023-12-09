#pragma once
#include <vector>
#include "Ant.h"
#include "FoodPile.h"
#include "Queen.h"
#include "Soldier.h"

class Colony {
private:
	Queen queen2;
	Soldier soldier2;
	vector<Ant*> ants;
	FoodPile* foodpile1 = nullptr;
public:
	Colony() : queen2("Queen"), soldier2("Soldier", 5) {}

	void FeedQueen(int amount) {
		//queen2.Eat(amount);
	}

	Queen& GetQueen() {
		return queen2;
	}

	void SetFoodPile(FoodPile* foodpile) {
		this->foodpile1 = foodpile;
	}

	void AddToPile(int quantity) {
		if (foodpile1 == nullptr) {
			cout << "No food found!" << endl;
		}
		else {
			foodpile1->AddFood(quantity);
		}
	}
};