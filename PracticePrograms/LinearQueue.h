#pragma once
class LinearQueue
{
	int* m_arr;    
	size_t m_size;
	size_t m_front;
	size_t m_rear;

public:

	//Parameterized constructor
	LinearQueue(size_t size);

	//Function to check if queue if empty
	bool IsEmpty()const;

	//Function to check if queue if full
	bool IsFull()const;

	//Function to add element in the queue
	bool Enqueue(int value);

	//Function to add element in the queue
	int Dequeue();

	//Function to get number of elelments in the queue
	size_t Size()const;

	//Function to get front element in the queue
	int Front()const;

	//Function to get rear element in the queue
	int Rear()const;

	//Function to print queue
	void Print()const;

	//Destructor
	~LinearQueue();
};

