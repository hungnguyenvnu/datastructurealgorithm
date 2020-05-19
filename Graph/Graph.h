#pragma once
#include <list>
class Graph
{
private:
	int v;
	std::list<int>* adj; // List adjacency;
public:
	Graph(int v);
	// Add ad edge to graph
	void AddEdge(int v, int w); 
	void BFS(int s);
};

