#include "fillit.h"

/*--- nb ottaa vastaan data->res + 1 ----*/
// static void	re_create_map(t_data *data, t_tetris *tetris, int nb)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < nb)
// 		ft_memset(tetris->map[i], '.', nb);
// 	data->new_res = nb;
// }

static clean_map(t_data *data, t_tetris *tetris)
{
	int i;

	i = -1;
	while (++i < data->new_res)
		ft_memset(tetris->map[i], '.', data->res);
}

static void	create_map(t_data *data, t_tetris *tetris)
{
	int	i;
	double ret;

	ret = ft_sqrt(data->tetrimino * 4);
	data->res = ret;
	if (ret > data->res)
		data->res += 1;
	i = -1;
	while (++i < data->res)
	{
		ft_bzero(tetris->map[i], data->res + 1);
		ft_memset(tetris->map[i], '.', data->res);
		printf("%s\n", tetris->map[i]);
	}
	data->new_res = data->res;
}

static int	recursive_solving(t_data *data, t_tetris *tetris, int y, int x)
{
	while (y < data->new_res)
	{
		while (x < data->new_res)
		{
			if (tetris->tetriminos[data->count].piece[y][x] == HASH)
				tetris->map[y][x] = symbol(data->count);
			i++;
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