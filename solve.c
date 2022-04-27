/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:56:51 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/26 15:09:46 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * check_coordination checks that the puzzle
 * doesnt overflow out from the map
 * if it overflows we want the data->y to increase by 1
 * and we set data->x to zero.
*/

static int	check_coordination(t_data *data, int y, int x, int p)
{
	if (data->size > y + data->coord.py[p][0] &&
		data->size > x + data->coord.px[p][0] &&
		data->size > y + data->coord.py[p][1] &&
		data->size > x + data->coord.px[p][1] &&
		data->size > y + data->coord.py[p][2] &&
		data->size > x + data->coord.px[p][2] &&
		data->size > y + data->coord.py[p][3] &&
		data->size > x + data->coord.px[p][3])
		return (1);
	else
	{
		data->y++;
		data->x = 0;
		return (0);
	}
}

/*
 * we check the coordinations y + py[] and x + px[] are equal to a dot
 * with this example we get faster checking because if all
 * them are not true(its not equal to a dot) we dont place it at all
 * and if its true(all the coordination are equal to dot) and if the
 * check_cordination its also true we place the block and return 1
*/
static int	placeblock(t_data *data, t_tetris *tetris, int y, int x)
{
	int	i;

	i = data->count;
	if (tetris->map[y + data->coord.py[i][0]]
		[x + data->coord.px[i][0]] == DOT &&
		tetris->map[y + data->coord.py[i][1]]
		[x + data->coord.px[i][1]] == DOT &&
		tetris->map[y + data->coord.py[i][2]]
		[x + data->coord.px[i][2]] == DOT &&
		tetris->map[y + data->coord.py[i][3]]
		[x + data->coord.px[i][3]] == DOT &&
		check_coordination(data, y, x, i))
	{
		tetris->map[y + data->coord.py[i][0]]
		[x + data->coord.px[i][0]] = 'A' + i;
		tetris->map[y + data->coord.py[i][1]]
		[x + data->coord.px[i][1]] = 'A' + i;
		tetris->map[y + data->coord.py[i][2]]
		[x + data->coord.px[i][2]] = 'A' + i;
		tetris->map[y + data->coord.py[i][3]]
		[x + data->coord.px[i][3]] = 'A' + i;
		return (1);
	}
	else
		return (0);
}

/*
 * when all the pieces are fitted on the map and
 * count variable(which piece it is in our tetromino struct)
 * we solve the map by calling recursively the function and return 1
 * else we call the cleanblock function.
*/

static int	solving(t_data *data, t_tetris *tetris, int count)
{
	data->y = -1;
	if (count == data->tetromino)
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
 * creates and re creates the map and calls the solving function
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
