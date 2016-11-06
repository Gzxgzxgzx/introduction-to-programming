#include "termio.h"

#include "debug.hpp"

#include <stdio.h>
#include <stdlib.h>

int termio_init()
{
	int ret = 0;

	ret = setvbuf(stdout, NULL, _IOLBF, BUFSIZ); 

	return ret;
}

void termio_clear()
{
	#ifndef DEBUG
		printf("\033[2J\033[1;1H");
	#endif
}

char termio_getch()
{
	char c;

	system("setterm -cursor off");
	system("/bin/stty raw -echo");

	c = getchar();

	system("setterm -cursor on");
	system("/bin/stty cooked echo");
	
	termio_clear();

	return c;
}


