#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

class Component
{
	public:
		Component() {}
		virtual ~Component() {}

		virtual void update() = 0;
		virtual const char *raw() = 0;
};

#endif /* _RENDERABLE_HPP_ */
