/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_refresh.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 23:10:48 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 20:42:40 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_clean_up(t_visual *vis, t_cursor *cursors)
{
	v_clean_instructions(vis);
	v_delete_cursors(vis, cursors);
}

void		v_refresh(t_game *cw, t_visual *vis, t_cursor *cur)
{
	v_execute_instructions(vis);
	v_print_cursors(vis, cur);
	v_print_stats(cw);
	v_print_ticker(cw, vis);
	wrefresh(vis->win);
	wrefresh(vis->stats);
	wrefresh(vis->ticker);
	usleep(2000 * vis->speed);
	v_clean_up(vis, cur);
}
