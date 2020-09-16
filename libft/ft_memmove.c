/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 00:19:07 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/06/04 16:48:32 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	if (src == NULL && dst == NULL)
		return (NULL);
	if (len > ((size_t)dst) - ((size_t)src))
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			((char*)dst)[i] = ((const char*)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char*)dst)[i] = ((const char*)src)[i];
			i++;
		}
	}
	return (dst);
}
