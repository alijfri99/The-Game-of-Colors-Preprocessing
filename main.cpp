#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include "Color.h"
#include "Map.h"
#include "Node.h"
#include "DFS_al_Roverso.h"
#include "BFS.h"
#include "HeuristicCalculator.h"

using namespace std;

int main()
{
	/*for (int file_name = 91; file_name >= 1; file_name--)
	{
		ifstream file("predicted_depths/" + to_string(file_name) + ".bin", ios::in | ios::binary);
		while (file)
		{
			int rows = 0;
			int cols = 0;
			Color color;

			file.read((char *)&rows, sizeof(int));
			file.read((char *)&cols, sizeof(int));

			Map map(rows, cols);

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					file.read((char *)&color, sizeof(Color));
					map.add(i, j, color);
				}
			}
			map.print();
			cout << endl;
			Node n(map, -1, -1, "");
			DFS_al_Roverso dfs;
			dfs.search(n);
		}
	}*/
	Map map(5, 5);
	map.add(0, 0, *(new Color(0, 110, 0)));
	map.add(0, 1, *(new Color(110, 20, 0)));
	map.add(0, 2, *(new Color(0, 70, 100)));
	map.add(0, 3, *(new Color(95, 5, 100)));
	map.add(0, 4, *(new Color(20, 150, 30)));

	map.add(1, 0, *(new Color(150, 45, 25)));
	map.add(1, 1, *(new Color(120, 120, 0)));
	map.add(1, 2, *(new Color(130, 25, 140)));
	map.add(1, 3, *(new Color(15, 115, 155)));
	map.add(1, 4, *(new Color(5, 200, 30)));

	map.add(2, 0, *(new Color(210, 35, 5)));
	map.add(2, 1, *(new Color(160, 160, 5)));
	map.add(2, 2, *(new Color(0, 150, 200)));
	map.add(2, 3, *(new Color(5, 250, 30)));
	map.add(2, 4, *(new Color(255, 35, 0)));

	map.add(3, 0, *(new Color(175, 15, 190)));
	map.add(3, 1, *(new Color(245, 100, 80)));
	map.add(3, 2, *(new Color(95, 245, 110)));
	map.add(3, 3, *(new Color(210, 210, 10)));
	map.add(3, 4, *(new Color(20, 185, 235)));

	map.add(4, 0, *(new Color(110, 210, 240)));
	map.add(4, 1, *(new Color(230, 0, 255)));
	map.add(4, 2, *(new Color(250, 250, 10)));
	map.add(4, 3, *(new Color(235, 100, 250)));
	map.add(4, 4, *(new Color(245, 245, 90)));

	map.print();
	Node node(map, -1, -1, "");
	DFS_al_Roverso dfs_al_roverso;
	dfs_al_roverso.search(node);
}