#include "Bullet.h"
#include <iostream>

Bullet::Bullet(Coord loc_of_obj, int dir, g_map m)
{
	Coord temp{ loc_of_obj };
	direction = dir;
	if (dir == 1) temp.x++;
	else if (dir == 2) temp.y--;
	else if (dir == 3) temp.x--;
	else if (dir == 4) temp.y++;
	if (!m.isTrungMap(temp))
	{
		location = temp;
	}
	else
	{
		location.y = location.x = -1;
	}
}

void Bullet::print()
{
	if (is_valid_location())
	{
		gotoxy(location.x, location.y);
		std::cout << "+";
	}
}

void Bullet::clr()
{
	if (is_valid_location())
	{
		gotoxy(location.x, location.y);
		std::cout << " ";
	}
}

void Bullet::move(g_map m)
{
	if (direction == 1) location.x++;
	else if (direction == 2) location.y--;
	else if (direction == 3) location.x--;
	else if (direction == 4) location.y++;
	if (m.isTrungMap(location))
	{
		location.x = location.y = -1;
	}
}

void Bullet::set_bullet(Coord loc_of_obj, int dir, g_map m)
{
	Coord temp{ loc_of_obj };
	direction = dir;
	if (dir == 1) temp.x++;
	else if (dir == 2) temp.y--;
	else if (dir == 3) temp.x--;
	else if (dir == 4) temp.y++;
	if (!m.isTrungMap(temp))
	{
		location = temp;
	}
	else
	{
		location.y = location.x = -1;
	}
}

BulletLine::BulletLine(Coord loc_of_obj, int dir, g_map m): count{0},
bullet_line{ new Bullet(loc_of_obj, dir, m) }, mem_alocated{ 1 }, num_of_bullet{ 1 }{}

void BulletLine::clr()
{
	for (int i{ 0 }; i < num_of_bullet; i++)
	{
		bullet_line[i].clr();
	}
}

void BulletLine::print()
{
	for (int i{ 0 }; i < num_of_bullet; i++)
	{
		bullet_line[i].print();
	}
}

void BulletLine::move(g_map m)
{
	for (int i{ 0 }; i < num_of_bullet; i++)
	{
		bullet_line[i].move(m);
	}
	count++;
	if (num_of_bullet > 0)
	{
		if (!bullet_line[0].is_valid_location())
		{
			for (int i{ 0 }; i < num_of_bullet - 1; i++)
			{
				bullet_line[i] = bullet_line[i + 1];
			}
			num_of_bullet--;
		}
	}
}

void BulletLine::refresh(Coord loc_of_obj, int dir, g_map m)
{
	if (count >= 2)
	{
		if (num_of_bullet < mem_alocated)
		{
			bullet_line[num_of_bullet].set_bullet(loc_of_obj, dir, m);
			num_of_bullet++;
			count = 0;
		}
		else
		{
			mem_alocated *= 2;
			Bullet* temp = new Bullet[mem_alocated];
			for (int i{ 0 }; i < num_of_bullet; i++)
			{
				temp[i] = bullet_line[i];
			}
			delete[] bullet_line;
			bullet_line = temp;
			bullet_line[num_of_bullet].set_bullet(loc_of_obj, dir, m);
			num_of_bullet++;
			count = 0;
		}
	}
}
