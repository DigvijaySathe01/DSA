#include "Trie.h"

//-----------------------------------------------------------------------------

Trie::Trie()
{
	m_root = new TrieNode();
}

//-----------------------------------------------------------------------------

void Trie::insertHelper(TrieNode* node, const std::string& word, int index)
{
	// Base case: If end of word is reached, mark as leaf node.
	if (index == word.size())
	{
		node->isLeafNode = true;
		return;
	}

	char currentChar = word[index];

	// If the current character is not in the map, create a new TrieNode.
	if (node->m_children.find(currentChar) == node->m_children.end())
	{
		node->m_children[currentChar] = new TrieNode();
	}

	// Recursively insert the next character.
	insertHelper(node->m_children[currentChar], word, index + 1);
}

//-----------------------------------------------------------------------------

bool Trie::searchHelper(TrieNode* node, const std::string& word, int index) const
{
	// Base case: If end of word is reached, check if it's a valid word.
	if (index == word.size())
	{
		return node->isLeafNode;
	}

	char currentChar = word[index];

	// If character is not found, the word does not exist.
	if (node->m_children.find(currentChar) == node->m_children.end())
	{
		return false;
	}

	// Recursively search for the next character.
	return searchHelper(node->m_children[currentChar], word, index + 1);
}

//-----------------------------------------------------------------------------

bool Trie::startsWithPrefixHelper(TrieNode* node, const std::string& prefix, int index) const
{
	// Base case: If end of prefix is reached, return true.
	if (index == prefix.size())
	{
		return true;
	}

	char currentChar = prefix[index];

	// If the current character is not found, prefix doesn't exist.
	if (node->m_children.find(currentChar) == node->m_children.end())
	{
		return false;
	}

	// Recursively check for the next character in the prefix.
	return startsWithPrefixHelper(node->m_children[currentChar], prefix, index + 1);
}

//-----------------------------------------------------------------------------

bool Trie::deleteHelper(TrieNode* node, const std::string& word, int index)
{
	// Base case: If end of word is reached.
	if (index == word.size())
	{
		// If the word does not exist, return false.
		if (!node->isLeafNode)
			return false;

		// Unmark the leaf node as it is no longer the end of a word.
		node->isLeafNode = false;

		// Return true if the current node has no children (safe to delete).
		return node->m_children.empty();
	}

	char currentChar = word[index];

	// If the current character is not found, the word does not exist.
	if (node->m_children.find(currentChar) == node->m_children.end())
	{
		return false;
	}

	// Recursively delete the next character.
	bool deleteChild = deleteHelper(node->m_children[currentChar], word, index + 1);

	// If the child node should be deleted.
	if (deleteChild)
	{
		delete node->m_children[currentChar];
		node->m_children[currentChar] = nullptr;  // Set to nullptr after deletion.
		node->m_children.erase(currentChar);

		// Return true if this node has no children and is not end of another word.
		return node->m_children.empty() && !node->isLeafNode;
	}

	return false;
}

//-----------------------------------------------------------------------------

void Trie::Insert(const std::string& word)
{
	insertHelper(m_root, word, 0);
}

//-----------------------------------------------------------------------------

bool Trie::Search(const std::string& word) const
{
	return searchHelper(m_root, word, 0);
}

//-----------------------------------------------------------------------------

bool Trie::StartsWithPrefix(const std::string& prefix) const
{
	return startsWithPrefixHelper(m_root, prefix, 0);
}

//-----------------------------------------------------------------------------

bool Trie::Delete(const std::string& word)
{
	return deleteHelper(m_root, word, 0);
}

//-----------------------------------------------------------------------------

void Trie::LCPHelper(TrieNode* node, std::string& lcp)
{
	while (node && node->m_children.size() == 1 && !node->isLeafNode)
	{
		auto it = node->m_children.begin();  
		lcp.push_back(it->first);           
		node = it->second;                  
	}
}

//-----------------------------------------------------------------------------

void Trie::LCP(std::string &lcp)
{
	LCPHelper(m_root, lcp);
}

//-----------------------------------------------------------------------------

void Trie::deleteTrie(TrieNode* node)
{
	for (auto& child : node->m_children)
	{
		deleteTrie(child.second);
	}
	delete node;
}

//-----------------------------------------------------------------------------

Trie::~Trie()
{
	delete m_root;
}

//-----------------------------------------------------------------------------
