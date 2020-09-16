/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_bytes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 21:42:53 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:14:21 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static void	op_bytes2(t_data *data)
{
	if (data->op->arg_t[2] == 1)
	{
		data->op->en_byte += 4;
		data->t_bytes += 1;
	}
	else if (data->op->arg_t[2] == 2)
	{
		data->op->en_byte += 8;
		data->t_bytes += size_off_tdir(data->op->instruction_code);
	}
	else if (data->op->arg_t[2] == 3)
	{
		data->op->en_byte += 8 + 4;
		data->t_bytes += 2;
	}
}

static void	op_bytes1(t_data *data)
{
	if (data->op->arg_t[1] == 1)
	{
		data->op->en_byte += 16;
		data->t_bytes += 1;
	}
	else if (data->op->arg_t[1] == 2)
	{
		data->op->en_byte += 32;
		data->t_bytes += size_off_tdir(data->op->instruction_code);
	}
	else if (data->op->arg_t[1] == 3)
	{
		data->op->en_byte += 32 + 16;
		data->t_bytes += 2;
	}
}

static void	op_bytes(t_data *data)
{
	if (data->op->arg_t[0] == 1)
	{
		data->op->en_byte += 64;
		data->t_bytes += 1;
	}
	else if (data->op->arg_t[0] == 2)
	{
		data->op->en_byte += 128;
		data->t_bytes += size_off_tdir(data->op->instruction_code);
	}
	else if (data->op->arg_t[0] == 3)
	{
		data->op->en_byte += 128 + 64;
		data->t_bytes += 2;
	}
}

void		count_bytes(t_data *data)
{
	data->op->op_byte = data->t_bytes;
	op_bytes(data);
	op_bytes1(data);
	op_bytes2(data);
	data->t_bytes++;
	if (size_off_octet(data->op->instruction_code) == 0)
		data->op->en_byte = 0;
	else
		data->t_bytes++;
}
