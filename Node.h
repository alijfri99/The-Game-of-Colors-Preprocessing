#ifndef NODE_H
#define NODE_H
#include<string>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdlib>
#include "Map.h"
#include "Tuple.h"
#include "HeuristicCalculator.h"

class Node
{
public:
	Map map;
	int parent_index;
	int depth;
	int h;
	std::string action;
	std::vector<Node> reverse_successor(int index);
	std::vector<Node> successor(int index, bool needs_h = true);
	std::string hash();
	Node();
	Node(Map map, int parent_index, int parent_depth, std::string action, bool needs_h = true);
	bool is_goal();
	int calculate_h();
};

#endif