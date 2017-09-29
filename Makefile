# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drecours <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 10:51:51 by drecours          #+#    #+#              #
#    Updated: 2017/09/29 13:44:38 by drecours         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
FLAGS = -Werror -Wall -Wextra
TERMCAPS = -ltermcap
SRCS = main.c 

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
