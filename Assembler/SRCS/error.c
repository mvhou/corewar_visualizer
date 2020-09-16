/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/10 17:43:11 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/14 15:12:16 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/assembler.h"

/*
**error_no1	Not Enough arguments
**error_no2	No . s check_file
**error_no3	Error: cant read %s.s
**error_no4	Error: No quotes\n
**error_no5	Error: redefine comment
**error_no6	Error: redefine store_name
**error_no7	Error: missing end quote\n
*/

void	error(char *s, int i)
{
	char	*str;
	char	*str2;
	char	*n;

	str = ft_strjoin("Error: ", s);
	str2 = str;
	if (i > 0)
	{
		str = ft_strjoin(str2, " at line ");
		free(str2);
		n = ft_itoa(i);
		str2 = ft_strjoin(str, n);
		free(n);
		free(str);
	}
	str = ft_strjoin(str2, "\n");
	free(str2);
	ft_putstr_fd(str, 2);
	free(str);
	exit(1);
}
