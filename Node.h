#ifndef NODE_H
#define NODE_H
#include<string>
#include "Map.h"

class Node
{
public:
	Map map;
	int parent_index;
	int depth;
	string action;
	vector<Node> reverse_successor(int index);
	string hash();
	Node();
	Node(Map map, int parent_index, int parent_depth, string action);
	bool is_goal();
};

#endif