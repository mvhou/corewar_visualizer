/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 22:15:00 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 18:17:58 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		main(int argc, char **argv)
{
	t_player	*players;
	t_game		*cw;
	int			winner;
	t_flag		flag;

	players = (t_player*)ft_memalloc(sizeof(t_player));
	players->data = (t_header*)ft_memalloc(sizeof(t_header));
	if (argc < 2 || ft_strcmp(argv[1], "-u") == 0)
		usage();
	flag = check_args(argv, argc, players);
	read_args(argv, players);
	intro_players(players);
	cw = game_set_par(players);
	cw->flag = flag;
	winner = game_loop(cw);
	kill_all_cursors(cw);
	free(cw);
	ft_printf("Contestant %i, \"%s\", has won !\n", winner, \
	get_winner(players, winner));
	free_players(players);
	return (0);
}
