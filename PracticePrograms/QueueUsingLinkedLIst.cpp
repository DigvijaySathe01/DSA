#include "QueueUsingLinkedLIst.h"
#include <cassert>
#include <iostream>

//-----------------------------------------------------------------------------

QueueUsingLinkedLIst::QueueUsingLinkedLIst():m_front(nullptr),m_rear(nullptr),m_size(0)
{
}

//-----------------------------------------------------------------------------

QueueUsingLinkedLIst::QueueUsingLinkedLIst(int value)
{
	Node* node = new Node(value);
	m_front = m_rear = node;
	m_size = 1;
}

//-----------------------------------------------------------------------------

bool QueueUsingLinkedLIst::IsEmpty() const
{
	return m_front == nullptr;
}

//-----------------------------------------------------------------------------

int QueueUsingLinkedLIst::Size() const
{
	return m_size;
}

//-----------------------------------------------------------------------------

void QueueUsingLinkedLIst::Enqueue(int value)
{
	Node* node = new Node(value);

	if (IsEmpty())
	{
		m_front = m_rear = node;
	}
	else
	{
		m_rear->next = node;
		m_rear = node;
	}

	++m_size;
}

//-----------------------------------------------------------------------------

bool QueueUsingLinkedLIst::Dequeue()
{
	if (IsEmpty())
	{
		assert(false && "Queue is empty, cannot dequeue!!!");
		return false;
	}

	Node* temp = m_front;
	m_front = m_front->next;
	delete temp;

	if (!m_front)
		m_rear = nullptr;

	--m_size;

	return true;
}

//-----------------------------------------------------------------------------

int QueueUsingLinkedLIst::Peek() const
{
	if (IsEmpty())
	{
		assert(false && "Cannot peek, queue is empty!!!");
		return -1;
	}

	return m_front->value;
}

//-----------------------------------------------------------------------------

void QueueUsingLinkedLIst::Display() const
{
	if (IsEmpty())
	{
		std::cout << "Queue is empty!!!";
	}

	Node* temp = m_front;

	while (temp != nullptr)
	{
		std::cout << temp->value<<" ";
		temp = temp->next;
	}
}

//-----------------------------------------------------------------------------

QueueUsingLinkedLIst::~QueueUsingLinkedLIst()
{
	while (!IsEmpty())
	{
		Dequeue();
	}
}

//-----------------------------------------------------------------------------


