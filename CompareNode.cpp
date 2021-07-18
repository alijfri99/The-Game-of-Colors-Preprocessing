#include "CompareNode.h"

CompareNode::CompareNode(std::vector<Node> &nodes)
{
	this->nodes = &nodes;
}

bool CompareNode::operator()(const int &index1, const int &index2)
{
	Node node1 = nodes->at(index1);
	Node node2 = nodes->at(index2);

	return ((node1.h + node1.depth) > (node2.h + node2.depth));
}