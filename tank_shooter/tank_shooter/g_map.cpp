#include "g_map.h"
#include <fstream>
#include <string>
#include "my_console.h"
#include <iostream>

g_map::g_map(int h, int w): width{w}, height{h}
{
	map_arr = new char* [height];
	for (int i{ 0 }; i < height; i++)
	{
		map_arr[i] = new char[width];
	}
	std::ifstream map_file(".\\map.txt");
	int i{ 0 };
	while (!map_file.eof())
	{
		std::string line;
		getline(map_file, line);
		for (int j{ 0 }; j < width; j++)
		{
			map_arr[i][j] = line[j];
		}
		i++;
	}
	map_file.close();
}

void g_map::print()
{
	for (int i{ 0 }; i < height; i++)
	{
		for (int j{ 0 }; j < width; j++)
		{
			if (map_arr[i][j] != ' ')
			{
				gotoxy(j, i);
				std::cout << (char)177;
			}
		}
	}
}

bool g_map::isTrungMap(Coord somewhere)
{
	if (map_arr[somewhere.y][somewhere.x] != ' ') return true;
	return false;
}
