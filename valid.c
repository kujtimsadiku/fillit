/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:47 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/12 17:50:17 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	add_data_values(t_data *data)
{
	data->hash = 0;
	data->dot = 0;
	data->newline = 0;
	data->tetrimino = 0;
	data->limit = 21;
	data->counthash = 0;
}

static void	valid_tet(t_data *data, char *str, int i)
{
	if ((data->hash == 6 || data->hash == 8)
		&& data->dot == 12 && data->newline == 4)
	{
		data->tetrimino++;
		data->hash = 0;
		data->newline = 0;
		data->dot = 0;
		if (str[i] == NL && str[i + 1] == '\0' && str[i - 1] == NL)
			errors(0);
		else if (str[i] == NL && str[i + 1] == NL && str[i - 1] == NL)
			errors(0);
		else if (str[i] == NL && str[i + 1] == NL)
			return ;
		else if (str[i] == NL && str[i + 1] == '\0')
			return ;
	}
	else
		errors(0);
}

static int	check(t_data *data, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == DOT)
			data->dot++;
		if (str[i] == NL && str[i - 1] != NL)
			data->newline++;
		if (str[i] == HASH && str[i + 1] == HASH)
			data->hash++;
		if (str[i] == HASH && str[i + 5] == HASH)
			data->hash++;
		if (i > 0 && str[i] == HASH && str[i - 1] == HASH)
			data->hash++;
		if (i > 4 && str[i] == HASH && str[i - 5] == HASH)
			data->hash++;
		if ((data->puzzle[i] == NL && data->puzzle[i + 1] == NL)
			|| (data->puzzle[i] == NL && data->puzzle[i + 1] == '\0'))
		{
			valid_tet(data, str, i);
			return (1);
		}
	}
	return (0);
}

static void	find_tetrimino(t_data *data)
{
	int		i;
	char	temp[22];

	i = 0;
	ft_bzero(temp, 22);
	while (data->puzzle[i] == HASH || data->puzzle[i] == DOT)
	{	
		if (check(data, ft_memcpy(temp, &data->puzzle[i], data->limit)))
		{
			ft_bzero(temp, 22);
			i += 21;
		}
		else
			errors(0);
	}
	if (data->puzzle[i] == NL)
		errors(0);
	if (0 != i % data->limit || (data->puzzle[i - 1] == NL
			&& data->puzzle[i] == '\0' && data->puzzle[i - 2] == NL))
		errors(0);
	if (data->tetrimino > MAX)
		errors(0);
}

void	check_map(t_data *data, char *filename)
{
	int	fd;
	int	ret;

	add_data_values(data);
	fd = open(filename, O_RDONLY);
	if (fd == 0)
		errors(0);
	ret = read(fd, data->puzzle, BUFFSIZE);
	if (ret < 0)
		errors(0);
	data->puzzle[ret] = '\0';
	close(fd);
	find_tetrimino(data);
	if (data->tetrimino == 0)
		errors(0);
}
