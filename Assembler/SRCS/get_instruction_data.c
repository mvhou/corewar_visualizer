/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_instruction_data.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 23:17:01 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:15:15 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static void	arg_type(t_data *data, int arg)
{
	if (arg == 1 || arg == 9 || arg == 12 || arg == 15 || arg == 16)
		arg_type1(data, arg);
	else if (arg == 2 || arg == 3 || arg == 13)
		arg_type2(data, arg);
	else if (arg == 4 || arg == 5 || arg == 6 || arg == 7 || arg == 8 ||\
	arg == 10 || arg == 11 || arg == 14)
		arg_type3(data, arg);
}

static int	count_args(int arg)
{
	if (arg == 1 || arg == 9 || arg == 12 || arg == 15 || arg == 16)
		return (1);
	else if (arg == 2 || arg == 3 || arg == 13)
		return (2);
	else if (arg == 4 || arg == 5 || arg == 6 || arg == 7 || arg == 8 ||\
	arg == 10 || arg == 11 || arg == 14)
		return (3);
	return (-1);
}

static int	instructions_2(char *s)
{
	if (ft_strcmp(s, "fork\0") == 0)
		return (12);
	else if (ft_strcmp(s, "lld\0") == 0)
		return (13);
	else if (ft_strcmp(s, "lldi\0") == 0)
		return (14);
	else if (ft_strcmp(s, "lfork\0") == 0)
		return (15);
	else if (ft_strcmp(s, "aff\0") == 0)
		return (16);
	else
		return (0);
}

int			instructions(char *s)
{
	if (ft_strcmp(s, "live\0") == 0)
		return (1);
	else if (ft_strcmp(s, "ld\0") == 0)
		return (2);
	else if (ft_strcmp(s, "st\0") == 0)
		return (3);
	else if (ft_strcmp(s, "add\0") == 0)
		return (4);
	else if (ft_strcmp(s, "sub\0") == 0)
		return (5);
	else if (ft_strcmp(s, "and\0") == 0)
		return (6);
	else if (ft_strcmp(s, "or\0") == 0)
		return (7);
	else if (ft_strcmp(s, "xor\0") == 0)
		return (8);
	else if (ft_strcmp(s, "zjmp\0") == 0)
		return (9);
	else if (ft_strcmp(s, "ldi\0") == 0)
		return (10);
	else if (ft_strcmp(s, "sti\0") == 0)
		return (11);
	else
		return (instructions_2(s));
}

void		get_instruction_data(t_data *data)
{
	char	**line;
	char	*str;

	op_to_start(data);
	while (data->op->line)
	{
		str = add_spaces(&data->op->line);
		line = ft_strsplit(str, ',');
		find_instruction(&line[0], data);
		data->op->nbr_args = count_args(data->op->instruction_code);
		valid_line(data, str);
		arg_type(data, data->op->instruction_code);
		arg_value(data, line);
		count_bytes(data);
		free_array_str(&line, &str, 2);
		if (data->op->next)
			data->op = data->op->next;
		else
			break ;
	}
	value_label(data);
}
