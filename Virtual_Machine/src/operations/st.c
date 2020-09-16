/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   st.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 13:43:40 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 19:00:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

int		st(t_cursor *c, t_game *cw)
{
	int pos;
	int arg;

	arg = c->reg[c->ins->arg1];
	if (c->ins->arg_type[1] == T_REG)
	{
		c->reg[c->ins->arg2] = arg;
		return (1);
	}
	else
	{
		pos = get_pos(c->pos, c->ins->arg2 % IDX_MOD);
		write_to_memory(cw, arg, 4, pos);
	}
	return (1);
}
