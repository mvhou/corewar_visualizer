/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:28:43 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 18:35:22 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void	kill_cursor2(t_game *cw, t_cursor **c)
{
	t_cursor *tmp;

	tmp = *c;
	if ((*c)->prev)
	{
		(*c)->prev->next = NULL;
		*c = (*c)->prev;
		if (tmp->ins)
			free(tmp->ins);
		free(tmp);
	}
	else
	{
		if (tmp->ins)
			free(tmp->ins);
		free(tmp);
		cw->c = NULL;
		*c = NULL;
	}
}

void		kill_cursor(t_game *cw, t_cursor **c)
{
	t_cursor	*tmp;

	tmp = *c;
	if ((*c)->next)
	{
		if ((*c)->prev)
			(*c)->prev->next = (*c)->next;
		(*c)->next->prev = (*c)->prev;
		if (!(*c)->prev)
			cw->c = (*c)->next;
		*c = (*c)->next;
		if (tmp->ins)
			free(tmp->ins);
		free(tmp);
	}
	else
		kill_cursor2(cw, c);
}

void		kill_all_cursors(t_game *cw)
{
	t_cursor *temp1;
	t_cursor *temp2;

	temp1 = cw->c;
	while (temp1)
	{
		temp2 = temp1->prev;
		if (temp1->ins)
			free(temp1->ins);
		free(temp1);
		temp1 = NULL;
		if (temp2)
			temp1 = temp2;
	}
}
