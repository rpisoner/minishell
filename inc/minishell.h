/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:32:02 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/15 18:05:14 by jolivare         ###   ########.fr       */
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

	// Hacemos flag de si hay here_doc?
	int				here_doc;
	int				infile;
	int				outfile;

	// Char **infiles y char **outfiles??
	char			**infiles;
	char			**outfiles;
	/** En este ya no se que más habría que poner*/
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
	// Array de childs?
	// pid_t *childs;
	int		status;
	int		quoted;
	int		double_quote;
	int		single_quote;
	char	t_quote;
}	t_mini;

/** Como mucho haría una más para las señales*/

void	initialize_data(t_mini *mini, char **envp);

void	get_env(t_mini *mini);

void	divide_commands(t_mini *mini);

int		ft_isspace(char c);

char	**search_path(char **envp);

//ERRRORS
void	unclosed_quote_check(t_mini *mini);

#endif