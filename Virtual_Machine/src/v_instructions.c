/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_instructions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 02:16:22 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 22:26:32 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_execute_instructions(t_visual *vis)
{
	t_v_ins *v_ins;

	v_ins = vis->ins;
	while (v_ins)
	{
		if (v_ins->op == 100)
			v_op_ld(vis, v_ins);
		else if (v_ins->op == 2)
			v_op_st(vis, v_ins);
		else if (v_ins->op == 3)
			v_op_live(vis, v_ins);
		v_ins->time--;
		v_ins = v_ins->next;
	}
}

void		v_delete_instruction(t_visual *vis, t_v_ins *ins)
{
	if (ins == vis->ins)
	{
		vis->ins = ins->next;
		if (ins->next)
			ins->next->prev = NULL;
		free(ins);
	}
	else
	{
		if (ins->prev)
			ins->prev->next = ins->next;
		if (ins->next)
			ins->next->prev = ins->prev;
		free(ins);
	}
}

void		v_reset_pixels(t_visual *vis, t_v_ins *ins)
{
	int i;
	int pos;

	i = 0;
	pos = ins->pos;
	if (ins->op == 2)
		pos = (pos >> 16);
	while (i < ins->size)
	{
		wattron(vis->win, \
		COLOR_PAIR((vis->arena[(pos + i) % MEM_SIZE] >> 16)));
		v_print_pixel(vis, (pos + i) % MEM_SIZE);
		wattroff(vis->win, \
		COLOR_PAIR((vis->arena[(pos + i) % MEM_SIZE] >> 16)));
		i++;
	}
}

void		v_clean_instructions(t_visual *vis)
{
	t_v_ins *walker;
	t_v_ins *temp;

	if (vis->ins == NULL)
		return ;
	walker = vis->ins;
	while (walker->next)
		walker = walker->next;
	while (walker)
	{
		if (walker->time == 0)
		{
			temp = walker->prev;
			v_reset_pixels(vis, walker);
			v_delete_instruction(vis, walker);
			walker = temp;
		}
		else
			walker = walker->prev;
	}
}
