#include "CircularQueue.h"
#include <cassert>

//-----------------------------------------------------------------------------

CircularQueue::CircularQueue(const int size)
{
	m_size = size;
	m_front = m_rear = 0;
	m_arr = new int(m_size);
}

bool CircularQueue::IsEmpty() const
{
	return m_front == m_rear;
}

bool CircularQueue::IsFull() const
{
	return (m_rear + 1) % m_size == m_front;
}

void CircularQueue::Enqueue(int value)
{
	if (IsFull())
	{
		assert(false && "Cannot add element, Queue is full!!!");
		return;
	}

	m_rear = (m_rear + 1) % m_size;
	m_arr[m_rear] = value;
}

int CircularQueue::Dequeue()
{
	if (IsEmpty())
	{
		assert(false && "Cannot remove element, Queue is empty!!!");
		return -1;
	}

	m_front = (m_front + 1) % m_size;
	return m_arr[m_front];
}

CircularQueue::~CircularQueue()
{
	delete[] m_arr;
}

//-----------------------------------------------------------------------------
