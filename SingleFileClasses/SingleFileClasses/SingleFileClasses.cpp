#include <iostream>
using namespace std;

class Avatar {	// class (class name){};
private:	// Visability (public, private, protected)
	// V Attributes V
	string name;
	int health = 20;
	int maxhealth = 20;
	int strength = 50;

	// Classes have a Default Constructor (if no other constructor is used, default is used)
public:
	Avatar() {	// Self made default Constructor
		name = "Anonymous";
	}
	
	Avatar(string aname) {	// Constructors	MUST be public
		name = aname;
	}

	Avatar(string aname, int ahealth, int astrength = 100) : name(aname), health(ahealth), strength(astrength) {
		maxhealth = health;
	}
		// Can set defaul values within parenthases
		// Can use : var1(avar1), var2(avar2) in order to initialize easier

	// Accessor/Mutator (Getter/Setter) Functions
	string GetName() {	// Getter Function
		return name;
	}

	int GetHealth() {	// Getter Function
		return health;
	}

	int GetStrength() {	// Getter Function
		return strength;
	}

	void SetName(string aname) {	// Setter Function
		name = aname;
	}

	void SetHealth(int ahealth) {	// Setter Function
		health = ahealth;

		if (health < 0) {
			health = 0;
		}
	}

	// Member Functions
	void PrintFormattedHealth() {
		cout << name << ": ";

		for (int i = 0; i < health; i++) {
			cout << "<3";
		}

		for (int i = health; i < maxhealth; i++) {
			cout << "-";
		}

		cout << endl;
	}

	void Attack(Avatar &enemy) {
		int damage = ComputeDamage();
		cout << this->name << " hits " << enemy.name << " for " << damage << " points!";	// 'this' refers to the caller
		enemy.SetHealth(enemy.health - damage);	// Updates health after attack
	}

private:
	int ComputeDamage() {	// Helper Function
		int damage = rand() % int(strength * .25) + 1;
		// Other code to figure out damage
		return damage;
	}
};

int main()
{
	Avatar player("Phoenix");	// creates Object player from Class Avatar

	Avatar EnemySet[5];

	EnemySet[0] = Avatar("Zombie", 20);
	EnemySet[1] = Avatar("Wraith", 13, 12);
	EnemySet[2] = Avatar("Gelatin", 50, 100);
	EnemySet[3] = Avatar("Skeleton", 10, 10);
	EnemySet[4] = Avatar("Skeleton", 10, 10);

	int re = rand() % 5;
	Avatar enemy = EnemySet[re];
	cout << player.GetName() + " encounters " + enemy.GetName() << endl;
	bool flee = false;

	do {
		player.PrintFormattedHealth();
		enemy.PrintFormattedHealth();
		cout << "(A)ttack or (R)un? ";
		char response;
		cin >> response;

		if (response == 'A') {
			player.Attack(enemy);
		}
		else {
			cout << "You run like a coward!";
			flee = true;
		}

		if (enemy.GetHealth() > 0 && !flee) {
			cout << enemy.GetName() << " prepares an attack!";
			cout << "(S)tay or (R)un? ";
			cin >> response;

			if (response == 'S') {
				enemy.Attack(player);
			}
			else {
				cout << "You run like a coward!";
				flee = true;
			}
		}
		else {

		}
	} while (player.GetHealth() > 0 && enemy.GetHealth() > 0 && !flee);

	player.PrintFormattedHealth();
	enemy.PrintFormattedHealth();

	if (enemy.GetHealth() > 0) {
		cout << enemy.GetName() << " prevails!";
	}
	else {
		cout << enemy.GetName() << " prevails!";
	}

	/*cout << player.GetName() << endl;

	cout << player.GetStrength() << endl;
	
	cout << Enemy3.GetName() << endl;
	
	cout << Enemy3.GetStrength() << endl;
	
	player.PrintFormattedHealth();

	player.Attack(Enemy2);
	player.PrintFormattedHealth();
	*/

	/* Object-Oriented Programming(OOP): Problem solving by modeling after real world
	* Extensible: can create own types, classes, objects, etc. to expand upon the language
	* 
	* 3 faucets of OOP:
	*	1 - Encapsulation
	*	2 - Inheritance
	*	3 - Polymorphism
	* 
	* Class: describe objects with the same attributes (properties) and operations (functions)
	* a class is like a blueprint for a house, it has the specifies the house details but isn't the house itself
	* 
	* Classes generally have 3 parts (not required):
	*	1 - Attributes (member values): properties of an Object
	*	2 - Constructors: how you instantiate (create) an Object from a Class
	*	3 - Member Functions: what the Object does
	* 
	* Feature Visability:
	*	1 - Public: access is available throughout the program
	*	2 - Private: access is restricted to the defining Class
	*	3 - Protected: access is the defining Class and any SubClasses
	*/

}


