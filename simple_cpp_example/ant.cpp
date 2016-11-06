#include "ant.hpp"
#include "debug.hpp"

#include <stdio.h>

int Ant::count;

Ant::Ant(const char * const _name, const int sx, const int sy, const char _tile)
		: name(_name), x(sy), y(sy), tile(_tile), lx(sx), ly(sy)
{
	id = count++;

	print("Created Ant(%s, %d)\n", name, id);
}

bool Ant::move(int x, int y)
{
	lx = this->x;
	ly = this->y;

	this->x = x;
	this->y = y;

	print("Moved %s to (%d, %d) from (%d, %d)\n", name, this->x, this->y, lx,
			ly);

	return true;
}

char Ant::get()
{
	return tile;
}
