/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_zeros.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 13:28:45 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/25 00:47:09 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_zerop0s(t_flags *checks)
{
	if ((checks->option & EU_P || checks->option & EU_S))
		print_plus_space(checks);
	else if (!(checks->option & EU_M))
		print_width(checks->width, checks);
}

void	handle_zerops(t_flags *checks)
{
	checks->width = checks->width - checks->percision;
	if ((checks->option & EU_P || checks->option & EU_S))
		print_plus_space(checks);
	if (!(checks->option & EU_M))
		print_width_0(checks->width, checks);
	print_percision_0(checks->percision, checks);
}

void	handle_zeros(t_flags *checks)
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
