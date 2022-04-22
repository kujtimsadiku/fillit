#ifndef FILLIT_H

# define FILLIT_H

# define MAXMAP 20
# define BUFFSIZE 600
# define NL '\n'
# define HASH '#'
# define DOT '.'
# define MAX 26

# include <fcntl.h>
# include "libft/includes/libft.h"


typedef struct	s_data
{
	int		i; 
	int		j;
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		count;
	int		size;
	int		limit;
	int		tetromino;
	int		hash;
	int		dot;
	int		newline;
	int		counthash;
	int		countletter;
	int		counter;
	int		py[30][4];
	int		px[30][4];
	char	c;
	char	puzzle[600];
}				t_data;

typedef struct	s_tetromino
{
	char	piece[4][4];
}				t_tetromino;

typedef struct	s_tetris
{
	char		map[20][20];
	char		piece[250][250];
	char		block[4][4];
	t_tetromino	minos[28];
}				t_tetris;

void	read_map(t_data *data, char *filename);
void	create_map(t_data *data, t_tetris *tetris);
void	re_create_map(t_data *data, t_tetris *tetris, int nb);
void	solve_map(t_data *data, t_tetris *tetris);
void	save_tetromino(t_data *data, t_tetris *tetris);
void	shifter(t_data *data, int p);
void	cleanblock(t_data *data, t_tetris *tetris, int count);
void	errors(int error);
void	print_map(t_data *data, t_tetris *tetris);


#endif
