/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   usage.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/14 17:03:53 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 18:33:04 by anonymous     ########   odam.nl         */
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
	ft_printf("			-g	: Graphics mode. ");
	ft_printf("-g is default, -gb for greyscale, -gm for matrix\n");
	exit(1);
}
