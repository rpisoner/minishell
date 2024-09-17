/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:32:02 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/17 15:02:22 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "pipex/pipex_bonus.h"
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


/**Estructura para el input */
typedef struct s_input
{
	char	*raw_info;
	char	*current_word;
	char	**words;
	int		infile;
	int		outfile;
}	t_input;

typedef struct s_parsed
{
	char	**cmd;
	char	*path;
	int		here_doc;
	int		infile;
	int		outfile;
	char	**infiles;
	char	**outfiles;
}	t_parsed;

/** Estructura para la ejecución*/
// Se va a parecer mucho a la del pipex esta
// Yo la haría la principal(donde linkamos las demás)
typedef struct s_mini
{
	t_input		input;
	t_pipe		*pipex;
	t_parsed	**parsed;
	char		**envp;
	char		**path;
	int			ign_char;
	int			cmd_num;
	int			quoted;
	char		t_quote;
	int			status;
}	t_mini;

//DEV_UTILS FUNCTIONS
void	print_stuff(char **stuff);
void	print_parsed_cmd(t_mini *mini);

//INITIALIZE FUNCTIONS
void	initialize_data(t_mini *mini, char **envp);
void	initialize_input(t_mini *mini);

//BUILT INS
void	get_env(t_mini *mini);

//TOKENIZER FUNCTIONS
void	lexer(t_mini *mini);
void	store_word(t_mini *mini, int *j, int *k);

//EXTRA LIBFT UTILS 
int		ft_isspace(char c);
char	*ft_strjoin_char(char *s1, char c);

//PARSER FUNCTIONS
void	parse_commands(t_mini *mini);
void	manage_redir(t_mini *mini);
void	manage_single_redir(t_mini *mini);

//PATH FUNCTIONS
char	**search_path(char **envp);
int		get_cmd_path(t_mini *mini);

//EXECUTE FUNCTIONS
void	execute_one_cmd(t_mini *mini);
void	execute_commands(t_mini *mini);

//EXPAND UTILS FUNCTIONS
void	annex_content(t_mini *mini, char *var_content, int *j);
char	*var_name(t_mini *mini, int i);
char	*search_var(t_mini *mini, char *var);
//CHECKERS
void	ign_char_setter(t_mini *mini);
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
//FREE FUNCTIONS
void	free_stuff(t_mini *mini);

#endif