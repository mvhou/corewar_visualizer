/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:09:58 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/02/04 05:46:52 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	e;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	e = i;
	while (s[e] != '\0')
		e++;
	e--;
	while (s[e] == ' ' || s[e] == '\n' || s[e] == '\t')
		e--;
	return (ft_strsub(s, i, e - i + 1));
}
