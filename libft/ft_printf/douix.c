/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   douixX.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 20:02:00 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/09/23 15:28:07 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				check_type(t_flags *checks, va_list args)
{
	unsigned long long	x;
	long long			y;

	x = 0;
	y = 0;
	if (ft_strchr("di", checks->specifier))
	{
		y = get_num_signed(args, checks);
		print_signed_dec(checks, y);
	}
	else if (ft_strchr("ouxX", checks->specifier))
	{
		x = get_num_unsigned(args, checks);
		print_unsigned_dec(checks, x);
	}
}
