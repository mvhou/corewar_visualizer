/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_to_start.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/03 10:42:30 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:15:44 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

void	to_start(t_instruction **op)
{
	while (*op)
	{
		if ((*op)->prev)
			*op = (*op)->prev;
		else
			break ;
	}
}

void	op_to_start(t_data *data)
{
	if (data->op == NULL)
		error("There are no instructions", 0);
	while (data->op)
	{
		if (data->op->prev != NULL)
			data->op = data->op->prev;
		else
			break ;
	}
}

void	label_to_start(t_data *data)
{
	while (data->label)
	{
		if (data->label->prev != NULL)
			data->label = data->label->prev;
		else
			break ;
	}
}
