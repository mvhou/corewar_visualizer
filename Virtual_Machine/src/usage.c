/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   usage.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 17:03:53 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/16 22:49:51 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		usage(void)
{
	ft_printf("Usage: ./corewar [-d N -dump N -v -a -u] \
	[[-n number] champion1.cor] ...\n");
	ft_printf("\t\tPossible Flags:\n");
	ft_printf("\t\t\t-u	: Outputs this usage message\n");
	ft_printf("\t\t\t-d N	: Dumps memory after N cycles, 64 octets per \
line, then exits\n");
	ft_printf("			-dump N	: Dumps memory after N cycles, 32 octets per \
line, then exits\n");
	ft_printf("			-a	: Prints output from 'aff', default is to hide \
it\n");
	ft_printf("			-v	: Verbose mode\n");
	exit(1);
}
