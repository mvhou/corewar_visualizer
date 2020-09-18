/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_stats.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 13:03:17 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 22:27:02 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_print_stats(t_game *cw)
{
	t_visual *vis;

	vis = cw->v;
	mvwprintw(vis->stats, 1, 2, "cycles:%9i", cw->cycles_count);
	mvwprintw(vis->stats, 2, 2, "last live:");
	wattron(vis->stats, COLOR_PAIR(cw->player_l_alive));
	wprintw(vis->stats, "%6i", cw->player_l_alive);
	wattroff(vis->stats, COLOR_PAIR(cw->player_l_alive));
	mvwprintw(vis->stats, 3, 2, "cy2die:%9i", cw->cycles_to_die);
	mvwprintw(vis->stats, 4, 2, "check:%10i", cw->die_count);
	mvwprintw(vis->stats, 5, 2, "live count:%5i", cw->live_count);
}
