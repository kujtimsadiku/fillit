/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:46:11 by ksadiku           #+#    #+#             */
/*   Updated: 2022/03/29 19:31:15 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*--- nb ottaa vastaan data->size + 1 ----*/

void	re_create_map(t_data *data, t_tetris *tetris, int nb)
{
	int	i;

	i = -1;
	while (++i < nb){
		ft_memset(tetris->map[i], '.', nb);
		printf("%s\n",  tetris->map[i]);
	}
	data->size = nb;
	data->y = 0;
	data->x = 0;
	data->count = 0;
}

void	create_map(t_data *data, t_tetris *tetris)
{
	int	i;
	double ret;

	ret = ft_sqrt(data->tetrimino * 4);
	data->size = ret;
	if (ret > data->size)
		data->size += 1;
	i = -1;
	while (++i < data->size)
	{
		ft_bzero(tetris->map[i], data->size + 1);
		ft_memset(tetris->map[i], '.', data->size);
		printf("%s\n", tetris->map[i]);
	}
	printf("The map is created\n");
}

void	cleanblock(t_data *data, t_tetris *tetris)
{
	// int y;
	// int x;
	int countletter;

	countletter = 0;
	data->y = 0;
	while (tetris->map[data->y] && data->y < data->size)
	{
		data->x = 0;
		while (tetris->map[data->y][data->x] && data->x < data->size)
		{
			if (tetris->map[data->y][data->x] == 'A' + data->count)
			{
				countletter++;
				tetris->map[data->y][data->x] = DOT;
			}
			// if (countletter == 1)
			// {
			// 	// if (x == 4)
			// 	// 	data->y = y;
			// 	// data->x = x + 1;
			// 	// data->y = y +;
			// }
			data->x++;
		}
		data->y++;
		if (countletter == 4 && data->x < data->size)
		{
			check_placement(data, tetris, data->y + 1, data->x);
		}
	}
}