/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_operations.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 22:57:14 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 17:30:32 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	v_op_ld(t_visual *vis, t_v_ins *ins)
{
	int i;

	i = 0;
	wattron(vis->win, A_BOLD);
	while (i < ins->size)
	{
		wattron(vis->win, \
		COLOR_PAIR((vis->arena[(ins->pos + i) % MEM_SIZE] >> 16)));
		v_print_pixel(vis, (ins->pos + i) % MEM_SIZE);
		wattroff(vis->win, \
		COLOR_PAIR((vis->arena[(ins->pos + i) % MEM_SIZE] >> 16)));
		i++;
	}
	wattroff(vis->win, A_BOLD);
}

void	v_op_st(t_visual *vis, t_v_ins *ins)
{
	int i;
	int pos;

	i = 0;
	pos = (ins->pos >> 16);
	wattron(vis->win, A_REVERSE);
	while (i < ins->size)
	{
		vis->arena[(i + pos) % MEM_SIZE] = \
		(vis->arena[(i + pos) % MEM_SIZE] & 0x00ff) | (ins->color << 16);
		wattron(vis->win, COLOR_PAIR(ins->color));
		v_print_pixel(vis, (pos + i) % MEM_SIZE);
		wattroff(vis->win, COLOR_PAIR(ins->color));
		i++;
	}
	wattroff(vis->win, A_REVERSE);
}

void	v_op_live(t_visual *vis, t_v_ins *ins)
{
	int i;

	i = 0;
	while (i < ins->size)
	{
		wattron(vis->win, \
		COLOR_PAIR((vis->arena[(ins->pos + i) % MEM_SIZE] >> 16) + 9));
		v_print_pixel(vis, (ins->pos + i) % MEM_SIZE);
		wattroff(vis->win, \
		COLOR_PAIR((vis->arena[(ins->pos + i) % MEM_SIZE] >> 16) + 9));
		i++;
	}
}
