#pragma once	// includes class only once so there's less redundency especially with dependants

class FoodPile{
private:
	int amount = 0;
public:
	FoodPile(int amount);
	void AddFood(int amount);
};

