#include "Object.h"
#include "my_console.h"
#include <iostream>

void Object::setDirection(int dir) {
	if (dir <= 4 && dir >= 1) {
		direction = dir;
	}
}

Coord Object::getPos() {
	return pos;
}

void Object::move() {
	//chua hoan thien vi map chua biet!
	clear();
	if (direction == 1) pos.x++;
	if (direction == 2) pos.y--;
	if (direction == 3) pos.x--;
	if (direction == 4) pos.y++;
	print();

}

void Object::print() {
	gotoxy(pos.x, pos.y);
	std::cout << '@';
}

void Object::clear() {
	gotoxy(pos.x, pos.y);
	std::cout << ' ';
}

Coord Object::ifMove() {
	Coord newPos{ pos };
	if (direction == 1) newPos.x++;
	if (direction == 2) newPos.y--;
	if (direction == 3) newPos.x--;
	if (direction == 4) newPos.y++;
	return newPos;
}

bool Object::found(Object b) {
	if (ifMove().x == b.getPos().x && ifMove().y == b.getPos().y)
		return true;
	return false;
}

void Object::setDirNearer(Coord destination) {

}