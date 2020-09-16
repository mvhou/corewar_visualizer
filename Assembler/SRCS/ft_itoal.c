/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoal.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/11 22:28:19 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:15:04 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static void	fill(char *num, int j, long long n)
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

static int	lenght_of_num(long long nbr)
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

char		*ft_itoal(long long n)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = lenght_of_num(n);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n == -9223372036854775807)
	{
		str = ft_strdup("-9223372036854775808");
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
