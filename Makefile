# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eovertoo <eovertoo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/02 17:11:36 by eovertoo      #+#    #+#                  #
#    Updated: 2020/09/18 13:52:11 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = asm

ASM_SRCS = error.c get_instruction_data.c loop_to_start.c split_instr.c \
		add_char.c asm.c check_file.c instruction.c label.c store_data.c \
		arg_type.c comment_name_str.c \
		free.c label_op_data.c read_op.c valid_line.c\
		arg_value.c count_bytes.c fresh_str.c set_value.c write_in_file.c\
		size_off.c value_label.c write_op.c find_instruction.c ft_atoil.c \
		ft_itoal.c check_comment.c

ASM_OBJ = error.o get_instruction_data.o loop_to_start.o \
		split_instr.o add_char.o\
		asm.o check_file.o instruction.o label.o store_data.o arg_type.o\
		comment_name_str.o free.o label_op_data.o read_op.o valid_line.o\
		arg_value.o count_bytes.o fresh_str.o set_value.o write_in_file.o\
		size_off.o value_label.o write_op.o find_instruction.o ft_atoil.o \
		ft_itoal.o check_comment.o

NAME2 = corewar

VM_SRC =  main.c utils_nflag.c check_args.c itoa_base.c reading.c intro.c\
		str_rev_by_2.c game_setup.c \
		game_set_par.c set_cursors.c free.c count.c\
		usage.c utils_nflag2.c nflag.c game_loop.c cursor.c enc_byte.c new.c\
		utilities.c operations.c op.c \
		print_dump.c operations/ld.c\
		operations/fork.c operations/live.c operations/sti.c operations/aff.c\
		operations/zjmp.c operations/st.c operations/add.c operations/sub.c\
		operations/and.c operations/or.c operations/xor.c write.c\
		operations/ldi.c \
		v_init_visualizer.c v_print.c v_free.c v_operations.c v_stats.c\
		v_cursors.c v_refresh.c v_new_instruction.c v_instructions.c\
		v_ticker.c

VM_OBJ =  main.o utils_nflag.o check_args.o itoa_base.o reading.o intro.o\
		str_rev_by_2.o game_setup.o game_set_par.o \
		set_cursors.o free.o count.o\
		usage.o utils_nflag2.o nflag.o game_loop.o cursor.o enc_byte.o new.o\
		utilities.o operations.o op.o fork.o sti.o aff.o zjmp.o live.o\
		ld.o st.o add.o sub.o and.o or.o xor.o write.o ldi.o\
		print_dump.o\
		v_init_visualizer.o v_print.o v_operations.o v_free.o v_stats.o\
		v_cursors.o v_refresh.o v_new_instruction.o v_instructions.o\
		v_ticker.o

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

PR = libft/ft_printf/libftprintf.a

ASM_S = $(addprefix Assembler/srcs/, $(ASM_SRCS))

ASM_O = $(addprefix Assembler/obj/, $(ASM_OBJ))

VM_S = $(addprefix Virtual_Machine/src/, $(VM_SRC))

VM_O = $(addprefix Virtual_Machine/obj/, $(VM_OBJ))

NORM = norminette $(ASM_S) $(VM_S) | grep -e "Error" -e "Warning" -B 1


all: $(ASM_O) $(VM_O) $(NAME) $(NAME2) 

$(NAME)	: $(LIB) $(ASM_O) $(PR)
	@echo "\x1B[36mCompiling Assembler... \x1B[0m"
	@make -C Assembler/
	@ mv Assembler/asm .

Assembler/obj/%.o : Assembler/srcs/%.c
	@make -C Assembler/
	@ mv Assembler/asm .

$(NAME2)	: $(LIB)  $(PR)
	@echo "\x1B[36mCompiling CoreWar... \x1B[0m"
	@make -C Virtual_Machine/
	@ mv Virtual_Machine/corewar .

Virtual_Machine/obj/%.o : Virtual_Machine/src/%.c
	@make -C Virtual_Machine/
	@ mv Virtual_Machine/corewar .

$(LIB) :
	@make -C libft/

$(PR) :
	@make -C libft/ft_printf/

clean:
	@echo "\x1B[34mObjects have been removed.\x1B[0m"
	@make clean  -C Assembler/
	@make clean  -C Virtual_Machine/
	@make clean  -C libft/

fclean: clean
	@echo "\x1B[35mLibrary has been removed.\x1B[0m"
	@rm -rf asm
	@rm -rf corewar
	@make fclean  -C Assembler/
	@make fclean  -C Virtual_Machine/
	@make fclean -C libft/

re: fclean all

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"
