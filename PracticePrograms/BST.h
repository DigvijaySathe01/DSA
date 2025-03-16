#pragma once

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int val) :value(val), left(nullptr), right(nullptr) {}
};


class BST
{
	Node* m_root;

	//Helper function for recursive insertion
	Node* insertHelper(Node* node, const int key);

	//Helper function to search for a key in the BST
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
	BST();

	//Function to insert a node in BST
	void Insert(const int key);

	//Function to search for a key in the BST
	Node* Search(const int key);

	//Function for inorder traversal of the BST(Left, Root, Right)
	void InOrder()const;

	//Function for preorder traversal of the BST(Root, Left, Right)
	void PreOrder()const;

	//Function for postorder traversal of the BST(Left, Right, Root)
	void PostOrder()const;

	//Function to delete a node from the BST
	void DeleteNode(const int key);

	//Destructor
	~BST();
};

