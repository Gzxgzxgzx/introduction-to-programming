#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
	public:
		Ant(const char * const name, const int sx, const int sy,
				const char tile = '*');

		bool move(int, int);
		char get();

	private:
		static int count;

		const char * const name;
		int id;
		int x, y;
		char tile;

		int lx, ly;
};

#endif // ANT_HPP
