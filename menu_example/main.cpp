#include "keys.hpp"
#include "menu.hpp"

#include <cstdio>

void DoContinue()
{
	char c;

	printf("Press enter to continue...\n");
	c = getchar();
}

int main(void)
{
	char c;

	Menu menu("Sample Menu");
	menu.AddEntry("Quit the menu", Keys::QUIT);
	menu.AddEntry("Continue", Keys::CONTINUE);

	while ((c = menu.Get()) != Keys::QUIT)
	{
		switch (c)
		{
			case Keys::CONTINUE:
					DoContinue();
					break;
		}
	}

	printf("Terminating...\n");

	return 0;
}
