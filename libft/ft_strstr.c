/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 17:25:14 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/02 00:15:09 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	if (needle[a] == '\0')
		return ((char*)haystack);
	while (haystack[a] != '\0')
	{
		c = a;
		while (haystack[c] == needle[b] && needle[b] != '\0')
		{
			b++;
			c++;
		}
		if (needle[b] == '\0')
			return ((char*)&haystack[a]);
		a++;
		b = 0;
	}
	return (NULL);
}
