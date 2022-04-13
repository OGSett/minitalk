# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 02:43:33 by yel-mekk          #+#    #+#              #
#    Updated: 2021/12/24 01:28:46 by yel-mekk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = 	ft_printf.c \
		needed.c \
		needed1.c \

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	$(CC) -c $(FLAGS) $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
