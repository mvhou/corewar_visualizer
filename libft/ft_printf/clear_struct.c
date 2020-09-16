/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_struct.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 21:58:55 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/09/20 17:17:30 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_checks_0(t_flags *checks)
{
	checks->width = 0;
	checks->specifier = 0;
	checks->percision = 0;
	checks->option = 0;
}
