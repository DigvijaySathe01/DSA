#pragma once

class CircularQueue
{
	int m_size;
	int m_front;
	int m_rear;
	int* m_arr;

public:

	//Parameterized constructor
	CircularQueue(const int size);

	//Function to check if queue is empty
	bool IsEmpty()const;

	//Function to check if queue is full
	bool IsFull()const;

	//Function to insert an element in the queue
	void Enqueue(int value);

	//Function to remove element from the queue
	int Dequeue();

	//Destructor
	~CircularQueue();
};

