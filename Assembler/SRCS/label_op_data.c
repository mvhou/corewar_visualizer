/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_op_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 00:52:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:15:37 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static int	colom(char *s)
{
	char	*tmp;

	tmp = ft_strchr(s, ':');
	if (tmp)
	{
		if (tmp[-1] && (tmp[-1] == '\t' || tmp[-1] == '%' || tmp[-1] == ','))
			return (1);
	}
	return (0);
}

void		get_op_data(t_data *data, char *s)
{
	char	**line;
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	line = ft_strsplit(s, ' ');
	if (line[0] && (ft_strchr(line[0], ':') == NULL || colom(line[0]) == 1))
	{
		free_array_str(&line, NULL, 0);
		store_instruction(data, s);
		data->op_nbr++;
		return ;
	}
	if (line[0] && ft_strchr(line[0], ':'))
		tmp = check_if_label(&line[0], data);
	if (tmp || (ft_strchr(line[0], ':') && ft_strchr(line[0], '%') == NULL))
		i++;
	if (line[i] || tmp)
	{
		make_one_str(line, data, i, tmp);
		data->op_nbr++;
	}
	free_array_str(&line, &tmp, 2);
}
