#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include "Color.h"
#include "Map.h"
#include "Node.h"
#include "DFS_al_Roverso.h"
#include "AStar.h"
#include "HeuristicCalculator.h"

using namespace std;

int main()
{
	for (int file_name = 20; file_name >= 1; file_name--)
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
			string s;
			cin >> s;
			if (s == "skip")
				continue;
			Node n(map, -1, -1, "");
			AStar aStar;
			int a = aStar.search(n);
			cout << a << endl;
			cin.get();
		}
	}
}