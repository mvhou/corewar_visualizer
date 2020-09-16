/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fresh_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 12:32:48 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:14:50 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static int	check_line(char *s)
{
	int		x;
	char	**tmp;
	char	*tmp2;

	x = 0;
	if (ft_strchr(s, COMMENT_CHAR))
		tmp = ft_strsplit(s, COMMENT_CHAR);
	else
		tmp = ft_strsplit(s, ALT_COMMENT_CHAR);
	if (tmp[0])
	{
		tmp2 = ft_strtrim(tmp[0]);
		if (tmp2[0] == ',')
			x = -1;
		free(tmp2);
	}
	free_array_str(&tmp, NULL, 0);
	return (x);
}

void		fresh_str(char **s, int l)
{
	char	*tmp;
	char	**array;

	tmp = ft_strtrim(*s);
	free(*s);
	array = NULL;
	if (tmp == NULL || ft_strlen(tmp) == 0\
	|| tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR)
	{
		if (tmp)
			free(tmp);
		*s = ft_strdup("");
		return ;
	}
	else if ((tmp && ft_strlen(tmp) < 2) || check_line(tmp) == -1)
		error("no instruction / comment", l);
	else if (ft_strchr(tmp, COMMENT_CHAR))
		array = ft_strsplit(tmp, COMMENT_CHAR);
	else
		array = ft_strsplit(tmp, ALT_COMMENT_CHAR);
	if (array != NULL && ft_strlen(array[0]) > 0)
		*s = ft_strtrim(array[0]);
	free_array_str(&array, &tmp, 2);
}
