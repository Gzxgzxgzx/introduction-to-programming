#include "ant.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	Ant *ant0 = new Ant("David", 0, 0);
	Ant *ant1 = new Ant("Emily", 0, 0);

	ant0->move(1, 2);

	return 0;
}
