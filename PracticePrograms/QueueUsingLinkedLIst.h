#pragma once

struct Node
{
	int value;
	Node* next;

	Node(int val) : value(val), next(nullptr) {}
};

class QueueUsingLinkedLIst
{
	Node* m_front;
	Node* m_rear;
	int m_size;

public:

	//Default constructor
	QueueUsingLinkedLIst();
	
	//Parameterized constructor
	QueueUsingLinkedLIst(int value);

	//Function to check if queue is empty
	bool IsEmpty()const;

	//Function to get size of the queue
	int Size()const;

	//Function to insert an element in the queue
	void Enqueue(int value);

	//Function to Dequeue an element from the queue
	bool Dequeue();

	//Function to get front element without removing it 
	int Peek()const;

	//Function to display the queue elements
	void Display()const;
	
	//Destructor
	~QueueUsingLinkedLIst();
};

