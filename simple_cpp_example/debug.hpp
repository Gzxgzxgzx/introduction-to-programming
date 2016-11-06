#ifndef DEBUG_HPP
#define DEBUG_HPP

/**
 * @print - This is called a variadic macro. Like it's name implies, it enables
 * the programmer to write macros with a variable number of arguments.
 *
 * In the case that DEBUG is defined, it will print to stdout. Otherwise it
 * will do nothing. 
 *
 * @notice - "(void) 0" will be translated by the compiler to "noop", an
 * assembly instruction.
 *
 * @see - https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
 */
#ifdef DEBUG
	#define print(...) printf(__VA_ARGS__)
#else
	#define print(...) (void) 0
#endif

#endif // DEBUG_HPP
