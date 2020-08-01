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
		direction = Randoms(1,4);
	}
	void setDirection(int);
	void setDirNearer(Coord);
	void setDirFarther(Coord);
	Coord getPos();
	void move();	 // ok move() neu nhu ifMove() k trung map
	Coord ifMove();  //neu nhu move() thi den dau?
	void print();
	void clear();
	bool found(Object b);
};