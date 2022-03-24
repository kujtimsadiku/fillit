#include "fillit.h"

/*--- nb ottaa vastaan data->res + 1 ----*/

static int	recursive_solving(t_data *data, t_tetris *tetris, int y, int x)
{
	while (y < data->new_res)
	{
		while (x < data->new_res)
		{
			if (tetris->tetriminos[data->count].piece[y][x] == HASH)
				tetris->map[y][x] = symbol(data->count);
			x++;
		}
		y++;
	}
	return (1);
}

/*
	we go piece by piece and every time we couldn't fit the piece
	we data->count-- that we go there and move the previous piece 1 forward
*/
void	solve_map(t_data *data, t_tetris *tetris)
{
	data->count = -1;
	create_map(data, tetris);
	while (++data->count < data->tetrimino)
	{
		if (recursive_solving(data, tetris, data->y, data->x) == 0)
		{
			data->count--;
		}
	}
}