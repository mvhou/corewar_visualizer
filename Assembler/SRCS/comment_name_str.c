/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comment_name_str.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/10 17:05:58 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:14:14 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static void	make_error_message(char *s, int slength, int length)
{
	char	*str;
	char	*str2;
	char	*str3;

	str3 = ft_itoa(slength);
	str = ft_strjoin(s, str3);
	free(str3);
	str3 = ft_strjoin(str, ") ");
	free(str);
	str2 = ft_itoa(length);
	str = ft_strjoin("> max len (", str2);
	free(str2);
	str2 = ft_strjoin(str, ")");
	free(str);
	str = ft_strjoin(str3, str2);
	free(str2);
	free(str3);
	error(str, 0);
}

static void	check_length(t_data *data)
{
	if (ft_strlen(data->name) > PROG_NAME_LENGTH)
		make_error_message("Champion name too long (", \
		ft_strlen(data->name), PROG_NAME_LENGTH);
	if (ft_strlen(data->comment) > COMMENT_LENGTH)
		make_error_message("Champion comment too long (", \
		ft_strlen(data->comment), COMMENT_LENGTH);
}

static char	*trim_str(char *s)
{
	char	*tmp;
	int		i;

	if (ft_strchr(s, '\"') && counting_quote(s) != 1)
		return (ft_strtrim(s));
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	tmp = &s[i];
	return (ft_strdup(tmp));
}

void		comment_name_str(char **s)
{
	char	*tmp;

	tmp = trim_str(*s);
	free(*s);
	if (tmp == NULL || ft_strlen(tmp) == 0\
	|| tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR)
	{
		if (tmp)
			free(tmp);
		*s = ft_strdup("");
		return ;
	}
	else
		check_comment(tmp, s);
	free_array_str(NULL, &tmp, 1);
}

void		read_name_comment(t_data *data)
{
	char	*s;
	char	**line;
	int		ret;

	ret = 0;
	while (!(data->name && data->comment))
	{
		ret = get_next_line(data->fd_r, &s);
		data->line++;
		if (ret <= 0)
			error("file is incomplete", 0);
		comment_name_str(&s);
		line = ft_strsplit(s, ' ');
		if (line[0] && ft_strstr(line[0], NAME_CMD_STRING))
			store_name(s, data);
		else if (line[0] && ft_strstr(line[0], COMMENT_CMD_STRING))
			store_commend(s, data);
		else if (ft_strcmp(s, "") != 0)
			error("no comment / name", data->line);
		free_array_str(&line, &s, 2);
	}
	check_length(data);
}
