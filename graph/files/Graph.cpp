#include "Graph.h"
void Graph::addNode(Node* node)
{
	if (existNodebyName(node->getName()))return;
	nodes.insert(node);

}
void Graph::removeNode(Node* node) {
	nodes.erase(node);
	// Remove also from all neighbours list
	for (std::set<Node*>::iterator it = nodes.begin();
		it != nodes.end(); it++) {
		(*it)->removeNeighbour(node);
	}
}
void Graph::addEdge(Node* begin, Node* end) {
	if (nodes.find(begin) == nodes.end())
		return;
	if (nodes.find(end) == nodes.end())
		return;
	begin->addNeighbour(end);
	end->addNeighbour(begin);
}

void Graph::removeEdge(Node* begin, Node* end)
{
	if (nodes.find(begin) == nodes.end())
		return;
	if (nodes.find(end) == nodes.end())
		return;
	begin->removeNeighbour(end);
	end->removeNeighbour(begin);

}

bool Graph::existNodebyName(std::string name)
{
	for (std::set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
		if ((*it)->getName() == name) return true;
	}
	return false;
}

Node* Graph::getNodebyName(string name)
{
	if (existNodebyName(name)) {
		for (std::set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
			if ((*it)->getName() == name) return (*it)->getNode();
		}
	}

	return new Node("empty");
}
