/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:46:11 by ksadiku           #+#    #+#             */
/*   Updated: 2022/03/31 18:33:23 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*--- nb ottaa vastaan data->size + 1 ----*/

void	re_create_map(t_data *data, t_tetris *tetris, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		ft_memset(tetris->map[i], '.', nb);
	data->size = nb;
	data->y = 0;
	data->x = 0;
	data->count = 0;
}

void	create_map(t_data *data, t_tetris *tetris)
{
	int	i;
	int ret;

	ret = ft_sqrt(data->tetrimino * 4);
	data->size = ret;
	if (ret > data->size)
		data->size += 1;
	i = -1;
	while (++i < data->size)
	{
		ft_bzero(tetris->map[i], data->size + 1);
		ft_memset(tetris->map[i], '.', data->size);
	}
}

void	cleanblock(t_data *data, t_tetris *tetris, int count)
{
	int y;
	int x;
	int countletter;

	countletter = 0;
	y = 0;
	while (tetris->map[y] && y < data->size)
	{
		x = 0;
		while (tetris->map[y][x] && x < data->size)
		{
			if (tetris->map[y][x] == 'A' + count)
			{
				countletter++;
				tetris->map[y][x] = DOT;
				if (countletter == 1)
				{
					data->y = y;
					data->x = x;
				}
			}
			x++;
		}
		if (countletter == 4)
		{
			break ;
		}
		y++;
	}
}