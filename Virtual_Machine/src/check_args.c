/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 19:30:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 22:45:31 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void	add_node(t_player **players, int *pl)
{
	if (*pl > 1)
	{
		(*players)->next = (t_player*)ft_memalloc(sizeof(t_player));
		(*players)->next->data = (t_header*)ft_memalloc(sizeof(t_header));
		(*players)->next->prev = *players;
		*players = (*players)->next;
		(*pl)--;
	}
}

static void	give_id(t_player *players, int plr)
{
	int		id;

	id = 1;
	while (players->prev)
		players = players->prev;
	while (id <= plr)
	{
		players->id = id;
		id++;
		if (players->next)
			players = players->next;
	}
}

static void	check_nflag(t_player *players, char *arg, int *i)
{
	if (arg && ft_isdigit(arg[0]) == 1)
	{
		players->n_flag = ft_atoi2(arg);
		if (players->n_flag <= 0)
			players->n_flag = -1;
	}
	else
		exit_vm(1, NULL);
	*i += 1;
}

static int	str_ending(char *str, char *ending)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != ending[0])
		i--;
	if (str[i] == ending[0])
		return (ft_strcmp(&str[i], ending));
	return (1);
}

t_flag		check_args(char **argv, int argc, t_player *players)
{
	int			pl;
	int			i;
	t_flag		flag;

	set_to_nul(&flag);
	pl = count_args(argv, argc);
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
			check_nflag(players, argv[i + 1], &i);
		else if (str_ending(argv[i], ".cor") == 0)
		{
			players->arg_n = i;
			add_node(&players, &pl);
		}
		else if (check_flags(argv, &flag, &i) != 0)
			exit_vm(2, argv[i]);
		i++;
	}
	give_id(players, count_args(argv, argc));
	ft_nflag(players);
	return (flag);
}
