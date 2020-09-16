/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_op.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/07 23:27:24 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:17:00 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static void	write_one_byte(int i, t_data *data)
{
	unsigned char	x;

	x = (unsigned char)i;
	write_backward(data, (unsigned char*)(&x), sizeof(x));
}

static void	check_arg_type(t_data *data, int counter)
{
	unsigned short	y;
	unsigned int	z;

	if (data->op->arg_t[counter] == 1)
		write_one_byte(data->op->argument[counter], data);
	else if (data->op->arg_t[counter] == 3 || (data->op->arg_t[counter]\
	== 2 && size_off_tdir(data->op->instruction_code) == 2))
	{
		y = (unsigned short)data->op->argument[counter];
		write_backward(data, (unsigned char*)(&y), sizeof(y));
	}
	else
	{
		z = (unsigned int)data->op->argument[counter];
		write_backward(data, (unsigned char*)(&z), sizeof(z));
	}
}

void		write_op(t_data *data)
{
	int	counter;

	op_to_start(data);
	while (data)
	{
		counter = 0;
		write_one_byte(data->op->instruction_code, data);
		if (data->op->en_byte != 0)
			write_one_byte(data->op->en_byte, data);
		while (counter < data->op->nbr_args)
		{
			check_arg_type(data, counter);
			counter++;
		}
		if (data->op->next != 0)
			data->op = data->op->next;
		else
			break ;
	}
}
