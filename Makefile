# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:19:53 by jolivare          #+#    #+#              #
#    Updated: 2024/07/29 17:45:03 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = src/main.c src/built-ins/getenv.c utils/isspace.c src/parser/tokenizer.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = inc/libft/libft.a
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = cc

all: $(NAME)

$(LIBFT):
	$(MAKE) -sC inc/libft/

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME) -Linc/libft/ -lft -lreadline

clean:
	make clean -sC inc/libft
	$(REMOVE) $(OBJECTS)

fclean: clean
	make fclean -sC inc/libft
	$(REMOVE) $(NAME)

re: fclean all

c: all clean

.PHONY: all clean fclean re