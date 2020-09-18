/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_cursors.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 22:58:12 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/17 22:58:12 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_print_cursors(t_visual *v, t_cursor *cursor)
{
	t_cursor *walker;

	walker = cursor;
	while (walker)
	{
		wattron(v->win, COLOR_PAIR((v->arena[walker->pos] >> 16) + 5));
		v_print_pixel(v, walker->pos);
		wattroff(v->win, COLOR_PAIR((v->arena[walker->pos] >> 16) + 5));
		walker = walker->next;
	}
}

void		v_delete_cursors(t_visual *v, t_cursor *cursor)
{
	t_cursor *walker;

	walker = cursor;
	while (walker)
	{
		wattron(v->win, COLOR_PAIR((v->arena[walker->pos] >> 16)));
		v_print_pixel(v, walker->pos);
		wattroff(v->win, COLOR_PAIR((v->arena[walker->pos] >> 16)));
		walker = walker->next;
	}
}
