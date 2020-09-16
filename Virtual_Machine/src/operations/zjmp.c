/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zjmp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 15:55:07 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 19:00:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

/*
** zjmp get an index defined by c->ins->arg1 (T_DIR)
** if carry == 1 then cursor moves to (c->pos + (index % IDX_MOD)) % MEM_SIZE
** else move cursor 2 bytes
*/

int				zjmp(t_cursor *c, t_game *cw)
{
	(void)cw;
	if (c->carry == 1)
	{
		c->pos = c->pos + (c->ins->arg1 % IDX_MOD);
		while (c->pos < 0)
			c->pos = c->pos + MEM_SIZE;
		c->pos = c->pos % MEM_SIZE;
	}
	else
		c->pos = get_pos(c->pos, 3);
	return (0);
}
