# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:10:08 by pebarbos          #+#    #+#              #
#    Updated: 2024/01/10 03:40:30 by pebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	#Compiling Variables#
CC		 = cc
CFLAGS	 = -Wall -Wextra -Werror

	#Names#
CLIENT	= client
SERVER	= server

	#LIBFT Variables#
LIBFT		= ./libft/libft.a

	#Sources#
SRC_CLIENT	= client.c
SRC_SRV		= server.c
SRC_CLIENT_BNS	= client_bonus.c
SRC_SRV_BNS		= server_bonus.c

OBJS_SERVER = $(SRC_SRV:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(LIBFT) $(SERVER) $(CLIENT)
	@echo "done some shit"	#${MAKE} --no-print-directory -C ./libft

$(LIBFT):
	${MAKE} --no-print-directory -C ./libft

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) -L./libft -lft 

$(CLIENT):  $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) -L./libft -lft	

clean: 
	${MAKE} clean -C ./libft
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	${MAKE} fclean -C ./libft
	rm -rf $(CLIENT) $(SERVER)

re: fclean all
