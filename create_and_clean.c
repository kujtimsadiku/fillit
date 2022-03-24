/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:46:11 by ksadiku           #+#    #+#             */
/*   Updated: 2022/03/24 13:43:31 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*--- nb ottaa vastaan data->res + 1 ----*/
void	clean_map(t_data *data, t_tetris *tetris)
{
	int i;

	i = -1;
	while (++i < data->new_res)
		ft_memset(tetris->map[i], '.', data->res);
}

void	re_create_map(t_data *data, t_tetris *tetris, int nb)
{
	int	i;

	i = -1;
	while (++i < nb){
		ft_memset(tetris->map[i], '.', nb);
		printf("%s\n",  tetris->map[i]);
	}
	data->new_res = nb;
}

void	create_map(t_data *data, t_tetris *tetris)
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
	printf("The map is created\n");
}