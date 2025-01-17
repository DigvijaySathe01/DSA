#include "BST.h"
#include <iostream>

//-----------------------------------------------------------------------------

BST::BST() :m_root(nullptr) 
{
}

//-----------------------------------------------------------------------------

Node* BST::insertHelper(Node* node, const int key)
{
	if (!node)
	{
		return new Node(key);
	}

	if (key < node->value)
	{
		node->left = insertHelper(node->left, key);
	}
	else if (key > node->value)
	{
		node->right = insertHelper(node->right, key);
	}

	return node;
}

//-----------------------------------------------------------------------------

void BST::Insert(const int key)
{
	m_root = insertHelper(m_root, key);
}

//-----------------------------------------------------------------------------

Node* BST::searchHelper(Node* node, const int key)
{
	if (!node || node->value == key)
		return node;

	if (key < node->value)
		return searchHelper(node->left, key);

	return searchHelper(node->right, key);
}

//-----------------------------------------------------------------------------

Node* BST::Search(const int key)
{
	return searchHelper(m_root, key);
}

//-----------------------------------------------------------------------------

void BST::inOrderHelper(const Node* node) const
{
	if (!node)
		return;

	inOrderHelper(node->left);
	std::cout << node->value << " ";
	inOrderHelper(node->right);
}

//-----------------------------------------------------------------------------

void BST::InOrder() const
{
	inOrderHelper(m_root);
}

//-----------------------------------------------------------------------------

void BST::preOrderHelper(const Node* node) const
{
	if (!node)
		return;

	std::cout << node->value << " ";
	preOrderHelper(node->left);
	preOrderHelper(node->right);
}

//-----------------------------------------------------------------------------

void BST::PreOrder() const
{
	preOrderHelper(m_root);
}

//-----------------------------------------------------------------------------

void BST::postOrderHelper(const Node* node) const
{
	if (!node)
		return;

	postOrderHelper(node->left);
	postOrderHelper(node->right);
	std::cout << node->value << " ";

}

//-----------------------------------------------------------------------------

void BST::PostOrder() const
{
	postOrderHelper(m_root);
}

//-----------------------------------------------------------------------------

Node* BST::inOrderSuccessor(Node* node) const
{
	while (node && node->left)
		node = node->left;

	return node;
}

//-----------------------------------------------------------------------------

Node* BST::deleteNodeHelper(Node* node, int key)
{
	if (!node)
		return node;

	if (key < node->value)
	{
		node->left = deleteNodeHelper(node->left, key);
	}
	else if (key > node->value)
	{
		node->right = deleteNodeHelper(node->right, key);
	}
	else
	{
		if (!node->left)
		{
			Node* temp = node->right;
			delete node;
			return temp;
		}
		else if (!node->right)
		{
			Node* temp = node->left;
			delete node;
			return temp;
		}

		Node* successor = inOrderSuccessor(node->right);
		node->value = successor->value;
		node->right = deleteNodeHelper(node->right, successor->value);
	}
	return node;
}

//-----------------------------------------------------------------------------

void BST::DeleteNode(const int key)
{
	m_root = deleteNodeHelper(m_root, key);
}

//-----------------------------------------------------------------------------

void BST::deleteTree(Node* node)
{
	if (!node)
		return;

	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

//-----------------------------------------------------------------------------

BST::~BST()
{
	deleteTree(m_root);
}

//-----------------------------------------------------------------------------
