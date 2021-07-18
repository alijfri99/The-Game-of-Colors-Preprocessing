#ifndef HEURISTICCALCULATOR_H
#define HEURISTICCALCULATOR_H
#include<cmath>
#include "Map.h"
#include "Node.h"
#include "BFS.h"

class HeuristicCalculator
{
public:
	HeuristicCalculator();
	int calculate_heuristic(Map map);
};

#endif