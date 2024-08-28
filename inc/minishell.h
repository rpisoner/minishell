/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:32:02 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/28 11:19:15 by rpisoner         ###   ########.fr       */
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
	/** En este caso si pillamos las flags porque no podemos hacer el split*/
	char	*raw_info;
	char	**words;
	char	*current_word;
	char	*cmds;
	char	*flags;
	char	*path;
	int		here_doc;
	int		infile;
	int		outfile;
	char	**infiles;
	char	**outfiles;
}	t_input;

/** Estructura para la ejecución*/
// Se va a parecer mucho a la del pipex esta
// Yo la haría la principal(donde linkamos las demás)
typedef struct s_mini
{
	t_input	input;
	t_pipe	*pipex;
	char	**envp;
	char	**path;
	int		expanded;
	int		cmd_num;
	int		status;
	int		more_envs;
	int		quoted;
	char	t_quote;
}	t_mini;

void	initialize_data(t_mini *mini, char **envp);

void	get_env(t_mini *mini);

void	divide_commands(t_mini *mini);

int		ft_isspace(char c);
char	*ft_strjoin_char(char *s1, char c);

//PATH FUNCTIONS
char	**search_path(char **envp);
int		get_cmd_path(t_mini *mini);
//EXECUTE FUNCTIONS
void	execute_one_cmd(t_mini *mini);
void	execute_commands(t_mini *mini);
//EXPAND FUNCTIONS
void	expander_check(t_mini *mini, int *i, int *j);
void	expander_setter(t_mini *mini);
//ERRRORS
void	exec_error(void);
void	unclosed_quote_check(t_mini *mini);
void	malloc_error(void);
//QUOTE CHECKER
void	quote_check(t_mini *mini, int i);
//SIGNALS
void	signals(void);
//FREE FUNCTIONS
void	free_stuff(t_mini *mini);

#endif