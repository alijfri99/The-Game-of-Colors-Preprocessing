#include "Database.h"

std::unordered_map<std::string, int> Database::old_items;
std::unordered_map<std::string, int> Database::new_items;

void Database::init(std::string filename)
{
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if (!file)
		return;

	size_t size;
	while(file.read((char *)&size, sizeof(size)))
	{
		std::string key;
		int value;
		key.resize(size);
		file.read((char *)&key[0], size);
		file.read((char *)&value, sizeof(int));
		old_items[key] = value;
	}

	file.close();
}

int Database::find(std::string key)
{
	if (new_items.find(key) != new_items.end())
		return new_items[key];

	else if (old_items.find(key) != old_items.end())
		return old_items[key];

	return -1;
}

void Database::write(std::string key, int value)
{
	new_items[key] = value;
}

void Database::commit(std::string filename)
{
	std::ofstream file(filename, std::ios::app | std::ios::binary);

	for (auto element : new_items)
	{
		std::string key = element.first;
		if (old_items.find(key) == old_items.end()) //this key does not exist in the old file
		{
			size_t size = key.size();
			int value = element.second;
			file.write((const char *)&size, sizeof(size));
			file.write((const char *)&key[0], size);
			file.write((const char *)&value, sizeof(int));
		}
	}
	
	file.close();
}