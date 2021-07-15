#ifndef BFS_H
#define BFS_H
#include<fstream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include "Node.h"
#include "Color.h"

using namespace std;

class BFS
{
public:
	void search(Node initial_node);
	void append_to_file(Node node, Node goal_node);
};

#endif