/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_instruction.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 22:17:01 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:14:34 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static int	add_instruction(t_data *data, char *arg)
{
	data->op->instruction_code = instructions(arg);
	if (data->op->instruction_code == 0)
		error("instruction does not exist", data->op->line_nbr);
	return (1);
}

void		find_instruction(char **line, t_data *data)
{
	char	*tmp;
	char	*tmp2;
	char	c;
	int		i;

	i = 0;
	tmp = ft_strtrim(*line);
	while (tmp[i])
	{
		if (ft_strchr(LABEL_CHARS, tmp[i]))
			i++;
		else
			break ;
	}
	c = tmp[i];
	tmp[i] = '\0';
	tmp2 = ft_strdup(tmp);
	add_instruction(data, tmp2);
	free(tmp2);
	tmp[i] = c;
	free(*line);
	*line = ft_strtrim(&tmp[i]);
	free(tmp);
}
