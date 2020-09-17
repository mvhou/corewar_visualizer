/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 11:19:01 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/17 02:18:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		get_pos(int position, int distance)
{
	int new_pos;

	new_pos = position + distance;
	while (new_pos < 0)
		new_pos += MEM_SIZE;
	return (new_pos % MEM_SIZE);
}

void	print_arg_type(t_instruction ins, int i)
{
	if (ins.arg_type[i] == T_REG)
		ft_printf("r");
	else if (ins.arg_type[i] == T_DIR)
		ft_printf("%%");
}

void	print_instruction_data(t_cursor *c)
{
	t_instruction ins;

	ins = *(c->ins);
	ft_printf("pos%5i | ", c->pos);
	ft_printf("%s ", g_op_tab[ins.op].name);
	print_arg_type(ins, 0);
	if (ins.arg_type[0])
		ft_printf("%i ", ins.arg1);
	print_arg_type(ins, 1);
	if (ins.arg_type[1])
		ft_printf("%i ", ins.arg2);
	print_arg_type(ins, 2);
	if (ins.arg_type[2])
		ft_printf("%i ", ins.arg3);
	if (ins.op == 9)
	{
		if (c->carry == 1)
			ft_printf("OK");
		else
			ft_printf("FAILED");
	}
	ft_printf("\n");
}

char	*get_winner(t_player *players, int id)
{
	t_player *temp;

	temp = players;
	while (temp)
	{
		if (temp->id == id)
			return (temp->data->prog_name);
		temp = temp->next;
	}
	return (NULL);
}

void	exit_vm(int code, char *str)
{
	if (code == 1)
		ft_printf("Error: Incorrect -n flag format\n");
	else if (code == 2)
		ft_printf("Error: '%s' is not a valid option or .cor file\n", str);
	else if (code == 3)
		ft_printf("Error: Invalid use of '%s' flag\n", str);
	else if (code == 4)
		ft_printf("Error: Duplicate -n flag\n");
	else if (code == 5)
		ft_printf("Error: Can't read file '%s'\n", str);
	else if (code == 6)
		ft_printf("Error: Invalid magic header\n");
	else if (code == 7)
		ft_printf("Error: Program name is too short\n");
	else if (code == 8)
		ft_printf("Error: Invalid null bytes\n");
	else if (code == 9)
		ft_printf("Error: Can't read code size\n");
	else if (code == 10)
		ft_printf("Error: Comment name is too short\n");
	else if (code == 11)
		ft_printf("Error: Champion code exceeds maximum size\n");
	else
		usage();
	exit(code);
}
