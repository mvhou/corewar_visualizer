/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_visualizer.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 16:23:10 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/17 16:23:10 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_VISUALIZER_H
# define VM_VISUALIZER_H

# include "vm.h"
# include <ncurses.h>
# include <curses.h>

/*
** Main window height and width
*/

# define HEIGHT 64
# define WIDTH 192

/*
** Speed setting presets
*/

# define INSTANT 0
# define WARP 1
# define FAST 10
# define NORMAL 30
# define SLOW 100
# define TURTLE 500


typedef struct 		s_v_ins
{
	int				op;
	int				pos;
	int				size;
	int				color;
	int				time;
	struct s_v_ins	*prev;
	struct s_v_ins	*next;
}					t_v_ins;

typedef struct		s_tick
{
	int				op;
	int				value;
	struct s_tick	*next;
}					t_tick;

typedef struct		s_visual
{
	WINDOW			*win;
	WINDOW			*stats;
	WINDOW			*ticker;
	int				speed;
	int				intro;
	int				arena[MEM_SIZE];
	struct s_v_ins	*ins;
	struct s_tick	*t;
}					t_visual;

t_visual			*v_init_vis(t_player *players, int flag);
void				v_refresh(t_game *cw, t_visual *vis, t_cursor *cur);
void				v_get_hex_str(int num, char *str);
void				v_print_pixel(t_visual *v, int pos);
void				v_print_cursors(t_visual *v, t_cursor *cursor);
void				v_print_stats(t_game *cw);
void				v_delete_cursors(t_visual *v, t_cursor *cursor);
void				v_execute_instructions(t_visual *vis);
void				v_new_instruction(t_visual *vis, int op, int pos, int size);
void				v_op_ld(t_visual *vis, t_v_ins *ins);
void				v_op_st(t_visual *vis, t_v_ins *ins);
void				v_op_live(t_visual *vis, t_v_ins *ins);
void				v_clean_instructions(t_visual *vis);
int					v_set_byte(int value, int data);
void				v_set_both(int value, short color, int *data);
void				v_free_visual(t_game *cw);
void				v_add_to_ticker(t_visual *vis, int op, int value);
void				v_print_ticker(t_game *cw, t_visual *vis);
void				v_init_colors(int flag);

#endif