# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:10:08 by pebarbos          #+#    #+#              #
#    Updated: 2024/01/16 12:24:04 by pebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	#Compiling Variables#
CC		 = cc
CFLAGS	 = -Wall -Wextra -Werror

	#Names#
CLIENT	= client
CLIENT_BONUS = client_bonus
SERVER	= server
SERVER_BONUS = server_bonus

	#LIBFT Variables#
LIBFT		= ./libft/libft.a

	#Sources#
SRC_CLIENT	= client.c
SRC_SRV		= server.c
SRC_CLI_BNS	= client_bonus.c
SRC_SRV_BNS	= server_bonus.c

OBJS_SERVER = $(SRC_SRV:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_BNS_SR	= $(SRC_SRV_BNS:.c=.o)
OBJS_BNS_CL	= $(SRC_CLI_BNS:.c=.o)

##################### MAKEFILE RULES ##########################

all: $(LIBFT) $(SERVER) $(CLIENT)

bonus: all $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

clean: 
	${MAKE} clean -C ./libft
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_BNS_SR) $(OBJS_BNS_CL)

fclean: clean
	${MAKE} fclean -C ./libft
	rm -rf $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

############ MAKING MAIN PROGRAMS ###########################

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) -L./libft -lft 

$(CLIENT):  $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) -L./libft -lft	

###################### MAKING BONUS PROGRAMS #################

$(SERVER_BONUS): $(OBJS_BNS_SR)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJS_BNS_SR) -L./libft -lft 

$(CLIENT_BONUS):  $(OBJS_BNS_CL)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(OBJS_BNS_CL) -L./libft -lft

####################### Making LIBFT #########################
$(LIBFT):
	${MAKE} --no-print-directory -C ./libft

