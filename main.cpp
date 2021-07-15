#include <iostream>
#include<fstream>
#include<vector>
#include "Color.h"
#include "Map.h"
#include "Node.h"
#include "BFS_al_Roverso.h"

using namespace std;

int main()
{
	Map map(2, 2);
	map.add(0, 0, *(new Color(0, 0, 0)));
	map.add(0, 1, *(new Color(255, 255, 255)));
	map.add(1, 0, *(new Color(0, 100, 0)));
	map.add(1, 1, *(new Color(100, 0, 100)));

	map.print();

	ifstream file("predicted_depths/1.bin", ios::in | ios::binary);
	
	file.read((char *) &(map.rows), sizeof(int));
	file.read((char *) &(map.cols), sizeof(int));

	Color temp;
	for (int i = 0; i < map.rows; i++)
	{
		for (int j = 0; j < map.cols; j++)
		{
			file.read((char *)&temp, sizeof(temp));
			map.add(i, j, temp);
		}
	}
	map.print();
}