/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intro.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 13:02:30 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 17:49:08 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			intro_players(t_player *pl)
{
	ft_printf("Introducing contestants...\n");
	while (pl)
	{
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",\
		pl->id, pl->data->prog_size, pl->data->prog_name, pl->data->comment);
		pl = pl->next;
	}
}
