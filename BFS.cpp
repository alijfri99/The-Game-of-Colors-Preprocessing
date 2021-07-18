#include "BFS.h"

void BFS::append_to_file(Node initial_node, Node goal_node)
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

int BFS::search(Node initial_node, bool append)
{
	if (initial_node.is_goal())
	{
		if (append)
			append_to_file(initial_node, initial_node);
		return 0;
	}

	vector<Node> nodes(1000000);
	int index = 0;
	queue<int> frontier;
	unordered_map<string, bool> in_frontier;
	unordered_map<string, bool> explored;

	nodes[index] = initial_node;
	frontier.push(index);
	in_frontier[initial_node.hash()] = true;

	while (!frontier.empty())
	{
		int current_index = frontier.front();
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
					if(append)
						this->append_to_file(initial_node, child);
					return child.depth;
				}
				index++;
				nodes[index] = child;
				frontier.push(index);
				in_frontier[child.hash()] = true;

				if (index % 10000 == 0)
				{
					cout << "Heuristic index: " << index << endl;
				}
			}
		}
	}
	return 0;
}