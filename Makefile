# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:19:53 by jolivare          #+#    #+#              #
#    Updated: 2024/09/25 15:26:12 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

NAME = minishell

SOURCES = src/main.c src/built-ins/getenv.c utils/isspace.c utils/ft_strjoin_char.c \
		src/parser/lexer.c src/single_path.c src/executor/single_command.c \
		src/initialize.c src/errors.c src/parser/expander_utils.c src/parser/checkers.c src/signals.c \
		utils/free_stuff.c utils/dev_utils.c src/parser/parser.c utils/redir.c utils/get_next_line_bonus.c \
		utils/flag_utils.c utils/redir_utils.c src/executor/multiple_commands.c src/executor/childs.c \
		src/executor/forks.c utils/path.c

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
	@valgrind --trace-children=yes --track-fds=all --leak-check=full ./$(NAME)	