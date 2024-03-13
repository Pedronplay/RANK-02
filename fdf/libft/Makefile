# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 09:58:50 by pebarbos          #+#    #+#              #
#    Updated: 2024/01/17 12:44:47 by pebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################COLORS###############################################

GREEN			= \033[1;32m
RESET			= \033[1;0m
BRIGHT_BLACK	= \033[1;30m
RED				= \033[1;31m
BRIGHT_GREEN	= \033[1;32m
BRIGHT_YELLOW	= \033[1;33m
BRIGHT_BLUE		= \033[1;34m
BRIGHT_MAGENTA	= \033[1;35m
BRIGHT_CYAN		= \033[1;36m
BRIGHT_WHITE	= \033[1;37m

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
USERNAME = $(USER)
SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isprint.c ft_memmove.c \
ft_strlcat.c ft_strlen.c ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c \
ft_memset.c ft_strlcpy.c ft_toupper.c ft_isascii.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c \
ft_strdup.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_split.c ft_striteri.c ft_itoa.c\
ft_printf.c ft_print_base.c ft_print_ptr.c ft_print_char.c ft_print_str.c \
get_next_line.c ft_atol.c

LISTS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
LISTS_OBJS = $(LISTS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN) $(USERNAME) $(BRIGHT_MAGENTA)IS READYYYYYYY! $(RESET)"
	@ar rc $(NAME) $(OBJS)

lists : $(LISTS_OBJS) $(OBJS)
	@echo "$(GREEN) SOME HELP FILES DONE$(RESET)"
	ar rc $(NAME) $(LISTS_OBJS) $(OBJS)

clean:
	@echo "$(MAGENTA) OBJECTS WENT TO TRASH$(RESET)"
	rm -rf $(OBJS) $(LISTS_OBJS)

fclean: clean
	@echo "$(RED) I LOST EVERYTHING :($(RESET)"
	rm -rf $(NAME)

re: fclean all

#.SILENT:
