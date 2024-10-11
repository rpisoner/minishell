/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:41:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 11:53:42 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

void	execute_built_ins(t_mini *mini)
{
	manage_single_redir(mini);
	mini->last_in = dup2(mini->input.infile, STDIN_FILENO);
	mini->last_out = dup2(mini->input.outfile, STDOUT_FILENO);
	do_built_ins(mini, mini->input.words);
	dup2(mini->stdin, mini->last_in);
	dup2(mini->stdout, mini->last_out);
}

void	execute_commands(t_mini *mini)
{
	if (mini->cmd_num == 1)
	{
		if (is_built_in(mini->input.words) == 0)
			one_cmd(mini);
		else if (is_built_in(mini->input.words) == 1)
			execute_built_ins(mini);
	}
	else if (mini->cmd_num > 1)
		multiple_commands(mini);
}
