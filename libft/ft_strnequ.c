/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/01 20:07:56 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 06:13:30 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (1);
	if (s1 && s2 && n)
	{
		i = ft_strncmp(s1, s2, n);
		if (i == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
