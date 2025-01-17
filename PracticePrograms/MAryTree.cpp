#include "MAryTree.h"
#include <iostream>
#include <queue>

MAryTree::MAryTree(const int numChildren):m_root(nullptr), m_numChildren(numChildren)
{
}

bool MAryTree::IsEmpty() const
{
	return m_root == nullptr;
}

void MAryTree::LevelOrderTraversal() const
{
	if (IsEmpty())
	{
		std::cout << "Tree is empty!!!";
		return;
	}

	std::queue<Node*> q;
	q.push(m_root);

	while (!q.empty())
	{
		int levelSize = (int)q.size();
		while (levelSize--)
		{
			Node* current = q.front();
			q.pop();
			std::cout << current->value << " ";
			for (Node* child : current->children)
			{
				q.push(child);
			}
		}
		std::cout << "\n";
	}
}

void MAryTree::Insert(const int value)
{
	Node* node = new Node(value, m_numChildren);

	if (IsEmpty())
	{
		m_root = node;
		return;
	}
	
	std::queue<Node*> q;
	q.push(m_root);

	while (!q.empty())
	{
		Node* current = q.front();
		q.pop();

		if (current->children.size() < m_numChildren)
		{
			current->children.push_back(node);
			return;
		}

		for (Node* child : current->children)
		{
			q.push(child);
		}
	}
}


void MAryTree::preOrderTraversal(const Node* node) const
{
	if (!node)
		return;

	std::cout << node->value << " ";

	for (Node* child : node->children)
	{
		preOrderTraversal(child);
	}
}

void MAryTree::PreOrder() const
{
	if (IsEmpty())
	{
		std::cout << "Tree is empty!!!\n";
		return;
	}

	preOrderTraversal(m_root);

	std::cout << "\n";
}

void MAryTree::postOrderTraversal(const Node* node) const
{
	if (!node)
		return;

	for (Node* child : node->children)
	{
		postOrderTraversal(child);
	}

	std::cout << node->value << " ";
}

void MAryTree::PostOrder() const
{
	if (IsEmpty())
	{
		std::cout << "Tree is empty!!!\n";
		return;
	}

	postOrderTraversal(m_root);

	std::cout << "\n";
}

int MAryTree::calculateHeight(const Node* node) const
{
	if (!node)
		return 0;

	int height = 0;

	for (Node* child : node->children)
	{
		height = std::max(height, calculateHeight(child));
	}

	return height + 1;
}

int MAryTree::Height() const
{
	return calculateHeight(m_root);
}

bool MAryTree::Search(const int value) const
{
	if (IsEmpty())
	{
		return false;
	}

	std::queue<Node*> q;
	q.push(m_root);

	while (!q.empty())
	{
		Node* current = q.front();
		q.pop();

		if (current->value == value)
		{
			return true;
		}

		for (Node* child : current->children)
		{
			q.push(child);
		}
	}
	return false;
}

void MAryTree::deleteTree(Node* node)
{
	if (!node)
		return;

	for (Node* child : node->children)
	{
		deleteTree(child);
	}

	delete node;
}

void MAryTree::Clear()
{
	deleteTree(m_root);
	m_root = nullptr;
}

MAryTree::~MAryTree()
{
	Clear();
}
