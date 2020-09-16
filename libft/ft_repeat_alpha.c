/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   repeat_alpha.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 13:02:53 by exam          #+#    #+#                 */
/*   Updated: 2019/05/22 21:52:59 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	caps(char s, int i)
{
	while (i > 0)
	{
		ft_putchar(s);
		i--;
	}
}

static void	low(char s, int i)
{
	while (i > 0)
	{
		ft_putchar(s);
		i--;
	}
}

void		ft_repeat_alpha(char *s)
{
	int	i;
	int j;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			j = s[i] - 64;
			caps(s[i], j);
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			j = s[i] - 96;
			low(s[i], j);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}
