#include "Dijkstra.h"
#include "PriorityOueue.h"
#include <map>


static Way unroll(std::map<Node*, MarkedNode> visited,
	Node* begin, Node* curr) {
	Way way;
	way.length = visited[curr].mark;
	while (curr != begin) {
		way.nodes.push_back(curr);
		curr = visited[curr].prev;
	}
	way.nodes.push_back(begin);
	return way;
}



Way Dijkstra::shortestWay(Node* begin, Node* end) {
	PriorityQueue nodes; nodes.push(begin, 0, 0);
	std::map<Node*, MarkedNode> visited;
	while (!nodes.empty()) {
		MarkedNode next = nodes.pop();
		visited[next.node] = next;
		if (end == next.node) return unroll(visited, begin, end);
		for (node_iterator it = next.node->nb_begin();
			it != next.node->nb_end(); it++) {
			int weight = (*it)->getWeight(next.node) + next.mark;
			if (visited.find(*it) == visited.end())
				nodes.push(*it, weight, next.node);
		}
	}
	return Way();
}



