#include "game.hpp"

#include "termio.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	Game game("Rogue-like-like");
	
	if (game.init() != 0)
	{
		return -1;
	}

	while (game.window_should_close() == false)
	{
		game.update();
		game.render();
	}

	termio_destroy();

	return 0;
}
