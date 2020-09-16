/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_zero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 13:58:59 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/01/14 17:43:36 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_zerop0(t_flags *checks)
{
	if (checks->option & EU_HA && checks->specifier == 'o')
		checks->width--;
	if (!(checks->option & EU_M))
	{
		print_width(checks->width, checks);
		checks->width = 0;
	}
}

void	handle_zerop(t_flags *checks)
{
	checks->width = checks->width - checks->percision;
	if ((checks->option & EU_P || checks->option & EU_S))
		print_plus_space(checks);
	if (!(checks->option & EU_M))
		print_width_0(checks->width, checks);
	print_percision_0(checks->percision, checks);
}

void	handle_zero(t_flags *checks)
{
	if ((checks->option & EU_P || checks->option & EU_S))
	{
		checks->width = checks->width - 1;
		print_plus_space(checks);
	}
	else if (!(checks->option & EU_M))
		print_width(checks->width - 1, checks);
	else if (checks->option & EU_M)
		checks->width = checks->width - 1;
}
