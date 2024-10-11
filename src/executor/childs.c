/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:18:22 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 17:45:48 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	check_mid_redir(t_mini *mini, int i)
{
	if (mini->parsed[i]->infile != -1)
	{
		dup2(mini->parsed[i]->infile, STDIN_FILENO);
		close(mini->parsed[i]->infile);
	}
	else
	{
		dup2(mini->old_pipe[READ], STDIN_FILENO);
		close(mini->old_pipe[READ]);
	}
	if (mini->parsed[i]->outfile != -1)
	{
		dup2(mini->parsed[i]->outfile, STDOUT_FILENO);
		close(mini->parsed[i]->outfile);
	}
	else
	{
		dup2(mini->new_pipe[WRITE], STDOUT_FILENO);
		close(mini->new_pipe[READ]);
		close(mini->new_pipe[WRITE]);
	}
}

void	first_command(t_mini *mini)
{
	if (mini->parsed[0]->infile != -1)
	{
		dup2(mini->parsed[0]->infile, STDIN_FILENO);
		close(mini->parsed[0]->infile);
	}
	if (mini->parsed[0]->outfile != -1)
	{
		dup2(mini->parsed[0]->outfile, STDOUT_FILENO);
		close(mini->parsed[0]->outfile);
	}
	else
	{
		dup2(mini->old_pipe[WRITE], STDOUT_FILENO);
		close(mini->old_pipe[READ]);
		close(mini->old_pipe[WRITE]);
	}
	if (is_built_in(mini->parsed[0]->cmd) == 0)
	{
		if (get_values(mini, 0) == 1)
			exec_error();
	}
	check_here_doc(mini);
	if (is_built_in(mini->parsed[0]->cmd) == 1)
	{
		do_built_ins(mini, mini->parsed[0]->cmd);
		dup2(mini->old_pipe[WRITE], STDOUT_FILENO);
		close(mini->old_pipe[READ]);
		close(mini->old_pipe[WRITE]);
	}
	else
	{
		execve(mini->cmd_path, mini->parsed[0]->cmd, mini->envp);
		exec_error();
	}
	exit (mini->status);
}

void	mid_commands(t_mini *mini, int i)
{
	check_mid_redir(mini, i);
	if (is_built_in(mini->parsed[i]->cmd) == 0)
	{
		if (get_values(mini, i) == 1)
			exec_error();
	}
	check_here_doc(mini);
	if (is_built_in(mini->parsed[i]->cmd) == 1)
		do_built_ins(mini, mini->parsed[i]->cmd);
	else
	{
		execve(mini->cmd_path, mini->parsed[i]->cmd, mini->envp);
		exec_error();
	}
	exit (mini->status);
}

void	last_command(t_mini *mini, int i)
{
	if (mini->parsed[i]->infile != -1)
	{
		dup2(mini->parsed[i]->infile, STDIN_FILENO);
		close(mini->parsed[i]->infile);
	}
	else
	{
		dup2(mini->old_pipe[READ], STDIN_FILENO);
		close(mini->old_pipe[READ]);
	}
	if (mini->parsed[i]->outfile != -1)
	{
		dup2(mini->parsed[i]->outfile, STDOUT_FILENO);
		close(mini->parsed[i]->outfile);
	}
	close(mini->old_pipe[WRITE]);
	if (is_built_in(mini->parsed[i]->cmd) == 0)
	{
		if (get_values(mini, i) == 1)
			exec_error();
	}
	check_here_doc(mini);
	if (is_built_in(mini->parsed[i]->cmd) == 1)
		do_built_ins(mini, mini->parsed[i]->cmd);
	else
	{
		execve(mini->cmd_path, mini->parsed[i]->cmd, mini->envp);
		exec_error();
	}
	exit (mini->status);
}
