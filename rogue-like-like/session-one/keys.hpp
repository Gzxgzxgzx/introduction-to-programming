#ifndef _KEYS_
#define _KEYS_

namespace Keys
{
	enum Key
	{
		#ifdef NON_CANONICAL_MODE
			ENTER = 13,
		#else
			ENTER = 10,
		#endif
		CONTINUE = 'c',
		QUIT     = 'q',
		UP       = 'w',
		DOWN     = 's',
		LEFT     = 'a',
		RIGHT    = 'd'
	};
}

#endif /* _KEYS_ */
