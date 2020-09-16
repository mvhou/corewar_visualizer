/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enc_byte.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 11:19:50 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 18:38:59 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		size_of_arg(t_instruction ins, int arg)
{
	if (ins.arg_type[arg] == T_DIR)
		return (g_op_tab[ins.op].label_size);
	if (ins.arg_type[arg] == T_IND)
		return (IND_SIZE);
	if (ins.arg_type[arg] == T_REG)
		return (1);
	return (0);
}

int		check_registries(t_instruction ins)
{
	if (ins.arg_type[0] == T_REG)
	{
		if (ins.arg1 > REG_NUMBER || ins.arg1 < 1)
			return (0);
	}
	if (ins.arg_type[1] == T_REG)
	{
		if (ins.arg2 > REG_NUMBER || ins.arg2 < 1)
			return (0);
	}
	if (ins.arg_type[2] == T_REG)
	{
		if (ins.arg3 > REG_NUMBER || ins.arg3 < 1)
			return (0);
	}
	return (1);
}

int		get_size(t_instruction ins)
{
	int ret;

	ret = 2;
	if (g_op_tab[ins.op].arg_type[0])
		ret += size_of_arg(ins, 0);
	if (g_op_tab[ins.op].arg_type[1])
		ret += size_of_arg(ins, 1);
	if (g_op_tab[ins.op].arg_type[2])
		ret += size_of_arg(ins, 2);
	return (ret);
}

int		check_enc_byte(t_instruction ins)
{
	if (ins.op > 16 || ins.op < 1)
		return (0);
	if (!(ins.arg_type[0] & g_op_tab[ins.op].arg_type[0]))
		return (0);
	if (!(ins.arg_type[1] & g_op_tab[ins.op].arg_type[1]) &&\
		g_op_tab[ins.op].arg_type[1] != 0)
		return (0);
	if (!(ins.arg_type[2] & g_op_tab[ins.op].arg_type[2]) &&\
		g_op_tab[ins.op].arg_type[2] != 0)
		return (0);
	return (1);
}

int		encoding_byte(unsigned char data, t_instruction *ins, int *ret)
{
	if (g_op_tab[ins->op].octet == 0)
	{
		ins->arg_type[0] = T_DIR;
		*ret = 1 + g_op_tab[ins->op].label_size;
		if (ins->op == 9)
			*ret = 0;
		return (1);
	}
	ins->arg_type[0] = (data >> 6) & 3;
	if (ins->arg_type[0] == 3)
		ins->arg_type[0] = 4;
	ins->arg_type[1] = (data >> 4) & 3;
	if (ins->arg_type[1] == 3)
		ins->arg_type[1] = 4;
	ins->arg_type[2] = (data >> 2) & 3;
	if (ins->arg_type[2] == 3)
		ins->arg_type[2] = 4;
	*ret = get_size(*ins);
	if (!check_enc_byte(*ins))
		return (0);
	return (1);
}
