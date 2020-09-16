/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_percision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/24 15:34:22 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/11/24 17:06:40 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_astrix(char **f, t_flags *checks, va_list a)
{
	if ((*f)[-1] == '.')
		checks->percision = va_arg(a, int);
	else
	{
		checks->width = va_arg(a, int);
		if (checks->width < 0)
		{
			checks->width = checks->width * -1;
			checks->option |= EU_M;
		}
	}
}

void	store_width(char **f, t_flags *checks, va_list a)
{
	if ((**f) == '*')
		handle_astrix(f, checks, a);
	else
	{
		checks->width = 0;
		while ((*f)[1] >= '0' && (*f)[1] <= '9')
		{
			checks->width = (checks->width * 10) + (**f - 48);
			(*f)++;
		}
		if (**f >= '0' && **f <= '9')
			checks->width = (checks->width * 10) + (**f - 48);
	}
}

void	store_precision(char **f, t_flags *checks, va_list a)
{
	checks->option |= EU_PO;
	(*f)++;
	if ((**f) == '*')
		handle_astrix(f, checks, a);
	else
	{
		checks->percision = 0;
		while ((*f)[1] >= '0' && (*f)[1] <= '9')
		{
			checks->percision = (checks->percision * 10) + (**f - 48);
			(*f)++;
		}
		if (**f >= '0' && **f <= '9')
			checks->percision = (checks->percision * 10) + (**f - 48);
		else
			(*f)--;
	}
}
