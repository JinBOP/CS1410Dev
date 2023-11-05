#include <iostream>
using namespace std;

struct Node {
	string data;
	Node* nextpointer;	// Pointer which points at the next Node in the Linked List
};

class Queue {
private:
	Node* frontpointer;	// tracks the Node currently at the front of the Queue
	Node* backpointer;	// tracks the Node currently at the back of the Queue
	int count;			// keeps track of how many Objects are in the Queue
public:
	Queue() {	// Constructor
		frontpointer = nullptr;
		backpointer = nullptr;
		count = 0;
	}
	~Queue() {	// Destructor
		while (!IsEmpty()) {
			cout << "Destroying: " << Peek() << endl;
			DeQueue();
		}
	}

	void EnQueue(string data) {	// adds data to the Queue
		Node* nodepointer = new Node{ data,nullptr };	// creates a new Node
		if (IsEmpty()) {	// if empty, add new Node
			frontpointer = nodepointer;
			backpointer = nodepointer;
			count++;
		}
		else {	// if not empty, add to back and change Pointer
			nodepointer->nextpointer = backpointer;	// new node next Points to "old" front
			backpointer = nodepointer;	// back Pointer points to "new" front
			count++;	// incerements the number of total Objects in the Queue
		}
	}

	// remove the front item
	void DeQueue() {
		if (!IsEmpty()) {
			Node* temp = frontpointer;	// stores frontpointer as temp
			frontpointer = frontpointer->nextpointer;	// moves frontpointer to next Node
			delete temp;	// delete "old" Node
			count--;	// decrements the number of total Objects in the Queue
		}
	}

	string Peek() {	// looks at the front item
		if (!IsEmpty()) {
			return frontpointer->data;
		}
		else {
			return " ";
		}
	}

	// check if Queue is empty
	bool IsEmpty() {
		return frontpointer == nullptr;
	}

	// check the size of the Queue
	int Size() {
		return count;
	}

	// look at all items in the Queue
	void Print() {
		if (!IsEmpty()) {
			Node* temp = frontpointer;
			while (temp != nullptr) {
				cout << "(" << temp->data << ")";
				temp = temp->nextpointer;
			}
			cout << endl;
		}
		else {
			cout << "Queue is empty!" << endl;
		}
	}
};

int main()
{
	// Queue starts empty
	Queue Queue;
	Queue.Print();

	// Queue with 1 Node
	Queue.EnQueue("Apple");
	cout << Queue.Size() << " item(s): ";
	Queue.Print();

	// removing 1 Node, Queue becomes empty
	Queue.DeQueue();
	Queue.Print();

	// trying to Dequeue from empty Queue
	Queue.DeQueue();

	// trying to Peek empty Queue
	Queue.Peek();

	// adding 3 Nodes
	Queue.EnQueue("Banana");
	Queue.EnQueue("Cherry");
	Queue.EnQueue("Date");
	cout << Queue.Size() << " item(s): ";
	Queue.Print();

	// removing 1 Node
	Queue.DeQueue();
	cout << Queue.Size() << " item(s): ";
	Queue.Print();

	// adding 1 additional Node
	Queue.EnQueue("Elderberry");
	cout << Queue.Size() << " item(s): ";
	Queue.Print();

	// Peeking first Node
	cout << "Peek: " << Queue.Peek() << endl;
}