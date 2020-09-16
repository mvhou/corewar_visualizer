/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_percision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 15:32:30 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/18 13:40:31 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percision(int y, t_flags *checks)
{
	while (y > 0)
	{
		write(1, "0", 1);
		y--;
		checks->counter = checks->counter + 1;
	}
}

void	print_percision_0(int y, t_flags *checks)
{
	while (y > 0)
	{
		write(1, "0", 1);
		y--;
		checks->counter = checks->counter + 1;
	}
}
