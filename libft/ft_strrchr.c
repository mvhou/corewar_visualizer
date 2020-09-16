/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/27 21:38:56 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 06:28:08 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tc;
	char	*t;

	t = (char*)s;
	tc = (char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i != 0 && s[i] != tc)
		i--;
	if (t[i] == tc)
		return (&t[i]);
	else
		return (NULL);
}
