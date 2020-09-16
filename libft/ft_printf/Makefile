# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eutrodri <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/17 01:27:44 by eutrodri      #+#    #+#                  #
#    Updated: 2020/07/02 15:59:57 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c douix.c store_flags.c clear_struct.c \
	   check_specifier.c putnbr_base.c unsigned_wp.c count_nbr.c\
	   handle_zero.c print_hash.c print_percision.c print_width.c\
	   di.c oux.c signed_wp.c handle_zeros.c print_plus_space.c\
	   print_neg.c print_char.c print_pointer.c print_str.c\
	   store_percision_width.c f.c get_float_in_string.c\
	   get_flags_in_float.c check_validf.c

OBJ = ft_printf.o douix.o store_flags.o clear_struct.o \
	  check_specifier.o putnbr_base.o unsigned_wp.o count_nbr.o\
	  handle_zero.o print_hash.o print_percision.o print_width.o\
	  di.o oux.o signed_wp.o handle_zeros.o print_plus_space.o\
	  print_neg.o print_char.o print_pointer.o print_str.o\
	  store_percision_width.o f.o get_float_in_string.o\
	  get_flags_in_float.o check_validf.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< -I .

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
