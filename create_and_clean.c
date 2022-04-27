/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:46:11 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/25 08:53:50 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * re creates the map if all the puzzles have been thru all
 * the possibilities that are available.
 * nb takes; data->size + 1 and increase the map by one
 * and x & y are set back to zero.
*/

void	re_create_map(t_data *data, t_tetris *tetris, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		ft_memset(tetris->map[i], '.', (size_t)nb);
	data->size = nb;
	data->count = 0;
}

/*
 * ----creates the map-----
 *  by ret(return) being double whe can see if its decimal number
 *  with that we can round it up. Ex. 5.25 = 6 and get the correct
 *  size map.
 *  then we memset the map with dots
*/

void	create_map(t_data *data, t_tetris *tetris)
{
	int		i;
	double	ret;

	ret = ft_sqrt(data->tetromino * 4);
	data->size = (int)ret;
	if (ret > data->size)
		data->size += 1;
	i = -1;
	while (++i < data->size)
		ft_memset(tetris->map[i], '.', (size_t)data->size);
}

/*
 * here we clean the previous piece if the current puzzle dont fit on the map.
 * with data->countletter we can break the loop so we dont try to read
 * the whole map even if we have found the piece. 
 * with this break we can make the solving more efficient.
 * data->y & data->coord.x will take first location of the first letter
 * from the piece that is found so we can continue to the next placement
 * 65 = 'A'
*/

void	cleanblock(t_data *data, t_tetris *tetris, int count)
{
	data->countletter = 0;
	data->coord.y2 = 0;
	while (tetris->map[data->coord.y2] && data->coord.y2 < data->size)
	{
		data->coord.x2 = 0;
		while (tetris->map[data->coord.y2][data->coord.x2] &&
			data->coord.x2 < data->size)
		{
			if (tetris->map[data->coord.y2][data->coord.x2] == 'A' + count)
			{
				data->countletter++;
				tetris->map[data->coord.y2][data->coord.x2] = DOT;
				if (data->countletter == 1)
				{
					data->y = data->coord.y2;
					data->x = data->coord.x2;
				}
			}
			data->coord.x2++;
		}
		if (data->countletter == 4)
			break ;
		data->coord.y2++;
	}
}
