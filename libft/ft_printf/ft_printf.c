/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 22:01:34 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/01/14 16:42:15 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_arg(t_flags *checks, va_list args, char **f)
{
	(*f)++;
	if (**f)
	{
		store_flags(f, checks, args);
		print_arg(checks, args);
	}
	set_checks_0(checks);
}

void		print_and_check(char **f, va_list args, t_flags *checks)
{
	char	buff[64];
	int		index;

	index = 0;
	ft_bzero(buff, 64);
	while (**f)
	{
		if (**f == '%' || index > 63)
		{
			write(1, &buff, index);
			checks->counter = checks->counter + index;
			index = 0;
			while (**f == '%')
				handle_arg(checks, args, f);
		}
		if ((**f) != '\0')
		{
			buff[index] = **f;
			(*f)++;
			index++;
		}
	}
	if (index != 0)
		write(1, &buff, index);
	checks->counter = checks->counter + index;
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	args;
	t_flags	checks;
	char	*f;

	ft_bzero((void*)&checks, sizeof(t_flags));
	va_start(args, format);
	f = (char*)format;
	print_and_check(&f, args, &checks);
	va_end(args);
	return (checks.counter);
}
