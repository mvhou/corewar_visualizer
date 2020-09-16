/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 13:17:37 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:14:06 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

static int	check_last_line(char *ch)
{
	char	*tmp;
	char	**array;

	tmp = ft_strtrim(ch);
	if (tmp == NULL || ft_strlen(tmp) == 0\
	|| tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR)
	{
		if (tmp)
			free(tmp);
		return (0);
	}
	else if (ft_strchr(tmp, COMMENT_CHAR))
		array = ft_strsplit(tmp, COMMENT_CHAR);
	else
		array = ft_strsplit(tmp, ALT_COMMENT_CHAR);
	free(tmp);
	if (array != NULL && ft_strlen(array[0]) > 0)
		split_inst(array[0]);
	free_array_str(&array, &tmp, 2);
	return (0);
}

static void	check_last_char(t_data *data)
{
	char	s[1010];
	char	str[1010];
	int		ret;
	char	*ch;

	ret = 1;
	while (ret > 0)
	{
		ft_bzero(s, 1009);
		ret = read(data->fd_r, s, 1009);
		if (ret <= 1)
			break ;
		ft_strcpy(str, s);
	}
	ch = ft_strrchr(str, '\n');
	if (ch == NULL || check_last_line(ch) == -1)
		error("file does not end with \\n", 0);
}

static void	get_file_name(char **argv, int argc, t_data *data)
{
	char	*fname;
	int		i;

	fname = ft_strtrim(argv[argc - 1]);
	i = ft_strlen(fname);
	if (fname[i - 2] == '.' && fname[i - 1] == 's')
	{
		fname[i - 1] = '\0';
		data->fname = ft_strjoin(fname, "cor");
	}
	else
	{
		free(fname);
		error(ft_strjoin(argv[argc - 1], " is no .s file"), 0);
	}
	free(fname);
}

void		check_file(char **argv, int argc, t_data *data)
{
	get_file_name(argv, argc, data);
	data->fd_r = open(argv[argc - 1], O_RDONLY);
	if (data->fd_r < 3 || read(data->fd_r, &data->name, 0) < 0)
		error(ft_strjoin("can't read ", argv[argc - 1]), 0);
	check_last_char(data);
	close(data->fd_r);
	data->fd_r = open(argv[argc - 1], O_RDONLY);
	if (data->fd_r < 3 || read(data->fd_r, &data->name, 0) < 0)
		error(ft_strjoin("can't read ", argv[argc - 1]), 0);
	data->name = NULL;
}
