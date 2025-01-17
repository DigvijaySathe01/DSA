#include "LinearQueue.h"
#include "cassert"

//-----------------------------------------------------------------------------

LinearQueue::LinearQueue(const int size)
{
	m_size = size;
	m_front = m_rear = -1;
	m_arr = new int(m_size);
}

//-----------------------------------------------------------------------------

bool LinearQueue::IsEmpty() const
{
	return m_front == m_rear;
}

//-----------------------------------------------------------------------------

bool LinearQueue::IsFull() const
{
	return m_rear == m_size - 1;
}

//-----------------------------------------------------------------------------

void LinearQueue::Enqueue(const int value)
{
	if(IsFull())
	{
		assert(false && "Cannot add element, queue is full!!!");
		return;
	}

	m_arr[++m_rear] = value;
}

//-----------------------------------------------------------------------------

int LinearQueue::Dequeue()
{
	if (IsEmpty())
	{
		assert(false && "Cannot remove element, queue is empty!!!");
		return -1;
	}

	return m_arr[++m_front];
}

//-----------------------------------------------------------------------------

LinearQueue::~LinearQueue()
{
	delete[] m_arr;
}

//-----------------------------------------------------------------------------




