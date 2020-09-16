/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_char.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:36:56 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:13:17 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

char		*add_newline(char **str)
{
	char	*tmp;

	tmp = ft_strjoin(*str, "\n");
	free(*str);
	return (tmp);
}

char		*add_space(char **str)
{
	char	*tmp;

	tmp = ft_strjoin(*str, " ");
	free(*str);
	return (tmp);
}

static int	check_separation(char **tmp, int j)
{
	if (tmp[0][j] == ',')
	{
		while (tmp[0][j - 1] == ' ')
			j--;
		tmp[0][j] = ',';
		j++;
		tmp[0][j] = ' ';
	}
	return (j);
}

char		*add_spaces(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char*)ft_memalloc(sizeof(char) * 2 * (ft_strlen(*str) + 1));
	while (str[0][i])
	{
		if (str[0][i] == '%')
		{
			tmp[j] = ' ';
			j++;
		}
		tmp[j] = str[0][i];
		if (str[0][i] == ',')
			j = check_separation(&tmp, j);
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}
