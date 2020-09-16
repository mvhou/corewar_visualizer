/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_specifier.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 20:41:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/12/01 01:41:04 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(t_flags *checks, va_list args)
{
	if (ft_strchr("scp%", checks->specifier))
	{
		if (checks->specifier == '%')
			print_char('%', checks);
		else if (checks->specifier == 'c')
			print_char(va_arg(args, int), checks);
		else if (checks->specifier == 's')
			print_str(va_arg(args, char*), checks);
		else if (checks->specifier == 'p')
			print_pointer(va_arg(args, unsigned long long int), checks);
	}
	else if (ft_strchr("douixX", checks->specifier))
		check_type(checks, args);
	else if (checks->specifier == 'f')
		handle_floats(checks, args);
}
