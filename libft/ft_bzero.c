/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 01:52:49 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 05:54:33 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*k;

	k = (char*)s;
	i = 0;
	while (i < n)
	{
		k[i] = 0;
		i++;
	}
}
