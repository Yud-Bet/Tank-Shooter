#pragma once
#include "my_console.h"

class Object {
private:
	Coord pos;
	int direction; //1: phai; 2: len; 3: trai; 4: xuong
public:
	Object(int x, int y) {
		pos.x = x;
		pos.y = y;
	}
	void setDirection(int);
	Coord getPos();
	void move();
	void print();
	void clear();
};