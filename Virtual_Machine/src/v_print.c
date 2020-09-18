/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_print.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 21:38:07 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 13:20:08 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_get_hex_str(int num, char *str)
{
	char	*chars;

	chars = "0123456789abcdef";
	str[0] = chars[num / 16];
	str[1] = chars[num % 16];
}

void		v_print_pixel(t_visual *v, int pos)
{
	char	str[3];
	char	*chars;
	short	num;

	chars = "0123456789abcdef";
	num = (short)v->arena[pos];
	str[0] = chars[num / 16];
	str[1] = chars[num % 16];
	str[2] = 0;
	mvwprintw(v->win, (pos * 3) / WIDTH + 1, (pos * 3) % WIDTH + 1, str);
}
