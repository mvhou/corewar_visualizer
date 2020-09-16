/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 22:09:14 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/01/14 16:46:19 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_specifier(char **f, t_flags *checks)
{
	if (ft_strchr("cspdiouxXf%", (**f)))
	{
		checks->specifier = **f;
		(*f)++;
	}
}

void	store_decimal_flags(char **f, t_flags *checks)
{
	if (**f == 'h' && (*f)[1] == 'h')
		checks->option |= EU_HH;
	else if (**f == 'h' && (*f)[-1] != 'h')
		checks->option |= EU_H;
	else if (**f == 'l' && (*f)[1] == 'l')
		checks->option |= EU_LL;
	else if (**f == 'l' && (*f)[-1] != 'l')
		checks->option |= EU_EL;
	else if (**f == 'L')
		checks->option |= EU_L;
}

void	store_flags(char **f, t_flags *checks, va_list args)
{
	while (ft_strchr("#0+*- hlL.", (**f)) || (**f > '0' && **f <= '9'))
	{
		if (**f == '#')
			checks->option |= EU_HA;
		else if (**f == '0')
			checks->option |= EU_Z;
		else if (**f == '+')
			checks->option |= EU_P;
		else if (**f == '-')
			checks->option |= EU_M;
		else if (**f == ' ')
			checks->option |= EU_S;
		else if (**f == '.')
			store_precision(f, checks, args);
		else if ((**f > '0' && **f <= '9') || **f == '*')
			store_width(f, checks, args);
		else
			store_decimal_flags(f, checks);
		(*f)++;
	}
	store_specifier(f, checks);
}
