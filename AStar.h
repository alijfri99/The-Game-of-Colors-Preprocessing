#ifndef ASTAR_H
#define ASTAR_H
#include<fstream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include "Node.h"
#include "CompareNode.h"

using namespace std;

class AStar
{
public:
	int search(Node initial_node, bool append = false);
	void append_to_file(Node initial_node, Node goal_Node);
	void print_result(Node goal_node, const vector<Node> &nodes);
};

#endif
