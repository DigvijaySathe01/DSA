#include "CircularDeQueue.h"
#include <iostream>
#include <cassert>

//-----------------------------------------------------------------------------

CircularDeQueue::CircularDeQueue(size_t size)
{
	assert(size > 0 && "Size of the queue should be greater than zero!!!");
	m_size = size;
	m_arr = new int[size];
	m_front = m_rear = -1;
}

//-----------------------------------------------------------------------------

bool CircularDeQueue::IsEmpty() const
{
	return m_front == -1;
}

//-----------------------------------------------------------------------------

bool CircularDeQueue::IsFull() const
{
	return ((m_rear + 1) % m_size == m_front);
}

//-----------------------------------------------------------------------------

bool CircularDeQueue::EnqueueFront(int value)
{
	if (IsFull())
	{
		assert(false && "Cannot enqueue an element at front, queue is full!!!");
		return false;
	}
	if (IsEmpty())
	{
		m_front = m_rear = 0;
	}
	else if (m_front == 0 && (m_rear != m_size - 1))
	{
		m_front = m_size - 1;
	}
	else
	{
		--m_front;
	}
	m_arr[m_front] = value;
	return true;
}

//-----------------------------------------------------------------------------

bool CircularDeQueue::EnqueueRear(int value)
{
	if (IsFull())
	{
		assert(false && "Cannot enqueue an element at rear, queue is full!!!");
		return false;
	}
	if (IsEmpty())
	{
		m_front = m_rear = 0;
	}
	else
	{
		m_rear = (m_rear + 1) % m_size;
	}
	m_arr[m_rear] = value;
	return true;
}

//-----------------------------------------------------------------------------

int CircularDeQueue::DequeueFront()
{
	if (IsEmpty())
	{
		assert(false && "Cannot dequeue an element from queue, queue is empty!!!");
		return -1;
	}

	int ans = m_arr[m_front];
	if (m_front == m_rear)
	{
		m_front = m_rear = -1;
	}
	else
	{
		m_front = (m_front + 1) % m_size;
	}
	return ans;
}

//-----------------------------------------------------------------------------

int CircularDeQueue::DequeueRear()
{
	if (IsEmpty())
	{
		assert(false && "Cannot dequeue an element from queue, queue is empty!!!");
		return -1;
	}

	int ans = m_arr[m_rear];
	if (m_front == m_rear)
		m_front = m_rear = -1;
	else if (m_rear == 0 && m_front != m_size - 1)
	{
		m_rear = m_size - 1;
	}
	else
	{
		--m_rear;
	}
	return ans;
}

//-----------------------------------------------------------------------------

size_t CircularDeQueue::Size() const
{
	if (IsEmpty())
		return 0;

	if (m_rear >= m_front)
		return m_rear - m_front + 1;
	else
		return m_size - (m_front - m_rear - 1);
}

//-----------------------------------------------------------------------------

void CircularDeQueue::Print() const
{
	if (IsEmpty())
	{
		std::cout << "Queue is Empty\n";
		return;
	}

	size_t index = m_front;
	while (true)
	{
		std::cout << m_arr[index] << " ";
		if (index == m_rear)
			break;
		index = (index + 1) % m_size;
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

CircularDeQueue::~CircularDeQueue()
{
	delete[] m_arr;
}

//-----------------------------------------------------------------------------


