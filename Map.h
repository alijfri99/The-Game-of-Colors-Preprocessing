#ifndef MAP_H
#define MAP_H
#include<iostream>
#include<vector>
#include "Color.h"

using namespace std;

class Map
{
public:
	int rows, cols;
	vector<Color> game;
	Map();
	Map(int rows, int cols);
	void add(int i, int j, Color color);
	Color at(int i, int j);
	void swap(int i1, int j1, int i2, int j2);
	void print();
};

#endif MAP_H