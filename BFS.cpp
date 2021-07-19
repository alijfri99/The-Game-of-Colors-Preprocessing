#include "BFS.h"
#include "Node.h"

void BFS::append_to_file(Node initial_node, Node goal_node)
{
	std::ofstream file("depths/" + std::to_string(goal_node.depth) + ".bin", std::ios::out | std::ios::binary | std::ios::app);
	file.write((const char *) &(initial_node.map.rows), sizeof(int));
	file.write((const char *) &(initial_node.map.cols), sizeof(int));

	for (Color color : initial_node.map.game)
	{
		file.write((const char *)&color, sizeof(color));
	}

	file.close();

	std::cout << "Depth: " << goal_node.depth << std::endl;
}

int BFS::search(Node initial_node, bool append)
{
	if (initial_node.is_goal())
	{
		if (append)
			append_to_file(initial_node, initial_node);
		return 0;
	}

	std::vector<Node> nodes(1000000);
	int index = 0;
	std::queue<int> frontier;
	std::unordered_map<std::string, bool> in_frontier;
	std::unordered_map<std::string, bool> explored;

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

		std::vector<Node> children = temp.successor(current_index, false);
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

				std::cout << "Heuristic index: " << index << std::endl;
			}
		}
	}
	return 0;
}