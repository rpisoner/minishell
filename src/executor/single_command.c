/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:41:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/24 13:40:21 by jolivare         ###   ########.fr       */
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
	if (pid == 0)
	{
		manage_single_redir(mini);
		execute_one_cmd(mini);
	}
	waitpid(pid, &status, 0);
	mini->status = WEXITSTATUS(status);
}

void	execute_one_cmd(t_mini *mini)
{
	if (mini->input.infile != -1)
	{
		if (dup2(mini->input.infile, STDIN_FILENO) < 0)
		{
			printf("Error en primer dup\n");
			return ;
		}
	}
	if (mini->input.outfile != -1)
	{
		if (dup2(mini->input.outfile, STDOUT_FILENO) < 0)
		{
			printf("Error en dup2\n");
			return ;
		}
		close (mini->input.outfile);
	}
	if ((get_cmd_path(mini)))
		exec_error();
	check_here_doc(mini);
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
	if (mini->cmd_num == 1)
		one_cmd(mini);
	free((mini->pipex));
}