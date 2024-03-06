# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedronplay <pedronplay@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 10:27:26 by pebarbos          #+#    #+#              #
#    Updated: 2024/03/06 15:04:03 by pedronplay       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	#Compiling Variables#
CC		 = cc
CFLAGS	 = -g -Wall -Wextra -Werror

	#Names#
NAME	= push_swap
BONUS	= checker

	#LIBFT Variables#
LIBFT		= ./libft/libft.a

	#Sources#
SRCS = push_swap.c \
	./inserting_to_stacks/verify_args.c \
	./inserting_to_stacks/insert_to_stacks.c \
	./operations/rotate_operations.c \
	./operations/swap.c \
	./algorithm/algorithm.c \
	./algorithm/algorithm_utils.c \
	./algorithm/big_sort_utils.c

BONUS_SRCS = checker.c \
	./inserting_to_stacks/verify_args.c \
	./inserting_to_stacks/insert_to_stacks.c \
	./operations/rotate_operations.c \
	./operations/swap.c \
	./algorithm/algorithm_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BNS_SR = $(BONUS_SRCS:.c=.o)
##################### MAKEFILE RULES ##########################

all: $(LIBFT) $(NAME)

bonus: all $(BONUS) $(LIBFT)

clean:
	${MAKE} clean -C ./libft
	rm -rf $(OBJS)
	rm -rf $(OBJS_BNS_SR)
	
fclean: clean
	${MAKE} fclean -C ./libft
	rm -rf $(NAME)
	rm -rf $(BONUS)

re: fclean all

################# MAKING MAIN PROGRAM ##################################

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft 

################################ MAKING BONUS PROGRAMS #################
#
$(BONUS): $(OBJS_BNS_SR)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BNS_SR) -L./libft -lft 

################################# Making LIBFT #########################
$(LIBFT):
	${MAKE} --no-print-directory -C ./libft
