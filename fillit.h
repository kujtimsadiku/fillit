#ifndef FILLIT_H

# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

# define BUFFSIZE 500
# define NL '\n'
# define HASH '#'
# define DOT '.'

typedef struct	s_data
{
	int i;
	int j;
	int x1;
	int y1;
	int x2;
	int y2;
	int new_res;
	int count;
	int res;
	int limit;
	int	tetrimino;
	int hash; // amount of hastags
	int dot; // amount of dots
	int newline; // amount of newlines
	int multip;
	char c;
	char puzzle[500];
}				t_data;

typedef struct	s_tetrimino
{
	char	piece[4][4];
}				t_tetrimino;

typedef struct	s_tetris
{
	char	map[50][50];
	char 	piece[500][500];
	char	block[4][4];
	t_tetrimino tetriminos[28];
}				t_tetris;

void	check_map(t_data *data, char *filename);
void	save_tetrimino(t_data *data, t_tetris *tetris);
// void	solve_map(t_data *data, t_tetris *tetris);

#endif
