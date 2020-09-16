/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 11:18:49 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 17:49:27 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

t_instruction		*new_instruction(void)
{
	t_instruction *new;

	new = (t_instruction*)malloc(sizeof(t_instruction));
	if (!new)
		exit(0);
	new->arg_type[0] = 0;
	new->arg_type[1] = 0;
	new->arg_type[2] = 0;
	new->arg1 = 0;
	new->arg2 = 0;
	new->arg3 = 0;
	new->op = 0;
	return (new);
}
