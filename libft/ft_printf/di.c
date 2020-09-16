/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   di.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 11:23:02 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/25 00:47:22 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_s_width_percision(t_flags *checks, long long x)
{
	int			y;

	y = count_s_nbr(x);
	checks->counter = checks->counter + y;
	if (x == 0 && checks->option & EU_PO && checks->percision == 0)
		handle_zerop0s(checks);
	else if (x == 0 && checks->option & EU_PO)
		handle_zerops(checks);
	else if (x == 0)
		handle_zeros(checks);
	else if (y < checks->percision && checks->percision >= checks->width)
		check_s_width_percision1(checks, y, x);
	else if (y >= checks->percision)
		check_s_width_percision2(checks, y, x);
	else if (y < checks->percision && checks->width > checks->percision)
		check_s_width_percision3(checks, y, x);
	else if (y < checks->percision)
		check_s_width_percision4(checks, y, x);
}

void		print_signed_dec(t_flags *checks, long long x)
{
	check_s_width_percision(checks, x);
	if (x < 0)
		x = x * -1;
	if (x != 0)
		putnbr_base(x, 10, 0);
	else if (x == 0 && (!(checks->option & EU_PO)))
	{
		putnbr_base(x, 10, 0);
		checks->counter = checks->counter + 1;
	}
	if (checks->option & EU_M && (!(checks->option & EU_PO)) && x != 0)
		print_width(checks->width, checks);
	else if (checks->option & EU_M && x == 0)
		print_width(checks->width, checks);
	else if (x != 0 && checks->option & EU_PO)
		print_width(checks->width, checks);
	else if (x == 0 && checks->option & EU_PO && checks->percision != 0)
		print_width(checks->width, checks);
}

long long	get_num_signed(va_list args, t_flags *checks)
{
	long long	y;

	y = 0;
	if (checks->option & EU_H)
		y = (short)va_arg(args, int);
	else if (checks->option & EU_HH)
		y = (signed char)va_arg(args, int);
	else if (checks->option & EU_EL)
		y = (long)va_arg(args, long int);
	else if (checks->option & EU_LL)
		y = (long long)va_arg(args, long long int);
	else
		y = (int)va_arg(args, int);
	return (y);
}
