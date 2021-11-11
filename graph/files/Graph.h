#pragma once
#include <set>
#include "node.h"

using namespace std;

typedef std::set<Node*>::const_iterator node_iterator;

class Graph {
	set<Node*> nodes;
public:
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);
	bool existNodebyName(string name);
	Node* getNodebyName(string name);
	std::set<Node*>::const_iterator find(Node* node) {
		return nodes.find(node);
	}
	std::set<Node*>::const_iterator begin() const {
		return nodes.begin();
	}
	std::set<Node*>::const_iterator end() const {
		return nodes.end();
	}


};