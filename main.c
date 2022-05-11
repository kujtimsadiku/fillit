/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:17:05 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/11 12:13:10 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*----init values------*/

static void	add_data_values(t_data *data)
{
	data->valid.hash = 0;
	data->valid.dot = 0;
	data->valid.newline = 0;
	data->tetromino = 0;
	data->limit = 21;
	data->counthash = 0;
}

void	errors(int error)
{
	if (error == 0)
	{
		ft_putendl("error");
		exit(1);
	}
	else if (error == 1)
	{
		ft_putendl("Usage: ./fillit <filename>");
		exit(1);
	}
}

void	print_map(t_data *data, t_tetris *tetris)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		ft_putstr(tetris->map[i]);
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_tetris	tetris;

	add_data_values(&data);
	if (argc != 2)
		errors(1);
	read_map(&data, argv[1]);
	save_tetromino(&data, &tetris);
	solve_map(&data, &tetris);
	print_map(&data, &tetris);
	return (0);
}
