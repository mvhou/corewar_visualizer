/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned_wp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 12:11:14 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/25 01:30:01 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_percision4(t_flags *checks, int y)
{
	checks->width = checks->width - y;
	if (checks->width > 0 && checks->option & EU_HA)
	{
		if (!(checks->option & EU_M))
			print_width(checks->width - 1, checks);
		checks->width = ifhash(checks->width, checks);
	}
	if (!(checks->option & EU_M))
		print_width(checks->width - 1, checks);
	print_percision(checks->percision, checks);
}

void	check_width_percision3(t_flags *checks, int y)
{
	checks->width = checks->width - y;
	if (checks->option & EU_HA && (!(checks->option & EU_PO))\
		&& checks->option & EU_Z && checks->specifier != 'o')
	{
		checks->width = ifhash(checks->width, checks);
		if ((!(checks->option & EU_M)) && checks->specifier == 'x')
			print_width(checks->width, checks);
		else if ((!(checks->option & EU_M)) && checks->specifier == 'X')
			print_width(checks->width, checks);
	}
	else if (checks->option & EU_HA)
	{
		if ((!(checks->option & EU_M)) && checks->specifier == 'o')
			print_width(checks->width - 1, checks);
		else if ((!(checks->option & EU_M)) && checks->specifier == 'x')
			print_width(checks->width - 2, checks);
		else if ((!(checks->option & EU_M)) && checks->specifier == 'X')
			print_width(checks->width - 2, checks);
		checks->width = ifhash(checks->width, checks);
	}
	if (!(checks->option & EU_M))
		print_width(checks->width, checks);
}

void	check_width_percision2(t_flags *checks, int y)
{
	checks->percision = checks->percision - y;
	checks->width = checks->width - checks->percision - y;
	if (y == 0)
		checks->width = checks->width + 1;
	if (checks->option & EU_HA)
	{
		if ((!(checks->option & EU_M)) && checks->specifier == 'o')
			print_width(checks->width, checks);
		else if ((!(checks->option & EU_M)) && checks->specifier == 'x')
			print_width(checks->width - 2, checks);
		else if ((!(checks->option & EU_M)) && checks->specifier == 'X')
			print_width(checks->width - 2, checks);
		if (checks->specifier == 'x' || checks->specifier == 'X')
			checks->width = ifhash(checks->width, checks);
		else
			checks->percision = ifhash(checks->percision, checks);
	}
	if (!(checks->option & EU_M))
		print_width(checks->width, checks);
	print_percision(checks->percision, checks);
}

void	check_width_percision1(t_flags *checks, int y)
{
	checks->width = 0;
	checks->percision = checks->percision - y;
	if (checks->option & EU_HA && ft_strchr("oxX", checks->specifier))
	{
		if (checks->specifier == 'o')
			checks->percision = ifhash(checks->percision, checks);
		else
			ifhash(checks->percision, checks);
	}
	print_percision(checks->percision, checks);
}
