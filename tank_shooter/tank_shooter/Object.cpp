#include "Object.h"
#include "my_console.h"
#include <iostream>

void Object::setDirection(int dir) {
	if (dir <= 4 && dir >= 1)
		direction = dir;
}

Coord Object::getPos() {
	return pos;
}

void Object::move() {
	//chua hoan thien vi map chua biet!

	if (direction == 1) pos.x++;
	if (direction == 2) pos.y--;
	if (direction == 3) pos.x--;
	if (direction == 4) pos.y++;

}

void Object::print() {
	gotoxy(pos.x, pos.y);
	std::cout << (char)219;
}

void Object::clear() {
	gotoxy(pos.x, pos.y);
	std::cout << ' ';
}