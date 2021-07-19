#include "DFS_al_Roverso.h"

void DFS_al_Roverso::append_to_file(Node initial_node)
{
	std::ofstream file("predicted_depths/" + std::to_string(initial_node.depth) + ".bin", std::ios::out | std::ios::binary | std::ios::app);
	file.write((const char *) &(initial_node.map.rows), sizeof(int));
	file.write((const char *) &(initial_node.map.cols), sizeof(int));

	for (Color color : initial_node.map.game)
	{
		file.write((const char *)&color, sizeof(color));
	}

	file.close();
}

void DFS_al_Roverso::search(Node initial_node)
{
	std::vector<Node> nodes(6000);
	int index = 0;
	std::stack<int> frontier;
	std::unordered_map<std::string, bool> in_frontier;
	std::unordered_map<std::string, bool> explored;
	int max_depth = 0;

	nodes[index] = initial_node;
	frontier.push(index);
	in_frontier[initial_node.hash()] = true;

	while (!frontier.empty() && max_depth <= 100)
	{
		int current_index = frontier.top();
		Node temp = nodes[current_index];
		frontier.pop();
		in_frontier[temp.hash()] = false;
		explored[temp.hash()] = true;

		std::vector<Node> children = temp.reverse_successor(current_index);
		while (!children.empty())
		{
			Node child = children.back();
			children.pop_back();
			if (in_frontier[child.hash()] == false && explored[child.hash()] == false)
			{
				if(child.depth <= 100)
				{
					this->append_to_file(child);
					index++;
					nodes[index] = child;
					frontier.push(index);
					in_frontier[child.hash()] = true;

					if (child.depth > max_depth)
						max_depth = child.depth;
					std::cout << child.depth  << " " << index << std::endl;

					if (index == 5999)
						return;
				}
			}
		}
	}

}