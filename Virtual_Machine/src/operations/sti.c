/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 15:51:08 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 11:17:40 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

/*
**	sti gets 3 arguments and writes the value of argument1 to an address
**	if argument2 is a T_IND the address is:
**	current_position + (argument2 % IDX_MOD)
**	else the address is:
**	current_position + ((argument2 + argument3) % IDX_MOD)
**	arg1		T_REG
**	arg2		T_REG/T_DIR/T_IND
**	arg3		T_REG/T_DIR
*/

int				sti(t_cursor *c, t_game *cw)
{
	int			dst;

	c->ins->arg1 = c->reg[c->ins->arg1];
	dst = 0;
	if (c->ins->arg_type[1] == T_REG)
		c->ins->arg2 = c->reg[c->ins->arg2];
	else if (c->ins->arg_type[1] == T_IND)
		c->ins->arg2 = get_argument(cw, 4, get_pos(c->pos,\
		(c->ins->arg2 % IDX_MOD)) - 1);
	if (c->ins->arg_type[2] == T_REG)
		c->ins->arg3 = c->reg[c->ins->arg3];
	dst = get_pos(c->pos, (c->ins->arg2 + c->ins->arg3) % IDX_MOD);
	write_to_memory(cw, c->ins->arg1, sizeof(T_REG), dst);
	if (cw->v)
		v_new_instruction(cw->v, 2, (dst << 16) | c->pos, 4);
	return (0);
}
