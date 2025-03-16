#pragma once

class CircularQueue
{
	int* m_arr;
	size_t m_size;
	size_t m_front;
	size_t m_rear;

public:

	//Parameterized constructor
	CircularQueue(size_t size);

	//Function to check if queue is empty
	bool IsEmpty()const;

	//Function to check if queue is full
	bool IsFull()const;

	//Function to enqueue an element in the queue
	bool Enqueue(int value);

	//Function to dequeue an element in the queue
	int Dequeue();

	//Function to get the front element in the queue
	int Front()const;

	//Function to get the rear element in the queue
	int Rear()const;

	//Function to print the queue
	void Print()const;

	//Function to get number of elements in the queue
	size_t Size()const;

	//Destructor
	~CircularQueue();
};