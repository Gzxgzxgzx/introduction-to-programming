#include "entity.hpp"

Entity::Entity() : Component()
{
	sprite = "*";
}

Entity::~Entity()
{

}

void Entity::update()
{

}

void Entity::render()
{
	printf("%s", sprite.c_str());
}
