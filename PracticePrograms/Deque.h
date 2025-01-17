#pragma once

struct Node
{
	int value;
	Node* next;
	Node* prev;

	Node(int val) :value(val), next(nullptr), prev(nullptr) {};
};

class Deque
{
	Node* m_front;
	Node* m_rear;
	int m_size;

public:

	//Default constructor
	Deque();

	//Function to check if double ended queue is empty
	bool IsEmpty()const;

	//Function to get size of double ended queue
	int Size()const;

	//Function to add an element to the front of the deque
	void PushFront(const int value);

	//Function to add an element to the end of the deque
	void PushBack(const int value);

	//Function to remove an element from the front of the deque
	bool PopFront();

	//Function to remove an element from the front of the deque
	bool PopBack();

	//Function to get the value at the front of deque
	int Front()const;

	//Function to get the value at the back of deque
	int Back()const;

	//Function to display the deque element
	void Display()const;

	//Destructor
	~Deque();
};

