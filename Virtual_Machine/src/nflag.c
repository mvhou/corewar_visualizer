/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nflag.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 10:55:23 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 17:55:49 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		set_to_nul(t_flag *flag)
{
	flag->aflag = 0;
	flag->dump_flag = 0;
	flag->mod = 0;
	flag->vflag = 0;
	flag->gflag = 0;
}

void		process_g_flag(char *str, t_flag *flags)
{
	flags->gflag = 1;
	while (str)
	{
		if (*str == 'm')
		{
			flags->gflag += 2;
			return ;
		}
		if (*str == 's')
		{
			flags->gflag += 4;
			return ;
		}
		if (*str == 'b' || *str == 'w')
		{
			flags->gflag += 8;
			return ;
		}
		str++;
	}
}

int			check_flags(char **arg, t_flag *flags, int *i)
{
	if (ft_strcmp(arg[*i], "-a") == 0)
		flags->aflag = 1;
	else if (ft_strcmp(arg[*i], "-v") == 0)
		flags->vflag = 1;
	else if (ft_strcmp(arg[*i], "-dump") == 0 || ft_strcmp(arg[*i], "-d") == 0)
	{
		if (ft_strcmp(arg[*i], "-dump") == 0)
			flags->mod = 32;
		else
			flags->mod = 64;
		if (arg[*i + 1] && ft_isdigit(arg[*i + 1][0]) == 1)
		{
			flags->dump_flag = ft_atoi2(arg[*i + 1]);
			if (flags->dump_flag < 0)
				flags->dump_flag = 0;
			(*i)++;
		}
		else
			exit_vm(3, arg[*i]);
	}
	else if (arg[*i][0] == '-' && arg[*i][1] == 'g')
		process_g_flag(arg[*i], flags);
	else
		return (-1);
	return (0);
}

static void	proces_nflag(t_player *players, int n, int max_pl)
{
	int		arr[max_pl];

	set_arr_m1(max_pl, arr);
	arr[n] = players->arg_n;
	n = find_n(&players, players->arg_n, max_pl);
	while (n != -1)
		n = check_find_n(&players, arr, n, max_pl);
	add_to_arr(players, arr, max_pl);
	adjust_id(players, arr, max_pl);
}

void		ft_nflag(t_player *players)
{
	int			i;
	int			cnt;

	cnt = count_players(players);
	i = find_n(&players, -1, cnt);
	if (i < 0)
		return ;
	proces_nflag(players, i, cnt);
	sort_players(&players);
}
