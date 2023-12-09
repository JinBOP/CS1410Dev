#include <iostream>
#include "Soldier.h"
using namespace std;

void Soldier::Attack(Ant ant) {
	if (survive(5)) {
		cout << designation << " Survives the encounter!" << endl;
	}
	else {
		cout << designation << " died!" << endl;
	}
};