#include "game.hpp"

#include "termio.h"

#include "debug.hpp"
#include "entity.hpp"
#include "keys.hpp"

#include <stdio.h>

using std::string;

Game::Game(string title)
{
	this->title = title;
	close_requested = false;
}

Game::~Game()
{
	for (int r = 0; r < win_rows; r++)
	{
		for (int c = 0; c < win_cols; c++)
		{
			delete world[r][c];
		}
		
		delete [] world[r];
	}

	delete [] world;
}

int Game::init()
{
	int ret = termio_init();

	win_rows = termio_rows();
	win_cols = termio_cols();

	if (ret == 0)
	{
		world = new Entity**[win_rows];

		for (int r = 0; r < win_rows; r++)
		{
			world[r] = new Entity*[win_cols];

			for (int c = 0; c < win_cols; c++)
			{
				world[r][c] = NULL;
			}
		}
	}

	// TODO: Remove
	world[3][3] = new Entity();

	PRINT("CONTEXT\n");
	PRINT("Rows: %d\n", win_rows);
	PRINT("Cols: %d\n", win_cols);

	return ret;
}

void Game::update()
{
	char c = termio_getch();
	
	switch (c)
	{
		case Keys::QUIT:
			close_requested = true;
			break;
	}
}

void Game::render()
{
	const char *buff;

	for (int r = 0; r < win_rows; r++)
	{
		for (int c = 0; c < win_cols; c++)
		{
			// This is very slow and should be avoided
			if (world[r][c] != NULL)
			{
				buff = world[r][c]->raw();
			}
			else
			{
				buff = "\e[0m ";
			}

			termio_print(r, c, buff);
		}
	}

	termio_swap(); // typically would swap front and back buffer
}

bool Game::window_should_close()
{
	return close_requested;
}
