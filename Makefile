# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:19:53 by jolivare          #+#    #+#              #
#    Updated: 2024/09/17 12:17:35 by jolivare         ###   ########.fr        #
=======
#    By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:19:53 by jolivare          #+#    #+#              #
#    Updated: 2024/09/17 11:40:16 by rpisoner         ###   ########.fr        #
>>>>>>> 8618c2375bb8c2060c21e1660708cb9e95db2fe7
#                                                                              #
# **************************************************************************** #

NAME = minishell

NAME = minishell

SOURCES = src/main.c src/built-ins/getenv.c utils/isspace.c utils/ft_strjoin_char.c \
<<<<<<< HEAD
		src/parser/lexer.c src/executor/single_command.c src/path.c src/executor/multiple_commands.c \
=======
		src/parser/lexer.c src/path.c src/executor/one_command.c\
>>>>>>> 8618c2375bb8c2060c21e1660708cb9e95db2fe7
		src/initialize.c src/errors.c src/parser/expander_utils.c src/parser/checkers.c src/signals.c \
		utils/free_stuff.c utils/dev_utils.c src/parser/parser.c utils/redir.c \

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
