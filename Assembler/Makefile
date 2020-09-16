# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eutrodri <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/05 01:47:23 by eutrodri      #+#    #+#                  #
#    Updated: 2020/09/15 00:06:13 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRCS = error.c get_instruction_data.c loop_to_start.c split_instr.c add_char.c\
		asm.c check_file.c instruction.c label.c store_data.c arg_type.c\
		comment_name_str.c free.c label_op_data.c read_op.c valid_line.c\
		arg_value.c count_bytes.c fresh_str.c set_value.c write_in_file.c\
		size_off.c value_label.c write_op.c find_instruction.c ft_atoil.c \
		ft_itoal.c check_comment.c

OBJ = error.o get_instruction_data.o loop_to_start.o split_instr.o add_char.o\
		asm.o check_file.o instruction.o label.o store_data.o arg_type.o\
		comment_name_str.o free.o label_op_data.o read_op.o valid_line.o\
		arg_value.o count_bytes.o fresh_str.o set_value.o write_in_file.o\
		size_off.o value_label.o write_op.o find_instruction.o ft_atoil.o \
		ft_itoal.o check_comment.o

FLAGS = -Wall -Werror -Wextra

HEADER_FILES = ../includes/assembler.h

LIB = ../Libft/libft.a
PR = ../libft/ft_printf/libftprintf.a

S = $(addprefix srcs/, $(SRCS))

O = $(addprefix obj/, $(OBJ))

O_P = mkdir -p obj

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_RED = $(shell printf "\e[31;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")
NORM = norminette $(S) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')
PRINT_CLEAN = $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFAULT)')
PROCESS = $(shell printf '$(COLOR_YELLOW)[ › ]$(COLOR_DEFAULT)')

all: $(NAME)

$(NAME) : $(LIB) $(O) $(PR)
	@echo "$(PROCESS) $(COLOR_YELLOW)COMPILING$(COLOR_DEFAULT)"
	@gcc -o $(NAME) $(O) -I ../includes ../libft/ft_printf/libftprintf.a\
	 ../libft/libft.a
	@echo "$(PRINT_PLUS) $(COLOR_GREEN)Done$(COLOR_DEFAULT)"

obj/%.o : srcs/%.c
	@$(O_P)
	@gcc $(FLAGS) -c -o $@ $< -I includes

$(LIB) :
	@make -C ../libft/
	@echo "$(PRINT_PLUS) $(COLOR_GREEN)Libft Done$(COLOR_DEFAULT)"

$(PR) :
	@make -C ../libft/ft_printf/
	@echo "$(PRINT_PLUS) $(COLOR_GREEN)Printf Done$(COLOR_DEFAULT)"

clean:
	@rm -rf $(O) obj/
	@echo "$(PRINT_CLEAN) $(COLOR_RED)Removed .o files$(COLOR_DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(PRINT_CLEAN) $(COLOR_RED)Removed libary$(COLOR_DEFAULT)"

re: fclean all

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"
