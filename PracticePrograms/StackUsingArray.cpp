#include "StackUsingArray.h"
#include <iostream>

//-----------------------------------------------------------------------------

StackUsingArray::StackUsingArray()
{
	m_size = 0;
	m_top = -1;
	m_array = nullptr;
}

//-----------------------------------------------------------------------------

StackUsingArray::StackUsingArray(int size)
{
	m_size = size;
	m_top = -1;
	m_array = new int(m_size);
}

//-----------------------------------------------------------------------------

bool StackUsingArray::IsEmpty() const
{
	if (m_top == -1)
		return true;

	return false;
}

//-----------------------------------------------------------------------------

bool StackUsingArray::IsFull() const
{
	if (m_top == m_size - 1)
		return true;

	return false;
}

//-----------------------------------------------------------------------------

bool StackUsingArray::Push(int value)
{
	if (IsFull())
	{
		std::cout << "Can't push, stack is full!!!\n";
		return false;
	}
	m_top++;
	m_array[m_top] = value;
	return false;
}

//-----------------------------------------------------------------------------

bool StackUsingArray::Pop()
{
	if (IsEmpty())
	{
		std::cout << "Can't pop stack is empty!!!\n";
		return false;
	}
	--m_top;
	return false;
}

//-----------------------------------------------------------------------------

int StackUsingArray::Peek(int position) const
{
	int index = m_top - position + 1;
	if (index < 0)
	{
		std::cout << "Invalid position!!!\n";
		return -1;
	}

	return m_array[index];
}

//-----------------------------------------------------------------------------

int StackUsingArray::StackTop() const
{
	if (IsEmpty())
	{
		std::cout << "Stack is empty!!!\n";
		return -1;
	}

	return m_array[m_top];
}

//-----------------------------------------------------------------------------

int StackUsingArray::StackBottom() const
{
	if (IsEmpty())
	{
		std::cout << "Stack is empty!!!\n";
		return -1;
	}
	return m_array[0];
}

//-----------------------------------------------------------------------------

StackUsingArray::~StackUsingArray()
{
	if (m_array)
		delete[] m_array;
}

//-----------------------------------------------------------------------------


