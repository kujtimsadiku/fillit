#ifndef FILLIT_H

# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

# define NL '\n'
# define BUFFSIZE 500
# define HASH '#'

typedef struct	s_data
{
	int i;
	int j;
	int x;
	int y;
	int limit;
	int count_hash;
	int	tetrimino;
	int ret_puzzle;
	int index;
	int hash; // amount of hastags
	int dot; // amount of dots
	int newline; // amount of newlines
	char puzzle[300];

}				t_data;

typedef struct	s_tetris
{
	char map[50][50];
	char **map1;
}				t_tetris;

void		check_map(t_data *data, char *filename);

#endif
