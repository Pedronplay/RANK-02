# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omeunome <omeunome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 12:37:06 by pebarbos          #+#    #+#              #
#    Updated: 2024/07/01 13:53:15 by omeunome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


	#Compiling Variables#
CC		 = cc
CFLAGS	 = -Wall -Wextra -Werror -g
MINILXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lbsd -lm -no-pie #-fsanitize=address

	#Names#
NAME	= fdf
# BONUS	= 

	#Library Variables#
LIBFT		= ./libft/libft.a 

	#Sources#
SRCS = main.c \
		./src/verify_maps.c \
		./src/save_map_vals.c \
		./src/create_img.c \
		./src/draw_utils.c \
		./src/rotations.c \
		./src/signals.c

# BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)
# OBJS_BNS_SR = $(BONUS_SRCS:.c=.o)
##################### MAKEFILE RULES ##########################

all: $(LIBFT) $(NAME)

bonus: all $(BONUS) $(LIBFT)

clean:
	${MAKE} clean -C ./libft
	rm -rf $(OBJS)
#	rm -rf $(OBJS_BNS_SR)
	
fclean: clean
	$(MAKE) clean -C ./minilibx-linux
	${MAKE} fclean -C ./libft
	rm -rf $(NAME)
#	rm -rf $(BONUS)

re: fclean all

################# MAKING MAIN PROGRAM ##################################

$(NAME): $(OBJS)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft $(MINILXFLAGS)

################################ MAKING BONUS PROGRAMS #################
#
#$(BONUS): $(OBJS_BNS_SR)
#	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BNS_SR) -L./libft -lft 

################################# Making LIBFT #########################
$(LIBFT):
	${MAKE} --no-print-directory -C ./libft
