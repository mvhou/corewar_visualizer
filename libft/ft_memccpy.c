/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 01:15:54 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 06:02:28 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			f;
	unsigned char	*j;
	unsigned char	*k;

	j = (unsigned char*)src;
	k = (unsigned char*)dst;
	f = 0;
	while (f < n)
	{
		if (j[f] == (unsigned char)c)
		{
			k[f] = (unsigned char)c;
			f++;
			return (&k[f]);
		}
		k[f] = j[f];
		f++;
	}
	return (NULL);
}
