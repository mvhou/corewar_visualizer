/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_comment.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 14:45:58 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/17 00:26:34 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

void	comment_after_quote(char **quote, char **s, t_data *data)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strchr(*s, '"');
	tmp2 = NULL;
	if (tmp && tmp[1])
		tmp2 = ft_strtrim(&tmp[1]);
	else
	{
		*quote[0] = '\0';
		return ;
	}
	if (tmp2 == NULL || (tmp2 && (tmp2[0] == '#' || tmp2[0] == ';')))
	{
		*quote[0] = '\0';
		free(tmp2);
		return ;
	}
	error("Invalid input after comment or name", data->line);
}

void	check_comment(char *tmp, char **s)
{
	int		quote;
	int		i;

	i = 0;
	quote = 0;
	while (tmp[i])
	{
		if (quote >= 2 && (tmp[i] == '#' || tmp[i] == ';'))
		{
			tmp[i] = '\0';
			break ;
		}
		else if (quote == 2 && (tmp[i] != '\t' || tmp[i] != ' '))
			tmp = ft_strdup("noo");
		if (quote < 2 && tmp[i] == '"')
			quote++;
		i++;
	}
	if (quote == 2)
		tmp = ft_strtrim(tmp);
	*s = ft_strdup(tmp);
	if (quote == 2)
		free(tmp);
}
