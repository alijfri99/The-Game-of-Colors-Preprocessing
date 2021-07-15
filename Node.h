#ifndef NODE_H
#define NODE_H
#include<string>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include "Map.h"
#include "Tuple.h"
#include "Color.h"

class Node
{
public:
	Map map;
	int parent_index;
	int depth;
	int h;
	string action;
	vector<Node> reverse_successor(int index);
	vector<Node> successor(int index);
	string hash();
	Node();
	Node(Map map, int parent_index, int parent_depth, string action);
	bool is_goal();
	int calculate_h();
};

#endif