/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_cursors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 16:09:38 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/09/16 19:00:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			add_cursor(t_cursor **cursor)
{
	(*cursor)->prev = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	(*cursor)->prev->next = *cursor;
	*cursor = (*cursor)->prev;
}

void			set_registries(t_cursor *cursor)
{
	int i;

	i = 2;
	cursor->reg[0] = 0;
	while (i < 17)
	{
		cursor->reg[i] = 0;
		i++;
	}
}

void			set_cursors(t_cursor *cursors, t_player *players)
{
	while (players->next)
	{
		cursors->pos = players->cursor;
		cursors->id = players->id;
		cursors->live = 0;
		cursors->jump = 0;
		cursors->ins = NULL;
		cursors->op = -1;
		cursors->carry = 0;
		cursors->reg[1] = -(players->id);
		add_cursor(&cursors);
		players = players->next;
	}
	cursors->reg[1] = -(players->id);
	cursors->pos = players->cursor;
	cursors->id = players->id;
	cursors->live = 0;
	cursors->jump = 0;
	cursors->ins = NULL;
	cursors->op = -1;
	cursors->carry = 0;
}
