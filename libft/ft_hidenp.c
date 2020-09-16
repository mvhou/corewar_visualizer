/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hidenp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 14:45:17 by exam          #+#    #+#                 */
/*   Updated: 2019/05/22 21:42:35 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hidenp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			i++;
		j++;
	}
	if (s1[i] == '\0')
		ft_putchar('1');
	else
		ft_putchar('0');
	ft_putchar('\n');
}
