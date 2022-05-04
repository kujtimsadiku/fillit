#include "fillit.h"

/*
	to make it faster we check does the next x have dot so we can automatically check 
	the placement
*/

// int fast_help(t_data *data, t_tetris *tetris, int y, int x)
// {
// 	int i = data->count;

// 	if ()

// }

// int faster(t_data *data, t_tetris *tetris, int y, int x)
// {
// 	int i = data->count;

// 	if (tetris->map[y + data->coord.py[i][1]
// 		[x + data->coord.px[i][1]] == DOT && data->coord.py[i][1] == 0)
// 	{
// 		fast_help(data, tetris, y + data->coord.py[i][1], x + data->coord.px[i][1]);
// 	}
// 	else if (tetris->map[y + data->coord.py[i][2]]
// 		[x + data->coord.px[i][2]] == DOT && data->coord.py[i][2] == 0)
// 	{
// 		fast_help(data, tetris, y + data->coord.py[i][2], x + data->coord.px[i][2]);
// 	}
// 	else if (tetris->map[y + data->coord.py[i][3]]
// 		[x + data->coord.px[i][3]] == DOT && data->coord.py[i][3] == 0)
// 	{
// 		fast_help(data, tetris, y + data->coord.py[i][3], x + data->coord.px[i][3]);
// 	}
// }

int faster(t_data *data, t_tetris *tetris, int y, int x)
{
	while (tetris->map[y] && data->y < data->size)
	{
		while (tetris->map[y][x] && data->x < data->size)
		{
			
		}
	}
}