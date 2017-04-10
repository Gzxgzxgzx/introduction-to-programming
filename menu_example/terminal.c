/**
 * @file - terminal.c
 * @description - Used to interact with the kernel terminal driver
 * @author - Harlan James <waldroha@oregonstate.edu>
 */
#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @clear - Clears user terminal and resets cursor
 */
void clear()
{
	printf("\033[2J\033[1;1H");
}

/**
 * @poll - Polls user input for a single character
 *
 * @returns - user input
 */
char poll()
{
	char c;

	system("setterm -cursor off");
	system("/bin/stty raw");

	c = getchar();

	system("setterm -cursor on");
	system("/bin/stty cooked");
	
	clear();

	return c;
}
