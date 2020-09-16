/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_op.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 13:20:30 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 23:46:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

void	read_op(t_data *data)
{
	char	*s;
	int		ret;

	ret = 1;
	data->op_nbr = 1;
	while (ret == 1)
	{
		ret = get_next_line(data->fd_r, &s);
		data->line++;
		fresh_str(&s, data->line);
		if (ft_strchr(s, ':') || ft_strchr(s, ',') || ft_strchr(s, '%'))
			get_op_data(data, s);
		else if (ft_strstr(s, "aff"))
		{
			store_instruction(data, s);
			data->op_nbr++;
		}
		else if (ft_strcmp(s, "") != 0)
			error("Wrong input", data->line);
		free(s);
	}
	if (ret != 0)
		error("Can't read", data->line);
}
