/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:53:44 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/05 13:54:58 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_cordination(t_data *data, int y, int x, int p)
{
	if (data->size > y + data->py[p][0] && data->size > x + data->px[p][0] &&
		data->size > y + data->py[p][1] && data->size > x + data->px[p][1] &&
		data->size > y + data->py[p][2] && data->size > x + data->px[p][2] &&
		data->size > y + data->py[p][3] && data->size > x + data->px[p][3])
		return (1);
	else
		return (0);
}
