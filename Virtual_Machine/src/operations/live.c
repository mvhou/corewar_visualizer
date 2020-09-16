/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 15:53:15 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 18:57:59 by anonymous     ########   odam.nl         */
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
	}
	else
		return (0);
	return (1);
}
