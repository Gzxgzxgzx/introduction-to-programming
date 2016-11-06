#ifndef KEYS_HPP_
#define KEYS_HPP_

namespace Keys
{
	enum KEY
	{
		#ifdef NON_CANONICAL_MODE
			ENTER    = 13,
		#else
			ENTER = 10,
		#endif
		CONTINUE = 'c',
		QUIT     = 'q',
		DOWN     = 's',
		UP       = 'w',
	};
}

#endif // KEYS_HPP_
