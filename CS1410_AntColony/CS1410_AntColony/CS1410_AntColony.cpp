#include <iostream>
using namespace std;

class Ant {	// Generic Ant Class
private:
	int stamina = 0;
protected:	// private to this class and any class derived from this class
	string designation;
	bool survive(int value) {
		return rand() % value;
	}
public:
	Ant(string designation) : designation(designation) {
		cout << "Creating " << designation << endl;
	}

	void Eat(int amount) {
		cout << designation << " eats " << amount << " food" << endl;
	}
};

// Inheritance
class Queen : public Ant {	// class 2 : class 1 ("a Queen is an Ant")
public:
	Queen(string designation = "Queen") : Ant(designation) {}	// passes instructor from Queen (child) to Ant (parent)

	void Breed(int amount) {
		cout << designation << " lays " << amount << " eggs" << endl;
	}
};

class Soldier : public Ant {
private:
	int strength;
public:
	Soldier(string designation, int strength) : Ant(designation), strength(strength) {}

	void Attack(Ant ant) {
		if (survive(5)) {
			cout << designation << " Survives the encounter!" << endl;
		}
		else {
			cout << designation << " died!" << endl;
		}
	}
};

class Worker : public Ant {
private:
	int capacity;
public:
	Worker(string designation, int capacity) : Ant(designation), capacity(capacity) {}

	void Work(int value) {
		cout << designation << " works for " << value << " minutes" << endl;
	}
};

class Forager : public Worker {
public:
	Forager(string designation = "Forager", int capacity = 2) : Worker(designation, capacity) {}

	// Overridden Funciton
	void Work(int value) {
		cout << designation << " searches for " << value << " minutes" << endl;
		Worker::Work(value);	// Function Chaining
	}
};

class Transporter : public Worker {
public:
	Transporter(string designation, int capacity) : Worker(designation, capacity) {}

	// Overridden Function
	void Work(int value) {
		cout << designation << " transports for " << value << " minutes" << endl;
	}
};

//Composition
class Colony {
private:
	Queen queen2;
public:
	void FeedQueen(int amount) {
		queen2.Eat(amount);
	}

	Queen& GetQueen() {
		return queen2;
	}
};

int main()
{
	// Ant Colony model

	/* Inheritance(general to specific)
	*  Relational Terms: parent/child or superclass/subclass or ancestor/descendant
	*  Semantic Terms: is a, is like a, is a kind of, etc.
	*  Directionality: unidirectional (one-way)
	*  Binding Strength: strong/tight
	*  UML symbols: empty arrow
	*/

	// Ant (designation, eat, work, ...)
	// Queen (breed)
	// Soldier (protect)
	// Worker
	// Foragers
	// Transporters

	Ant ant1("sugar Ant 01");
	ant1.Eat(1);

	Queen queen1("Sugar Queen");
	queen1.Eat(2);
	queen1.Breed(3);

	Soldier soldier1("Sugar Soldier", 4);
	soldier1.Attack(ant1);

	Worker worker1("Sugar Worker", 5);
	worker1.Work(6);
	Forager forager1("Sugar Forager", 7);
	forager1.Work(8);
	Transporter transporter1("Sugar Transporter", 9);
	transporter1.Work(10);

	/* Composition(one class exists as an integral part of another class)
	*  Objects live and die together
	*  Semantic Terms: has a, is a part of
	*  Directionality: Unidirectional (one-way)
	*  Binding Strength: strong/tight
	*  Lifetime: coincident (created and destroyed together
	*  Sharing: exclusive (whole does not share the part)
	*  UML symbols: filled diamond
	*/

	Colony colony1;
	colony1.FeedQueen(11);	// colony queen access needs to go through colony
	colony1.GetQueen().Eat(12);
}
