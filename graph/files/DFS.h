#pragma once
#include "Graph.h"
class DFS {
	const Graph& graph;
	std::set<Node*> visited;
	bool connected(Node* begin, Node* end, int depth);
public:
	DFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end);
};

