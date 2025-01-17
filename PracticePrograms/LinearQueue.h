#pragma once

class LinearQueue
{
	int m_size;
	int m_front;
	int m_rear;
	int* m_arr;

public:

	//Parameterized constructor;
	LinearQueue(const int size);

	//Function to check if the queue is empty
	bool IsEmpty()const;

	//Function to check if queue if full
	bool IsFull()const;

	//Function to add an elelement to the queue
	void Enqueue(const int value);

	//Function to remove an element from the queue
	int Dequeue();

	//Destructor
	~LinearQueue();
};

