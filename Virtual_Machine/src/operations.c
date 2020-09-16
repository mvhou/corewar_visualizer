/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 15:32:57 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 21:56:39 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			get_argument(t_game *cw, int size, int pos)
{
	int				p;
	int				i;
	int				ret;
	unsigned char	data[4];

	p = size;
	i = 0;
	while (i < size)
	{
		data[i] = cw->arena[get_pos(pos, p)];
		p--;
		i++;
	}
	ret = *(int*)data;
	if (size == 2)
		ret = *(short*)data;
	if (size == 1)
		ret = *(char*)data;
	return (ret);
}

void		collect_arguments(t_cursor *c, t_game *cw)
{
	int	pos;

	pos = get_pos(c->pos, g_op_tab[c->ins->op].octet);
	c->ins->arg1 = get_argument(cw, size_of_arg(*(c->ins), 0), pos);
	pos = get_pos(pos, size_of_arg(*(c->ins), 0));
	c->ins->arg2 = get_argument(cw, size_of_arg(*(c->ins), 1), pos);
	pos = get_pos(pos, size_of_arg(*(c->ins), 1));
	c->ins->arg3 = get_argument(cw, size_of_arg(*(c->ins), 2), pos);
	pos = get_pos(pos, size_of_arg(*(c->ins), 2));
}

int			execute_operation(t_cursor *c, t_game *cw, t_ops op)
{
	int	ret;
	int	t;

	ret = 1;
	t = 0;
	if (c->op > 16 || c->op < 1)
		return (1);
	t = encoding_byte(cw->arena[get_pos(c->pos, 1)], c->ins, &ret);
	if (!t)
		return (ret);
	collect_arguments(c, cw);
	if (!check_registries(*(c->ins)))
		return (ret);
	if (cw->flag.vflag == 1)
		print_instruction_data(c);
	op[c->ins->op](c, cw);
	return (ret);
}

void		get_operation(t_cursor *c, t_game *cw)
{
	t_instruction	*ins;

	c->op = cw->arena[c->pos];
	if (c->op > 16 || c->op < 1)
		c->wait = 0;
	else
	{
		ins = new_instruction();
		ins->op = cw->arena[c->pos];
		c->ins = ins;
		c->wait = g_op_tab[ins->op].cycles;
	}
}
