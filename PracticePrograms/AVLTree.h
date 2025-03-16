#pragma once

struct Node
{
	int value;
	Node* left;
	Node* right;
	int height;

	Node(int val) :value(val), left(nullptr), right(nullptr), height(1) {}
};


class AVLTree
{
	Node* m_root;

	//Function to get height of the node
	int getHeight(const Node* node)const;

	//Function to get balance factor of the tree node
	int getBalanceFactor(const Node* node)const;

	//Function to perform right rotation to balance the subtree rooted at given node
	/*
					y                    x
	               / \                  / \
	              x   T3      --->     T1  y
	             / \                      / \
				T1  T2                   T2  T3
	*/
	Node* rotateRight(Node* y);

	//Function to perform left rotation to balance the subtree rooted at given node
	/*
					y                    x
				   / \                  / \
				  x   T3      <---     T1  y
				 / \                      / \
				T1  T2                   T2  T3
	*/
	Node* rotateLeft(Node* x);

	//Function to balance node of the tree
	Node* balance(Node* node);

	//Helper function for recursive insertion
	Node* insertHelper(Node* node, const int key);

	//Helper function to search for a key in the AVLTree
	Node* searchHelper(Node* node, const int key);

	//Helper function for inorder traversal
	void inOrderHelper(const Node* node)const;

	//Helper function for preorder traversal
	void preOrderHelper(const Node* node)const;

	//Helper function for postorder traversal
	void postOrderHelper(const Node* node)const;

	//Function to get inorder successor of the node
	Node* inOrderSuccessor(Node* node)const;

	Node* deleteNodeHelper(Node* node, int key);

	//Helper function to delete tree
	void deleteTree(Node* node);

public:

	// Constructor
	AVLTree();

	//Function to insert a node in AVLTree
	void Insert(const int key);

	//Function to search for a key in the AVLTree
	Node* Search(const int key);

	//Function for inorder traversal of the AVLTree(Left, Root, Right)
	void InOrder()const;

	//Function for preorder traversal of the AVLTree(Root, Left, Right)
	void PreOrder()const;

	//Function for postorder traversal of the AVLTree(Left, Right, Root)
	void PostOrder()const;

	//Function to delete a node from the AVLTree
	void DeleteNode(const int key);

	//Destructor
	~AVLTree();
};

