/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zjmp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 15:55:07 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/17 09:24:05 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

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
