/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:02:41 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 11:38:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	write_to_memory(t_game *cw, int arg, int size, int pos)
{
	unsigned char	mask;
	int				shift;
	int				i;
	int				w_pos;

	i = 0;
	mask = 255;
	shift = 24;
	w_pos = pos;
	while (i < size)
	{
		cw->arena[w_pos] = (arg >> shift) & mask;
		if (cw->v)
			cw->v->arena[w_pos] = (cw->v->arena[w_pos] & 0xffff0000) \
			| ((arg >> shift) & mask);
		shift -= 8;
		i++;
		w_pos = get_pos(w_pos, 1);
	}
}
