# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eovertoo <eovertoo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/02 17:11:36 by eovertoo      #+#    #+#                  #
#    Updated: 2020/09/16 21:38:49 by eutrodri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC =  main.c utils_nflag.c check_args.c itoa_base.c reading.c intro.c\
		str_rev_by_2.c game_setup.c game_set_par.c set_cursors.c free.c count.c\
		usage.c utils_nflag2.c nflag.c game_loop.c cursor.c enc_byte.c new.c\
		utilities.c operations.c op.c print_dump.c operations/ld.c\
		operations/fork.c operations/live.c operations/sti.c operations/aff.c\
		operations/zjmp.c operations/st.c operations/add.c operations/sub.c\
		operations/and.c operations/or.c operations/xor.c write.c\
		operations/ldi.c

OBJ =  main.o utils_nflag.o check_args.o itoa_base.o reading.o intro.o\
		str_rev_by_2.o game_setup.o game_set_par.o set_cursors.o free.o count.o\
		usage.o utils_nflag2.o nflag.o game_loop.o cursor.o enc_byte.o new.o\
		utilities.o operations.o op.o fork.o sti.o aff.o zjmp.o live.o\
		ld.o st.o add.o sub.o and.o or.o xor.o write.o ldi.o\
		print_dump.o

FLAGS = -Wall -Wextra -Werror

INC = ../includes/

LIB = ../libft/libft.a

PR = ../libft/ft_printf/libftprintf.a

S = $(addprefix src/, $(SRC))

O = $(addprefix obj/, $(OBJ))

O_P = mkdir -p obj

all: $(NAME)

$(NAME)	: $(LIB) $(O) $(PR)
	@echo "\x1B[36mCompiling... \x1B[0m"
	@gcc -o $(NAME) $(O) -I ../includes ../libft/ft_printf/libftprintf.a \
	../libft/libft.a

obj/%.o :  src/%.c
	@$(O_P)
	@gcc $(FLAGS) -c -o $@ $< -I includes

obj/%.o : src/operations/%.c
	@$(O_P)
	@gcc $(FLAGS) -c -o $@ $< -I includes

$(LIB) :
	@make -C libft/

$(PR) :
	@make -C libft/ft_printf/

clean:
	@echo "\x1B[34mObjects have been removed.\x1B[0m"
	@rm -rf $(O) obj/

fclean: clean
	@echo "\x1B[35mLibrary has been removed.\x1B[0m"
	@/bin/rm -f $(NAME) libft.a

re: fclean all
