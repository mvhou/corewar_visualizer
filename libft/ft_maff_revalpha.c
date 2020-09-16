/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maff_revalpha.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/11/16 10:08:41 by exam          #+#    #+#                 */
/*   Updated: 2019/05/22 22:01:49 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_maff_revalpha(char z, char y)
{
	while (z >= 'b' && y >= 'A')
	{
		ft_putchar(z);
		ft_putchar(y);
		z = z - 2;
		y = y - 2;
	}
	ft_putchar('\n');
}
