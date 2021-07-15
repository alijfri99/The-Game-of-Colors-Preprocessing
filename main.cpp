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
	Map map(5, 5);
	map.add(0, 0, *(new Color(110, 210, 240)));
	map.add(0, 1, *(new Color(20, 185, 235)));
	map.add(0, 2, *(new Color(0, 150, 200)));
	map.add(0, 3, *(new Color(15, 115, 155)));
	map.add(0, 4, *(new Color(0, 70, 100)));

	map.add(1, 0, *(new Color(245, 245, 90)));
	map.add(1, 1, *(new Color(250, 250, 10)));
	map.add(1, 2, *(new Color(210, 210, 10)));
	map.add(1, 3, *(new Color(160, 160, 5)));
	map.add(1, 4, *(new Color(120, 120, 0)));

	map.add(2, 0, *(new Color(95, 245, 110)));
	map.add(2, 1, *(new Color(5, 250, 30)));
	map.add(2, 2, *(new Color(5, 200, 30)));
	map.add(2, 3, *(new Color(20, 150, 30)));
	map.add(2, 4, *(new Color(0, 110, 0)));

	map.add(3, 0, *(new Color(245, 100, 80)));
	map.add(3, 1, *(new Color(255, 35, 0)));
	map.add(3, 2, *(new Color(210, 35, 5)));
	map.add(3, 3, *(new Color(150, 45, 25)));
	map.add(3, 4, *(new Color(110, 20, 0)));

	map.add(4, 0, *(new Color(235, 100, 250)));
	map.add(4, 1, *(new Color(230, 0, 255)));
	map.add(4, 2, *(new Color(175, 15, 190)));
	map.add(4, 3, *(new Color(130, 25, 140)));
	map.add(4, 4, *(new Color(95, 5, 100)));

	map.print();
}