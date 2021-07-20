#ifndef DATABASE_H
#define DATABASE_H
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>

class Database
{
public:
	static std::unordered_map<std::string, int> old_items;
	static std::unordered_map<std::string, int> new_items;
	static void init(std::string filename = "pattern_database.bin");
	static int find(std::string key);
	static void write(std::string key, int value);
	static void commit(std::string filename = "pattern_database.bin");

private:
	Database();
};

#endif