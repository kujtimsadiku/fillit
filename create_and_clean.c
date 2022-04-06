/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:46:11 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/06 15:08:26 by ksadiku          ###   ########.fr       */
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
	int		i;
	double	ret;

	ret = ft_sqrt(data->tetrimino * 4);
	data->size = ret;
	if (ret > data->size)
		data->size += 1;
	i = -1;
	while (++i < data->size)
		ft_memset(tetris->map[i], '.', data->size);
}

void	cleanblock(t_data *data, t_tetris *tetris, int count)
{
	data->countletter = 0;
	data->y2 = 0;
	while (tetris->map[data->y2] && data->y2 < data->size)
	{
		data->x2 = 0;
		while (tetris->map[data->y2][data->x2] && data->x2 < data->size)
		{
			if (tetris->map[data->y2][data->x2] == 'A' + count)
			{
				data->countletter++;
				tetris->map[data->y2][data->x2] = DOT;
				if (data->countletter == 1)
				{
					data->y = data->y2;
					data->x = data->x2;
				}
			}
			data->x2++;
		}
		if (data->countletter == 4)
			break ;
		data->y2++;
	}
}
