#ifndef FILLIT_H

# define FILLIT_H

# define MAXMAP 20
# define BUFFSIZE 600
# define NL '\n'
# define HASH '#'
# define DOT '.'

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
	int		tetrimino;
	int		hash;
	int		dot;
	int		newline;
	int		counthash;
	int		countletter;
	int		py[30][4];
	int		px[30][4];
	char	c;
	char	puzzle[600];
}				t_data;

typedef struct	s_tetrimino
{
	char	piece[4][4];
}				t_tetrimino;

typedef struct	s_tetris
{
	char		map[20][20];
	char		piece[200][200];
	char		block[4][4];
	t_tetrimino	minos[28];
}				t_tetris;

void	check_map(t_data *data, char *filename);
void	create_map(t_data *data, t_tetris *tetris);
void	re_create_map(t_data *data, t_tetris *tetris, int nb);
void	solve_map(t_data *data, t_tetris *tetris);
void	save_tetrimino(t_data *data, t_tetris *tetris);
void	shifter(t_data *data, int p);
void	cleanblock(t_data *data, t_tetris *tetris, int count);
int		check_cordination(t_data *data, int y, int x, int p);
void	errors(int error);

#endif
