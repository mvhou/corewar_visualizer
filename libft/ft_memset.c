/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 23:54:26 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 06:08:26 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		k;
	char		*s;

	s = (char*)b;
	k = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		s[i] = k;
		i++;
	}
	return (b);
}
