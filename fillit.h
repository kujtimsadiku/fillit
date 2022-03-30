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
	int x;
	int y;
	int x2;
	int y2;
	int new_size;
	int count;
	int size;
	int limit;
	int	tetrimino; // pieces
	int hash; // amount of hastags
	int dot; // amount of dots
	int newline; // amount of newlines
	int multip;
	int counthash;
	int py[4];
	int px[4];
	int yx[2];
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
	t_tetrimino minos[28];
}				t_tetris;

void	check_map(t_data *data, char *filename);
void	create_map(t_data *data, t_tetris *tetris);
void	re_create_map(t_data *data, t_tetris *tetris, int nb);
void	solve_map(t_data *data, t_tetris *tetris);
void	save_tetrimino(t_data *data, t_tetris *tetris);
char	symbol(int symbol_nb);
void	shifter(t_data *data);
void	cleanblock(t_data *data, t_tetris *tetris, int count);
int		check_cordination(t_data *data, int y, int x);

#endif
