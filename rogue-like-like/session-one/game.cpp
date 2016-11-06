#include "game.hpp"

#include "termio.h"

#include "debug.hpp"
#include "entity.hpp"
#include "keys.hpp"

using std::string;

#define WND_WIDTH 15
#define WND_HEIGHT WND_WIDTH

Game::Game(string title)
{
	this->title = title;
	
	close_requested = false;
	
	world = new Entity**[WND_WIDTH];
	
	for (size_t r = 0; r < WND_WIDTH; r++)
	{
		world[r] = new Entity*[WND_HEIGHT];

		for (size_t c = 0; c < WND_HEIGHT; c++)
		{
			world[r][c] = NULL;
		}
	}
}

Game::~Game()
{
	for (size_t r = 0; r < WND_WIDTH; r++)
	{
		for (size_t c = 0; c < WND_HEIGHT; c++)
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
	for (size_t r = 0; r < WND_WIDTH; r++)
	{
		for (size_t c = 0; c < WND_HEIGHT; c++)
		{
			if (world[r][c] !== NULL)
			{
				world[r][c]->render();
			}
		}
	}
}

bool Game::window_should_close()
{
	return close_requested;
}
