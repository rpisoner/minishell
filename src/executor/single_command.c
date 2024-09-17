/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD:src/executor/single_command.c
/*   single_command.c                                   :+:      :+:    :+:   */
=======
/*   one_command.c                                      :+:      :+:    :+:   */
>>>>>>> 8618c2375bb8c2060c21e1660708cb9e95db2fe7:src/executor/one_command.c
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:41:22 by jolivare          #+#    #+#             */
<<<<<<< HEAD:src/executor/single_command.c
/*   Updated: 2024/09/17 12:13:06 by jolivare         ###   ########.fr       */
=======
/*   Updated: 2024/09/17 11:39:01 by rpisoner         ###   ########.fr       */
>>>>>>> 8618c2375bb8c2060c21e1660708cb9e95db2fe7:src/executor/one_command.c
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**Si hay más de un comando hacemos como en el pipex, si no hardcodeada histórica*/

void	one_cmd(t_mini *mini)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		mini->status = 1;
		return ;
	}
	manage_single_redir(mini);
	if (pid == 0)
		execute_one_cmd(mini);
	waitpid(pid, &status, 0);
	mini->status = WEXITSTATUS(status);
}

void	execute_one_cmd(t_mini *mini)
{
	if(mini->input.outfile != -1)
	{
		if (dup2(mini->input.outfile, STDOUT_FILENO) < 0)
		{
			perror("Error en dup2");
			return ;
		}
		close(mini->input.outfile);
	}
	if ((get_cmd_path(mini)))
		exec_error();
	execve(mini->pipex->path, mini->input.words, mini->envp);
	exec_error();
}

void	init_pipex(t_pipe **pipex)
{
	*pipex = (t_pipe *)malloc(sizeof(t_pipe));
	if (*pipex == NULL)
	{
		perror("Error al asignar memoria");
		exit(EXIT_FAILURE);
	}
}

void	execute_commands(t_mini *mini)
{
	init_pipex(&(mini->pipex));
	one_cmd(mini);
	free((mini->pipex));
}
