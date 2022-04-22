/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:13:46 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/22 12:02:20 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	shift_x(t_data *data, int p, int n)
{
	data->px[p][0] += n;
	data->px[p][1] += n;
	data->px[p][2] += n;
	data->px[p][3] += n;
}

static void	shift_y(t_data *data, int p, int n)
{
	data->py[p][0] += n;
	data->py[p][1] += n;
	data->py[p][2] += n;
	data->py[p][3] += n;
}

/*
 * p = piece(the pieces coordination)
 * here we use our shifter to shift the piece top left
 * by changing the coordinations
 * the main reason for this is that first px[pieces][0] must
 * equal to 0 so that when we place the block our calculation will
 * be correct
 * the coordinations can go also under zero
 * but the first px coordinatio must be 0
 *
 *	example before and after
 * 1	2	   1	2	
 * ....	....	   #...	#...
 * ...#	.#..     ###...	###.
 * .###	.###	   ....	....
 * ....	....	   ....	....
 *
 * 1->coords px[p][0,-2,-1,0]
 * 2->coords px[p][0,0,1,2]
*/

void	shifter(t_data *data, int p)
{
	while (data->px[p][0] != 0 && data->px[p][1] != 0 &&
		data->px[p][2] != 0 && data->px[p][3] != 0)
	{
		shift_x(data, p, -1);
	}
	while (data->py[p][0] != 0 && data->py[p][1] != 0 &&
		data->py[p][2] != 0 && data->py[p][3] != 0)
	{
		shift_y(data, p, -1);
	}
	while (data->px[p][0] != 0 && data->py[p][0] == 0)
		shift_x(data, p, -1);
}
