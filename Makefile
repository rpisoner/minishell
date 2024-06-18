# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:19:53 by jolivare          #+#    #+#              #
#    Updated: 2024/06/18 15:44:25 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = src/history.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = inc/libft/libft.a
PRINTF = inc/printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = cc

all: $(NAME)

$(LIBFT):
	$(MAKE) -sC inc/libft/
	$(MAKE) -sC inc/printf/

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME) -Linc/libft/ -lft -Linc/printf/ -lftprintf -lreadline

clean:
	make clean -sC inc/libft
	make clean -sC inc/printf
	$(REMOVE) $(OBJECTS)

fclean: clean
	make fclean -sC inc/libft
	make fclean -sC inc/printf
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re