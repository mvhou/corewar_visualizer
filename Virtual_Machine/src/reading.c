/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:42:07 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 22:42:07 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		get_null_bytes(int fd)
{
	int				i;
	unsigned int	j;

	i = read(fd, &j, 4);
	if (i < 4 || j != 0)
		exit_vm(8, NULL);
}

void		get_name_comment(t_player *players, int fd)
{
	int				i;
	unsigned int	j;

	i = read(fd, players->data->prog_name, PROG_NAME_LENGTH);
	if (i < PROG_NAME_LENGTH)
		exit_vm(7, NULL);
	get_null_bytes(fd);
	i = read(fd, &j, 4);
	if (i < 4)
		exit_vm(9, NULL);
	i = read(fd, players->data->comment, COMMENT_LENGTH);
	if (i < COMMENT_LENGTH)
		exit_vm(10, NULL);
}

void		get_code_size(t_player *players, int fd)
{
	int				i;

	players->code = (unsigned char *)ft_strnew(CHAMP_MAX_SIZE + 1);
	i = read(fd, players->code, CHAMP_MAX_SIZE + 1);
	if (i > CHAMP_MAX_SIZE)
		exit_vm(11, NULL);
	players->data->prog_size = i;
}

void		get_data(int fd, t_player *players)
{
	int			i;
	char		*str;
	char		*str2;

	i = read(fd, &players->data->magic, 4);
	if (i < 4)
		exit_vm(6, NULL);
	str = itoa_base(players->data->magic, 16);
	str2 = itoa_base(COREWAR_EXEC_MAGIC, 16);
	str[6] = '\0';
	str = str_rev_by_2(str);
	if (ft_strcmp(str, str2) != 0)
		exit_vm(6, NULL);
	free(str);
	free(str2);
	get_name_comment(players, fd);
	get_null_bytes(fd);
	get_code_size(players, fd);
}

void		read_args(char **argv, t_player *players)
{
	int		fd;

	while (players->next)
	{
		fd = open(argv[players->arg_n], O_RDONLY);
		if (fd < 0)
			exit_vm(5, argv[players->arg_n]);
		get_data(fd, players);
		players = players->next;
	}
	fd = open(argv[players->arg_n], O_RDONLY);
	if (fd < 0)
		exit_vm(5, argv[players->arg_n]);
	get_data(fd, players);
	while (players->prev)
		players = players->prev;
}
