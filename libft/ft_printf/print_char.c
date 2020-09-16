/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/24 14:19:37 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/24 14:20:37 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(char x, t_flags *checks)
{
	checks->option &= ~(EU_HA | EU_Z | EU_P | EU_S | EU_PO);
	checks->option &= ~(EU_H | EU_HH | EU_EL | EU_LL | EU_L);
	if (checks->width > 0 && checks->option == 0)
	{
		if (checks->width > 1)
			print_width(checks->width - 1, checks);
	}
	write(1, &x, 1);
	checks->counter = checks->counter + 1;
	if (checks->width > 0 && checks->option == 8)
	{
		if (checks->width > 1)
			print_width(checks->width - 1, checks);
	}
}
