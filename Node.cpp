#include "Node.h"

Node::Node(Map map, int parent_index, int parent_depth, string action)
{
	this->map = map;
	this->parent_index = parent_index;
	this->depth = parent_depth + 1;
	this->action = action;
}

vector<Node> Node::reverse_successor(int index)
{
	vector<Node> result;

	for (int i = 0; i < this->map.rows; i++)
	{
		for (int j = 0; j < this->map.cols; j++)
		{
			if (j > 0) //left swap is possible
			{
				Node left_move = *(new Node(this->map, index, this->depth, ""));
				left_move.map.add(i, j, left_move.map.at(i, j).invert());
				left_move.map.swap(i, j, i, j - 1);
				result.push_back(left_move);
			}
			if (i > 0) //up swap is possible
			{
				Node up_move = *(new Node(this->map, index, this->depth, ""));
				up_move.map.add(i, j, up_move.map.at(i, j).invert());
				up_move.map.swap(i, j, i - 1, j);
				result.push_back(up_move);
			}
		}
	}

	return result;
}

string Node::hash()
{
	string result = "";

	for (int i = 0; i < this->map.rows; i++)
	{
		for (int j = 0; j < this->map.cols; j++)
		{
			result += std::to_string(this->map.at(i, j).red) + "," + std::to_string(this->map.at(i, j).green) + "," + std::to_string(this->map.at(i, j).blue) + ",";
		}
	}

	return result;
}

bool Node::is_goal()
{
	for (int i = 0; i < this->map.game.size() - 1; i++)
	{
		if (this->map.game[i].magnitude() > this->map.game[i + 1].magnitude())
			return false;
	}

	return true;
}