#include "Map.h"

Map::Map(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	vector<Color> temp(rows * cols);
	this->game = temp;
}

void Map::add(int i, int j, Color color)
{
	this->game[(i * this->cols) + j] = color;
}

Color Map::at(int i, int j)
{
	return this->game[(i * this->cols) + j];
}

void Map::print()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			cout << at(i, j).magnitude() << " ";
		}
		cout << endl;
	}
}