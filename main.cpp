#include <iostream>
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

	Node n(map, -1, -1, "");

	BFS_al_Roverso bfs_al_roverso;
	bfs_al_roverso.search(n);
}