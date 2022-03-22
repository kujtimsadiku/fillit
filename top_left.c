#include "fillit.h"

/*----	Moves the piece to left corner
		Might not need this.
----*/
void	top_left(t_data *data, t_tetris *tetris)
{
	int y;
	int x;
	int count;

	y = -1;
	count = 0;
	x = 0;
	while (++y < 4)
	{
		if (tetris->tetriminos[count].piece[y][x + 0] == HASH &&)

		if (tetris->tetriminos[count].piece[y][x + 1] == HASH &&)

		if (tetris->tetriminos[count].piece[y][x + 2] == HASH &&)
			
		if (tetris->tetriminos[count].piece[y][x + 3] == HASH &&)

	}
}