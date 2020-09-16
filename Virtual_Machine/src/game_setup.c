/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_setup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 14:58:08 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/09/16 17:49:01 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int		count_players2(t_player *players)
{
	int		cnt;

	cnt = 1;
	while (players->prev)
	{
		players = players->prev;
		cnt++;
	}
	while (players->next)
		players = players->next;
	return (cnt);
}

int				count_players(t_player *players)
{
	int		cnt;

	cnt = 1;
	if (players->next)
	{
		while (players->next)
		{
			players = players->next;
			cnt++;
		}
		while (players->prev)
			players = players->prev;
		return (cnt);
	}
	if (players->prev)
		return (count_players2(players));
	return (cnt);
}

static void		give_start_cursor(t_player *plr, int cnt_pl, unsigned char *arn)
{
	while (plr->next)
	{
		plr->cursor = (MEM_SIZE / cnt_pl) * (plr->id - 1);
		ft_memcpy(&arn[plr->cursor], plr->code, CHAMP_MAX_SIZE);
		plr = plr->next;
	}
	plr->cursor = (MEM_SIZE / cnt_pl) * (plr->id - 1);
	ft_memcpy(&arn[plr->cursor], plr->code, CHAMP_MAX_SIZE);
	while (plr->prev)
		plr = plr->prev;
}

void			game_setup(t_player *players, t_game *game_data)
{
	int				cnt_pl;

	cnt_pl = count_players(players);
	give_start_cursor(players, cnt_pl, game_data->arena);
}
