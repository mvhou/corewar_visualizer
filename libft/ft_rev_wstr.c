/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_wstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 15:50:15 by exam          #+#    #+#                 */
/*   Updated: 2019/06/03 21:34:34 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_wstr(char *s, int len)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = len;
	k = len;
	while (j > 0)
	{
		while (s[j] != ' ' && s[j] != '\t' && j > -1)
			j--;
		i = j + 1;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
			k--;
		}
		if (j > 0)
			ft_putchar(' ');
		while (s[j] == ' ' || s[j] == '\t')
			j--;
	}
	ft_putchar('\n');
}
