#include <iostream>
#include <vector>
using namespace std;

class Colony;

class Predator {
private:
	Colony* colony = nullptr;
public:
	void SetCurrentColony(Colony* colony);
	void Attack();
};

class Colony {
private:
	Predator* predator = nullptr;
	vector<Predator*> PredatorVector;
public:
	void SetCurrentPredator(Predator* predator);
	void Attack();
};

void Predator::SetCurrentColony(Colony* colony) {
	this->colony = colony;
}

void Predator::Attack() {
	cout << "The predator attacks!" << endl;
}

void Colony::SetCurrentPredator(Predator* predator) {
	this->predator = predator;
}

void Colony::Attack() {
	cout << "The colony attacks!" << endl;
}

int main()
{
	/* Association (2 classes have "equal" status or importance)
	*  a Colony and a Predator
	* 
	*/
	Predator predator;
	Colony colony;

	predator.SetCurrentColony(&colony);
	colony.SetCurrentPredator(&predator);

	predator.Attack();
	colony.Attack();
}
