/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 15:53:15 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 14:52:49 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

int		live(t_cursor *c, t_game *cw)
{
	cw->live_count++;
	c->live = cw->cycles_count;
	if (-(c->ins->arg1) > 0 && -(c->ins->arg1) <= cw->players)
	{
		cw->player_l_alive = -(c->ins->arg1);
		if (cw->v)
		{
			v_new_instruction(cw->v, 3, c->pos, 5);
			v_add_to_ticker(cw->v, 3, -(c->ins->arg1));
		}
	}
	else
		return (0);
	return (1);
}
