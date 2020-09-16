/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 21:05:27 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/17 00:26:16 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

int		main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		error("Too few arguments", 0);
	data = (t_data*)ft_memalloc(sizeof(t_data));
	check_file(argv, argc, data);
	read_name_comment(data);
	read_op(data);
	get_instruction_data(data);
	write_in_file(data);
	close(data->fd_w);
	close(data->fd_r);
	free_data(data);
	return (0);
}
