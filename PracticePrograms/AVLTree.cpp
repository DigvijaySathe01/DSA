#include "AVLTree.h"

#include "AVLTree.h"
#include <iostream>

//-----------------------------------------------------------------------------

AVLTree::AVLTree() :m_root(nullptr)
{
}

//-----------------------------------------------------------------------------

int AVLTree::getHeight(const Node* node) const
{
	return (node) ? node->height : 0;
}

//-----------------------------------------------------------------------------

int AVLTree::getBalanceFactor(const Node* node) const
{
	return (node) ? (getHeight(node->left) - getHeight(node->right)) : 0;
}

//-----------------------------------------------------------------------------

Node* AVLTree::rotateRight(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
	x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

	return x;
}

//-----------------------------------------------------------------------------

Node* AVLTree::rotateLeft(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
	y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

	return y;
}

//-----------------------------------------------------------------------------

Node* AVLTree::balance(Node* node)
{
	int balanceFactor = getBalanceFactor(node);

	// Left heavy
	if (balanceFactor > 1)
	{
		if (getBalanceFactor(node->left) < 0)
		{
			node->left = rotateRight(node->left); // LR case
		}

		return rotateRight(node); // LL case
	}
	// Right heavy
	if(balanceFactor < -1)
	{
		if (getBalanceFactor(node->right) > 0)
		{
			node->right = rotateLeft(node->right); // RL case
		}

		return rotateLeft(node); // RR case
	}
	return node;
}

//-----------------------------------------------------------------------------

Node* AVLTree::insertHelper(Node* node, const int key)
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

	node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

	return balance(node);
}

//-----------------------------------------------------------------------------

void AVLTree::Insert(const int key)
{
	m_root = insertHelper(m_root, key);
}

//-----------------------------------------------------------------------------

Node* AVLTree::searchHelper(Node* node, const int key)
{
	if (!node || node->value == key)
		return node;

	if (key < node->value)
		return searchHelper(node->left, key);

	return searchHelper(node->right, key);
}

//-----------------------------------------------------------------------------

Node* AVLTree::Search(const int key)
{
	return searchHelper(m_root, key);
}

//-----------------------------------------------------------------------------

void AVLTree::inOrderHelper(const Node* node) const
{
	if (!node)
		return;

	inOrderHelper(node->left);
	std::cout << node->value << " ";
	inOrderHelper(node->right);
}

//-----------------------------------------------------------------------------

void AVLTree::InOrder() const
{
	inOrderHelper(m_root);
}

//-----------------------------------------------------------------------------

void AVLTree::preOrderHelper(const Node* node) const
{
	if (!node)
		return;

	std::cout << node->value << " ";
	preOrderHelper(node->left);
	preOrderHelper(node->right);
}

//-----------------------------------------------------------------------------

void AVLTree::PreOrder() const
{
	preOrderHelper(m_root);
}

//-----------------------------------------------------------------------------

void AVLTree::postOrderHelper(const Node* node) const
{
	if (!node)
		return;

	postOrderHelper(node->left);
	postOrderHelper(node->right);
	std::cout << node->value << " ";

}

//-----------------------------------------------------------------------------

void AVLTree::PostOrder() const
{
	postOrderHelper(m_root);
}

//-----------------------------------------------------------------------------

Node* AVLTree::inOrderSuccessor(Node* node) const
{
	while (node && node->left)
		node = node->left;

	return node;
}

//-----------------------------------------------------------------------------

Node* AVLTree::deleteNodeHelper(Node* node, int key)
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

	node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

	return balance(node);
}

//-----------------------------------------------------------------------------

void AVLTree::DeleteNode(const int key)
{
	m_root = deleteNodeHelper(m_root, key);
}

//-----------------------------------------------------------------------------

void AVLTree::deleteTree(Node* node)
{
	if (!node)
		return;

	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

//-----------------------------------------------------------------------------

AVLTree::~AVLTree()
{
	deleteTree(m_root);
	m_root = nullptr;
}

//-----------------------------------------------------------------------------
