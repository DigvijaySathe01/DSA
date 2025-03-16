#include "CircularQueue.h"
#include <cassert>
#include <iostream>

//-----------------------------------------------------------------------------

CircularQueue::CircularQueue(size_t size)
{
	assert(size > 0 && "Queue size must be greater than zero!!!");
	m_size = size;
	m_arr = new int[m_size];
	m_front = -1;
	m_rear = -1;
}

//-----------------------------------------------------------------------------

bool CircularQueue::IsEmpty() const
{
	return m_front == -1;
}

//-----------------------------------------------------------------------------

bool CircularQueue::IsFull() const
{
	return ((m_rear + 1) % m_size == m_front);
}

//-----------------------------------------------------------------------------

bool CircularQueue::Enqueue(int value)
{
	if (IsFull())
	{
		assert(false && "Cannot enqueue an element, queue is already full!!!");
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

int CircularQueue::Dequeue()
{
	if (IsEmpty())
	{
		assert(false && "Cannot dequeue an element, queue is empty()!!!");
		return -1;
	}

	int ans = m_arr[m_front];

	if (m_front == m_rear)
	{
		m_front = m_rear = -1;  // Queue becomes empty
	}
	else
	{
		m_front = (m_front + 1) % m_size;
	}

	return ans;
}

//-----------------------------------------------------------------------------

int CircularQueue::Front() const
{
	if (IsEmpty())
	{
		assert(false && "Cannot get front element, queue is empty!!!");
		return -1;
	}
	return m_arr[m_front];
}

//-----------------------------------------------------------------------------

int CircularQueue::Rear() const
{
	if (IsEmpty())
	{
		assert(false && "Cannot get rear element, queue is empty!!!");
		return -1;
	}
	return m_arr[m_rear];
}

//-----------------------------------------------------------------------------

void CircularQueue::Print() const
{
	if (IsEmpty())
	{
		std::cout << "Cannot print the queue, queue is empty!!!\n";
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

size_t CircularQueue::Size() const
{
	if (IsEmpty())
		return 0;

	if (m_rear >= m_front)
		return m_rear - m_front + 1;
	else
		return m_size - m_front + m_rear + 1;
}

//-----------------------------------------------------------------------------
