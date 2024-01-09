# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:10:08 by pebarbos          #+#    #+#              #
#    Updated: 2023/12/27 11:36:42 by pebarbos         ###   ########.fr        #
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
# LIBFT_DIR	= ./libft
# INCLUDE		= -I. -I$(LIBFT_DIR) -I$(LIBFT_DIR)/stack

	#Sources#
SRC_CLIENT	= client.c
SRC_SRV		= server.c
SRC_CLIENT_BNS	= client_bonus.c
SRC_SRV_BNS	= server_bonus.c


all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJS_SERVER) $
		
