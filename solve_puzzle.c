#include "fillit.h"

/*----py[] & px[] hold the puzzle cordination----*/
static void block_values(t_data *data, t_tetris *tetris, int y, int x)
{
	// int y2;
	// int x2;

	// x2 = 0;
	// y2 = 0;
	// data->counthash = 0;
	while (y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tetris->tetriminos[data->count].piece[y][x] == HASH)
			{
				data->py[data->counthash] = y;
				data->px[data->counthash] = x;
				printf("py[%d] == HASH\n", data->py[data->counthash]);
				printf("px[%d] == HASH\n", data->px[data->counthash]);
				data->counthash++;
				// x2++;
			}
		}
		// if (data->counthash > 0)
		// 	y2++;
		y++;
		// x2 = 0;
	}
}

static int	placeblock(t_data *data, t_tetris *tetris)
{
	if (tetris->map[data->y + data->py[0]][data->x + data->px[0]] == DOT &&
		tetris->map[data->y + data->py[1]][data->x + data->px[1]] == DOT &&
		tetris->map[data->y + data->py[2]][data->x + data->px[2]] == DOT &&
		tetris->map[data->y + data->py[3]][data->x + data->px[3]] == DOT)
	{
		tetris->map[data->y + data->py[0]][data->x + data->px[0]] = 'A' + data->count;
		tetris->map[data->y + data->py[1]][data->x + data->px[1]] = 'A' + data->count;
		tetris->map[data->y + data->py[2]][data->x + data->px[2]] = 'A' + data->count;
		tetris->map[data->y + data->py[3]][data->x + data->px[3]] = 'A' + data->count;
		int i = 0;
		while (i < 4)
		{
			printf("%s\n", tetris->map[i]);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

/*----checks if the y and x is dot----*/
static int	check_placement(t_data *data, t_tetris *tetris)
{
	while (tetris->map[data->y] && data->y < 4)
	{
		while (tetris->map[data->y][data->x] && data->x < 4)
		{
			if (tetris->map[data->y][data->x] == DOT)
			{
				if (placeblock(data, tetris) == 1)
					return (1);
			}
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	return (0);
}

static int	solving(t_data *data, t_tetris *tetris)
{
	if (data->count < data->tetrimino)
	{
		block_values(data, tetris, 0, -1);
		while (check_placement(data, tetris) == 0)
		{
			if (data->x == 3 && data->y == 3)
				return (0);
		}
	}
	return (1);
}

/*
	we go piece by piece and every time we couldn't fit the piece
	we data->count-- that we go there and move the previous piece 1 forward
*/
void	solve_map(t_data *data, t_tetris *tetris)
{
	data->count = 0;
	data->y = 0;
	data->x = 0;
	data->yx[0] = 0;
	data->yx[1] = 0;
	create_map(data, tetris);
	while (data->count < data->tetrimino)
	{
		if (solving(data, tetris) == 0)
		{
			data->count--;
			if (data->count == -1) // 3 - 1 = count = 2 ---> 
				re_create_map(data, tetris, data->size + 1);
			// else
			// 	cleanblock(data, tetris); // lisaa tahan data->x ja data->y kordinaatiot 'A' + count
		}
		else
			data->count++;
		data->counthash = 0;
	}
}