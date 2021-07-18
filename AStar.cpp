#include "AStar.h"

void AStar::append_to_file(Node initial_node, Node goal_node)
{
	ofstream file("depths/" + to_string(goal_node.depth) + ".bin", ios::out | ios::binary | ios::app);
	file.write((const char *) &(initial_node.map.rows), sizeof(int));
	file.write((const char *) &(initial_node.map.cols), sizeof(int));

	for (Color color : initial_node.map.game)
	{
		file.write((const char *)&color, sizeof(color));
	}

	file.close();

	cout << "Depth: " << goal_node.depth << endl;
}

void AStar::print_result(Node goal_node, const vector<Node> &nodes)
{
	vector<Node> result_nodes;
	while (goal_node.parent_index != -1)
	{
		result_nodes.push_back(goal_node);
		goal_node = nodes[goal_node.parent_index];
	}
	result_nodes.push_back(goal_node);

	while (!result_nodes.empty())
	{
		Node temp = result_nodes.back();
		result_nodes.pop_back();
		cout << temp.action << endl << endl;
		temp.map.print();
		cout << endl;
	}
}

int AStar::search(Node initial_node, bool append)
{
	if (initial_node.is_goal())
	{
		if (append)
			append_to_file(initial_node, initial_node);
		return 0;
	}

	vector<Node> nodes(500000);
	int index = 0;
	priority_queue<int, vector<int>, CompareNode> frontier(nodes);
	unordered_map<string, bool> in_frontier;
	unordered_map<string, bool> explored;

	nodes[index] = initial_node;
	frontier.push(index);
	in_frontier[initial_node.hash()] = true;

	while (!frontier.empty())
	{
		int current_index = frontier.top();
		Node temp = nodes[current_index];
		frontier.pop();
		in_frontier[temp.hash()] = false;
		explored[temp.hash()] = true;

		vector<Node> children = temp.successor(current_index);
		while (!children.empty())
		{
			Node child = children.back();
			children.pop_back();
			if (in_frontier[child.hash()] == false && explored[child.hash()] == false)
			{
				if (child.is_goal())
				{
					if (append)
						append_to_file(initial_node, child);
					print_result(child, nodes);
					return child.depth;
				}
				index++;
				nodes[index] = child;
				frontier.push(index);
				in_frontier[child.hash()] = true;

				if (index % 1000 == 0)
				{
					cout << index << endl;
				}
			}
		}
	}
	return 0;
}