#include "fillit.h"

static
static
static void check_placement(t_data *data, t_tetris *tetris)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tetris->map[j][i] == HASH && i < data->size)
	{
		if (i == 3)
		{
			j++;
			i = -1;
		}
		i++;
	}
	data->x = i;
	data->y = j;
}
// 
static find_block(t_data *data, t_tetris *tetris)
{

}

void	solve(t_data *data, t_tetris *tetris)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->count = 0;
	create_map(data, tetris);
}