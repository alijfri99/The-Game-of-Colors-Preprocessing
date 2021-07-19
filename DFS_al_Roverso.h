#ifndef DFS_AL_ROVERSO_H
#define DFS_AL_ROVERSO_H
#include<fstream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<string>
#include "Node.h"
#include "Color.h"



class DFS_al_Roverso
{
public:
	void search(Node initial_node);
	void append_to_file(Node initial_node);
};

#endif