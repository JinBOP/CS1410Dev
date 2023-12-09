#include <iostream>
#include "FoodPile.h"	// connects header file to main file
#include "Ant.h"
#include "Queen.h"
#include "Soldier.h"
#include "Worker.h"
#include "Forager.h"
using namespace std;

int main()
{
	FoodPile pile1(20);
	pile1.AddFood(5);

	Ant ant1("Sugar Ant");
	ant1.Eat(1, pile1);

	Queen queen1("Sugar Queen");
	queen1.Eat(2, pile1);
	queen1.Breed(3);

	Soldier soldier1("Sugar Soldier", 4);
	soldier1.Attack(ant1);

	Worker worker1("Sugar Worker", 5);
	worker1.Work(6);

	Forager forager1("Sugar Forager", 7);
	forager1.Work(8);
};
