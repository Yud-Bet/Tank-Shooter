#pragma once
#include "my_console.h"
#include "g_map.h"

class Bullet
{
private:
	Coord location;
	int direction;
public:
	Bullet(Coord, int, g_map);
	Bullet(){}
	void print();
	void clr();
	void move(g_map);
	Coord get_location() { return location; }
	void set_bullet(Coord, int, g_map);
	bool is_valid_location() { return (location.x != -1 && location.y != -1); }
};

class BulletLine
{
private:
	Bullet* bullet_line;
	int mem_alocated;
	int num_of_bullet;
	int count;
public:
	BulletLine(Coord, int, g_map);
	void clr();
	void print();
	void move(g_map);
	void refresh(Coord, int, g_map);
};

