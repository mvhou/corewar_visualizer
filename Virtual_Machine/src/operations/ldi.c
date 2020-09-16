/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ldi.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:58:56 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 19:21:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

/*
**  ldi takes 3 arguments
**  arg1    T_REG/T_DIR/T_IND
**  arg2    T_REG/T_DIR
**  arg3    T_REG
**  ldi reads 4 bytes from the address current_pos + ((arg1 + arg2) % IDX_MOD)
**  and saves the result to arg3
**  if arg1 is a T_IND the 4 bytes are read from current_pos + (arg1 % IDX_MOD)
**  if the value of arg3 != 0, carry is set to 0 else cary is set to 1
*/

/*
**  lldi is the same as ldi but without % IDX_MOD
**  if arg1 == T_IND then the % IDX_MOD is still performed
*/

int		ldi(t_cursor *c, t_game *cw)
{
	int arg1;
	int arg2;
	int pos;

	if (c->ins->arg_type[0] == T_IND)
	{
		pos = get_pos(c->pos, c->ins->arg1 % IDX_MOD) - 1;
		arg1 = get_argument(cw, 4, pos);
	}
	else if (c->ins->arg_type[0] == T_DIR)
		arg1 = c->ins->arg1;
	else
		arg1 = c->reg[c->ins->arg1];
	if (c->ins->arg_type[1] == T_REG)
		arg2 = c->reg[c->ins->arg2];
	else
		arg2 = c->ins->arg2;
	c->reg[c->ins->arg3] = get_argument(cw, 4, \
	get_pos(c->pos, (arg1 + arg2) % IDX_MOD) - 1);
	return (0);
}

int		lldi(t_cursor *c, t_game *cw)
{
	int		address;

	if (c->ins->arg_type[0] == T_REG)
		c->ins->arg1 = c->reg[c->ins->arg1];
	else if (c->ins->arg_type[0] == T_IND)
		c->ins->arg1 = get_argument(cw, 4, \
		get_pos(c->pos, c->ins->arg1 % IDX_MOD) - 1);
	if (c->ins->arg_type[1] == T_REG)
		c->ins->arg2 = c->reg[c->ins->arg2];
	address = get_pos(c->pos, c->ins->arg1 + c->ins->arg2 - 1);
	c->reg[c->ins->arg3] = get_argument(cw, 4, address);
	if (c->reg[c->ins->arg3] == 0)
		c->carry = 1;
	else
		c->carry = 0;
	return (0);
}
