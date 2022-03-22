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

void	recursive_solving(t_data *data, t_tetris *tetris)
{
	int i;
	int j;
	j = 0;
	while (    )
}

void	solve_map(t_data *data, t_tetris *tetris)
{
	data->count = -1;
	create_map(data, tetris);
	while (++data->count < data->tetrimino)
		recursive_solving(data, tetris);
}