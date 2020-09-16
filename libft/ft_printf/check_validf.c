/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_validf.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 17:19:42 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/01/21 19:20:55 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flags_inf_0(t_flags *checks)
{
	if (checks->option & EU_M)
		checks->counter = checks->counter +\
						ft_printf("% -*s", checks->width, "-inf");
	else
		checks->counter = checks->counter +\
						ft_printf("% *s", checks->width, "-inf");
}

static void	flags_inf(t_floats *floats, t_flags *checks)
{
	if (checks->option & EU_S)
	{
		if (floats->floats < 0)
			flags_inf_0(checks);
		else
		{
			if (checks->option & EU_M)
				checks->counter = checks->counter +\
							ft_printf("%-*s", checks->width, " inf");
			else
				checks->counter = checks->counter +\
							ft_printf("%*s", checks->width, " inf");
		}
	}
	if (checks->option & EU_P)
	{
		if (checks->option & EU_M)
			checks->counter = checks->counter +\
							ft_printf("%-*s", checks->width, "+inf");
		else
			checks->counter = checks->counter +\
							ft_printf("%*s", checks->width, "+inf");
	}
}

static void	inf(t_floats *floats, t_flags *checks)
{
	if (checks->option & EU_S)
		flags_inf(floats, checks);
	else if (floats->floats < 0 && (!(checks->option & EU_M)))
		checks->counter = checks->counter +\
						ft_printf("%*s", checks->width, "-inf");
	else if (floats->floats < 0)
		checks->counter = checks->counter +\
						ft_printf("%-*s", checks->width, "-inf");
	else if (checks->option & EU_P)
		flags_inf(floats, checks);
	else if (checks->option & EU_M)
		checks->counter = checks->counter +\
						ft_printf("%-*s", checks->width, "inf");
	else
		checks->counter = checks->counter +\
						ft_printf("%*s", checks->width, "inf");
}

int			check_validf(t_floats *floats, t_flags *checks)
{
	if (floats->floats == 1.0 / 0.0 || floats->floats == -1.0 / 0.0)
		inf(floats, checks);
	else if (floats->floats == 0 || floats->floats > 0 || floats->floats < 0)
		return (0);
	else
	{
		if (checks->option & EU_M)
			checks->counter = checks->counter +\
							ft_printf("%-*s", checks->width, "nan");
		else
			checks->counter = checks->counter +\
							ft_printf("%*s", checks->width, "nan");
	}
	return (1);
}
