/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_plus_space.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 18:38:19 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/19 17:25:57 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_plus_space(t_flags *checks)
{
	checks->width = checks->width - 1;
	if ((!(checks->option & EU_M) && (!(checks->option & EU_Z))))
		print_width(checks->width, checks);
	if (checks->option & EU_P)
		write(1, "+", 1);
	else
		write(1, " ", 1);
	if ((!(checks->option & EU_M)) && (checks->option & EU_Z))
		print_width(checks->width, checks);
	checks->counter = checks->counter + 1;
}
