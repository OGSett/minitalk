# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mekk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 00:01:30 by yel-mekk          #+#    #+#              #
#    Updated: 2022/04/11 00:01:40 by yel-mekk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: client server

client: client.c utils.c
	@cd ft_printf && make
	cc -Wall -Wextra -Werror client.c utils.c ft_printf/libftprintf.a -o client

server:	server.c
	cc -Wall -Wextra -Werror server.c ft_printf/libftprintf.a -o server

client_bonus: client_bonus.c utils.c
	@cd ft_printf && make
	cc -Wall -Wextra -Werror client_bonus.c utils.c ft_printf/libftprintf.a -o client_bonus

server_bonus:	server_bonus.c
	cc -Wall -Wextra -Werror server_bonus.c ft_printf/libftprintf.a -o server_bonus

bonus: client_bonus server_bonus

fclean: clean
	@$(MAKE) -C ft_printf fclean
	@rm -f	client
	@rm -f	server
	@rm -f	client_bonus
	@rm -f	server_bonus
	@echo 'Full clean done'

clean: 
	@$(MAKE) -C ft_printf clean
	@rm -f	client
	@rm -f	server
	@rm -f	client_bonus
	@rm -f	server_bonus
	@echo 'clean done'

re: fclean all
