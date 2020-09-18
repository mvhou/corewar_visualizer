/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_free.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 11:36:16 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 11:41:38 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_free_visual(t_game *cw)
{
	free(cw->v);
	cw->v = NULL;
	endwin();
}
