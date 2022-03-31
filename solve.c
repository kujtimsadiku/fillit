#include "fillit.h"

/*----py[] & px[] hold the puzzle cordination----*/
static void block_values(t_data *data, t_tetris *tetris, int count)
{
	int y = 0;
	int x;
	while (y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tetris->minos[count].piece[y][x] == HASH)
			{
				data->py[data->counthash] = y;
				data->px[data->counthash] = x;
				data->counthash++;
			}
			if (data->counthash == 4)
			{
				data->counthash = 0;
				break ;
			}
		}
		y++;
	}
}

static int	placeblock(t_data *data, t_tetris *tetris, int y, int x, int count)
{
	shifter(data);
	if (tetris->map[y + data->py[0]][x + data->px[0]] == DOT &&
		tetris->map[y + data->py[1]][x + data->px[1]] == DOT &&
		tetris->map[y + data->py[2]][x + data->px[2]] == DOT &&
		tetris->map[y + data->py[3]][x + data->px[3]] == DOT &&
		check_cordination(data, y, x))
	{
		tetris->map[y + data->py[0]][x + data->px[0]] = 'A' + count;
		tetris->map[y + data->py[1]][x + data->px[1]] = 'A' + count;
		tetris->map[y + data->py[2]][x + data->px[2]] = 'A' + count;
		tetris->map[y + data->py[3]][x + data->px[3]] = 'A' + count;
		// int i = 0;
		// while (i < data->size)
		// {
		// 	printf("%s\n", tetris->map[i]);
		// 	i++;
		// }
		// printf("\n");
		// sleep(1);
		return (1);
	}
	else
		return (0);
}

static int	solving(t_data *data, t_tetris *tetris, int count)
{
	data->y = 0;
	while (tetris->map[data->y] && data->y < data->size)
	{
		data->x = 0;
		while (tetris->map[data->y][data->x] && data->x < data->size)
		{
			if (tetris->map[data->y][data->x] == DOT)
			{
				block_values(data, tetris, count);
				if (placeblock(data, tetris, data->y, data->x, count) == 1)
				{
					if (solving(data, tetris, count + 1))
						return (1);
					else
						cleanblock(data, tetris, count);
					if (count + 1 == data->tetrimino)
						return (1);
				}
			}
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	return (0);
}

/*
	we go piece by piece and every time we couldn't fit the piece
	we data->count-- that we go there and move the previous piece 1 forward
*/
void	solve_map(t_data *data, t_tetris *tetris)
{
	data->y = 0;
	data->x = 0;
	create_map(data, tetris);
	while (!solving(data, tetris, 0))
	{
		re_create_map(data, tetris, data->size + 1);
		data->count = 0;
	}
	int i = 0;
	while (i < data->size)
	{
		printf("%s\n", tetris->map[i]);
		i++;
	}
	printf("\n");
}