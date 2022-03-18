#include "fillit.h"

static void	read_file(t_data *data, char *filename)
{
	int	ret;
	int	fd;

	fd = open(filename, O_RDONLY);
	ret = read(fd, data->puzzle, BUFFSIZE);
	data->puzzle[ret] = '\0';
	data->count_hash = 0;
	data->dot = 0;
	data->limit = 20;
	data->tetrimino = 0;
	data->index = -1;
	close(fd);
}

static void	check_tetrimino(t_data *data)
{
	if (data->count_hash == 4)
	{
		data->tetrimino++;
		printf("Tetrimino: %d\n", data->tetrimino);
		printf("HASH: %d\n", data->count_hash);
		data->count_hash = 0;
	}
	else
	{
		printf("Exit was success");
		exit(0);
	}
}

void	check_map(t_data *data, char *filename)
{
	int	i;

	i = -1;
	read_file(data, filename);
	while (data->puzzle[++i])
	{
		if (data->puzzle[i] == '.')
			data->dot++;
		if ((data->puzzle[i + 1] == HASH && data->puzzle[i] == HASH) 
			|| (data->puzzle[i + 5] == HASH && data->puzzle[i] == HASH))
			data->count_hash++;
		else if (i > 1 && ((data->puzzle[i - 1] == HASH 
				&& data->puzzle[i] == HASH) || (data->puzzle[i - 5] 
					== HASH && data->puzzle[i] == HASH)))
			data->count_hash++;
		if (data->puzzle[i] != '#' && data->puzzle[i] != '.' 
			&& data->puzzle[i] != '\n')
			exit(0);
		if (0 == i % data->limit && i > 19)
			check_tetrimino(data);
	}
	if (0 != i % data->limit) 	/*Checks the map is valid size*/
		exit(0);
}

// if (data->count_hash == 4)
// 		{0
// 			printf("HASH: %d\n", data->count_hash);
// 			data->tetrimino++;
// 			printf("Tetrimino: %d\n", data->tetrimino);
// 			data->count_hash = 0;
// 			// check_tetrimino(data);
// 		}
