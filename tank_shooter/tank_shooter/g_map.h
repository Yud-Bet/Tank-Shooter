#pragma once
#include "my_console.h"

class g_map
{
private:
	char** map_arr;
	int width;
	int height;
public:
	g_map(int h = 30, int w = 60);
	void print();
	bool isTrungMap(Coord);
};

