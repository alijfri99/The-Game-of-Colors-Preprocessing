#include <iostream>
#include "Color.h"
#include "Map.h"

using namespace std;

int main()
{
	Map map(2, 2);
	map.add(0, 0, *(new Color(0, 0, 0)));
	map.add(0, 1, *(new Color(255, 255, 255)));
	map.add(1, 0, *(new Color(0, 100, 0)));
	map.add(1, 1, *(new Color(100, 0, 100)));

	map.print();

	map.add(1, 0, map.at(1, 0).invert());
	map.print();
	cout << map.at(1, 0).red << " " << map.at(1, 0).green << " " << map.at(1, 0).blue << endl;
}