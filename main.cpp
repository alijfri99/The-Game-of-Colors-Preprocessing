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
#include "Database.h"



int main()
{
	Database::init();
	std::string s;

	for (int file_name = 1; file_name <=100; file_name++)
	{
		std::ifstream file("predicted_depths/" + std::to_string(file_name) + ".bin", std::ios::in | std::ios::binary);

		int rows = 0;
		int cols = 0;
		Color color;
		int i = 1;

		while (file.read((char *)&rows, sizeof(int)))
		{
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
			std::cout << "Predicted depth: " << file_name << ", Iteration: " << i << std::endl << std::endl;
			map.print();
			std::cout << std::endl;
			if(s != "proceed" || i % 40 == 0)
				std::cin >> s;

			if (s == "skip")
			{
				i++;
				continue;
			}
			else if (s == "skipdepth")
				break;

			Node n(map, -1, -1, "");
			AStar aStar;
			int a = aStar.search(n, true);
			std::cout << a << std::endl;
			Database::commit();
			i++;
		}
	}
}