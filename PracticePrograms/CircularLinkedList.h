#pragma once

struct Node
{
	int value{};
	Node* next{};

	Node(int val) :value(val), next(nullptr) {};
};

class CircularLinkedList
{
	Node* m_head{};

public:

	//Default constructor
	CircularLinkedList();

	//Parameterized constructor
	CircularLinkedList(int value);

	//Function to traverse circular linked list
	void Traverse()const;

	//Function to search node in the circular linked list
	Node* Search(int value)const;

	//Function to insert element at start in circular linked list
	void InsertAtStart(int value);

	//Function to insert element at end in circular linked list
	void InsertAtEnd(int value);

	//Function to insert element after the given node in circular linked list
	void InsertNodeAfterGivenNode(int key, int value);

	//Function to delete first node in circular linked list
	bool DeleteFirstNode();

	//Function to delete last node in circular linked list
	bool DeleteLastNode();

	//Function to delete node after given node in circular linked list
	bool DeleteGivenNode(int key);

	//Destructor
	~CircularLinkedList();
};

