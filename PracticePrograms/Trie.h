#pragma once
#include <unordered_map>
#include <string>

struct TrieNode
{
	std::unordered_map<char, TrieNode*> m_children;
	bool isLeafNode;
	TrieNode()
	{
		isLeafNode = false;
	}
};


class Trie
{
	TrieNode* m_root;

	// Recursive helper function to insert a word into the Trie.
	void insertHelper(TrieNode* node, const std::string& word, int index);

	// Recursive helper function to search for a word in the Trie.
	bool searchHelper(TrieNode* node, const std::string &word, int index)const;

	// Recursive helper function to check if any word starts with a given prefix.
	bool startsWithPrefixHelper(TrieNode* node, const std::string& prefix, int index)const;

	// Recursive helper function to delete a word from the Trie.
	bool deleteHelper(TrieNode* node, const std::string &word, int index);

	// Recursive function to find longest common prefix in the trie
	void LCPHelper(TrieNode* node, std::string& lcp);

	// Recursive helper to delete all nodes in the Trie.
	void deleteTrie(TrieNode* node);

public:

	//constructor
	Trie();
	
	// This function inserts a word into the Trie.
	void Insert(const std::string& word);

	// This function searches for a word in the Trie.
	bool Search(const std::string &word)const;
	
	// This function checks if any word in the Trie starts with a given prefix.
	bool StartsWithPrefix(const std::string &prefix)const;

	// This function deletes a word from the Trie.
	bool Delete(const std::string &word);

	// Function to find longest common prefix in the trie
	void LCP(std::string &lcp);

	// Destructor
	~Trie();
};

