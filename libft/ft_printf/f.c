/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_floats.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 00:44:54 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/01/21 17:22:54 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_cal(char *a, char *b, int i)
{
	while (i < 65)
	{
		if (a[i] != '.')
			b[i] = (a[i] - 48) + b[i];
		else
			b[i] = '.';
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (b[i] > 57 && b[i] != '.')
		{
			b[i - 1] = b[i - 1] + ((b[i] - 48) / 10);
			b[i] = ((b[i] - 48) % 10) + 48;
		}
		i--;
	}
}

static void	half_odd(char *a, int i, int j)
{
	int		tmp;
	int		k;

	tmp = 0;
	k = 0;
	while (i >= j)
	{
		if (tmp == 5)
		{
			k = 5;
			tmp = 0;
		}
		if (a[j] == '.')
		{
			j++;
			i++;
		}
		if (((a[j] - 48) % 2) == 1)
			tmp = 5;
		if (a[j] >= '0' && a[j] <= '9')
			a[j] = ((a[j] - 48) / 2) + 48 + k;
		j++;
		k = 0;
	}
}

static void	get_mantissa(t_floats *floats, char *fstr)
{
	unsigned long	bit;
	char			a[67];
	int				i;
	int				j;

	fstr[66] = '\0';
	ft_strcpy(a, fstr);
	a[0] = '1';
	i = 63;
	j = 0;
	while (i >= 0)
	{
		bit = 1UL << i;
		if (floats->mantissa & bit)
			str_cal(a, &fstr[0], 0);
		half_odd(a, j + 1, 0);
		i--;
		j++;
	}
	fstr[66] = '0';
}

void		handle_floats(t_flags *checks, va_list args)
{
	t_floats			floats;
	char				str[40000];
	int					num;

	if (checks->option & EU_L)
		floats.floats = va_arg(args, long double);
	else
		floats.floats = va_arg(args, double);
	num = check_validf(&floats, checks);
	if (num == 1)
		return ;
	ft_memset(str, '/', 40000);
	ft_memset(&str[20000], 48, 20000);
	ft_memset(&str[20001], '.', 1);
	str[39999] = '\0';
	get_mantissa(&floats, &str[20000]);
	num = get_float_in_string(checks, &floats, &str[0]);
	num = get_flag_in_float(&str[0], num, checks);
	checks->counter = checks->counter + ft_printf("%s", &str[num]);
}
