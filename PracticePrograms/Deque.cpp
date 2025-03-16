#include "Deque.h"
#include <iostream>

//-----------------------------------------------------------------------------

Deque::Deque():m_front(nullptr), m_rear(nullptr), m_size(0)
{
}

//-----------------------------------------------------------------------------

bool Deque::IsEmpty() const
{
	return m_front == nullptr;
}

//-----------------------------------------------------------------------------

int Deque::Size() const
{
	return m_size;
}

//-----------------------------------------------------------------------------

void Deque::PushFront(const int value)
{
	Node* node = new Node(value);

	if (IsEmpty())
	{
		m_front = m_rear = node;
	}
	else
	{
		node->next = m_front;
		m_front->prev = node;
		m_front = node;
	}
	++m_size;
}

//-----------------------------------------------------------------------------

void Deque::PushBack(const int value)
{
	Node* node = new Node(value);

	if (IsEmpty())
	{
		m_front = m_rear = node;
	}
	else
	{
		m_rear->next = node;
		node->prev = m_rear;
		m_rear = node;
	}
	++m_size;
}

//-----------------------------------------------------------------------------

bool Deque::PopFront()
{
	if (IsEmpty())
	{
		std::cerr << "Cannot pop, deque is empty!!!";
		return false;
	}
	
	Node* temp = m_front;
	m_front = m_front->next;
	if (m_front)
	{
		m_front->prev = nullptr;
	}
	else
	{
		m_rear = nullptr;
	}

	delete temp;
	--m_size;
	return true;
}

//-----------------------------------------------------------------------------

bool Deque::PopBack()
{
	if (IsEmpty())
	{
		std::cerr << "Cannot pop, deque is empty!!!";
		return false;
	}
	
	Node* temp = m_rear;
	m_rear = m_rear->prev;

	if (m_rear)
	{
		m_rear->next = nullptr;
	}
	else
	{
		m_front = nullptr;
	}

	delete temp;
	--m_size;

	return true;;
}

//-----------------------------------------------------------------------------

int Deque::Front() const
{
	if (IsEmpty())
	{
		std::cerr << "Deque is empty, cannot get front!!!";
		return -1;
	}

	return m_front->value;
}

//-----------------------------------------------------------------------------

int Deque::Back() const
{
	if (IsEmpty())
	{
		std::cerr << "Deque is empty, cannot get rear!!!";
		return -1;
	}

	return m_rear->value;
}

//-----------------------------------------------------------------------------

void Deque::Display() const
{
	if (IsEmpty())
	{
		std::cout << "Deque is empty!!!";
		return;
	}

	Node* temp = m_front;
	while (temp)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
}

//-----------------------------------------------------------------------------

Deque::~Deque()
{
	while (!IsEmpty())
	{
		PopFront();
	}
}

//-----------------------------------------------------------------------------

