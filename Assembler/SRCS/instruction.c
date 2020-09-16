/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 17:48:10 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:15:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static char	*trim_and_dup(char *s)
{
	char	*tmp;

	tmp = ft_strtrim(s);
	s = ft_strdup(tmp);
	free(tmp);
	return (s);
}

void		store_instruction(t_data *data, char *s)
{
	if (!data->op)
	{
		data->op = (t_instruction*)ft_memalloc(sizeof(t_instruction));
		data->op->line = trim_and_dup(s);
		data->op->op_nbr = data->op_nbr;
		data->op->line_nbr = data->line;
	}
	else
	{
		data->op->next = (t_instruction*)ft_memalloc(sizeof(t_instruction));
		data->op->next->prev = data->op;
		data->op = data->op->next;
		data->op->line = trim_and_dup(s);
		data->op->op_nbr = data->op_nbr;
		data->op->line_nbr = data->line;
	}
}

void		make_one_str(char **line, t_data *data, int i, char *l1)
{
	char	*tmp;
	char	*tmp2;

	if (l1)
		tmp2 = ft_strjoin(l1, " ");
	else
	{
		tmp2 = ft_strjoin(line[i], " ");
		i++;
	}
	while (line[i])
	{
		tmp = ft_strjoin(tmp2, line[i]);
		free(tmp2);
		tmp2 = tmp;
		tmp = ft_strjoin(tmp2, " ");
		free(tmp2);
		tmp2 = tmp;
		i++;
	}
	store_instruction(data, tmp2);
	free(tmp2);
}
