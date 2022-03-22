/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:47 by ksadiku           #+#    #+#             */
/*   Updated: 2022/03/21 18:03:30 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	add_data_values(t_data *data)
{
	data->hash = 0;
	data->dot = 0;
	data->newline = 0;
	data->tetrimino = 0;
	data->limit = 20;
}

static void	read_file(t_data *data, char *filename)
{
	int	ret;
	int	fd;

	fd = open(filename, O_RDONLY);
	ret = read(fd, data->puzzle, BUFFSIZE);
	if (ret < 0)
		exit(0);
	data->puzzle[ret] = '\0';
	close(fd);
}

static void	check_tetrimino(t_data *data)
{
	if (data->hash == 4 && data->dot == 12 && data->newline == 5)
	{
		data->tetrimino++;
		printf("Tetrimino: %d\n", data->tetrimino);
		printf("HASH: %d\n", data->hash);
		data->hash = 0;
		data->newline = 0;
		data->dot = 0;
	}
	else
	{
		printf("Invalid map");
		exit(0);
	}
}

static void	find_tetrimino(t_data *data)
{
	int	i;

	i = -1;
	while (data->puzzle[++i])
	{
		if (data->puzzle[i] == '.')
			data->dot++;
		if (data->puzzle[i] == '\n')
			data->newline++;
		if ((data->puzzle[i + 1] == HASH && data->puzzle[i] == HASH)
			|| (data->puzzle[i + 5] == HASH && data->puzzle[i] == HASH))
			data->hash++;
		else if (i > 1 && ((data->puzzle[i - 1] == HASH
					&& data->puzzle[i] == HASH) || (data->puzzle[i - 5]
					== HASH && data->puzzle[i] == HASH)))
			data->hash++;
		if (data->puzzle[i] == NL && data->puzzle[i - 1] == NL)
			check_tetrimino(data);
	}
	printf("Reading was success\n");
}

void	check_map(t_data *data, char *filename)
{
	add_data_values(data);
	read_file(data, filename);
	find_tetrimino(data);
	/*if (0 != (i + 1) % data->limit) 	"Checks the map is valid size"
	{
		printf("%lu\n", strlen(data->puzzle));
		printf("Exit on if (0 != i %% data->limit)");
		exit(0);
	}*/
}
