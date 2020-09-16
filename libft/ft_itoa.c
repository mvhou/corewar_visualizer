/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 23:37:40 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 03:48:21 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char *num, int j, int n)
{
	static int	i;

	i = j;
	if (n % 10 == n)
	{
		num[i] = n + '0';
		i++;
	}
	else
	{
		fill(num, i, n / 10);
		num[i] = (n % 10) + '0';
		i++;
	}
}

static int	lenght_of_num(int nbr)
{
	int	l;

	l = 0;
	if (nbr < 0)
		l = 1;
	while (nbr % 10 != nbr)
	{
		nbr = nbr / 10;
		l++;
	}
	l++;
	return (l);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = lenght_of_num(n);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0)
	{
		str[i] = '-';
		n = n * -1;
		i++;
	}
	fill(str, i, n);
	str[len] = '\0';
	return (str);
}
