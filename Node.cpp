#include "Node.h"

Node::Node() 
{
	this->parent_index = -2;
}

Node::Node(Map map, int parent_index, int parent_depth, std::string action, bool needs_h)
{
	this->map = map;
	this->parent_index = parent_index;
	this->depth = parent_depth + 1;
	this->action = action;

	if (needs_h)
		this->h = this->calculate_h();
	else
		this->h = 0;
}

std::vector<Node> Node::reverse_successor(int index)
{
	std::vector<Node> result;

	for (int i = 0; i < this->map.rows; i++)
	{
		for (int j = 0; j < this->map.cols; j++)
		{
			Node left_move;
			Node up_move;
			if (j > 0) //left swap is possible
			{
				left_move = *(new Node(this->map.copy(), index, this->depth, ""));
				left_move.map.add(i, j, left_move.map.at(i, j).invert());
				left_move.map.swap(i, j, i, j - 1);
			}
			if (i > 0) //up swap is possible
			{
				up_move = *(new Node(this->map.copy(), index, this->depth, ""));
				up_move.map.add(i, j, up_move.map.at(i, j).invert());
				up_move.map.swap(i, j, i - 1, j);
			}

			int random_number = rand() % 1000;
			if (random_number >= 500) //alternating between push orders randomly
			{
				if (left_move.parent_index != -2) //the default value for parent_index is -2!!!
					result.push_back(left_move);
				if (up_move.parent_index != -2)
					result.push_back(up_move);
			}
			else
			{
				if (up_move.parent_index != -2)
					result.push_back(up_move);
				if (left_move.parent_index != -2)
					result.push_back(left_move);
			}
		}
	}

	return result;
}

std::vector<Node> Node::successor(int index, bool needs_h)
{
	std::vector<Node> result;

	for (int i = 0; i < this->map.rows; i++)
	{
		for (int j = 0; j < this->map.cols; j++)
		{
			if (j < this->map.cols - 1) //right swap is possible
			{
				Node right_move = *(new Node(this->map.copy(), index, this->depth, std::to_string(i) + " " + std::to_string(j) + " right", needs_h));
				right_move.map.add(i, j, right_move.map.at(i, j).invert());
				right_move.map.swap(i, j, i, j + 1);
				if(needs_h)
					right_move.h = right_move.calculate_h();
				result.push_back(right_move);
			}
			if (i < this->map.rows - 1) //down swap is possible
			{
				Node down_move = *(new Node(this->map.copy(), index, this->depth, std::to_string(i) + " " + std::to_string(j) + " down", needs_h));
				down_move.map.add(i, j, down_move.map.at(i, j).invert());
				down_move.map.swap(i, j, i + 1, j);
				if(needs_h)
					down_move.h = down_move.calculate_h();
				result.push_back(down_move);
			}
		}
	}

	return result;
}

std::string Node::hash()
{
	std::string result = "";

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

int Node::calculate_h()
{
	/*int result = 0;
	Map sorted_map = this->map.copy();
	unordered_map<float, Tuple> sorted_indices;
	sort(sorted_map.game.begin(), sorted_map.game.end());

	for (int i = 0; i < sorted_map.rows; i++)
	{
		for (int j = 0; j < sorted_map.cols; j++)
		{
			sorted_indices[sorted_map.at(i, j).hash()] = *(new Tuple(i, j));
		}
	}

	for (int i = 0; i < this->map.rows; i++)
	{
		for (int j = 0; j < this->map.cols; j++)
		{
			//result += abs(i - sorted_indices[this->map.at(i, j).hash()].i) + abs(j - sorted_indices[this->map.at(i, j).hash()].j);
			if (i != sorted_indices[this->map.at(i, j).hash()].i || j != sorted_indices[this->map.at(i, j).hash()].j)
				result += 1;
		}
	}*/
	HeuristicCalculator heuristicCalculator;
	return heuristicCalculator.calculate_heuristic(this->map);
}