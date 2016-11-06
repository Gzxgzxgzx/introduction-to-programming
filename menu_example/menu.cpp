#include "menu.hpp"

#include "keys.hpp"
#include "terminal.h"

#include <cstdio>

#define COLOR_BOLD   "\e[1;37m"
#define COLOR_SELECT "\e[1;31m"
#define COLOR_RESET  "\e[0m"

int Menu::AddEntry(const char * const desc, char k)
{
	if (size == MENU_MAX_ENTRIES)
	{
		return -1;
	}

	entries[size++] = { k, desc };

	return 0;
}

void Menu::PrintMenu()
{
	size_t i;
	
	clear();
	printf("%s%s%s\n", COLOR_BOLD, title, COLOR_RESET);
	for (i = 0; i < size; i++)
	{
		if (i == cur)
			printf("%s", COLOR_SELECT);

		printf("\t%c\t\t%s%s\n", entries[i].k, entries[i].desc, COLOR_RESET);
	}
}

char Menu::Get()
{
	char k;
	
	if (size == 0)
		return 0;

	PrintMenu();

	// Poll User Input
	k = poll();
	
	// Handle Input
	if (k == Keys::UP)
		cur = (++cur)%size;
	else if (k == Keys::DOWN)
		cur = (--cur)%size;
	else if (k == Keys::ENTER)
		k = entries[cur].k;

	return k;
}
