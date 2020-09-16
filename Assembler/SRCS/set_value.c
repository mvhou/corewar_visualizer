/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 10:15:26 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 22:47:50 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static int	find_label(t_data *data, char *s)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(s, ':');
	label_to_start(data);
	while (ft_strcmp(split[i], data->label->name) != 0)
	{
		if (data->label->next)
			data->label = data->label->next;
		else
			break ;
	}
	if (ft_strcmp(split[i], data->label->name) == 0)
	{
		free_array_str(&split, NULL, 0);
		return (data->label->op_nbr);
	}
	error("argument label not exist", data->op->line_nbr);
	return (-1);
}

static char	*remove_tokens(char *s)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		if (!(s[i] == '%' || s[i] == ':' || s[i] == ','))
		{
			tmp[j] = s[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static void	value_check_r(t_data *data, int c)
{
	if (data->op->arg_t[c] == 2 || data->op->arg_t[c] == 3\
	|| data->op->arg_t[c] == 5)
		error("wrong argument of type for instruction", data->op->line_nbr);
	data->op->arg_t[c] = 1;
}

void		set_value_reg(t_data *data, char *line, int c)
{
	int		i;
	char	str[3];

	line = remove_tokens(line);
	value_check_r(data, c);
	i = 1;
	while (line[i])
	{
		if (line[i] && ft_isdigit(line[i]))
			i++;
		else
			error("wrong input for t_reg", data->op->line_nbr);
	}
	i = 1;
	while (line[i])
	{
		str[i - 1] = line[i];
		i++;
	}
	str[i - 1] = '\0';
	data->op->argument[c] = ft_atoi(str);
	if (data->op->argument[c] < 0 || data->op->argument[c] > 99)
		error("wrong input for t_reg", data->op->line_nbr);
	free(line);
}

void		set_value_dir(t_data *data, char *s, int c)
{
	int	i;

	i = data->op->arg_t[c];
	if (ft_strchr(s, '%') && (i == 2 || i == 4 || i == 5 || i == 6))
		data->op->arg_t[c] = 2;
	else if (i == 3 || i == 4 || i == 5 || i == 7)
		data->op->arg_t[c] = 3;
	else
		error("wrong argument type for instruction", data->op->line_nbr);
	if (ft_strchr(s, ':'))
		i = 1;
	s = remove_tokens(s);
	if (i == 1)
		data->op->label[c] = find_label(data, s);
	else
	{
		if (ft_strlen(s) > ft_strlen("-9223372036854775808") && \
		ft_strchr(s, '-'))
			data->op->argument[c] = ft_atoil("-9223372036854775808");
		else if (ft_strlen(s) > ft_strlen("9223372036854775808"))
			data->op->argument[c] = ft_atoil("9223372036854775807");
		else
			data->op->argument[c] = ft_atoil(s);
	}
	free(s);
}
