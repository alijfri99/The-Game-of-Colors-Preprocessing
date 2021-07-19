#ifndef MAP_H
#define MAP_H
#include<iostream>
#include<vector>
#include "Color.h"



class Map
{
public:
	int rows, cols;
	std::vector<Color> game;
	Map();
	Map(int rows, int cols);
	void add(int i, int j, Color color);
	Color at(int i, int j);
	void swap(int i1, int j1, int i2, int j2);
	void print();
	Map copy();
};

#endif MAP_H