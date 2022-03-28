/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:32:36 by ksadiku           #+#    #+#             */
/*   Updated: 2022/03/28 12:40:44 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This is for the  symbol we going to add.
	It takes the piece number tetris->tetrimino[count] 
	and adds character + the number;
*/
#include "fillit.h"

char	symbol(int symbol_nb)
{
	char c;

	c = 'A' + symbol_nb;
	return (c);
}