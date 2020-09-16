/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   size_off.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 16:47:18 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:16:08 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

int	size_off_tdir(int i)
{
	if ((i > 0 && i <= 8) || i == 13 || i == 16)
		return (4);
	return (2);
}

int	size_off_octet(int i)
{
	if (i < 2 || i == 9 || i == 12 || i == 15)
		return (0);
	return (1);
}
