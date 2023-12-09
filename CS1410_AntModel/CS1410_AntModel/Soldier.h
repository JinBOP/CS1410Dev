#pragma once
#include <iostream>
#include "Ant.h"
class Soldier : public Ant{
private:
	int strength;
public:
	Soldier(string designation, int strength) : Ant(designation), strength(strength) {}
	void Attack(Ant ant);
};