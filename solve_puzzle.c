#include "fillit.h"

static void block_values(t_data *data, t_tetris *tetris)
{
	int x;
	int y;

	data->counthash = 0;
	y = -1;
	while (tetris->tetriminos[data->count].piece[++y][x])
	{
		x = -1;
		while (tetris->tetriminos[data->count].piece[y][++x])
		{
			if (tetris->tetriminos[data->count].piece[y][x] == HASH)
			{
				data->py[y] = y;
				data->px[x] = x;
			}
		}
		if (data->counthash++ == 4)
			break ;
	}
}
static void placeblock(t_data *data, t_tetris *tetris, int y, int x)
{
	if 
}

static int check_placement(t_data *data, t_tetris *tetris, int y, int x)
{
	while (tetris->map[data->y])
	{
		while (tetris->map[data->y][data->x])
		{
			if (tetris->map[data->y][data->x] == DOT)
			{
				data->yx[0] = data->y;
				data->yx[1] = data->x;
				return (1);
			}
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	return (0);
}

static int	recursive_solving(t_data *data, t_tetris *tetris, int y, int x)
{
	while (y < 4)
	{
		if (check_placement(data, tetris) == 0)
			return (0);
		while (tetris->tetriminos[data->count].piece[y][x] != HASH && x < 4)
		{
			if (x == 3)
			{
				y++;
				x = 0;
				break ;
			}
			x++;
		}
		placeblock();
	}
}

/*
	we go piece by piece and every time we couldn't fit the piece
	we data->count-- that we go there and move the previous piece 1 forward
*/
void	solve_map(t_data *data, t_tetris *tetris)
{
	data->count = -1;
	data->y = 0;
	data->x = 0;
	data->yx[0] = 0;
	data->yx[1] = 0;
	create_map(data, tetris);
	while (++data->count < data->tetrimino)
	{
		if (recursive_solving(data, tetris, 0, 0) == 0)
			data->count--;
		if (data->count == -1)
			re_create_map(data, tetris, data->new_size + 1);
		data->counthash = 0;
	}
}