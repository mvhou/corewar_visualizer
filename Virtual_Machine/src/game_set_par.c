/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_set_par.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 15:04:22 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/09/17 16:53:17 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			set_game_data(t_game *game, t_player *players)
{
	game->players = count_players(players);
	game->player_l_alive = game->players;
	game->cycles_count = 0;
	game->live_count = 0;
	game->cycles_to_die = CYCLE_TO_DIE;
	game->check_count = 0;
	game->die_count = CYCLE_TO_DIE;
}

t_game			*game_set_par(t_player *players)
{
	t_game		*game_data;
	t_cursor	*cursors;

	game_data = (t_game *)ft_memalloc(sizeof(t_game));
	set_game_data(game_data, players);
	game_setup(players, game_data);
	cursors = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	set_cursors(cursors, players);
	while (cursors->prev)
		cursors = cursors->prev;
	game_data->c = cursors;
	game_data->v = NULL;
	return (game_data);
}
