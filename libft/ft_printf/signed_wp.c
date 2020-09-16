/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signed_wp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 08:08:40 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/19 21:47:44 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_s_width_percision4(t_flags *checks, int y, long long x)
{
	if (checks->option & EU_PO)
		checks->option &= ~EU_Z;
	checks->percision = checks->percision - y;
	checks->width = checks->width - checks->percision;
	if (x < 0 && checks->option & EU_Z)
		print_neg(checks);
	if ((checks->option & EU_P || checks->option & EU_S) && x > -1)
		print_plus_space(checks);
	if ((!(checks->option & EU_M)))
	{
		if (x < 0)
			print_width(checks->width, checks);
		else
			print_width(checks->width + 1, checks);
	}
	if (x < 0 && (!(checks->option & EU_Z)))
		print_neg(checks);
	print_percision(checks->percision, checks);
}

void	check_s_width_percision3(t_flags *checks, int y, long long x)
{
	if (checks->option & EU_PO)
		checks->option &= ~EU_Z;
	checks->percision = checks->percision - y;
	checks->width = checks->width - checks->percision - y;
	if (x < 0 && checks->option & EU_Z)
		print_neg(checks);
	if ((checks->option & EU_P || checks->option & EU_S) && x > -1)
		print_plus_space(checks);
	if ((!(checks->option & EU_M)))
	{
		if (x < 0 && (!(checks->option & EU_Z)))
			checks->width--;
		print_width(checks->width, checks);
	}
	if (x < 0 && (!(checks->option & EU_Z)))
		print_neg(checks);
	print_percision(checks->percision, checks);
}

void	check_s_width_percision2(t_flags *checks, int y, long long x)
{
	if (checks->option & EU_PO && checks->percision > -1)
		checks->option &= ~EU_Z;
	checks->width = checks->width - y;
	if (x < 0 && checks->option & EU_Z)
		print_neg(checks);
	if ((checks->option & EU_P || checks->option & EU_S) && x > -1)
		print_plus_space(checks);
	if ((!(checks->option & EU_M)) && x > -1)
		print_width(checks->width, checks);
	else if (!(checks->option & EU_M))
		print_width(checks->width - 1, checks);
	if (x < 0 && (!(checks->option & EU_Z)))
		print_neg(checks);
}

void	check_s_width_percision1(t_flags *checks, int y, long long x)
{
	if (checks->option & EU_PO)
		checks->option &= ~EU_Z;
	checks->width = 0;
	checks->percision = checks->percision - y;
	if (x < 0 && checks->option & EU_Z)
		print_neg(checks);
	if ((checks->option & EU_P || checks->option & EU_S) && x > -1)
		print_plus_space(checks);
	if (x < 0 && (!(checks->option & EU_Z)))
		print_neg(checks);
	print_percision(checks->percision, checks);
}
