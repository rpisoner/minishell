# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:19:53 by jolivare          #+#    #+#              #
#    Updated: 2024/10/03 11:44:23 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

#########################################################################################
# Sources & objects
#########################################################################################

SOURCES = src/main.c src/built-ins/getenv.c utils/isspace.c utils/ft_strjoin_char.c \
		src/parser/lexer.c utils/path.c src/executor/single_command.c utils/get_next_line_bonus.c\
		src/initialize.c src/errors.c src/parser/expander_utils.c src/parser/checkers.c src/signals.c \
		utils/free_stuff.c utils/dev_utils.c src/parser/parser.c utils/redir.c src/single_path.c \
		utils/flag_utils.c  utils/redir_utils.c src/executor/childs.c  src/executor/forks.c src/executor/multiple_commands.c \
		src/built-ins/pwd.c  src/built-ins/built-ins.c utils/get_env_utils.c src/built-ins/exit.c  src/built-ins/unset.c \
		src/parser/redirection_utils.c src/parser/counter_utils.c  src/parser/counter.c  utils/next_word_size.c \
		src/built-ins/cd.c

OBJECTS = $(SOURCES:.c=.o)
LIBFT = inc/libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3
REMOVE = rm -f
CC = cc

#########################################################################################
# Colors
#########################################################################################
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

#########################################################################################
# Compilation rules
#########################################################################################

all: $(NAME)

$(LIBFT):
	@printf "$(Y)Compiling libft...$(END)\n"
	@$(MAKE) -sC inc/libft/
	@printf "$(G)Libft:\t\tcompiled!📚$(END)\n"
	
$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME) -Linc/libft/ -lft -lreadline
	@printf "$(G)Minishell:\tCompiled!🥟$(END)\n"
	
%.o: %.c
	@printf "$(Y)Compiling $<...$(END)\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(CUT)\r"

clean:
	@make clean -sC inc/libft
	@$(REMOVE) $(OBJECTS)
	@printf "$(R)All .o files removed$(END)\n"
	
fclean: clean
	@make fclean -sC inc/libft
	@printf "$(R)Executable file removed$(END)\n"
	@$(REMOVE) $(NAME)

re: fclean all

c: all clean

.PHONY: all clean fclean re

r: all clean
	@clear
	@./$(NAME)

v: all
	@clear
	@valgrind --leak-check=full ./$(NAME)	
