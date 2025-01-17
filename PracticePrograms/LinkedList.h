#pragma once

struct Node
{
	int value;
	Node* next;

	Node(int val) :value(val), next(nullptr) {};
};

class LinkedList
{
	Node* m_head{};

public:

	//Default costructor
	LinkedList();

	//Parameterized constructor
	LinkedList(int value);

	//Function to traverse the linked list
	void Traverse()const;

	//Function to search the given value in the linked list
	bool Search(int value)const;

	//Function to insert the given value at the start of linked list
	void InsertAtStart(int value);

	//Function to insert the given value at the end of linked list
	void InsertAtEnd(int value);

	//Function to insert after given node
	void InsertAfterGivenNode(int key, int value);

	//Function to delete first node of the linked list
	bool DeleteAtFirst();

	//Function to delete last node of the linked list
	bool DeleteLastNode();

	//Function to delete node after given node of the linked list
	bool DeleteNodeAfterGivenNode(int key);

	//Function to get head node of the linked list
	const Node* GetHead()const;

	//Destructor
	~LinkedList();
};

