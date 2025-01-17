#include "CircularLinkedList.h"
#include <iostream>

//-----------------------------------------------------------------------------

CircularLinkedList::CircularLinkedList()
{
	m_head = nullptr;
}

//-----------------------------------------------------------------------------

CircularLinkedList::CircularLinkedList(int value)
{
	m_head = new Node(value);
	m_head->next = m_head;
}

//-----------------------------------------------------------------------------

void CircularLinkedList::Traverse() const
{
	if (!m_head)
	{
		std::cout << "Circular linked list is empty\n";
		return;
	}

	Node* tempNode = m_head;
	do
	{
		std::cout << tempNode->value << "->";
		tempNode = tempNode->next;

	} while (tempNode != m_head);

	std::cout << "\n";
}

//-----------------------------------------------------------------------------

Node* CircularLinkedList::Search(int value) const
{
	if(!m_head)
	{
		std::cout << "Curcular linked list is empty\n";
		return nullptr;
	}

	Node* tempNode = m_head;
	do
	{
		if (tempNode->value == value)
			return tempNode;

		tempNode = tempNode->next;
	} while (tempNode != m_head);

	return nullptr;
}

//-----------------------------------------------------------------------------

void CircularLinkedList::InsertAtStart(int value)
{
	Node* newNode = new Node(value);

	if (!m_head)
	{
		m_head = newNode;
		m_head->next = m_head;
		return;
	}

	Node* tempNode = m_head;
	while (tempNode->next != m_head)
	{
		tempNode = tempNode->next;
	}

	tempNode->next = newNode;
	newNode->next = m_head;
	m_head = newNode;
}

//-----------------------------------------------------------------------------

void CircularLinkedList::InsertAtEnd(int value)
{
	Node* newNode = new Node(value);

	if (!m_head)
	{
		m_head = newNode;
		m_head->next = m_head;
		return;
	}

	Node* tempNode = m_head;
	while (tempNode->next != m_head)
	{
		tempNode = tempNode->next;
	}

	tempNode->next = newNode;
	newNode->next = m_head;
}

//-----------------------------------------------------------------------------

void CircularLinkedList::InsertNodeAfterGivenNode(int key, int value)
{
	Node* nodeToFind = Search(key);
	if (!nodeToFind)
	{
		std::cout << "Node with given key not found in linked list\n";
		return;
	}
	Node* newNode = new Node(value);
	newNode->next = nodeToFind->next;
	nodeToFind->next = newNode;
}

//-----------------------------------------------------------------------------

bool CircularLinkedList::DeleteFirstNode()
{
	if(!m_head)
	{
		std::cout << "Curcular linked list is empty\n";
		return false;
	}
	Node* tempNode = m_head;
	while (tempNode->next != m_head)
	{
		tempNode = tempNode->next;
	}

	if (tempNode == m_head)
	{
		delete m_head;
		m_head = nullptr;
		return true;
	}

	tempNode->next = m_head->next;
	delete m_head;
	m_head = tempNode->next;
		
	return true;
}

//-----------------------------------------------------------------------------

bool CircularLinkedList::DeleteLastNode()
{
	if (!m_head)
	{
		return false;
	}

	if (m_head->next == m_head)
	{
		delete m_head;
		m_head = nullptr;
		return true;
	}

	Node* tempNode = m_head;
	while (tempNode->next->next != m_head)
		tempNode = tempNode->next;

	Node* lastNode = tempNode->next;
	tempNode->next = m_head;
	delete lastNode;

	return true;
}

//-----------------------------------------------------------------------------

bool CircularLinkedList::DeleteGivenNode(int key)
{
	if (!m_head)
	{
		std::cout << "Circular linked list is empty.\n";
		return false;
	}

	Node* nodeToDelete = Search(key);
	if (!nodeToDelete)
	{
		std::cout << "Key not found in the circular linked list.\n";
		return false;
	}

	if (nodeToDelete == m_head && m_head->next == m_head)
	{
		delete m_head;
		m_head = nullptr;
		return true;
	}

	Node* tempNode = m_head;
	while (tempNode->next != nodeToDelete)
	{
		tempNode = tempNode->next;
	}

	tempNode->next = nodeToDelete->next;

	if (nodeToDelete == m_head)
		m_head = nodeToDelete->next;

	delete nodeToDelete;
	return true;
}

//-----------------------------------------------------------------------------

CircularLinkedList::~CircularLinkedList()
{
	if (!m_head)
		return;

	Node* iterator = m_head;

	do
	{
		Node* temp = iterator;
		iterator = iterator->next; 
		delete temp;              
	} while (iterator != m_head);

	m_head = nullptr;
}

//-----------------------------------------------------------------------------



