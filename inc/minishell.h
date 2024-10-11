/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:32:02 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 14:38:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# define WRITE 1
# define READ 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

typedef struct s_input
{
	char	*raw_info;
	char	*current_word;
	char	**words;
	int		aux_fd;
	int		infile;
	int		outfile;
}	t_input;

typedef struct s_parsed
{
	char	**cmd;
	char	*path;
	int		here_doc;
	int		aux_fd;
	int		infile;
	int		outfile;
	int		in_redir;
	char	**infiles;
	char	**outfiles;
}	t_parsed;

typedef struct s_mini
{
	t_input		input;
	t_parsed	**parsed;
	int			old_pipe[2];
	int			new_pipe[2];
	char		**envp;
	char		**path;
	char		*cmd_path;
	int			here_doc;
	int			ign_char;
	int			line;
	int			meta_char;
	int			unclosed_quote;
	int			cmd_num;
	int			quoted;
	int			redir;
	int			my_stdin;
	int			last_in;
	int			my_stdout;
	int			last_out;
	char		t_quote;
	int			status;
	int			last_child;
}	t_mini;

//DEV_UTILS FUNCTIONS
void	print_stuff(char **stuff);
void	print_parsed_cmd(t_mini *mini);
void	write_word(char *word, int init, int len);

//INITIALIZE FUNCTIONS
void	initialize_data(t_mini *mini, char **envp);
void	initialize_input(t_mini *mini);
char	**copy_envp(char **envp);
char	**modify_shlvl(char **envp);
char	**insert_into_env(char **envp, char *insert);

//BUILT INS
int		is_built_in(char **str);
void	do_built_ins(t_mini *mini, char **str);
void	get_env(t_mini *mini);
void	do_pwd(t_mini *mini);
void	do_exit(t_mini *mini, char **str);
void	do_unset(t_mini *mini, char **str);
void	do_cd(t_mini *mini, char **str, int i);
void	do_echo(t_mini *mini, char	**str, int i);
void	do_export(t_mini *mini, char **str, int i);

//BUILT-INS UTILS
int		search_on_env(char **envp, char *var);
int		search_env_var(t_mini *mini, char *var);

//TOKENIZER FUNCTIONS
void	lexer(t_mini *mini);
void	store_word(t_mini *mini, int *j, int *k);
int		next_word_size(t_mini *mini, int i);

//EXTRA LIBFT UTILS 
int		ft_isspace(char c);
char	*ft_strjoin_char(char *s1, char c);

//COUNTER FUNCIONS
int		split_counter(t_mini *mini);
void	dquotes(char *comando, int len, int *i, int *memoria_total);
void	squotes(char *comando, int len, int *i, int *memoria_total);
void	redirections(char *comando, int len, int *i, int *memoria_total);
void	symbols(int *i, int *memoria_total);
void	advancer(char *comando, int len, int *i, int *memoria_total);
int		is_redirection(char c);
int		is_symbol(char c);

//PARSER FUNCTIONS
void	parse_commands(t_mini *mini);
void	parse_quotes(t_mini *mini);

// REDIR FUNCTIONS
void	check_here_doc(t_mini *mini);
void	reassign_words(char **str);
void	emulate_here_doc(t_mini *mini, char *limiter);
void	manage_in_redir(t_mini *mini, int i);
void	manage_out_redir(t_mini *mini, int i);
void	manage_redir(t_mini *mini, int i);
void	manage_single_redir(t_mini *mini);
void	manage_pipe_out(t_mini *mini, int i, int j);
void	manage_pipe_in(t_mini *mini, int i, int j);
void	copy_std_io(t_mini *mini);

//PATH FUNCTIONS
char	**search_path(char **envp);
int		get_cmd_path(t_mini *mini);
int		get_values(t_mini *mini, int index);

//EXECUTE FUNCTIONS
void	execute_one_cmd(t_mini *mini);
void	execute_fork(t_mini *mini);
void	first_command(t_mini *mini);
void	mid_commands(t_mini *mini, int i);
void	last_command(t_mini *mini, int i);
void	multiple_commands(t_mini *mini);
void	execute_commands(t_mini *mini);

// GET_NEXT_LINE
char	*get_next_line(int fd);

//EXPAND UTILS FUNCTIONS
void	annex_content(t_mini *mini, char *var_content, int *j);
char	*var_name(t_mini *mini, int i);
char	*search_var(t_mini *mini, char *var);
//CHECKERS
void	ign_char_setter(t_mini *mini);
void	copy_redirs(t_mini *mini, char *token, int i);
void	redir_check(t_mini *mini, int *i, int *j, int *k);
void	expander_check(t_mini *mini, int *i, int *j);
void	pipe_check(t_mini *mini, int *i, int *j, int *k);
void	quote_check(t_mini *mini, int i);
void	checkers(t_mini *mini, int *i, int *j, int *k);
//SIGNALS
void	signals(void);
//ERRRORS
void	exec_error(void);
void	unclosed_quote_check(t_mini *mini);
void	malloc_error(void);
void	pipe_error(void);
//FREE FUNCTIONS
void	free_stuff(t_mini *mini);
void	free_strs(char	**str);

#endif