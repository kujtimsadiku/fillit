/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:02:36 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/03 14:09:26 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# define MAXMAP 20
# define BUFFSIZE 600
# define NL '\n'
# define HASH '#'
# define DOT '.'
# define MAX 26

# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_coord
{
	int		x2;
	int		y2;
	int		px[30][4];
	int		py[30][4];
}				t_coord;

typedef struct s_valid
{
	int		hash;
	int		dot;
	int		newline;
}				t_valid;

typedef struct s_data
{
	t_coord	coord;
	t_valid	valid;	
	int		y;
	int		x;
	int		i;
	int		j;
	int		size;
	int		limit;
	int		tetromino;
	int		count;
	int		counter;
	int		counthash;
	int		countletter;
	char	c;
	char	puzzle[600];
}				t_data;

typedef struct s_tetromino
{
	char	piece[4][4];
}				t_tetromino;

typedef struct s_tetris
{
	char		map[20][20];
	char		piece[250][250];
	char		block[4][4];
	t_tetromino	minos[28];
}				t_tetris;

void	read_map(t_data *data, char *filename);
void	save_tetromino(t_data *data, t_tetris *tetris);

void	solve_map(t_data *data, t_tetris *tetris);
void	shifter(t_data *data, int p);

void	print_map(t_data *data, t_tetris *tetris);
void	errors(int error);

void	re_create_map(t_data *data, t_tetris *tetris, int nb);
void	cleanblock(t_data *data, t_tetris *tetris, int count);
void	create_map(t_data *data, t_tetris *tetris);

#endif
