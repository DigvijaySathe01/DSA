#include "StackUsingLinkedList.h"
#include <cassert>

//-----------------------------------------------------------------------------

void StackUsingLinkedList::Push(const int value)
{
	m_list.InsertAtStart(value);
	++m_count;
}

//-----------------------------------------------------------------------------

void StackUsingLinkedList::Pop()
{
	if (IsEmpty())
		assert(false && "Cannot pop, Stack is empty!!!");

	m_list.DeleteAtFirst();
	--m_count;
}

//-----------------------------------------------------------------------------

int StackUsingLinkedList::Top() const
{
	if (IsEmpty())
		assert(false && "Cannot get top element, Stack is empty()!!!");
	
	const Node* head = m_list.GetHead();
	return head->value;
}

//-----------------------------------------------------------------------------

bool StackUsingLinkedList::IsEmpty() const
{
	return m_count == 0;
}

//-----------------------------------------------------------------------------

size_t StackUsingLinkedList::Size() const
{
	return m_count;
}

//-----------------------------------------------------------------------------
