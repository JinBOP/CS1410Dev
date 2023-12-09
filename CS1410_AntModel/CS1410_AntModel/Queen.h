#pragma once
#include <iostream>
#include "Ant.h"
class Queen : public Ant{
public:
	Queen(string designation = "Queen") : Ant(designation) {}	// passes instructor from Queen (child) to Ant (parent)

	void Breed(int amount) {
		cout << designation << " lays " << amount << " eggs" << endl;
	}
};