/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_flags_in_float.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 22:22:11 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/01/14 16:24:27 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	bankersrounding(char *s, int num, t_flags *c)
{
	int	i;

	i = 2;
	while (s[num + c->percision + i] == '0' && s[num + c->percision] != '\0')
		i++;
	if (s[num + c->percision] != '.' && s[num + c->percision] % 2 != 0)
		s[num + c->percision]++;
	else if (s[num + c->percision] == '.' && s[num + c->percision - 1] % 2 != 0)
		s[num + c->percision - 1]++;
	else if (s[num + c->percision + i] != '\0')
	{
		if (s[num + c->percision] == '.')
			s[num + c->percision - 1]++;
		else
			s[num + c->percision]++;
	}
}

static int	check_width_in_floats(char *str, int num, t_flags *c, int counter)
{
	c->width = c->width - (counter - 1);
	if (c->option & EU_M)
	{
		while (c->width > 0)
		{
			str[num + counter] = ' ';
			counter++;
			c->width--;
		}
		str[num + counter] = '\0';
		return (num);
	}
	else
	{
		while (c->width > 0)
		{
			if (c->option & EU_Z)
				str[num] = '0';
			else
				str[num] = ' ';
			num--;
			c->width--;
		}
	}
	return (num + 1);
}

static int	percision_rounding(char *s, int num, int p)
{
	while (s[num + p] != '/')
	{
		if (s[num + p] == '.')
			num--;
		if (s[num + p] > '9')
		{
			s[num + p] = '0';
			if (s[num + p - 1] != '.' && s[num + p - 1] != '/')
				s[num + p - 1]++;
			else if (s[num + p - 1] == '/')
				s[num + p - 1] = '1';
			else
				s[num + p - 2]++;
		}
		num--;
	}
	return (num);
}

static int	percision_float(char *s, int num, t_flags *c)
{
	if ((!(c->option & EU_PO)) || c->percision < 0)
		c->percision = 6;
	while (s[num] != '.')
		num++;
	if (s[num] == '.')
	{
		if (s[num + c->percision + 1] > '5')
		{
			if (s[num + c->percision] != '.')
				s[num + c->percision]++;
			else
				s[num + c->percision - 1]++;
		}
		else if (s[num + c->percision + 1] == '5')
			bankersrounding(s, num, c);
		if (c->percision != 0 || (c->percision == 0 && c->option & EU_HA))
			s[num + c->percision + 1] = '\0';
		else
			s[num + c->percision] = '\0';
	}
	num = percision_rounding(s, num, c->percision);
	return (num + c->percision + 1);
}

int			get_flag_in_float(char *str, int num, t_flags *c)
{
	int	counter;

	counter = 0;
	num = percision_float(str, num, c);
	num--;
	while (str[num + counter] != '\0')
		counter++;
	if (c->option & (EU_S | EU_FM | EU_P) && (!(c->option & EU_Z)))
		c->width--;
	if (c->width > counter - 1 && (c->option & EU_Z || c->option & EU_M))
		num = check_width_in_floats(str, num, c, counter);
	if (c->option & EU_FM)
		str[num] = '-';
	else if (c->option & EU_P)
		str[num] = '+';
	else if (c->option & EU_S)
		str[num] = ' ';
	if (c->option & EU_S || c->option & EU_FM || c->option & EU_P)
		num--;
	if (c->width > counter - 1 && (!(c->option & EU_Z && c->option & EU_M)))
		num = check_width_in_floats(str, num, c, counter);
	while (str[num] == '/')
		num++;
	return (num);
}
