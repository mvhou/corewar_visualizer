/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 10:16:13 by eutrodri      #+#    #+#                 */
/*   Updated: 2019/05/07 20:28:41 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lost_and_found(char *str, char **line, char *tmp)
{
	int			i;
	int			j;

	j = ft_strlen(str);
	i = tmp - str;
	tmp[0] = '\0';
	*line = ft_strdup(str);
	ft_memmove(str, &tmp[1], j - i);
}

static int	check_new_return(char *str, char **line, int ret)
{
	char		*tmp;

	tmp = ft_strchr(str, '\n');
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str == NULL || str[0] == '\0'))
	{
		*line = ft_strnew(0);
		return (0);
	}
	else if ((tmp))
		lost_and_found(str, line, tmp);
	else
	{
		*line = ft_strdup(str);
		ft_bzero(str, ft_strlen(str));
	}
	return (1);
}

static void	read_for_life(char **str, char *tmp, char *buf)
{
	tmp = *str;
	str[0] = ft_strjoin(str[0], buf);
	free(tmp);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[4096];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || fd > 4096)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	if (fd < 0 || line == NULL || !str[fd])
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret > 0)
		{
			read_for_life(&str[fd], tmp, buf);
			tmp = ft_strchr(str[fd], '\n');
			if (tmp)
				break ;
		}
	}
	return (check_new_return(str[fd], line, ret));
}
