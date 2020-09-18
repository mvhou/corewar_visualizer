/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_init_visualizer.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 17:41:08 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/18 14:54:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		v_store_champion(t_visual *v, t_player *player, int pos, int size)
{
	char	*data;
	int		i;

	data = (char*)malloc(sizeof(char) * 3);
	data[2] = 0;
	i = pos;
	wattron(v->win, COLOR_PAIR(player->id));
	while (i - pos < size)
	{
		v->arena[i] = (player->id << 16) | player->code[i - pos];
		v_get_hex_str((short)(v->arena[i]), data);
		mvwprintw(v->win, (i * 3) / WIDTH + 1, (i * 3) % WIDTH + 1, data);
		wrefresh(v->win);
		usleep(1000000 * v->intro / player->data->prog_size);
		i++;
	}
	wattroff(v->win, COLOR_PAIR(player->id));
}

void		v_init_screen(t_visual *v, t_player *players)
{
	int			pos;
	t_player	*walker;

	pos = 0;
	walker = players;
	while (pos < MEM_SIZE)
	{
		mvwprintw(v->win, (pos * 3) / WIDTH + 1, (pos * 3) % WIDTH + 1, "00");
		pos++;
	}
	wrefresh(v->win);
	while (walker)
	{
		v_store_champion(v, walker, walker->cursor, walker->data->prog_size);
		walker = walker->next;
	}
	wrefresh(v->win);
}

void		v_init_colors(void)
{
	start_color();
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

t_visual	*v_init_vis(t_player *players)
{
	t_visual *v_new;

	v_new = (t_visual*)malloc(sizeof(t_visual));
	if (!v_new)
		return (NULL);
	initscr();
	curs_set(0);
	v_new->speed = INSTANT;
	v_new->intro = INSTANT;
	v_new->win = newwin(HEIGHT + 2, WIDTH + 2, 1, 10);
	v_new->stats = newwin(7, 20, 1, WIDTH + 13);
	v_new->ticker = newwin(59, 20, 8, WIDTH + 13);
	box(v_new->win, 0, 0);
	box(v_new->stats, 0, 0);
	box(v_new->ticker, 0, 0);
	wrefresh(v_new->ticker);
	v_new->ins = NULL;
	ft_bzero((void*)v_new->arena, MEM_SIZE);
	v_init_colors();
	v_init_screen(v_new, players);
	return (v_new);
}
