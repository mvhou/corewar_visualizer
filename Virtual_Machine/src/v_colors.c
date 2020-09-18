/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_colors.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 17:03:50 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 20:07:15 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_matrix_mode(void)
{
	init_color(COLOR_RED, 0, 400, 0);
	init_color(COLOR_BLUE, 0, 400, 0);
	init_color(COLOR_YELLOW, 0, 400, 0);
	init_color(COLOR_MAGENTA, 0, 400, 0);
	init_color(COLOR_GREEN, 0, 200, 0);
	init_color(COLOR_WHITE, 100, 300, 100);
}

void		v_bw_mode(void)
{
	init_color(COLOR_RED, 600, 600, 600);
	init_color(COLOR_BLUE, 600, 600, 600);
	init_color(COLOR_YELLOW, 600, 600, 600);
	init_color(COLOR_MAGENTA, 600, 600, 600);
	init_color(COLOR_GREEN, 600, 600, 600);
	init_color(COLOR_WHITE, 300, 300, 300);
}

void		v_init_color_pairs(void)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_RED, COLOR_WHITE);
	init_pair(7, COLOR_BLUE, COLOR_WHITE);
	init_pair(8, COLOR_YELLOW, COLOR_WHITE);
	init_pair(9, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(10, COLOR_RED, COLOR_GREEN);
	init_pair(11, COLOR_BLUE, COLOR_GREEN);
	init_pair(12, COLOR_YELLOW, COLOR_GREEN);
	init_pair(13, COLOR_MAGENTA, COLOR_GREEN);
	init_pair(14, COLOR_WHITE, COLOR_BLACK);
}

void		v_init_colors(int flag)
{
	if (flag)
		start_color();
	init_color(COLOR_RED, 600, 100, 100);
	init_color(COLOR_BLUE, 200, 200, 600);
	init_color(COLOR_YELLOW, 600, 500, 200);
	init_color(COLOR_MAGENTA, 400, 0, 600);
	init_color(COLOR_GREEN, 200, 600, 200);
	init_color(COLOR_WHITE, 700, 700, 700);
	v_init_color_pairs();
	if (flag & 2)
		v_matrix_mode();
}
