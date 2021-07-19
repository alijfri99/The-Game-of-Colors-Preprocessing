#include "Map.h"

Map::Map() {}

Map::Map(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	std::vector<Color> temp(rows * cols);
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

void Map::swap(int i1, int j1, int i2, int j2)
{
	Color temp = this->at(i1, j1);
	this->add(i1, j1, this->at(i2, j2));
	this->add(i2, j2, temp);
}

void Map::print()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			std::cout << at(i, j).magnitude() << " ";
		}
		std::cout << std::endl;
	}
}

Map Map::copy()
{
	Map result(this->rows, this->cols);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			result.add(i, j, this->at(i, j));
		}
	}

	return result;
}