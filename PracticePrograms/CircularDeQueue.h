#pragma once
class CircularDeQueue
{
	int* m_arr;
	size_t m_size;
	size_t m_front;
	size_t m_rear;

public:

	//Parameterized constructor
	CircularDeQueue(size_t size);

	//Function to check if queue is empty
	bool IsEmpty()const;

	//Function to check if queue is full
	bool IsFull()const;

	//Function to enqueue element from front
	bool EnqueueFront(int value);

	//Function to enqueue element from rear
	bool EnqueueRear(int value);

	//Function to dequeue element from front
	int DequeueFront();

	//Function to dequeue an element from rear
	int DequeueRear();

	//Function to get number of element in queue
	size_t Size()const;

	//Function to print queue
	void Print()const;

	//Destructor
	~CircularDeQueue();

};

