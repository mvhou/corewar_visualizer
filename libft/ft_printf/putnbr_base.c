/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   putnbr_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/04 13:18:37 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/09/07 22:20:39 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_base(unsigned long long value, int base, int l)
{
	if (value >= (unsigned long long)base)
		putnbr_base(value / base, base, l);
	if (value % base > 9 && l == 1)
		ft_putchar(value % base + 55);
	else if (value % base > 9 && l == 0)
		ft_putchar(value % base + 87);
	else
		ft_putchar(value % base + 48);
}
