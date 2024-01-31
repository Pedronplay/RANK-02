# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 10:27:26 by pebarbos          #+#    #+#              #
#    Updated: 2024/01/31 11:33:23 by pebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	#Compiling Variables#
CC		 = cc
CFLAGS	 = -Wall -Wextra -Werror

	#Names#
NAME	= push_swap

	#LIBFT Variables#
LIBFT		= ./libft/libft.a

	#Sources#
SRCS	=	push_swap.c verify_args.c insert_to_stacks.c
#Im going to put here the .c files im going to make its wild for now

OBJS	=	$(SRCS:.c=.o)

##################### MAKEFILE RULES ##########################

all: $(LIBFT) $(NAME)

bonus: $(LIBFT)

clean: 
	${MAKE} clean -C ./libft
	rm -rf $(OBJS)
	
fclean: clean
	${MAKE} fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

################# MAKING MAIN PROGRAM ##################################

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft 

################################ MAKING BONUS PROGRAMS #################
#
#$(SERVER_BONUS): $(OBJS_BNS_SR)
#	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJS_BNS_SR) -L./libft -lft 
#
################################# Making LIBFT #########################
$(LIBFT):
	${MAKE} --no-print-directory -C ./libft
