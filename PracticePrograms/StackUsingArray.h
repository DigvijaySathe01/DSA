#pragma once

class StackUsingArray
{
	int* m_array;    // Pointer to dynamically allocated array for stack elements
	int m_size;      // Maximum size of the stack
	int m_top;       // Index of the topmost element in the stac

public:

	//Default constructor
	StackUsingArray();

	//Parameterized constructor
	StackUsingArray(int size);

	//Function to check whether the stack is empty
	bool IsEmpty()const;

	//Function to check whether the stack is full
	bool IsFull()const;

	//Function to push an element in the stack
	bool Push(int value);

	//Function to pop an element from the stack
	bool Pop();

	//Function to peek at given position in the stack
	int Peek(int position)const;

	//Function to get top element of the stack
	int StackTop()const;

	//Function to get bottom element of the stack
	int StackBottom()const;

	//Destructor
	~StackUsingArray();

};

