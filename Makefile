# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:19:51 by jocaball          #+#    #+#              #
#    Updated: 2023/05/03 10:53:45 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDR = ft_printf.h

SRC	= 	ft_printf.c			pf_char_convert.c	pf_str_convert.c	\
		pf_hex_convert.c	pf_int_convert.c 	pf_uint_convert.c	\
		pf_flags_read.c		ft_htoa.c			ft_uitoa.c		\
		ft_putchar.c		ft_putstr.c
		
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
	@echo "-------> Library $(NAME) has been created"

.PHONY: clean fclean re bonus make_ft

clean :
	rm -f $(OBJ)
	$(MAKE_LIBFT) clean 

fclean : clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re : fclean all

bonus : all
	$(MAKE_LIBFT) bonus
	@cp $(LIBFT) $(NAME)
	@$(LIB) $(NAME) $(OBJ)
	@echo "-------> Library $(NAME) has been created including bonus functions"
