#ifndef HEURISTICCALCULATOR_H
#define HEURISTICCALCULATOR_H
#include<cmath>
#include<iostream>
#include "Map.h"
#include "Node.h"
#include "BFS.h"
#include "Database.h"

class HeuristicCalculator
{
public:
	HeuristicCalculator();
	int calculate_heuristic(Map map);
	int calculate_sub_heuristic(Map map);
};

#endif