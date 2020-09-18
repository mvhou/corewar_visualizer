/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_ticker.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 13:43:53 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 18:14:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

char	*v_get_op_name(int op)
{
	if (op == 3)
		return ("live");
	return ("fork");
}

void	v_clean_ticker(t_tick *tick, t_tick *prev)
{
	t_tick *temp;

	prev->next = NULL;
	while (tick)
	{
		temp = tick->next;
		free(tick);
		tick = temp;
	}
}

void	v_add_to_ticker(t_visual *vis, int op, int value)
{
	t_tick *new;
	t_tick *walker;

	new = (t_tick*)malloc(sizeof(t_tick));
	new->op = op;
	new->value = value;
	new->next = NULL;
	walker = vis->t;
	if (!walker)
		vis->t = new;
	else
	{
		new->next = vis->t;
		vis->t = new;
	}
}

void	v_print_ticker(t_game *cw, t_visual *vis)
{
	t_tick	*walker;
	t_tick	*temp;
	int		y;

	y = 1;
	walker = vis->t;
	while (walker && y < 58)
	{
		if (walker->op == 3 && walker->value > 0 && \
		walker->value <= cw->players)
			wattron(vis->ticker, COLOR_PAIR(walker->value));
		mvwprintw(vis->ticker, y, 2, "%s %i", \
		v_get_op_name(walker->op), walker->value);
		if (walker->op == 3 && walker->value > 0 && \
		walker->value <= cw->players)
			wattroff(vis->ticker, COLOR_PAIR(walker->value));
		y++;
		if (y == 57)
			temp = walker;
		walker = walker->next;
	}
	if (walker)
		v_clean_ticker(walker, temp);
}
