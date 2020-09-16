/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ld.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 16:02:14 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 19:00:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

int		ld(t_cursor *c, t_game *cw)
{
	int arg;
	int pos;

	if (c->ins->arg_type[0] == T_IND)
	{
		pos = get_pos(c->pos, c->ins->arg1 % IDX_MOD) - 1;
		arg = get_argument(cw, 4, pos);
	}
	else
		arg = c->ins->arg1;
	c->reg[c->ins->arg2] = arg;
	if (arg != 0)
		c->carry = 0;
	else
		c->carry = 1;
	return (0);
}

int		lld(t_cursor *c, t_game *cw)
{
	int arg;
	int pos;

	if (c->ins->arg_type[0] == T_IND)
	{
		pos = get_pos(c->pos, c->ins->arg1 - 1);
		arg = get_argument(cw, 2, pos);
	}
	else
		arg = c->ins->arg1;
	c->reg[c->ins->arg2] = arg;
	if (arg == 0)
		c->carry = 1;
	else
		c->carry = 0;
	return (0);
}
