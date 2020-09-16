/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_pointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/24 14:21:19 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/24 14:21:50 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_pointer(unsigned long long int x, t_flags *checks)
{
	int					i;

	i = count_position(x, 16) + 2;
	if (i == 2)
		i = 3;
	if (checks->width > i && checks->option == 0)
	{
		checks->width = checks->width - i;
		print_width_0(checks->width, checks);
	}
	write(1, "0x", 2);
	if ((!(checks->option & EU_PO && x == 0 && checks->percision == 0)))
		putnbr_base((unsigned long long)x, 16, 0);
	else
		i = i - 1;
	if (checks->width > i && checks->option & EU_M)
	{
		checks->width = checks->width - i;
		print_width_0(checks->width, checks);
	}
	checks->counter = checks->counter + i;
}
