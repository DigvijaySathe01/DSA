#include "LinkedList.h"
#include "iostream"

//-----------------------------------------------------------------------------

LinkedList::LinkedList()
{
	m_head = nullptr;
}

//-----------------------------------------------------------------------------

LinkedList::LinkedList(int value)
{
	m_head = new Node(value);
}

//-----------------------------------------------------------------------------

void LinkedList::Traverse() const
{
	Node* temp = m_head;
	while (temp != nullptr)
	{
		std::cout << temp->value << "->";
		temp = temp->next;
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------

bool LinkedList::Search(int value) const
{
	Node* temp = m_head;

	while (temp != nullptr)
	{
		if (temp->value == value)
			return true;

		temp = temp->next;
	}

	return false;
}

//-----------------------------------------------------------------------------

void LinkedList::InsertAtStart(int value)
{
	Node* tempNode = new Node(value);
	tempNode->next = m_head;
	m_head = tempNode;
}

//-----------------------------------------------------------------------------

void LinkedList::InsertAtEnd(int value)
{
	Node* newNode = new Node(value);
	if (m_head == nullptr)
	{
		m_head = newNode;
		return;
	}

	Node* tempNode = m_head;
	while (tempNode->next != nullptr)
	{
		tempNode = tempNode->next;
	}

	tempNode->next = newNode;
}

//-----------------------------------------------------------------------------

void LinkedList::InsertAfterGivenNode(int key, int value)
{
	Node* tempNode = m_head;

	while (tempNode != nullptr)
	{
		if (tempNode->value == value)
			break;
	}

	if (tempNode == nullptr)
	{
		std::cout << "Node with give key value is not present in the linked list\n";
		return;
	}

	Node* newNode = new Node(value);
	newNode->next = tempNode->next;
	tempNode->next = newNode;

}

//-----------------------------------------------------------------------------

bool LinkedList::DeleteAtFirst()
{
	if (m_head == nullptr)
	{
		std::cout << "cannot delete, linked list is empty\n";
		return false;
	}
	Node* tempNode = m_head;
	m_head = m_head->next;
	delete tempNode;
	return true;
}

//-----------------------------------------------------------------------------

bool LinkedList::DeleteLastNode()
{
	if (m_head == nullptr)
	{
		std::cout << "cannot delete, linked list is empty\n";
		return false;
	}

	Node* tempNode = m_head;
	while (tempNode != nullptr && tempNode->next != nullptr)
		tempNode = tempNode->next;

	if (tempNode->next == nullptr)
	{
		delete tempNode;
		m_head = nullptr;
		return true;
	}

	delete tempNode->next;
	tempNode->next = nullptr;
	return true;;
}

//-----------------------------------------------------------------------------

bool LinkedList::DeleteNodeAfterGivenNode(int key)
{
	if (m_head == nullptr)
	{
		std::cout << "cannot delete, linked list is empty\n";
		return false;
	}

	Node* tempNode = m_head;
	while (tempNode != nullptr && tempNode->next != nullptr)
	{
		if (tempNode->value == key)
			break;

		tempNode = tempNode->next;
	}
	if (tempNode == nullptr)
	{
		std::cout << "Node with given key is not present in the linked list\n";
		return false;
	}

	if (tempNode->next == nullptr)
	{
		std::cout << "There is no node after given node in the linked list\n";
		return false;
	}

	Node* temp = tempNode->next;
	tempNode->next = tempNode->next->next;
	delete temp;
	return true;
}

//-----------------------------------------------------------------------------

const Node* LinkedList::GetHead() const
{
	return m_head;
}

//-----------------------------------------------------------------------------

LinkedList::~LinkedList()
{
	while (m_head != nullptr)
	{
		Node* tempNode = m_head;
		m_head = m_head->next;
		delete tempNode;
	}
}

//-----------------------------------------------------------------------------


