/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_nflag.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 17:00:24 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 17:50:48 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int		check(t_player **players)
{
	while ((*players)->prev)
	{
		if ((*players)->id == (*players)->prev->id + 1)
			*players = (*players)->prev;
		else
		{
			while ((*players)->prev)
				*players = (*players)->prev;
			return (0);
		}
	}
	if ((*players)->id == (*players)->next->id - 1)
		return (1);
	return (0);
}

static void		swap(int *tmp, int *pl)
{
	(*tmp) = (*tmp) + (*pl);
	(*pl) = (*tmp) - (*pl);
	(*tmp) = (*tmp) - (*pl);
}

void			sort_players(t_player **players)
{
	t_player	*tmp;

	while ((*players)->next)
	{
		tmp = *players;
		*players = (*players)->next;
		if (tmp->id > (*players)->id)
		{
			swap(&tmp->id, &(*players)->id);
			swap(&tmp->arg_n, &(*players)->arg_n);
		}
	}
	if (check(players) == 0)
		sort_players(players);
	else
		return ;
}

int				find_n(t_player **players, int old_n, int max_pl)
{
	while ((*players)->prev)
	{
		if ((*players)->n_flag > 0 && (*players)->arg_n != old_n)
		{
			if ((*players)->n_flag > max_pl)
				(*players)->n_flag = -1;
			else
				return ((*players)->n_flag - 1);
		}
		*players = (*players)->prev;
	}
	if ((*players)->n_flag > 0 && (*players)->arg_n != old_n)
	{
		if ((*players)->n_flag > max_pl)
			(*players)->n_flag = -1;
		else
			return ((*players)->n_flag - 1);
	}
	return (-1);
}

int				search_in_arr(int *arr, int num, int max_pl)
{
	int		i;

	i = 0;
	while (i < max_pl)
	{
		if (arr[i] == num)
			return (i + 1);
		i++;
	}
	return (-2);
}
