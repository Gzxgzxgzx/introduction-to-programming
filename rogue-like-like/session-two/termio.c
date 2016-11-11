#include "termio.h"

#include "debug.hpp"

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

static int _rows = -1;
static int _cols  = -1;

static int _initd  = -1;

// TODO: This should actually be char ** and instead be
// complimented with a bitmask buffer for color
static char ***_buffer = NULL;

int termio_init()
{
	int ret;
	struct winsize win;

	// TODO: This syntax sucks
	if (_initd == -1)
	{
		ret = setvbuf(stdout, NULL, _IOLBF, BUFSIZ); 

		if (ret == 0)
			ret = ioctl(0, TIOCGWINSZ, &win);

		if (ret == 0)
		{
			_initd  = 0;
			_rows = win.ws_row;
			_cols = win.ws_col;

			_buffer = malloc(_rows * sizeof(char **));

			for (size_t r = 0; r < _rows; r++)
			{
				_buffer[r] = malloc(_cols * sizeof(char *));
				for (size_t c = 0; c < _cols; c++)
				{
					// Only god can judge me
					_buffer[r][c] = malloc(3*sizeof(char));
					_buffer[r][c][0] = ' ';
					_buffer[r][c][1] = ' ';
					_buffer[r][c][2] = '\0';
				}
			}
		}
		else
		{
			_rows = -1;
			_cols = -1;
		}
	}
	else
	{
		ret = 0;
	}

	return ret;
}

void termio_destroy()
{
	for (size_t r = 0; r < termio_rows(); r++)
	{
		for (size_t c = 0; c < termio_cols(); c++)
		{
			free(_buffer[r][c]);
		}
		free(_buffer[r]);
	}

	free(_buffer);
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

void termio_print(int r, int c, const char *fmt, ...)
{
	char *str;

	assert(r == r%termio_rows()); // Prevent seg fault
	assert(c == c%termio_cols());

	va_list args;
	va_start(args, fmt);

	vasprintf(&str, fmt, args);

	if (_buffer[r][c] != NULL)
		free(_buffer[r][c]);

	_buffer[r][c] = str;

	va_end(args);
}

void termio_swap()
{
	for (size_t r = 0; r < termio_rows(); r++)
	{
		for (size_t c = 0; c < termio_cols(); c++)
		{
			printf(_buffer[r][c]);
		}
	}

	printf("\n");
	termio_clear();
}

int termio_rows()
{
	return _rows;
}

int termio_cols()
{
	return _cols;
}
