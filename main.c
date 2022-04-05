/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:17:05 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/05 15:28:42 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

	if (argc != 2)
		errors(1);
	check_map(&data, argv[1]);
	save_tetrimino(&data, &tetris);
	solve_map(&data, &tetris);
	print_map(&data, &tetris);
	return (0);
}
