/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 15:33:17 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/01/15 13:48:16 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(int y, t_flags *checks)
{
	if (checks->option & EU_M)
		checks->option &= ~EU_Z;
	if (checks->percision > -1 && checks->option & EU_PO)
		checks->option &= ~EU_Z;
	if (checks->option & EU_Z)
		print_width_zero(y, checks);
	else
	{
		while (y > 0)
		{
			write(1, " ", 1);
			y--;
			checks->counter = checks->counter + 1;
		}
	}
	checks->width = 0;
}

void	print_width_0(int y, t_flags *checks)
{
	if (checks->option & EU_M || checks->option & EU_PO)
		checks->option &= ~EU_Z;
	if (checks->option & EU_Z && (!(checks->option & EU_PO)))
		print_width_zero(y, checks);
	else
	{
		while (y > 0)
		{
			write(1, " ", 1);
			y--;
			checks->counter = checks->counter + 1;
		}
	}
	checks->width = 0;
}

void	print_width_zero(int y, t_flags *checks)
{
	while (y > 0)
	{
		write(1, "0", 1);
		y--;
		checks->counter = checks->counter + 1;
	}
	if (!(checks->option & EU_M && checks->width > 0))
		checks->width = 0;
}
