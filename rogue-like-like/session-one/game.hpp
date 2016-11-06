#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "entity.hpp"

#include <string>

class Game
{
	public:
		Game(std::string title);
		~Game();
	
	int init();
	void update();
	void render();

	bool window_should_close();

	private:
		std::string title;
		bool close_requested;

		Entity ***world;
};

#endif /* _GAME_HPP_ */
