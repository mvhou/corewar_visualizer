/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 19:22:19 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 06:20:46 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		a;
	size_t		b;
	size_t		c;

	a = 0;
	b = 0;
	if (needle[a] == '\0')
		return ((char*)haystack);
	while (haystack[a] != '\0' && a < len)
	{
		c = a;
		while (haystack[c] == needle[b] && c < len && needle[b] != '\0')
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
