/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:41:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/25 17:57:47 by rpisoner         ###   ########.fr       */
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
	execve(mini->cmd_path, mini->input.words, mini->envp);
	exec_error();
}

void	execute_commands(t_mini *mini)
{
	if (mini->cmd_num == 1)
		one_cmd(mini);
	else if (mini->cmd_num > 1)
		multiple_commands(mini);
}