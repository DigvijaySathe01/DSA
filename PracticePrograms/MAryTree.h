#pragma once
#include <vector>

struct Node
{
	int value;
	std::vector<Node*> children;

	Node(int val, int size)
	{
		value = val;
		children.reserve(size);
	}
};

class MAryTree
{
	Node* m_root;
	int m_numChildren;
	
	//Helper function for preOrder traversal of the tree
	void preOrderTraversal(const Node* node)const;

	//Helper function for postOrder traversal of the tree
	void postOrderTraversal(const Node* node)const;

	//Helper function to calculate the height of the tree
	int calculateHeight(const Node* node)const;

	//Function to delete entire tree
	void deleteTree(Node* node);

public:

	//Constructor
	MAryTree(const int numChildren);

	//Function to check if tree is empty
	bool IsEmpty()const;

	//Function to perform level-order traversal
	void LevelOrderTraversal()const;

	//Function to insert an element into the tree
	void Insert(const int value);

	//Function for preorder traversal of the tree
	void PreOrder()const;

	//Function for postorder traversal of the tree
	void PostOrder()const;

	//Function to get the height of the tree
	int Height()const;

	//Function to a value in the tree
	bool Search(const int value)const;

	//Function to delete the tree
	void Clear();

	//Destructor
	~MAryTree();

};

