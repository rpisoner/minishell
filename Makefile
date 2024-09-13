# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:19:53 by jolivare          #+#    #+#              #
#    Updated: 2024/09/13 23:27:55 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

NAME = minishell

SOURCES = src/main.c src/built-ins/getenv.c utils/isspace.c utils/ft_strjoin_char.c \
		src/parser/lexer.c src/exec.c src/path.c \
		src/initialize.c src/errors.c src/parser/expander_utils.c src/parser/checkers.c src/signals.c \
		utils/free_stuff.c utils/dev_utils.c src/parser/parser.c

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

r: all clean
	@clear
	@./$(NAME)

v: all
	@clear
	@valgrind --leak-check=full ./$(NAME)	
