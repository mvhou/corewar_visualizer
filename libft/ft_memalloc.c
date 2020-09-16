/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 00:23:24 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/01 23:18:56 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = (void*)malloc(sizeof(*str) * (size));
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}
