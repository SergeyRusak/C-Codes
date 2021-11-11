#include "Node.h"

void Node::addNeighbour(Node* neighbour)
{
	neighbours.insert(neighbour);


}

void Node::removeNeighbour(Node* neighbour)
{
	neighbours.erase(neighbours.find(neighbour));


}
