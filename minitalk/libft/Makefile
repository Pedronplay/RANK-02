# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pebarbos <pebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 09:58:50 by pebarbos          #+#    #+#              #
#    Updated: 2024/01/10 02:48:58 by pebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isprint.c ft_memmove.c \
ft_strlcat.c ft_strlen.c ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c \
ft_memset.c ft_strlcpy.c ft_toupper.c ft_isascii.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c \
ft_strdup.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_split.c ft_striteri.c ft_itoa.c\
ft_printf.c ft_print_base.c ft_print_ptr.c ft_print_char.c ft_print_str.c \
get_next_line.c

LISTS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
LISTS_OBJS = $(LISTS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

lists : $(LISTS_OBJS) $(OBJS)
	ar rc $(NAME) $(LISTS_OBJS) $(OBJS)

clean:
	rm -rf $(OBJS) $(LISTS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
