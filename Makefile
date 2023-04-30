# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:19:51 by jocaball          #+#    #+#              #
#    Updated: 2023/04/27 20:27:55 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDR = ft_printf.h
SRC	= ft_printf.c ft_convertions.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rcs 

all : $(NAME)

$(NAME): $(OBJ) $(HDR)
	make -C libft
	@$(LIB) $(NAME) $(OBJ)
	@echo "Library has been created"

.PHONY: clean fclean re 

clean :
	rm -f $(OBJ) 

fclean : clean
	rm -f $(NAME)

re : fclean all
