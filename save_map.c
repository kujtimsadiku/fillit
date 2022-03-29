/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:43 by ksadiku           #+#    #+#             */
/*   Updated: 2022/03/29 17:06:41 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// static void	struct_tetrimino(t_data *data, t_tetris *tetris)
// {
// 	int	count;

// 	count = -1;
// 	data->j = -1;
// 	data->i = 0;
// 	while (tetris->piece[++data->j])
// 	{
// 		if (tetris->piece[data->j][0] != NL && data->i < 4)
// 		{
// 			ft_bzero(tetris.minos[count].piece[data->i], 5);
// 			ft_memcpy(tetris.minos[count].piece[data->i], tetris->piece[data->j], 4);
// 			printf("%s", tetris.minos[count].piece[data->i]);
// 			data->i++;
// 			if (data->i == 4)
// 			{
// 				count++;
// 				data->i = 0;
// 			}
// 		}
// 		if (tetris->piece[data->j][0] == NL && tetris->piece[data->j + 1][0] == '\0')
// 		{
// 			printf("We have breaked successfully from while loop\n");
// 			break ;
// 		} 
// 		printf("\n");
// 	}
// }

// void	save_tetrimino(t_data *data, t_tetris *tetris)
// {
// 	int	index;

// 	data->j = 0;
// 	data->i = 0;
// 	index = -1;
// 	while (data->puzzle[++index])
// 	{
// 		data->c = data->puzzle[index];
// 		tetris->piece[data->j][data->i] = data->c;
// 		if (tetris->piece[data->j][data->i] == NL)
// 		{
// 			data->j++;
// 			data->i = -1;
// 		}
// 		data->i++;
// 	}
// 	struct_tetrimino(data, tetris);
// }


static void	struct_tetrimino(t_data *data, t_tetris *tetris)
{
	int	count;

	count = 0;
	data->j = -1;
	data->i = 0;
	while (tetris->piece[++data->j])
	{
		if (tetris->piece[data->j][0] != NL && data->i < 4)
		{
			ft_bzero(tetris->minos[count].piece[data->i], 5);
			ft_memcpy(tetris->minos[count].piece[data->i], tetris->piece[data->j], 4);
			// tetris.minos[count].piece[data->i] = ft_strsub(tetris->piece[data->j], 0, 4);
			printf("%s", tetris->minos[count].piece[data->i]);
			data->i++;
			if (data->i == 4)
			{
				count++;
				data->i = 0;
			}
		}
		if (tetris->piece[data->j][0] == NL && tetris->piece[data->j + 1][0] == '\0')
		{
			printf("We have breaked successfully from while loop\n");
			break ;
		}
		printf("\n");
	}
}


void	save_tetrimino(t_data *data, t_tetris *tetris)
{
	int	index;

	data->j = 0;
	data->i = 0;
	index = -1;
	while (data->puzzle[++index])
	{
		data->c = data->puzzle[index];
		tetris->piece[data->j][data->i] = data->c;
		if (tetris->piece[data->j][data->i] == NL)
		{
			// move_the_piece(data, tetris);
			data->j++;
			data->i = -1;
		}
		data->i++;
	}
	struct_tetrimino(data, tetris);
}