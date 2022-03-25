/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:46:11 by ksadiku           #+#    #+#             */
/*   Updated: 2022/03/25 14:59:37 by ksadiku          ###   ########.fr       */
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
	data->new_size = nb;
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
	data->new_size = data->size;
	printf("The map is created\n");
}