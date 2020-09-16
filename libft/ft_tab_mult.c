/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tab_mult.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/16 02:17:05 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/06/03 21:38:15 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab_mult(int c)
{
	int	i;

	i = 1;
	while (i < 10)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(c);
		ft_putstr(" = ");
		ft_putnbr(i * c);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
