/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_nflag2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 15:52:15 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 17:50:54 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int		get_empty_index(int *arr, int max_pl)
{
	int			i;

	i = 0;
	while (arr[i] != -1 && i < max_pl)
		i++;
	if (i == max_pl)
	{
		i--;
		while (arr[i] != -1)
			i--;
	}
	if (arr[i] == -1)
		return (i);
	return (-1);
}

void			adjust_id(t_player *players, int *arr, int max_pl)
{
	while (players->next)
		players = players->next;
	while (players->prev)
	{
		players->id = search_in_arr(arr, players->arg_n, max_pl);
		players = players->prev;
	}
	players->id = search_in_arr(arr, players->arg_n, max_pl);
}

void			set_arr_m1(int max_pl, int *arr)
{
	int			i;

	i = 0;
	while (i <= max_pl)
	{
		arr[i] = -1;
		i++;
	}
}

int				check_find_n(t_player **players, int *arr, int n, int max_pl)
{
	if (arr[n] == -1)
		arr[n] = (*players)->arg_n;
	else
		exit(ft_printf("same n_flag used twice\n"));
	n = find_n(players, (*players)->arg_n, max_pl);
	return (n);
}

void			add_to_arr(t_player *players, int *arr, int max_pl)
{
	int			i;

	while (players->next)
	{
		if (players->n_flag <= 0)
		{
			i = get_empty_index(arr, max_pl);
			if (i == -1)
				exit(-1);
			arr[i] = players->arg_n;
		}
		players = players->next;
	}
	if (players->n_flag <= 0)
	{
		i = get_empty_index(arr, max_pl);
		if (i == -1)
			exit(-1);
		arr[i] = players->arg_n;
	}
}
