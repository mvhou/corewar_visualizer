/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hash.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 18:27:17 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/09/20 16:47:51 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ifhash(int y, t_flags *checks)
{
	write(1, "0", 1);
	y--;
	checks->counter = checks->counter + 1;
	if (checks->specifier == 'x')
	{
		y--;
		write(1, "x", 1);
		checks->counter = checks->counter + 1;
	}
	else if (checks->specifier == 'X')
	{
		write(1, "X", 1);
		y--;
		checks->counter = checks->counter + 1;
	}
	return (y);
}
