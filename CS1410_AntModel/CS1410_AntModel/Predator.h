#include <iostream>
#include <vector>
using namespace std;

class ColonyP;

class Predator {
private:
	ColonyP* colony = nullptr;
public:
	void SetCurrentColony(ColonyP* colony);
	void AttackP();
};

class ColonyP {
private:
	Predator* predator = nullptr;
	vector<Predator*> PredatorVector;
public:
	void SetCurrentPredator(Predator* predator);
	void AttackP();
};

void Predator::SetCurrentColony(ColonyP* colony) {
	this->colony = colony;
}

void Predator::AttackP() {
	cout << "The predator attacks!" << endl;
}

void ColonyP::SetCurrentPredator(Predator* predator) {
	this->predator = predator;
}

void ColonyP::AttackP() {
	cout << "The colony attacks!" << endl;
}