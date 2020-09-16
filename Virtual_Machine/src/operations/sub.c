/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sub.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:30:04 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 18:29:21 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

int		sub(t_cursor *c, t_game *cw)
{
	int new;

	if (!cw)
		return (0);
	new = c->reg[c->ins->arg1] - c->reg[c->ins->arg2];
	c->reg[c->ins->arg3] = new;
	if (new != 0)
	{
		c->carry = 0;
		return (1);
	}
	else
		c->carry = 1;
	return (0);
}
