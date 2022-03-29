#include "fillit.h"

/*----py[] & px[] hold the puzzle cordination----*/
static void block_values(t_data *data, t_tetris *tetris, int y, int x)
{
	while (y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tetris->minos[data->count].piece[y][x] == HASH)
			{
				data->py[data->counthash] = y;
				data->px[data->counthash] = x;
				printf("py[%d] == HASH\n", data->py[data->counthash]);
				printf("px[%d] == HASH\n", data->px[data->counthash]);
				data->counthash++;
			}
			if (data->counthash == 4)
				break ;
		}
		y++;
	}
}

static int	placeblock(t_data *data, t_tetris *tetris, int y, int x)
{
	shifter(data);
	if (tetris->map[y + data->py[0]][x + data->px[0]] == DOT &&
		tetris->map[y + data->py[1]][x + data->px[1]] == DOT &&
		tetris->map[y + data->py[2]][x + data->px[2]] == DOT &&
		tetris->map[y + data->py[3]][x + data->px[3]] == DOT &&
		check_cordination(data, y, x))
	{
		tetris->map[y + data->py[0]][x + data->px[0]] = 'A' + data->count;
		tetris->map[y + data->py[1]][x + data->px[1]] = 'A' + data->count;
		tetris->map[y + data->py[2]][x + data->px[2]] = 'A' + data->count;
		tetris->map[y + data->py[3]][x + data->px[3]] = 'A' + data->count;
		int i = 0;
		while (i < data->size)
		{
			printf("%s\n", tetris->map[i]);
			i++;
		}
		sleep(2);
		data->y = 0;
		data->x = 0;
		return (1);
	}
	else
		return (0);
}

/*----checks if the y and x is dot----*/
int	check_placement(t_data *data, t_tetris *tetris, int y, int x)
{
	while (tetris->map[y] && y < data->size)
	{
		x = 0;
		while (tetris->map[y][x] && x < data->size)
		{
			if (tetris->map[y][x] == DOT)
			{
				if (placeblock(data, tetris, y, x) == 1)
					return (1);
				// if (data->x == data->size)
				// 	data->x = -1;
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	solving(t_data *data, t_tetris *tetris)
{
	if (data->count < data->tetrimino)
	{
		block_values(data, tetris, 0, 0);
		if (check_placement(data, tetris, 0, 0) == 0)
		{
			return (0);
			// if (data->y == data->size && data->x == data->size)
			// 	return (0);
		}
		// else
		// {
		// 	data->y = -1;
		// 	data->x = -1;
		// }
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
		printf("1");
		if (solving(data, tetris) == 0)
		{
			data->count--;
			// cleanblock(data, tetris);
			if (data->count == -1) // 3 - 1 = count = 2 ---> 
				re_create_map(data, tetris, data->size + 1);
			else
				cleanblock(data, tetris); // lisaa tahan data->x ja data->y kordinaatiot 'A' + count
		}
		else
			data->count++;
		data->counthash = 0;
	}
}