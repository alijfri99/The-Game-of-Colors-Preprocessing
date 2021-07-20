#include "HeuristicCalculator.h"

HeuristicCalculator::HeuristicCalculator() {}

int HeuristicCalculator::calculate_heuristic(Map map)
{
	/*Map ceil_ceil((int) ceil(map.rows / 2.0), (int) ceil(map.cols / 2.0));
	Map ceil_floor((int) ceil(map.rows / 2.0), (int) floor(map.cols / 2.0));
	Map floor_ceil((int) floor(map.rows / 2.0), (int) ceil(map.cols / 2.0));
	Map floor_floor((int) floor(map.rows / 2.0), (int) floor(map.cols / 2.0));
	
	for (int i = 0; i < ceil_ceil.rows; i++) //filling the ceil_ceil map
	{
		for (int j = 0; j < ceil_ceil.cols; j++)
		{
			ceil_ceil.add(i, j, map.at(i, j));
		}
	}

	for (int i = 0; i < ceil_floor.rows; i++) //filling the ceil_floor map
	{
		for (int j = 0; j < ceil_floor.cols; j++)
		{
			ceil_floor.add(i, j, map.at(i, j + ceil_ceil.cols));
		}
	}

	for (int i = 0; i < floor_ceil.rows; i++) //filling the floor_ceil map
	{
		for (int j = 0; j < floor_ceil.cols; j++)
		{
			floor_ceil.add(i, j, map.at(i + ceil_ceil.rows, j));
		}
	}

	for (int i = 0; i < floor_floor.rows; i++) //filling the floor_floor map
	{
		for (int j = 0; j < floor_floor.cols; j++)
		{
			floor_floor.add(i, j, map.at(i + ceil_ceil.rows, j + ceil_ceil.cols));
		}
	}

	ceil_ceil.print();
	ceil_floor.print();
	floor_ceil.print();
	floor_floor.print();

	Node ceil_ceil_Node(ceil_ceil, -1, -1, "");
	Node ceil_floor_Node(ceil_floor, -1, -1, "");
	Node floor_ceil_Node(floor_ceil, -1, -1, "");
	Node floor_floor_Node(floor_floor, -1, -1, "");
	BFS bfs;

	int h1 = bfs.search(ceil_ceil_Node);
	int h2 = bfs.search(ceil_floor_Node);
	int h3 = bfs.search(floor_ceil_Node);
	int h4 = bfs.search(floor_floor_Node);

	return h1 + h2 + h3 + h4;*/
	Map map1(2, 2);
	Map map2(2, 2);
	Map map3(2, 1);
	Map map4(2, 2);
	Map map5(2, 2);
	Map map6(2, 1);
	Map map7(1, 2);
	Map map8(1, 2);

	map1.add(0, 0, map.at(0, 0));
	map1.add(0, 1, map.at(0, 1));
	map1.add(1, 0, map.at(1, 0));
	map1.add(1, 1, map.at(1, 1));

	map2.add(0, 0, map.at(0, 2));
	map2.add(0, 1, map.at(0, 3));
	map2.add(1, 0, map.at(1, 2));
	map2.add(1, 1, map.at(1, 3));

	map3.add(0, 0, map.at(0, 4));
	map3.add(1, 0, map.at(1, 4));

	map4.add(0, 0, map.at(2, 0));
	map4.add(0, 1, map.at(2, 1));
	map4.add(1, 0, map.at(3, 0));
	map4.add(1, 1, map.at(3, 1));

	map5.add(0, 0, map.at(2, 2));
	map5.add(0, 1, map.at(2, 3));
	map5.add(1, 0, map.at(3, 2));
	map5.add(1, 1, map.at(3, 3));

	map6.add(0, 0, map.at(2, 4));
	map6.add(1, 0, map.at(3, 4));

	map7.add(0, 0, map.at(4, 0));
	map7.add(0, 1, map.at(4, 1));

	map8.add(0, 0, map.at(4, 2));
	map8.add(0, 1, map.at(4, 3));


	int h1 = calculate_sub_heuristic(map1);
	int h2 = calculate_sub_heuristic(map2);
	int h3 = calculate_sub_heuristic(map3);
	int h4 = calculate_sub_heuristic(map4);
	int h5 = calculate_sub_heuristic(map5);
	int h6 = calculate_sub_heuristic(map6);
	int h7 = calculate_sub_heuristic(map7);
	int h8 = calculate_sub_heuristic(map8);

	std::cout << "h1: " << h1 << ", h2: " << h2 << ", h3: " << h3 << ", h4: " << h4 << ", h5: " << h5 << ", h6: " << h6 << ", h7: " << h7 << ", h8: " << h8 << std::endl;

	return (h1 + h2 + h3 + h4 + h5 + h6 + h7 + h8);
}

int HeuristicCalculator::calculate_sub_heuristic(Map map)
{
	Node node(map, -1, -1, "", false);
	int result = Database::find(node.hash());
	if (result != -1)
		return result;
	else
	{
		BFS bfs;
		result = bfs.search(node);
		Database::write(node.hash(), result);
		return result;
	}
}