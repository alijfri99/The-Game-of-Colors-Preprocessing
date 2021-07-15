#include "DFS_al_Roverso.h"

void DFS_al_Roverso::append_to_file(Node node)
{
	ofstream file("predicted_depths/" + to_string(node.depth) + ".bin", ios::out | ios::binary | ios::app);
	file.write((const char *) &(node.map.rows), sizeof(int));
	file.write((const char *) &(node.map.cols), sizeof(int));

	for (Color color : node.map.game)
	{
		file.write((const char *)&color, sizeof(color));
	}

	file.close();
}

void DFS_al_Roverso::search(Node initial_node)
{
	vector<Node> nodes(6000);
	int index = 0;
	stack<int> frontier;
	unordered_map<string, bool> in_frontier;
	unordered_map<string, bool> explored;
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

		vector<Node> children = temp.reverse_successor(current_index);
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
					cout << child.depth  << " " << index << endl;

					if (index == 5999)
						return;
				}
			}
		}
	}

}