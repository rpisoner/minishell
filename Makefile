# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:19:53 by jolivare          #+#    #+#              #
#    Updated: 2024/08/21 13:17:34 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = src/main.c src/built-ins/getenv.c utils/isspace.c utils/ft_strjoin_char.c \
		src/parser/tokenizer.c src/exec.c src/path.c utils/check_expansion.c \
		src/initialize.c src/errors.c src/parser/expander.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = inc/libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3
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