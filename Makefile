# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drecours <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 10:51:51 by drecours          #+#    #+#              #
#    Updated: 2017/10/06 15:19:23 by drecours         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
FLAGS = -Werror -Wall -Wextra
TERMCAPS = -ltermcap
SRCS =  srcs/main.c \
		srcs/my_putchar.c \
		srcs/list.c \
		srcs/ft_memalloc.c \
		srcs/ft_memset.c \
		srcs/ft_select.c \
		srcs/ft_move.c \
		srcs/ft_strlen.c \
		srcs/mac_key_n.c \
		srcs/init_win.c \
		srcs/ft_erase.c \
		srcs/ft_return.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putendl_fd.c \
		srcs/get_signal.c \
		srcs/win.c
	#	srcs/ft_quit.c \ 

OBJ = $(SRCS:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(TERMCAPS) -o $(NAME) $(SRCS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
