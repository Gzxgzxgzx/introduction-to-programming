#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "component.hpp"

#include <stddef.h>
#include <string>

typedef enum
{
	TILE,
	MONSTER,
	PLAYER
} type_t;

typedef struct
{
	size_t r;
	size_t c;
} coord_t;

class Entity : public Component
{
	public:
		Entity();
		~Entity();

		void update();
		void render();
	
	private:
		type_t type;
		coord_t coord;

		std::string sprite;
};

#endif /* _ENTITY_HPP_ */
