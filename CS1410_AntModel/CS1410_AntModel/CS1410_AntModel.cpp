#include <iostream>
#include "FoodPile.h"	// connects header file to main file
#include "Ant.h"
#include "Queen.h"
#include "Soldier.h"
#include "Worker.h"
#include "Forager.h"
#include "Transporter.h"
#include "Colony.h"
//#include "Predator.h"
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

	Transporter transporter1("Sugar Transporter", 9);
	transporter1.Work(10);

	Colony colony1;

	colony1.AddToPile(13);
	FoodPile* foodpile2 = new FoodPile(14);
	colony1.SetFoodPile(foodpile2);
	colony1.AddToPile(15);

	colony1.FeedQueen(11);	// colony queen access needs to go through colony
	colony1.GetQueen().Eat(12, *foodpile2);

	/*Predator predator;
	ColonyP colony;

	predator.SetCurrentColony(&colony);
	colony.SetCurrentPredator(&predator);

	predator.Attack();
	colony.Attack();*/
};
