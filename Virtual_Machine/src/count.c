/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 09:38:57 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 17:48:26 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			count_args(char **argv, int argc)
{
	int		i;
	int		cnt;
	char	*tmp;

	i = 0;
	cnt = 0;
	while (i < argc)
	{
		tmp = ft_strstr(argv[i], ".cor\0");
		if (tmp != NULL)
			cnt++;
		i++;
	}
	return (cnt);
}
