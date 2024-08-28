/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:41:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/28 15:37:59 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	if (pid == 0)
		execute_one_cmd(mini);
	waitpid(pid, &status, 0);
	mini->status = WEXITSTATUS(status);
}

void	execute_one_cmd(t_mini *mini)
{
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
	//free(&(mini->pipex));
}
