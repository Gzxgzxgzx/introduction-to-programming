#ifndef MENU_HPP_
#define MENU_HPP_

#define MENU_MAX_ENTRIES 10

#include <cstddef>

class Menu
{
	private:
		struct entry
		{
			char k;
			const char *desc;
		};

		const char * title;
		struct entry entries[MENU_MAX_ENTRIES];
		size_t size;

		size_t cur;

	public:
		Menu(const char * const _title)
			: title(_title), size(0), cur(0) {}

		int AddEntry(const char * const, char k = 0);
		void PrintMenu();
		char Get();
};

#endif // MENU_HPP_
