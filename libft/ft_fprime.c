/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fprime.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 13:07:03 by exam          #+#    #+#                 */
/*   Updated: 2019/05/22 02:21:30 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fprime(int i)
{
	int	j;

	if (i == 1)
		ft_putnbr(i);
	j = 2;
	while (i > 1)
	{
		if (i % j == 0)
		{
			ft_putnbr(i);
			if (i / j > 1)
				write(1, "*", 1);
			i = i / j;
		}
		else
			j++;
		if (i <= 1)
			write(1, "\n", 1);
	}
}
