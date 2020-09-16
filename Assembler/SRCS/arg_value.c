/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 23:34:29 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 22:49:01 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static void	check_if_arg_value(char *s, t_data *data)
{
	int	i;

	i = 1;
	if (s[0] == ':' || ft_strchr("1234567890", s[0]))
		return ;
	else if (s[0] == 'r' && ft_strchr("1234567890", s[1]))
		return ;
	else if (s[0] == '%' || s[0] == '-')
	{
		if (s[i] == '-')
			i++;
		else if (s[i] == ':')
			return ;
		if (s[i] && ft_strchr("1234567890", s[i]))
			return ;
	}
	error("No or wrong value at arg", data->op->line_nbr);
}

static void	check_if_valid_arg(char *s, t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(s);
	while (tmp[i])
	{
		if (ft_strchr("abcdefghijklmnopqrstuvwxyz_0123456789-:%", tmp[i]))
			i++;
		else
			break ;
	}
	if (tmp[i] && tmp[i] != '\0')
		error("wrong input at argument", data->op->line_nbr);
	free(tmp);
}

void		arg_value(t_data *data, char **line)
{
	int		j;
	char	*tmp;

	j = 0;
	while (line[j])
	{
		tmp = ft_strtrim(line[j]);
		check_if_valid_arg(tmp, data);
		check_if_arg_value(tmp, data);
		if (j > data->op_nbr)
			error("to many arguments for instruction", data->op->line_nbr);
		if (tmp[0] == 'r')
			set_value_reg(data, tmp, j);
		else
			set_value_dir(data, tmp, j);
		j++;
		free(tmp);
	}
}
