/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 17:31:35 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/09/16 17:48:45 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			free_cursor(t_cursor *cursors)
{
	t_cursor	*tmp;

	while (cursors)
	{
		tmp = cursors->prev;
		free(cursors);
		cursors = tmp;
	}
	free(cursors);
}

void			free_players(t_player *players)
{
	t_player	*tmp;

	while (players)
	{
		tmp = players->next;
		free(players->data);
		free(players->code);
		free(players);
		players = tmp;
	}
	free(players);
}
