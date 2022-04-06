/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:56:51 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/06 15:10:43 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_cordination(t_data *data, int y, int x, int p)
{
	if (data->size > y + data->py[p][0] && data->size > x + data->px[p][0] &&
		data->size > y + data->py[p][1] && data->size > x + data->px[p][1] &&
		data->size > y + data->py[p][2] && data->size > x + data->px[p][2] &&
		data->size > y + data->py[p][3] && data->size > x + data->px[p][3])
		return (1);
	else
		return (0);
}

/*---tekstia----*/
static int	placeblock(t_data *data, t_tetris *tetris, int y, int x)
{
	int	i;

	i = data->count;
	if (tetris->map[y + data->py[i][0]][x + data->px[i][0]] == DOT &&
		tetris->map[y + data->py[i][1]][x + data->px[i][1]] == DOT &&
		tetris->map[y + data->py[i][2]][x + data->px[i][2]] == DOT &&
		tetris->map[y + data->py[i][3]][x + data->px[i][3]] == DOT &&
		check_cordination(data, y, x, i))
	{
		tetris->map[y + data->py[i][0]][x + data->px[i][0]] = 'A' + i;
		tetris->map[y + data->py[i][1]][x + data->px[i][1]] = 'A' + i;
		tetris->map[y + data->py[i][2]][x + data->px[i][2]] = 'A' + i;
		tetris->map[y + data->py[i][3]][x + data->px[i][3]] = 'A' + i;
		return (1);
	}
	else
		return (0);
}

static int	solving(t_data *data, t_tetris *tetris, int count)
{
	data->y = -1;
	if (count == data->tetrimino)
		return (1);
	while (tetris->map[++data->y] && data->y < data->size)
	{
		data->x = 0;
		while (tetris->map[data->y][data->x] && data->x < data->size)
		{
			if (tetris->map[data->y][data->x] == DOT)
			{
				data->count = count;
				if (placeblock(data, tetris, data->y, data->x) == 1)
				{
					if (solving(data, tetris, count + 1))
						return (1);
					else
						cleanblock(data, tetris, count);
				}
			}
			data->x++;
		}
	}
	return (0);
}

/*
**	Here we we call our function "solving" on a while loop.
** 	If the return from solving is 0 it will re create the map by size + 1
**	If its 1 it means the map is created.
*/
void	solve_map(t_data *data, t_tetris *tetris)
{
	data->y = 0;
	data->x = 0;
	create_map(data, tetris);
	while (!solving(data, tetris, 0))
	{
		re_create_map(data, tetris, data->size + 1);
	}
}
