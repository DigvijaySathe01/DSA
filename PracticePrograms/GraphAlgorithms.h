#pragma once
#include <vector>
class GraphAlgorithms
{

	// Helper function for recursive DFS
	static void helperDFS(const int start, const std::vector<std::vector<int>>& adjList, 
				   std::vector<bool>& visit);

public:

	//Function for depth first traversal of graph
	static void DFS(const int start, const std::vector<std::vector<int>>& adjList);

	//Function for breadth first traversal of graph
	static void BFS(const int start, const std::vector<std::vector<int>>& adjList);
};

