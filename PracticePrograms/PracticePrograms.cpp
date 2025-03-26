#include "Trie.h"
#include "string"
#include <iostream>
using namespace std;

int main()
{
	Trie trie;
	trie.Insert("");
	trie.Insert("b");

	string str;
	trie.LCP(str);
	cout << str;

	return 0;
	
}