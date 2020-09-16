/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   value_label.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 18:10:18 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:16:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static void	calc_value(t_data *data, int i)
{
	t_instruction	*op;

	op = data->op;
	to_start(&op);
	while (op)
	{
		if (op->op_nbr == data->op->label[i])
		{
			data->op->argument[i] = op->op_byte - data->op->op_byte;
			break ;
		}
		op = op->next;
	}
	if (op == NULL)
		data->op->argument[i] = data->t_bytes - data->op->op_byte;
}

void		value_label(t_data *data)
{
	int i;

	op_to_start(data);
	while (data->op)
	{
		i = 0;
		while (i < 3)
		{
			if (data->op->label[i] != 0)
				calc_value(data, i);
			i++;
		}
		if (data->op->next)
			data->op = data->op->next;
		else
			break ;
	}
}
