/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:47 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/25 08:58:47 by ksadiku          ###   ########.fr       */
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

/*
 * valid_tet check how many connection we have gotten with the algo
 * the correct checkins are 6 || 8 depends on the piece
 * 12 dots and 4 newlines.
 * we check that the 4x4 is correct
*/

static void	valid_tet(t_data *data, char *str, int i)
{
	if ((data->valid.hash == 6 || data->valid.hash == 8)
		&& data->valid.dot == 12 && data->valid.newline == 4)
	{
		data->tetromino++;
		data->valid.hash = 0;
		data->valid.newline = 0;
		data->valid.dot = 0;
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

/*
 * with the if checking algorithm we can check if the
 * hashes are connected to each other correctly.
 * if they are correctly connected we return 1 if not then 0.
*/

static int	check_map(t_data *data, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == DOT)
			data->valid.dot++;
		if (str[i] == NL && str[i - 1] != NL)
			data->valid.newline++;
		if (str[i] == HASH && str[i + 1] == HASH)
			data->valid.hash++;
		if (str[i] == HASH && str[i + 5] == HASH)
			data->valid.hash++;
		if (i > 0 && str[i] == HASH && str[i - 1] == HASH)
			data->valid.hash++;
		if (i > 4 && str[i] == HASH && str[i - 5] == HASH)
			data->valid.hash++;
		if ((data->puzzle[i] == NL && data->puzzle[i + 1] == NL)
			|| (data->puzzle[i] == NL && data->puzzle[i + 1] == '\0'))
		{
			valid_tet(data, str, i);
			return (1);
		}
	}
	return (0);
}

/*
 * we create a temp that holds 22 characters (1 extra just in case)
 * we bzero it always so that there wont be any unnecessary characters
 * we add i += 21 to skip current 4x4 to get to the next one (4x4)
 * with error checking we can see that the piece(4x4) is
 * not a valid piece(4x4)
*/

static void	find_tetromino(t_data *data)
{
	int		i;
	char	temp[22];

	i = 0;
	ft_bzero(temp, 22);
	while (data->puzzle[i] == HASH || data->puzzle[i] == DOT)
	{	
		if (check_map(data,
				ft_memcpy(temp, &data->puzzle[i], (size_t)data->limit)))
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
	if (data->tetromino > MAX)
		errors(0);
}

/*
 * we open the file and read it to data->puzzle
 * and we have BUFFSIZE big enough to read the max
*/

void	read_map(t_data *data, char *filename)
{
	int	fd;
	int	ret;

	add_data_values(data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		errors(0);
	ret = read(fd, data->puzzle, BUFFSIZE);
	if (ret < 0)
		errors(0);
	data->puzzle[ret] = '\0';
	close(fd);
	find_tetromino(data);
	if (data->tetromino == 0)
		errors(0);
}
