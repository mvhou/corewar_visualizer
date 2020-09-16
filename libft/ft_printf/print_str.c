/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/24 14:22:21 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/24 14:24:22 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ifnull(t_flags *checks)
{
	if (checks->option & EU_PO && checks->percision < 6)
	{
		checks->width = checks->width - checks->percision;
		if (!(checks->option & EU_M))
			print_width_0(checks->width, checks);
		write(1, "(null)", checks->percision);
		if (checks->option & EU_M)
			print_width_0(checks->width, checks);
		checks->counter = checks->counter + checks->percision;
	}
	else
	{
		checks->width = checks->width - 6;
		if (!(checks->option & EU_M))
			print_width_0(checks->width, checks);
		write(1, "(null)", 6);
		if (checks->option & EU_M)
			print_width_0(checks->width, checks);
		checks->counter = checks->counter + 6;
	}
}

void		print_strpers(char *x, t_flags *checks, int y)
{
	if (checks->percision < 0)
		checks->percision = checks->percision * -1;
	if (checks->percision > y)
		checks->width = checks->width - y;
	else
		checks->width = checks->width - checks->percision;
	if (checks->width > 0 && checks->option == 1024)
		print_width_0(checks->width, checks);
	if (checks->percision < y)
	{
		write(1, &(*x), checks->percision);
		checks->counter = checks->counter + checks->percision;
	}
	else
	{
		write(1, &(*x), y);
		checks->counter = checks->counter + y;
	}
	if (checks->width > 0 && checks->option == 1032)
		print_width_0(checks->width, checks);
}

void		print_str(char *x, t_flags *checks)
{
	int	y;

	if (x == NULL)
	{
		ifnull(checks);
		return ;
	}
	y = ft_strlen(x);
	checks->option &= ~(EU_HA | EU_Z | EU_P | EU_S);
	checks->option &= ~(EU_H | EU_HH | EU_EL | EU_LL | EU_L);
	if (checks->option < 1023)
	{
		if (checks->width > 0)
			checks->width = checks->width - y;
		if (checks->width > 0 && (!(checks->option & EU_M)))
			print_width_0(checks->width, checks);
		write(1, &(*x), y);
		checks->counter = checks->counter + y;
		if (checks->width > 0 && checks->option & EU_M)
			print_width_0(checks->width, checks);
	}
	else
		print_strpers(x, checks, y);
}
