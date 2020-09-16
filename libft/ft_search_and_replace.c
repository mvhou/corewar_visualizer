/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_and_replace.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 12:25:41 by exam          #+#    #+#                 */
/*   Updated: 2019/05/22 22:06:46 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_search_and_replace(char **s)
{
	int	a;

	a = 0;
	while (s[1][a] != '\0')
	{
		if (s[1][a] != s[2][0])
			ft_putchar(s[1][a]);
		if (s[1][a] == s[2][0])
			ft_putchar(s[3][0]);
		a++;
	}
	ft_putchar('\n');
	return (0);
}
