#ifndef BFS_AL_ROVERSO_H
#define BFS_AL_ROVERSO_H
#include<fstream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include "Node.h"

using namespace std;

class BFS_al_Roverso
{
public:
	void search(Node initial_node);
	void append_to_file(Node node);
};

#endif