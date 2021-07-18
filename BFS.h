#ifndef BFS_H
#define BFS_H
#include<fstream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include "Node.h"

using namespace std;

class BFS
{
public:
	int search(Node initial_node, bool append = false);
	void append_to_file(Node initial_node, Node goal_node);
};

#endif