# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:10:08 by pebarbos          #+#    #+#              #
#    Updated: 2024/01/09 06:36:45 by pebarbos         ###   ########.fr        #
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
SRC_SRV_BNS	= server_bonus.c

OBJS_SERVER = $(SRC_SRV:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	ar rc $(SERVER) $(OBJS_SERVER)

$(CLIENT): $(OBJS_CLIENT)
	ar rc $(CLIENT) $(OBJS_CLIENT)

clean:
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all
