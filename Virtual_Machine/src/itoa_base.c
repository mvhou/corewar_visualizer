/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa_base.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 19:26:38 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 17:49:14 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static long long	loop_str(const char *str, int i)
{
	long long		res;

	res = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		exit(ft_printf("number after n flag is incorrect\n"));
	return (res);
}

int					ft_atoi2(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		if (ft_strcmp(&str[i], "-2147483648") == 0)
			return (-2147483648);
		sign = -1;
		if (str[i + 1] == '\0')
			exit(ft_printf("incorrect number after n flag\n"));
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = loop_str(str, i);
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		exit(ft_printf("number after n flag is not correct\n"));
	return (sign * res);
}

static int			count_n(long long n, int base)
{
	int		cnt;

	cnt = 1;
	if (n < 0)
	{
		cnt++;
		n = n * -1;
	}
	while (n % base != n)
	{
		cnt++;
		n = n / base;
	}
	return (cnt);
}

static char			*make_str(long long n, int base, int cnt, char *str)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = n * -1;
	}
	while (cnt >= i)
	{
		if (n % base > 9)
			str[cnt] = (n % base) + 87;
		else
			str[cnt] = (n % base) + '0';
		cnt--;
		n = n / base;
	}
	return (str);
}

char				*itoa_base(unsigned long long nbr, int base)
{
	int		cnt;
	char	*str;

	cnt = count_n(nbr, base);
	str = (char *)ft_memalloc(cnt + 1);
	str[cnt] = '\0';
	return (make_str(nbr, base, cnt - 1, str));
}
