/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_new_instruction.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 00:08:18 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 12:25:07 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	v_add_to_tail(t_v_ins *tail, t_v_ins *new)
{
	if (tail->op > new->op)
	{
		new->next = tail;
		new->prev = tail->prev;
		tail->prev->next = new;
		tail->prev = new;
	}
	else
	{
		tail->next = new;
		new->prev = tail;
	}
}

t_v_ins	*v_add_to_head(t_v_ins *head, t_v_ins *new)
{
	if (head->op > new->op)
	{
		new->next = head;
		head->prev = new;
		return (new);
	}
	else
	{
		new->prev = head;
		if (head->next)
			head->next->prev = new;
		head->next = new;
		return (head);
	}
}

void	v_add_to_list(t_visual *vis, t_v_ins *new)
{
	t_v_ins *walker;

	walker = vis->ins;
	while (walker)
	{
		if (walker->op <= new->op && walker->next)
			walker = walker->next;
		else
			break ;
	}
	if (walker == vis->ins)
		vis->ins = v_add_to_head(vis->ins, new);
	else if (walker->next)
	{
		new->next = walker;
		new->prev = walker->prev;
		walker->prev->next = new;
		walker->prev = new;
	}
	else
		v_add_to_tail(walker, new);
}

void	v_new_instruction(t_visual *vis, int op, int pos, int size)
{
	t_v_ins *new;

	if (vis)
		new = (t_v_ins*)malloc(sizeof(t_v_ins));
	new->op = op;
	new->pos = pos;
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	if (op == 1)
		new->time = 10;
	if (op == 2)
	{
		new->time = 50;
		new->color = (vis->arena[0x0000ffff & pos] >> 16);
	}
	if (op == 3)
		new->time = 75;
	if (vis->ins)
		v_add_to_list(vis, new);
	else
		vis->ins = new;
}
