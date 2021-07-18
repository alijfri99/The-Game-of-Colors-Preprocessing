#ifndef COMPARENode_H
#define COMPARENode_H
#include<vector>
#include "Node.h"

class CompareNode
{
public:
	std::vector<Node> *nodes;
	CompareNode(std::vector<Node> &nodes);
	bool operator()(const int &index1, const int &index2);
};

#endif