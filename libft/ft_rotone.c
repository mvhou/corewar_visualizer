/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotone.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 21:50:17 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/05/22 22:00:14 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rotone(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] < 'z')
			ft_putchar(s[i] + 1);
		else if (s[i] >= 'A' && s[i] < 'Z')
			ft_putchar(s[i] + 1);
		else
		{
			if (s[i] == 'Z')
				ft_putchar('A');
			else if (s[i] == 'z')
				ft_putchar('a');
			else
				ft_putchar(s[i]);
		}
		i++;
	}
	ft_putchar('\n');
	return (0);
}
