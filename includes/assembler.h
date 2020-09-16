/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assembler.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 21:08:51 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/09/13 21:57:07 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include "op.h"

# define ALT_COMMENT_CHAR	';'
# define ARG				3

typedef struct				s_instruction
{
	int						op_nbr;
	int						line_nbr;
	int						nbr_args;
	int						op_byte;
	char					en_byte;
	int						instruction_code;
	int						argument[ARG];
	int						arg_t[ARG];
	int						label[ARG];
	char					*line;
	struct s_instruction	*next;
	struct s_instruction	*prev;
}							t_instruction;

typedef struct				s_label
{
	int						op_nbr;
	char					*name;
	struct s_label			*next;
	struct s_label			*prev;
}							t_label;

typedef struct				s_data
{
	char					*name;
	char					*fname;
	char					*comment;
	int						fd_r;
	int						fd_w;
	int						line;
	int						op_nbr;
	int						t_bytes;
	t_instruction			*op;
	t_label					*label;
}							t_data;

/*
**	Does file exist
*/
void						check_file(char **argv, int argc, t_data *data);
int							split_inst(char *line);

/*
**	Store Name and Comment
*/
void						read_name_comment(t_data *data);
void						store_name(char *s, t_data *data);
void						store_commend(char *s, t_data *data);
void						comment_name_str(char **s);
void						read_multipule_lines(char **s, t_data *data);
int							counting_quote(char *s);
void						check_comment(char *tmp, char **s);
void						comment_after_quote(char **quote, char **s, \
							t_data *data);

/*
**	Get Operations
*/
void						read_op(t_data *data);
void						get_op_data(t_data *data, char *s);
void						store_instruction(t_data *data, char *s);
void						check_label(char *s);
char						*check_if_label(char **line, t_data *data);
void						store_label(char *label, t_data *data);
void						fresh_str(char **s, int l);
void						make_one_str(char **line, t_data *data, int i,\
							char *l1);

/*
**	Store all Data
*/
void						get_instruction_data(t_data *data);
int							instructions(char *s);
void						arg_type1(t_data *data, int arg);
void						arg_type2(t_data *data, int arg);
void						arg_type3(t_data *data, int arg);
void						arg_value(t_data *data, char **line);
void						valid_line(t_data *data, char *line);
void						set_value_reg(t_data *data, char *line, int c);
void						set_value_dir(t_data *data, char *s, int c);
void						count_bytes(t_data *data);
void						value_label(t_data *data);
void						find_instruction(char **line, t_data *data);

/*
**	Write data in file
*/
int							write_in_file(t_data *data);
void						write_backward(t_data *data, unsigned char *s,\
							unsigned length);
void						write_op(t_data *data);

/*
**	Loop To Start
*/
void						label_to_start(t_data *data);
void						op_to_start(t_data *data);
void						to_start(t_instruction **op);

/*
**	Free Functions
*/
void						free_data(t_data *data);
void						free_array_str(char ***array, char **str, int num);
void						dup_and_free(char **str, char **s);

/*
**	Functions to Add Chars
*/
char						*add_spaces(char **str);
char						*add_space(char	**str);
char						*add_newline(char	**str);

/*
** 	Error Function
*/
void						error(char *s, int i);

/*
**	Size of bytes
**	T_DIR_SIZE	(int[]){0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4}
**	OCTET		(int[]){0, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 1, 1, 0, 1, 1, 0, 1}
*/
int							size_off_tdir(int i);
int							size_off_octet(int i);

long long int				ft_atoil(const char *str);
char						*ft_itoal(long long n);

#endif
