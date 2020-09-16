/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 15:37:54 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:59 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		b;
	int		len;
	char	*str;

	len = 0;
	b = 0;
	while (s1[len] != '\0')
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!(str))
		return (NULL);
	while (len != -1)
	{
		str[b] = s1[b];
		b++;
		len--;
	}
	return (str);
}
