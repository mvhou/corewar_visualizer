/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/27 21:26:50 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 06:27:37 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tc;
	char	*t;

	t = (char*)s;
	tc = (char)c;
	i = 0;
	while (s[i] != tc && s[i] != '\0')
		i++;
	if (t[i] == tc)
		return (&t[i]);
	else
		return (NULL);
}
