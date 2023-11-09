#include <iostream>
using namespace std;


class Ant {
private:
	string name;
	int workload;
public:
	Ant(string name, int workload) : name(name), workload(workload) {}	// Default Constructor

	friend ostream& operator<<(ostream& out, const Ant ant) {	// Overloaded Insertion Operator for ease of printing Objects
		out << ant.name << " (" << ant.workload << ") ";
		return out;
	}

	friend Ant operator+(const Ant ant1, const Ant ant2) {	// Overloaded Addition Operator for adding Variables using Template
		return Ant(ant1.name + ", " + ant2.name, ant1.workload + ant2.workload);
	}
};



struct Node {
	string data;
	Node* nextpointer;
};

class Stack {
private:
	Node* toppointer;	// used for keeping track of the Node currently at the top of the Stack
public:
	Stack() {	// Constructor
		toppointer = nullptr;
	}
	~Stack() {	// Destructor
		while (!IsEmpty()) {
			cout << "Destroying: " << Peek() << endl;
			Pop();
		}
	}

	void Push(string data) {	// adds data to the Stack
		Node* nodepointer = new Node{ data,nullptr };	// creates a new Node
		if (IsEmpty()) {	// if empty, add new Node
			toppointer = nodepointer;
		}
		else {	// if not empty, add to top and change Pointer
			nodepointer->nextpointer = toppointer;	// new node next Points to "old" top
			toppointer = nodepointer;	// top Pointer points to "new" top
		}
	}

	string Peek() {	// looks at the top item
		return toppointer->data;
	}

	// remove the top item
	void Pop() {
		if (!IsEmpty()) {
			Node* temp = toppointer;	// stores toppointer as temp
			toppointer = toppointer->nextpointer;	// moves toppointer to next Node
			delete temp;	// Delete "old" Node
		}
	}

	// check if Stack is empty
	bool IsEmpty() {
		return toppointer == nullptr;
	}

	// look at all items in the Stack
	friend ostream& operator<<(ostream& out, const Stack& stack);
};

ostream& operator<<(ostream& out, const Stack& stack) {
	Node* current = stack.toppointer;
	while (current != nullptr) {
		out << current->data << " ";
		current = current->nextpointer;
	}
	return out;
}

int main()
{
	Stack fruitstack;

	fruitstack.Push("Apple");
	fruitstack.Push("Banana");
	fruitstack.Push("Cantelope");
	fruitstack.Push("Durian");

	cout << fruitstack << endl;
}