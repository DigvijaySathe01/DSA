#include "GraphAlgorithms.h"
#include <iostream>
#include <queue>

//-----------------------------------------------------------------------------

void GraphAlgorithms::helperDFS(const int node, const std::vector<std::vector<int>>& adjList,
	std::vector<bool>& visit)
{
	visit[node] = true;
	std::cout << node << " ";

	for (int connectedNode : adjList[node])
	{
		if (!visit[connectedNode])
			helperDFS(connectedNode, adjList, visit);
	}
}

//-----------------------------------------------------------------------------

void GraphAlgorithms::DFS(const int startNode, const std::vector<std::vector<int>>& adjList)
{
	std::vector<bool> visited(adjList.size(), false);
	helperDFS(startNode, adjList, visited);
	std::cout << "\n"; 
}

//-----------------------------------------------------------------------------

void GraphAlgorithms::BFS(const int startNode, const std::vector<std::vector<int>>& adjList)
{
	std::vector<bool> visited(adjList.size(), false);
	visited[startNode] = true;

	std::queue<int> q;
	q.push(startNode);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		std::cout << current << " ";

		for (int connectedNode : adjList[current])
		{
			if (!visited[connectedNode]) 
			{
				q.push(connectedNode);
				visited[connectedNode] = true; 
			}
		}
	}
	std::cout << "\n";
}

//-----------------------------------------------------------------------------
