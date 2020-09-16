/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 22:57:53 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/17 00:33:00 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static void	join_str(char **tmp, char **str, char **s)
{
	*tmp = ft_strjoin(*str, *s);
	free(*str);
	*str = ft_strdup(*tmp);
	free(*tmp);
}

void		read_multipule_lines(char **s, t_data *data)
{
	char	*str;
	char	*tmp;
	char	*quote;
	int		ret;

	str = ft_strdup(*s);
	free(*s);
	quote = NULL;
	while (quote == NULL)
	{
		ret = get_next_line(data->fd_r, s);
		data->line++;
		quote = ft_strchr(*s, '"');
		if (quote)
			comment_after_quote(&quote, s, data);
		if (ft_strstr(*s, NAME_CMD_STRING) ||\
		ft_strstr(*s, COMMENT_CMD_STRING) || ret <= 0)
			error("Missing end quote", data->line - 1);
		str = add_newline(&str);
		if (ft_strlen(*s) > 0)
			join_str(&tmp, &str, s);
		free(*s);
	}
	dup_and_free(&str, s);
}

int			counting_quote(char *s)
{
	int	size;
	int quote;

	quote = 0;
	size = (int)ft_strlen(s);
	while (s[size - 1] && quote < 2)
	{
		if (s[size - 1] == '"')
			quote++;
		size--;
	}
	return (quote);
}

void		store_name(char *s, t_data *data)
{
	char	**array;
	int		quote;

	quote = counting_quote(s);
	array = ft_strsplit(s, '"');
	if (quote <= 0)
		error("Missing quotes", data->line);
	if (array[1])
		s = ft_strdup(array[1]);
	else
		s = ft_strdup("");
	if (quote == 1)
		read_multipule_lines(&s, data);
	if (!data->name)
		data->name = ft_strdup(s);
	else
		error("Redefinition of name", data->line);
	free_array_str(&array, &s, 2);
}

void		store_commend(char *s, t_data *data)
{
	char	**array;
	int		quote;

	quote = counting_quote(s);
	array = ft_strsplit(s, '"');
	if (quote <= 0)
		error("Missing quotes", data->line);
	if (array[1])
		s = ft_strdup(array[1]);
	else
		s = ft_strdup("");
	if (quote == 1)
		read_multipule_lines(&s, data);
	if (!data->comment)
		data->comment = ft_strdup(s);
	else
		error("Redefinition of comment", data->line);
	free_array_str(&array, &s, 2);
}
