/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_instr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 17:14:21 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:16:20 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

int	split_inst(char *line)
{
	char	**inst;
	int		nbr;

	if (ft_strcmp(line, "") == 0)
		return (0);
	line = add_spaces(&line);
	inst = ft_strsplit(line, ' ');
	nbr = instructions(inst[0]);
	free_array_str(&inst, &line, 2);
	if (nbr > 0)
		error("instruction at last line does not end with a \\n", 0);
	error(\
	"instruction does not exist and does not end with a \\n at last line", 0);
	return (nbr);
}
