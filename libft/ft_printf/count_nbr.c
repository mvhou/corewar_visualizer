/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_nbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 12:03:28 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/18 15:58:13 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_s_nbr(long long x)
{
	int	y;

	y = 0;
	while (x != 0)
	{
		x = x / 10;
		y++;
	}
	return (y);
}

int	count_position(unsigned long long x, unsigned long long z)
{
	int y;

	y = 0;
	while (x > 0)
	{
		x = x / z;
		y++;
	}
	return (y);
}

int	count_nbr(t_flags *checks, unsigned long long x)
{
	int y;

	if (x == 0)
		return (0);
	if (checks->specifier == 'x' || checks->specifier == 'X')
		y = count_position(x, 16);
	else if (checks->specifier == 'o')
		y = count_position(x, 8);
	else
		y = count_position(x, 10);
	return (y);
}
