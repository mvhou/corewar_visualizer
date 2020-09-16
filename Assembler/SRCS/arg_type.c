/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_type.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 18:19:16 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:13:33 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

void	arg_type3(t_data *data, int arg)
{
	data->op->arg_t[2] = 1;
	if (arg == 4 || arg == 5)
	{
		data->op->arg_t[0] = 1;
		data->op->arg_t[1] = 1;
	}
	else if (arg == 6 || arg == 7 || arg == 8)
	{
		data->op->arg_t[0] = 4;
		data->op->arg_t[1] = 4;
	}
	else if (arg == 10 || arg == 14)
	{
		data->op->arg_t[0] = 4;
		data->op->arg_t[1] = 6;
	}
	else
	{
		data->op->arg_t[0] = 1;
		data->op->arg_t[1] = 4;
		data->op->arg_t[2] = 6;
	}
}

void	arg_type2(t_data *data, int arg)
{
	if (arg == 2 || arg == 13)
	{
		data->op->arg_t[0] = 5;
		data->op->arg_t[1] = 1;
	}
	else
	{
		data->op->arg_t[0] = 1;
		data->op->arg_t[1] = 7;
	}
}

void	arg_type1(t_data *data, int arg)
{
	if (arg == 16)
		data->op->arg_t[0] = 1;
	else
		data->op->arg_t[0] = 2;
}
