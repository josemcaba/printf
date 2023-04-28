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

SRC	= ft_printf.c

OBJ = $(SRC:%.c=%.o)

LIBFT_PATH = ./libft

LIBFT_NAME = $(LIBFT_PATH)/libft.a

HDR = ft_printf.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rcs 

all : $(NAME)

$(NAME): $(OBJ) $(HDR):
	cp $(LIBFT_NAME) $(NAME)
	@$(LIB) $(NAME) $(OBJ)
	@echo "Library has been created"

clean :
#	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ) $(OBJ_BONUS) 

fclean : clean
#	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re 
