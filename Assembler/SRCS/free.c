/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 13:13:38 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:14:42 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

void		dup_and_free(char **str, char **s)
{
	*s = ft_strdup(*str);
	free(*str);
}

static void	free_label(t_data *data)
{
	t_label	*tmp;

	label_to_start(data);
	while (data->label)
	{
		tmp = data->label;
		data->label = data->label->next;
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp->name);
		free(tmp);
	}
}

static void	free_op(t_data *data)
{
	t_instruction	*tmp;

	op_to_start(data);
	while (data->op)
	{
		tmp = data->op;
		data->op = data->op->next;
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp->line);
		free(tmp);
	}
}

void		free_data(t_data *data)
{
	free_label(data);
	free_op(data);
	free(data->name);
	free(data->fname);
	free(data->comment);
	free(data);
}

void		free_array_str(char ***array, char **str, int num)
{
	int		i;

	if ((num == 1 || num == 2) && *str != 0)
	{
		free(*str);
		*str = NULL;
	}
	if ((num == 0 || num == 2) && array != 0 && *array != 0)
	{
		i = 0;
		while (array[0][i])
		{
			free(array[0][i]);
			array[0][i] = NULL;
			i++;
		}
		free(*array);
		*array = NULL;
	}
}
