#include <iostream>
using namespace std;

#define MAX_HEALTH 25
const int MAX_STAMINA = 30;

enum { // Enumerations automatically count up by 1 between variables, 0 > 1 > 2 > 3 > etc...
	STRENGTH, CHARM, DEFENSE, ATTACK, LOOKS // These are integer constants and hold integer values
}; // Can be set equal to a certain value

enum Color { RED, YELLOW, BLUE, GREEN, WILD}; // Enumerations can be named

struct Point {
	int x;
	int y;
};

struct UnoCard {
	int value;
	Color color; // Structures can house Enumerations and other Structures
};

struct Book {
	string author;
	string title;
	double price = 19.99; // Default values can be set
	int number{}; // Value Initialization sets something rather than nothing so no garbage is displayed when value is missing
};

void PrintBook(Book book);

int main()
{
	/* Aggregate Data : grouping data
	* C++ is meant to be an extensible language
	* Enumerations: a set of integer constants, good for code readability,
	* Any Constants should be all caps and underscore for word seperation
	* PascalCase, camelCase, snake_case, CAPS_CASE
	*/
	cout << "Strength:" << STRENGTH << endl;
	cout << "Charm:" << CHARM << endl;
	cout << "Defense:" << DEFENSE << endl;
	cout << "Attack:" << ATTACK << endl;
	cout << "Looks:" << LOOKS << endl;

	Color card1 = RED;
	Color card2 = BLUE;

	/* Structures: containers for storing, organizing, transporting, and accessing data
	*/
	Point pointa = { 5,6 }; // Condensed way of assigning Structure variables
	Point pointb;
	pointb.x = 5; // Specific way of assigning Structure variables
	pointb.y = 6;

	UnoCard card3 = { 6,BLUE };
	UnoCard card4;
	card4.value = rand() % 9;
	card4.color = RED;

	Book book1 = { "Petrie", "The Breaker", 17.99, 97818 }; // Copy-List Initialization
	Book book2 { "Baldacci", "Walk The Wire", 18.99, 43344 }; // List Initialization
	Book book3; // Define, then Initialize
	book3 = {"Slaughter", "False Witness", 16.99, 97800};
	Book book4;
	book4.author = "Child";

	PrintBook(book1);
	PrintBook(book2);
	PrintBook(book3);
	PrintBook(book4);

	// Copying a Structure
	Book book6 = book1;
	book6.title = "The Iceman";

	PrintBook(book6);
}

void PrintBook(Book book) {
	cout << "Author:" << book.author << endl;
	cout << "Title:" << book.title << endl;
	cout << "Price:" << book.price << endl;
	cout << "Number:" << book.number << endl << endl;
}
// A Structure can be a return type for a Function