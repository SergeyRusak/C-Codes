#pragma once
#include <vector>
#include "Graph.h"
struct Way {
	std::vector<Node*> nodes;
	int length;
	Way() : length(-1) {}
};
class Dijkstra {
	const Graph& graph;
public:
	Dijkstra(const Graph& agraph) : graph(agraph) {}
	Way shortestWay(Node* begin, Node* end);
};

