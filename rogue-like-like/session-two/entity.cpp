#include "entity.hpp"

#include "colors.hpp"

Entity::Entity() : Component()
{
	sprite = "*";
	color  = Colors::RED;

	raw_data = color + sprite;
}

Entity::~Entity()
{

}

void Entity::update()
{

}

const char *Entity::raw()
{
	return raw_data.c_str();
}
