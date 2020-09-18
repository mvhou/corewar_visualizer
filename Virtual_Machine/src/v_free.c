/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_free.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 11:36:16 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 22:22:56 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_free_visual(t_game *cw)
{
	t_tick *temp;
	t_tick *walker;

	free(cw->v);
	cw->v = NULL;
	walker = cw->v->t;
	while (walker)
	{
		temp = walker->next;
		free(walker);
		walker = temp;
	}
	endwin();
}
