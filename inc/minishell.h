/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:32:02 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/18 15:31:18 by jolivare         ###   ########.fr       */
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
	char			*raw_info;
	char			**words;
	char			*cmds;
	char			*flags;
	char			*path;
	int				here_doc;
	int				infile;
	int				outfile;
	char			**infiles;
	char			**outfiles;
}	t_input;

/** Estructura para la ejecución*/
// Se va a parecer mucho a la del pipex esta
// Yo la haría la principal(donde linkamos las demás)
typedef struct s_mini
{
	t_input	input;
	char	**envp;
	char	**path;
	int		cmd_num;
	int		status;
	int		quoted;
	char	t_quote;
}	t_mini;

void	initialize_data(t_mini *mini, char **envp);

void	get_env(t_mini *mini);

void	divide_commands(t_mini *mini);

int		ft_isspace(char c);

char	**search_path(char **envp);

void	expand_var(t_mini *mini, char *var, int i);
char	*search_var(t_mini *mini, char *var);
void	expander(t_mini *mini);

//ERRRORS
void	unclosed_quote_check(t_mini *mini);
void	malloc_error(void);

#endif