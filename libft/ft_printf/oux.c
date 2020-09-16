/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oux.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 11:20:09 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/25 01:04:06 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				check_width_percision(t_flags *checks, unsigned long long x)
{
	int	y;

	y = count_nbr(checks, x);
	checks->counter = checks->counter + y;
	if (x == 0 && (!(checks->option & EU_PO)))
		checks->counter++;
	if (x == 0 && checks->option & EU_PO && checks->percision == 0)
		handle_zerop0(checks);
	else if (x == 0 && checks->option & EU_PO)
		handle_zerop(checks);
	else if (x == 0)
		handle_zero(checks);
	else if (checks->percision >= checks->width)
		check_width_percision1(checks, y);
	else if (checks->percision < checks->width && checks->percision > y)
		check_width_percision2(checks, y);
	else if (checks->percision < checks->width)
		check_width_percision3(checks, y);
	else
		check_width_percision4(checks, y);
}

void				print_unsigned_dec(t_flags *checks, unsigned long long x)
{
	check_width_percision(checks, x);
	if (!(x == 0 && checks->option & EU_PO))
	{
		if (checks->specifier == 'o')
			putnbr_base((unsigned long long)x, 8, 0);
		else if (checks->specifier == 'u')
			putnbr_base((unsigned long long)x, 10, 0);
		else if (checks->specifier == 'x')
			putnbr_base((unsigned long long)x, 16, 0);
		else if (checks->specifier == 'X')
			putnbr_base((unsigned long long)x, 16, 1);
	}
	else if (x == 0 && checks->option & EU_PO && checks->percision == 0)
	{
		if (checks->option & EU_HA && checks->specifier == 'o')
			print_width_zero(1, checks);
	}
	if (checks->option & EU_M && x != 0)
		print_width(checks->width, checks);
	else if (checks->option & EU_M && x == 0)
		print_width_0(checks->width, checks);
}

unsigned long long	get_num_unsigned(va_list args, t_flags *checks)
{
	unsigned long long	x;

	x = 0;
	if (checks->option & EU_H)
		x = (unsigned short)va_arg(args, unsigned int);
	else if (checks->option & EU_HH)
		x = (unsigned char)va_arg(args, unsigned int);
	else if (checks->option & EU_EL)
		x = (unsigned long)va_arg(args, unsigned long int);
	else if (checks->option & EU_LL)
		x = (unsigned long long)va_arg(args, unsigned long long int);
	else
		x = (unsigned int)va_arg(args, unsigned int);
	return (x);
}
