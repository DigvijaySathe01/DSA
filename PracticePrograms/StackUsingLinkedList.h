#pragma once
#include "LinkedList.h"

class StackUsingLinkedList
{
	LinkedList m_list; 
	size_t m_count;

public:

	//Default constructor 
	StackUsingLinkedList() = default;

	//Function to push an element in the stack
	void Push(const int value);

	//Function to remove top element from the stack
	void Pop();

	//Function to get top element from the stack without removing it from the stack
	int Top()const;

	//Function to check if the stack is empty
	bool IsEmpty()const;

	//Function to get size of the stack
	size_t Size()const;

	//Destructor
	~StackUsingLinkedList()= default;
};

