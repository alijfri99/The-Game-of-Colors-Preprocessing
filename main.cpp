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



int main()
{
	for (int file_name = 5; file_name >= 1; file_name--)
	{
		std::ifstream file("predicted_depths/" + std::to_string(file_name) + ".bin", std::ios::in | std::ios::binary);
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
			std::cout << std::endl;
			std::string s;
			std::cin >> s;
			if (s == "skip")
				continue;
			Node n(map, -1, -1, "");
			AStar aStar;
			int a = aStar.search(n);
			std::cout << a << std::endl;
			std::cin.get();
		}
	}
}