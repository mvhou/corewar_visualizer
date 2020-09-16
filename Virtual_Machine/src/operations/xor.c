/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   xor.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:40:19 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 19:00:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

int				xor(t_cursor *c, t_game *cw)
{
	int arg1;
	int arg2;

	if (c->ins->arg_type[0] == T_IND)
		arg1 = get_argument(cw, 4, get_pos(c->pos, c->ins->arg1 % IDX_MOD) - 1);
	else if (c->ins->arg_type[0] == T_DIR)
		arg1 = c->ins->arg1;
	else
		arg1 = c->reg[c->ins->arg1];
	if (c->ins->arg_type[1] == T_IND)
		arg2 = get_argument(cw, 4, get_pos(c->pos, c->ins->arg2 % IDX_MOD) - 1);
	else if (c->ins->arg_type[1] == T_DIR)
		arg2 = c->ins->arg2;
	else
		arg2 = c->reg[c->ins->arg2];
	c->reg[c->ins->arg3] = (arg1 ^ arg2);
	if (c->reg[c->ins->arg3] != 0)
	{
		c->carry = 0;
		return (1);
	}
	else
		c->carry = 1;
	return (0);
}
