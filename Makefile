# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:19:51 by jocaball          #+#    #+#              #
#    Updated: 2023/05/01 12:48:55 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDR = ft_printf.h

SRC	= 	ft_printf.c			ft_chars_convert.c	ft_nbrs_convert.c \
		ft_hex_convert.c	ft_flags_input.c	ft_flags_output.c
		
OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a

MAKE_LIBFT = @make -C libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rcs 

all : make_ft $(NAME)

make_ft:
	$(MAKE_LIBFT)

$(NAME): $(OBJ) $(HDR) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@$(LIB) $(NAME) $(OBJ)
	@echo "Library $(NAME) has been created"

.PHONY: clean fclean re 

clean :
	rm -f $(OBJ)
	$(MAKE_LIBFT) clean 

fclean : clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re : fclean all

tests : all
	gcc -Wall -Werror -Wextra tests.c -L. -lftprintf
	./a.out
