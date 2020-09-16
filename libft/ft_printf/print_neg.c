/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_neg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 13:02:11 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/18 13:42:44 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_neg(t_flags *checks)
{
	write(1, "-", 1);
	if (checks->option & EU_M)
		checks->width = checks->width - 1;
	checks->counter = checks->counter + 1;
}
