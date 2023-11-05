#include <iostream>
using namespace std;

struct Node {
	string data;	
	Node* nextpointer;	// Pointer which points at the next Node in the Linked List
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
	void Print() {
		if (!IsEmpty()) {
			Node* temp = toppointer;
			while (temp != nullptr) {
				cout << "(" << temp->data << ")" << endl;
				temp = temp->backpointer;
			}
			cout << endl;
		}
	}
};

int main()
{
	Stack stack;

	// adding Objects to list using Push Function
	stack.Push("Doctor Who");
	stack.Push("Lost");
	stack.Push("Dead Like Me");
	stack.Push("Pushing Daisies");
	stack.Push("Roswell");

	stack.Print(); // displayes the whole Stack using Print Function

	stack.Pop();	// Deletes the topmost Node on the Stack using Pop Function
	stack.Print();

	stack.Pop();
	stack.Print();

	cout << stack.Peek() << endl << endl;	// displayes the topmost Object on the Stack using the Peek Function
}