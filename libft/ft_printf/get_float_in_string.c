/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_float_in_string.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 03:12:33 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/01/06 19:03:09 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	divide(char *fstr, int i, int j)
{
	int		tmp;
	int		tmp2;

	tmp = 0;
	tmp2 = 0;
	while (i >= j)
	{
		if (tmp == 5)
		{
			tmp2 = 5;
			tmp = 0;
		}
		if (fstr[j] == '.')
			j++;
		if (((fstr[j] - 48) % 2) == 1)
			tmp = 5;
		if (fstr[j] >= '0' && fstr[j] <= '9')
			fstr[j] = ((fstr[j] - 48) / 2) + 48 + tmp2;
		j++;
		tmp2 = 0;
	}
}

static void	floats_divide(char *str, t_floats *floats, int *i, int *num)
{
	floats->exponent[4] = 16383 - floats->exponent[4];
	while (floats->exponent[4] > 0)
	{
		floats->exponent[4] = floats->exponent[4] - 1;
		divide(&str[*num], *i, 0);
		if (str[*num + *i] > '0')
			(*i)++;
	}
}

static void	multiply(char *fstr, int i)
{
	int	tmp;

	tmp = 0;
	while (fstr[i] != '/' || tmp != 0)
	{
		if (fstr[i] != '.' && fstr[i] != '/')
			fstr[i] = ((fstr[i] - 48) * 2) + 48 + tmp;
		else if (fstr[i] == '/')
			fstr[i] = tmp + 48;
		if (fstr[i] != '.')
			tmp = 0;
		if (fstr[i] > 57 && fstr[i] != '.')
		{
			tmp = (fstr[i] - 48) / 10;
			fstr[i] = ((fstr[i] - 48) % 10) + 48;
		}
		i--;
	}
}

static void	floats_multiply(char *str, t_floats *floats, int *i, int *num)
{
	floats->exponent[4] = floats->exponent[4] - 16383;
	while (floats->exponent[4] > 0)
	{
		floats->exponent[4] = floats->exponent[4] - 1;
		multiply(&str[*num], *i);
		if (str[*num - 1] > '0')
		{
			(*i)++;
			*num = *num - 1;
		}
	}
}

int			get_float_in_string(t_flags *c, t_floats *floats, char *str)
{
	int		num;
	int		i;

	i = 63;
	num = 20000;
	if (floats->exponent[4] & 1 << 15)
	{
		c->option |= EU_FM;
		floats->exponent[4] &= ~(1 << 15);
	}
	if (floats->exponent[4] > 16383)
		floats_multiply(str, floats, &i, &num);
	else if (floats->exponent[4] < 16383)
		floats_divide(str, floats, &i, &num);
	return (num);
}
