#ifndef _NODE_
#define _NODE_

#include <set>
#include <string>

using namespace std;

class Node {
	typedef std::set<Node*>::const_iterator node_iterator;

	string name;
	set<Node*> neighbours;
	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);
	Node* getNode() { return this; }
public:
	Node(const std::string& aname) : name(aname) {}
	const string& getName() const { return name; }
	node_iterator nb_begin() const {
		return neighbours.begin();
	}
	node_iterator nb_end() const {
		return neighbours.end();
	}

	double getWeight(Node* n) { return 1.0; }
	friend class Graph;
};

#endif