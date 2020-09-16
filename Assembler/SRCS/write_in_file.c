/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_in_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:19:11 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:16:51 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

void		write_backward(t_data *data, unsigned char *s, unsigned length)
{
	while (length > 0)
	{
		length--;
		write(data->fd_w, &s[length], 1);
	}
}

static void	write_header(t_data *data)
{
	int	header;

	header = COREWAR_EXEC_MAGIC;
	write_backward(data, (unsigned char*)(&header), sizeof(int));
}

static void	write_name_comment(t_data *data, char *s, int length)
{
	int		len;
	char	*zero;

	len = ft_strlen(s);
	zero = (char*)ft_memalloc(sizeof(char) * ((length - len) + 1));
	ft_putstr_fd(s, data->fd_w);
	write(data->fd_w, zero, (length - len));
	free(zero);
}

int			write_in_file(t_data *data)
{
	int	zero_bytes;

	zero_bytes = 0;
	data->fd_w = open(data->fname, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (data->fd_w < 3)
		error(ft_strjoin("Can not create ", data->fname), 0);
	write_header(data);
	write_name_comment(data, data->name, PROG_NAME_LENGTH);
	write(data->fd_w, (unsigned char*)(&zero_bytes), 4);
	write_backward(data, (unsigned char*)(&data->t_bytes), 4);
	write_name_comment(data, data->comment, COMMENT_LENGTH);
	write(data->fd_w, (unsigned char*)(&zero_bytes), 4);
	write_op(data);
	ft_printf("Writing output program to %s\n", data->fname);
	return (1);
}
