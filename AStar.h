#ifndef ASTAR_H
#define ASTAR_H
#include<fstream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include "Node.h"

using namespace std;

class AStar
{
public:
	int search(Node initial_node, bool append = false);
	void append_to_file(Node node, Node goal_node);
};

#endif
