/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 13:11:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/17 00:33:13 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static int	count_separation(char *line)
{
	char	**str;
	char	*str2;
	int		i;

	i = 0;
	str2 = ft_strtrim(line);
	str = ft_strsplit(str2, ',');
	free(str2);
	while (str[i])
		i++;
	free_array_str(&str, NULL, 0);
	return (i);
}

void		valid_line(t_data *data, char *line)
{
	int	i;

	i = count_separation(line);
	if (i > data->op->nbr_args)
		error("Too many arguments for instruction", data->op->line_nbr);
	else if (i < data->op->nbr_args)
		error("Too few arguments for instruction", data->op->line_nbr);
}
